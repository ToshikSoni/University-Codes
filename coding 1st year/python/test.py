#q10 program to split the array and add the first part to the end
list=[]
l2=[]
l3=[]
while True:
    inp=input("Enter elements(enter to stop entering):")
    if inp=="":
        break
    list.append(inp)
for i in list:
    c=int(i)
    l2.append(c)
for i in l2:
    