t = int(input())
for _ in range(t):
    inf = 12345678910
    totalval,k,turner= list(map(int,input().split()))
    allvalues =  list(map(int,input().split()))
    if(turner == 1):
        if(k%2 == 1):
            print(min(allvalues))
        else:
            finaltotalanswer = inf
            for i in range(totalval):
                if i== 0:
                    finaltotalanswer = min(allvalues[i+1],finaltotalanswer)
                if(i == totalval-1):
                    finaltotalanswer = min(allvalues[i-1],finaltotalanswer)
                else:
                    finaltotalanswer = min(max(allvalues[i-1],allvalues[i+1]),finaltotalanswer)
            print(finaltotalanswer)
    else:
        if(k%2 == 1):
            print(max(allvalues))
        else:
          
            finaltotalanswer = -inf
            for i in range(totalval):
                if i== 0:
                    finaltotalanswer = max(allvalues[i+1],finaltotalanswer)
                if(i == totalval-1):
                    finaltotalanswer = max(allvalues[i-1],finaltotalanswer)
                else:
                    finaltotalanswer = max(min(allvalues[i-1],allvalues[i+1]),finaltotalanswer)
            print(finaltotalanswer)
