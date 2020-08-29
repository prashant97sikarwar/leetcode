def answer(n,m,str1,str2):
    dp = [[0 for i in range(m+1)] for i in range(n+1)]
    for i in range(n+1):
        for j in range(m+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif str1[i-1] == str2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    x = dp[n][m]
    return (n - x + m - x)


t = int(input())
while t > 0:
    n,m = map(int,input().split())
    str1, str2 = map(str,input().split())
    print(answer(n,m,str1,str2))
    t -= 1