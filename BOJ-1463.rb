n = gets.chomp.to_i

dp = Array.new(1000001)
dp[1] = 0

for i in 2..n
  dp[i] = dp[i-1] + 1
  if i%2 == 0 and dp[i] > dp[i/2] + 1
    dp[i] = dp[i/2] + 1
  end

  if i%3 == 0 and dp[i] > dp[i/3] + 1
    dp[i] = dp[i/3] + 1
  end
end

puts dp[n]
