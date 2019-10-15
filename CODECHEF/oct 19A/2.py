t = int(input())
for _ in range(t):
    n,k = list(map(int,input().split()))
    arr = list(map(int,input().split()))
    brr = [[] for i in range(n)]
    
    for i in range(0,n//2):
        a = arr[i] 
        b = arr[n-i-1]
        x = a^b
        print(i,n-i-1)
        if(i!= n-i-1):
            brr[i].append(x)
            brr[i].append(b)
            brr[i].append(a)
            
            brr[n-i-1].append(a)
            brr[n-i-1].append(x)
            brr[n-i-1].append(b)
        else:
            brr[i].append(0)
            brr[i].append(0)
            brr[i].append(0)
    print(brr)
    for i in range(0,n):
        cnt = 0 
        q = k // n
        if(q>=1):
            cnt = (q-1)%3
        r = k%n
        print(cnt)
        if((r-1)>=i):
            cnt = (cnt+1)%3
            print(brr[i][cnt])
        else:
            print(brr[i][cnt])




# a = 2
# b = 2
# print(bin(a)[2:])
# print(bin(b)[2:] )
# for i in range(10):
#     print(a^b,end = " " )
#     print(bin(a^b)[2:],end = " " )
#     a = a^b
#     print(b^a,end = " ")
#     print(bin(a^b)[2:],end = " " )
#     b = b^a
    
#     print("")
    
    