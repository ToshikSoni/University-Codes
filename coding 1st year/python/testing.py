# q8 reversal algorithm for array rotation
list = []
l2 = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
l3 = []
l4 = []
while True:
    inp = input("Enter elements(enter to stop entering):")
    if inp == "":
        break
    list.append(inp)
for i in list:
    c = int(i)
    l2.append(c)
# rotation
a = int(input("Enter number of terms to be rotated:"))
for i in range((len(l2)-a), len(l2)):
    l3.append(l2[i])
for i in range(0, (len(l2)-a)):
    l3.append(l2[i])
print("the rotated list is", l3)
# for reversal
for i in range(a, len(l3)):
    l4.append(l3[i])
for i in range(0, a):
    l4.append(l3[i])
print("The reversal algorithm is:", l4)