def solve
  dp = Array.new(201,0)
  mod = 1000000000

  input = gets.split.map(&:to_i)
  n = input[0]
  k = input[1]

  dp[0] = 1
  for i in 1..k
    for j in 1..n
      dp[j] += dp[j-1]
      dp[j] %= mod
    end
  end

  puts dp[n]

end

solve
