import math

def pythagorean_triplets_with_side_less_than_n(n) :
  # using euclid's formula a = x ^ 2 - y ^ 2, b = 2xy, c = x ^ 2 + y ^ 2
  triplets = set()
  y = 1
  while True :
    x = y + 1
    a = x * x - y * y 
    b = x * y * 2
    c = x * x + y * y
    if c > n :
      break
    while c <= n :
      a = x * x - y * y 
      b = x * y * 2
      c = x * x + y * y
      k = 1
      while k * c <= n :
        triplets.add((min(k * a, k * b), max(k * a, k * b), k * c))
        k += 1
      x += 1
    y += 1
  return triplets

def main() :
  maxn = 1500000
  pythagorean_triplets = pythagorean_triplets_with_side_less_than_n(math.floor(maxn / 2))
  
  count = dict()
  for triplet in pythagorean_triplets :
    a, b, c = triplet
    if a + b + c <= maxn :
      count[a + b + c] = count.get(a + b + c, 0) + 1

  ans = 0
  for v in count.values() :
    if v == 1 :
      ans += 1
  print(ans)

main()
