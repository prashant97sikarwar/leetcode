def lengthOfSuperSubsequence(n,m,first,sec):
    dp = [[0 for i in range(m+1)] for j in range(n+1)]
    for i in range(n+1):
        for j in range(m+1):
            if i == 0 or j == 0:
                dp[i][j] = 0
            elif first[i-1] == sec[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    dep = dp[n][m]
    return (n + m - dep)

t = int(input())
while t > 0:
    n = int(input())
    m = int(input())
    first = input()
    sec = input()
    print(lengthOfSuperSubsequence(n,m,first,sec))
    t -= 1