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

primes, is_prime = sieve(1000000)

def main() :
  upper_limit = 550
  ans = 1
  counts = dict()
  for i in range(len(primes) - upper_limit) :
    curr = 0
    for j in range(0, upper_limit) :
      curr += primes[i + j]
      if curr < len(is_prime) and is_prime[curr] :
        counts[j - i + 1] = curr
        ans = max(ans, j - i + 1)
  print(counts[ans])
  
main()