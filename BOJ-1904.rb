MOD = 15746
dp = Array.new(1000001,0)

n = gets.chomp.to_i

dp[0] = 0
dp[1] = 1
dp[2] = 2

for i in 3..n
  dp[i] = dp[i-1] % MOD + dp[i-2] % MOD
end

puts dp[n] % MOD

