n = int(input())
for i in range(1,n+1):
    s = str(n)
    cnt = 0
    while(len(s)!=1):
        temp = 1
        for i in s:
            temp *= int(i)
        s = str(temp)
        cnt+=1
    print(n," ",cnt)