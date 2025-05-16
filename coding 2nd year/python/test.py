n=int(input())
a=[]
for i in range(n):
  x=input().split(",")
  xp=[]
  for j in x:
    xp.append(int(j))   
  a.append(xp)
print(a)
b=[]
for i in range(n):
  x=input().split(",")
  xp=[]
  for j in x:
    xp.append(int(j))
  b.append(xp)
print(b)
c=[[0]*n]*n
print(c)
for i in range(n):
  for j in range(n):
      c[i][j]=a[i][j]+b[i][j]
print("Output: \n",c)