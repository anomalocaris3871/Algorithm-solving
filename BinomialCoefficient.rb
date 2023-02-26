cache = Array.new(30) { Array.new(30, -1) }
n = gets.chomp.to_i
r = gets.chomp.to_i

def bino(n, r, cache)
  if (r == 0 or n == r)
    return 1
  end

  if (cache[n][r] != -1)
    return cache[n][r]
  end

  return cache[n][r] = bino(n-1, r-1, cache) + bino(n-1, r, cache)
end

puts bino(n,r,cache)
