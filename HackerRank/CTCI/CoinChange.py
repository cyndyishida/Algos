def make_change(coins, n):
    dp = [0 for i in range(n+1)]
    dp[0] = 1 # base case 
    for i in range(len(coins)):
        for j in range(coins[i], n+1):
            dp[j] += dp[ j - coins[i] ]
    return dp[-1]
            
            

n,m =(int(i) for i in input().strip().split())

print(make_change([int(coin) for coin in input().strip().split()], n))
