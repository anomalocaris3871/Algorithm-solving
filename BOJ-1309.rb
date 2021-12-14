def solve
  mod = 9901
  max = 100001

  dp = Array.new(max, 0)
  cases = Array.new(max,0)

  dp[0] = 1
  cases[0] = 1

  dp[1] = 2
  cases[1] = dp[0] + dp[1]

  n = gets.chomp.to_i

  for i in 2..n
    dp[i] = 2*cases[i-2] + dp[i-1]
    cases[i] = dp[i] + cases[i-1]

    dp[i] %= mod
    cases[i] %= mod


  end

  puts cases[n]

end

solve
