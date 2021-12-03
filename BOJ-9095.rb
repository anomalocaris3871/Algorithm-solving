n = gets.chomp.to_i

dp = Array.new(1001)
dp[0] = 1
dp[1] = 1
dp[2] = 2

while n > 0
  m = gets.chomp.to_i
  for i in 3..m
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
  end
  n = n - 1
  puts dp[m]
end

