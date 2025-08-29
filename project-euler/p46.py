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
  return primes

def main() :
  n = int(1e6) + 6
  primes = sieve(n)
  print(primes[len(primes)-1])
  st = 5
  itr = 3
  while True:
    found = True
    for j in range(1, itr) :
      num = (st - primes[j]) / 2
      # print(num)
      sqrt_num = int(math.sqrt(num))
      if sqrt_num * sqrt_num == num :
        found = False
        # print(f"{st} = {primes[j]} + 2 * {sqrt_num} * {sqrt_num}")
        break
    if found :
      print(st)
      break
    st += 2
    while st >= primes[itr] :
      itr += 1

main()