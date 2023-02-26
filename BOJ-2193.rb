dp = Array.new(91){Array.new(2,0)}
dp[1][0] = 0
dp[1][1] = 1

n = gets.chomp.to_i

for i in 2..n
  dp[i][0] = dp[i-1][1] + dp[i-1][0]
  dp[i][1] = dp[i-1][0]
end

puts dp[n][0] + dp[n][1]





