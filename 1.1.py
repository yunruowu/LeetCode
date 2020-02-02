'''
@Description: 
@Version: 2.0
@Author: yunruowu
@Date: 2020-01-16 19:55:43
@LastEditors  : yunruowu
@LastEditTime : 2020-01-16 20:03:19
'''
import torch
import torch.nn as nn
DIM = 10
w = torch.empty(DIM)
torch.nn.init.uniform_(w,a=0.5,b=1.5)

def f(x): #定义要优化的函数，求x的最优解
    x= w*(x-1)
    return ((x+1)*(x+0.5)*x*(x-1)).sum()



def SGD(gradients, state, learning_rate=0.001):
    return -gradients*learning_rate, state

def RMS(gradients, state, learning_rate=0.1, decay_rate=0.9):
    if state is None:
        state = torch.zeros(DIM)
    
    state = decay_rate*state + (1-decay_rate)*torch.pow(gradients, 2)
    update = -learning_rate*gradients / (torch.sqrt(state+1e-5))
    return update, state

def Adam():
    return torch.optim.Adam()



TRAINING_STEPS = 15
theta = torch.empty(DIM)
torch.nn.init.uniform_(theta,a=-1,b=1.0) 
theta_init = torch.tensor(theta,dtype=torch.float32,requires_grad=True)

def learn(optimizee,unroll_train_steps,retain_graph_flag=False,reset_theta = False): 
    """retain_graph_flag=False   PyTorch 默认每次loss_backward后 释放动态图
    #  reset_theta = False     默认每次学习前 不随机初始化参数"""
    
    if reset_theta == True:
        theta_new = torch.empty(DIM)
        torch.nn.init.uniform_(theta_new,a=-1,b=1.0) 
        theta_init_new = torch.tensor(theta,dtype=torch.float32,requires_grad=True)
        x = theta_init_new
    else:
        x = theta_init
        
    global_loss_graph = 0 #这个是为LSTM优化器求所有loss相加产生计算图准备的
    state = None
    x.requires_grad = True
    if optimizee.__name__ !='Adam':
        losses = []
        for i in range(unroll_train_steps):
            x.requires_grad = True
            
            loss = f(x)
            
            #global_loss_graph += (0.8*torch.log10(torch.Tensor([i]))+1)*loss
            
            global_loss_graph += loss
            
            #print(loss)
            loss.backward(retain_graph=retain_graph_flag) # 默认为False,当优化LSTM设置为True
            update, state = optimizee(x.grad, state)
            losses.append(loss)
            
            #这个操作 直接把x中包含的图给释放了，
            x = x + update
            
            x = x.detach_()
            #这个操作 直接把x中包含的图给释放了，
            #那传递给下次训练的x从子节点变成了叶节点，那么梯度就不能沿着这个路回传了，        
            #之前写这一步是因为这个子节点在下一次迭代不可以求导，那么应该用x.retain_grad()这个操作，
            #然后不需要每次新的的开始给x.requires_grad = True
            
            #x.retain_grad()
            #print(x.retain_grad())
            
            
        #print(x)
        return losses ,global_loss_graph 
    
    else:
        losses = []
        x.requires_grad = True
        optimizee= torch.optim.Adam( [x],lr=0.1 )
        
        for i in range(unroll_train_steps):
            
            optimizee.zero_grad()
            loss = f(x)
            global_loss_graph += loss
            
            loss.backward(retain_graph=retain_graph_flag)
            optimizee.step()
            losses.append(loss.detach_())
        #print(x)
        return losses,global_loss_graph 


import matplotlib
import matplotlib.pyplot as plt
# %matplotlib inline
import numpy as np

T = np.arange(TRAINING_STEPS)
for _ in range(1): 
    
    sgd_losses, sgd_sum_loss = learn(SGD,TRAINING_STEPS,reset_theta=True)
    rms_losses, rms_sum_loss = learn(RMS,TRAINING_STEPS,reset_theta=True)
    adam_losses, adam_sum_loss = learn(Adam,TRAINING_STEPS,reset_theta=True)
    p1, = plt.plot(T, sgd_losses, label='SGD')
    p2, = plt.plot(T, rms_losses, label='RMS')
    p3, = plt.plot(T, adam_losses, label='Adam')
    plt.legend(handles=[p1, p2, p3])
    plt.title('Losses')
    plt.show()
    print("sum_loss:sgd={},rms={},adam={}".format(sgd_sum_loss,rms_sum_loss,adam_sum_loss ))
