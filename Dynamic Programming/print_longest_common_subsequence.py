def answer(n,m,arr,brr):
    dp = [[0 for i in range(m+1)] for i in range(n+1)]
    for i in range(n+1):
        for j in range(m+1):
            if  i == 0 or j == 0:
                dp[i][j] = 0
            elif arr[i-1] == brr[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    i = n
    j = m
    l = []
    while i > 0 and j > 0:
        if arr[i-1] == brr[j-1]:
            l.append(arr[i-1])
            i -= 1
            j -= 1
        else:
            if dp[i][j-1] > dp[i-1][j]:
                j -= 1
            else:
                i -= 1
    for i in range(len(l)-1,-1,-1):
        print(l[i],end=' ')
    


n,m = map(int,input().split())
arr = list(map(int,input().split()))
brr = list(map(int,input().split()))
answer(n,m,arr,brr)
print()
