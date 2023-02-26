def solve

  dp = Array.new(1001,0)
  seq = Array.new(1001,0)

  n = gets.chomp.to_i
  seq = gets.split.map(&:to_i)

  for i in 0...n
    dp[i] = 1
    for j in 0...i
      if(seq[j] < seq[i] and dp[i] < dp[j] + 1)
        dp[i] = dp[j] + 1
      end
    end
  end

  ans = 0
  for i in 0...n
    ans = ans > dp[i] ? ans : dp[i]
  end

  puts ans

end

solve
