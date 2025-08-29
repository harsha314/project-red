import math

a = 1
b = 1
digits = 1
itr = 3

while digits < 1000 :
  c = a + b
  digits = math.ceil(math.log10(c))
  if math.ceil(math.log10(b)) != digits :
    print(f"itr : {itr}, digits: {digits}")
  a = b
  b = c
  itr += 1 