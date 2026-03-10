import kmNet #import kmNet模块
import time
kmNet.init('192.168.2.188','8320','24875054') #连接盒子
#下面是python调用10000次鼠标移动函数的耗时
t1=time.time()
cnt=10000
while cnt>0:
    kmNet.move(0,10)
    cnt=cnt-1
    kmNet.move(0,-10)
    cnt=cnt-1

t2=time.time()
print('10000次调用耗时%sms'%((t2-t1)*1000))    



'''
鼠标物理监控 
'''
import kmNet
import time

