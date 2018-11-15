from sympy import *
import numpy as np
#文字宣言
P0  =   Symbol('P0');
P1  =   Symbol('P1');
M0  =   Symbol('M0');
M1  =   Symbol('M1');

G0  =   Symbol('G0');
G1  =   Symbol('G1');

i=0
u_I0=[]
u_I1=[]

#I0  =   (P0/M0)/((P0/M0)+(P1/M1))
#I1  =   (P1/M1)/((P0/M0)+(P1/M1))

I0     =G0/(G0+G1)
I1     =G1/(G0+G1)
#ファイル系
data01  = np.loadtxt("./exp476_tmp.dat", comments='#')
err     = np.loadtxt("./error/476_raw.txt", comments='#')
pow_mrr = np.loadtxt("./mirror_pow/476_mrr.txt", comments='#')

# data01  = np.loadtxt("./exp705.dat", comments='#')
# err     = np.loadtxt("./error/705_raw.txt", comments='#')
# pow_mrr = np.loadtxt("./mirror_pow/705_mrr.txt", comments='#')


#dI0_dxi =   [diff(I0,P0),diff(I0,P1),diff(I0,M0),diff(I0,M1)]
#dI1_dxi =   [diff(I1,P0),diff(I1,P1),diff(I1,M0),diff(I1,M1)]

dI0_dxi =   [diff(I0,G0),diff(I0,G1)]
dI1_dxi =   [diff(I1,G0),diff(I1,G1)]
#もとの誤差を変えること
ui_raw  =   np.std(err)
G0_num  =   data01[:,1]/data01[:,2]
G1_num  =   data01[:,3]/data01[:,4]
ui_0      =   (ui_raw / pow_mrr)  *   data01[:,1]
ui_1      =   (ui_raw / pow_mrr)  *   data01[:,3]
print(ui_0)
print(ui_1)


# for i in range(5):
#     u_I0.insert(i,  sqrt(   (dI0_dxi[0].subs([(P0,data01[i,1]),(P1,data01[i,3]),(M0,data01[i,2]),(M1,data01[i,4])])*(data01[i,1]*0.1))**2
#                          +  (dI0_dxi[1].subs([(P0,data01[i,1]),(P1,data01[i,3]),(M0,data01[i,2]),(M1,data01[i,4])])*(data01[i,3]*0.1))**2
#                          +  (dI0_dxi[2].subs([(P0,data01[i,1]),(P1,data01[i,3]),(M0,data01[i,2]),(M1,data01[i,4])])*(data01[i,2]*0.1))**2
#                          +  (dI0_dxi[3].subs([(P0,data01[i,1]),(P1,data01[i,3]),(M0,data01[i,2]),(M1,data01[i,4])])*(data01[i,4]*0.1))**2
#                             ))
#     u_I1.insert(i,  sqrt(   (dI1_dxi[0].subs([(P0,data01[i,1]),(P1,data01[i,3]),(M0,data01[i,2]),(M1,data01[i,4])])*(data01[i,1]*0.1))**2
#                          +  (dI1_dxi[1].subs([(P0,data01[i,1]),(P1,data01[i,3]),(M0,data01[i,2]),(M1,data01[i,4])])*(data01[i,3]*0.1))**2
#                          +  (dI1_dxi[2].subs([(P0,data01[i,1]),(P1,data01[i,3]),(M0,data01[i,2]),(M1,data01[i,4])])*(data01[i,2]*0.1))**2
#                          +  (dI1_dxi[3].subs([(P0,data01[i,1]),(P1,data01[i,3]),(M0,data01[i,2]),(M1,data01[i,4])])*(data01[i,4]*0.1))**2
#                             ))
for i in range(5):
    u_I0.insert(i, sqrt(    (dI0_dxi[0].subs([(G0, G0_num[i]), (G1, G1_num[i])]) * ui_0[i] )** 2
                        +   (dI0_dxi[1].subs([(G0, G0_num[i]), (G1, G1_num[i])]) * ui_1[i] )** 2
                        ))
    # u_I1.insert(i, sqrt(    (dI1_dxi[0].subs([(G0, G0_num[i]), (G1, G1_num[i])]) * ui_1[i]) ** 2
    #                     +   (dI1_dxi[1].subs([(G0, G0_num[i]), (G1, G1_num[i])]) * ui_1[i]) ** 2
    #                     ))
    #
#変更すること！
np.savetxt("err476.dat",u_I0,delimiter='\n')
#print(dI0_dxi)
#print(dI1_dxi)
print("error with 0-order")
print(u_I0)
# print("error with 1-order")
# print(u_I1)
# print(err)
# print(ui_0)
# print(ui_1)
# print(pow_mrr)