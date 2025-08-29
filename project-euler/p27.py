import math

def sieve(n) :
  is_prime = [1] * (n + 1)
  primes = []
  for i in range(2, math.floor(math.sqrt(n))) :
    if not is_prime[i] :
      continue
    for j in range(i * 2, n + 1, i) :
      is_prime[j] = 0
  for i in range(2, n + 1) :
    if is_prime[i] :
      primes.append(i)
  return primes, is_prime

primes, is_prime = sieve(100000)


def count_consecutives(a, b) :
  n = 0 
  while is_prime[n * n + n * a + b] :
    n += 1
  return n

def main() :
  ans = 1
  counts = dict()
  for b in range(-1000, 1000) :
    if not is_prime[abs(b)] :
      continue
    for a in range(-1000, 1000) :
      counts[(a, b)] = count_consecutives(a, b)
      ans = max(ans, counts[(a, b)])

  for k, v in counts.items() :
    if ans == v :
      print(k, v)
      print(k[0] * k[1])
      break


main()