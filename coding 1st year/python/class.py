#q12 program to intercange first and last element
l2=[0,1,2,3,4,5,6,7,8,9]
a=l2[0]
b=l2[(len(l2)-1)]
l2.pop(0)
l2.pop(len(l2)-1)
l2.insert(0,b)
l2.insert(len(l2),a)
print(l2)