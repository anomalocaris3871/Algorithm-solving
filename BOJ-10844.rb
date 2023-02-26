mod = 1000000000

dp = Array.new(101){Array.new(10,0)}

for i in 1..9
  dp[0][i] = 0
  dp[1][i] = 1
end

n = gets.chomp.to_i

for i in 2..n
  for j in 0..9
    dp[i][j] = 0
    if(j-1 >= 0)
      dp[i][j] += dp[i-1][j-1]
    end

    if(j+1 <= 9)
      dp[i][j] += dp[i-1][j+1]
    end

    dp[i][j] %= mod

  end
end

ans = 0
for i in 0..9
  ans += dp[n][i]
end
ans %= mod

puts ans


