for a in range(1, 10):
    for c in range(10,a,-1):
        print("  ",end="")
    for b in range(1, a+1):
        print(b, end=" ")
    for d in range(a-1,0,-1):
        print(d,end=" ")
    print("")
