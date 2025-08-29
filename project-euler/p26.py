

def divide(a, b) :
  decimal_part = a // b
  a = (a % b) * 10
  fractional_part = ""
  rem_index = dict()
  rem_index[a] = len(fractional_part)
  while a > 0 :
    for i in range(9, -1, -1) :
      if a >= i * b :
        fractional_part += str(i)
        a -= b * i
        break
    a *= 10
    # print(fractional_part, end=" ")
    if rem_index.get(a, None) != None :
      fractional_part = fractional_part[0: rem_index[a]] + '(' + fractional_part[rem_index[a]:] + ')'
      break
    rem_index[a] = len(fractional_part)
    
  return f"{decimal_part}.{fractional_part}"

def main() :
  # print(divide(1, 2))
  # print(divide(10, 100))
  # print(divide(2, 3))
  # print(divide(6, 180))
  # print(divide(4, 11))
  rec_length = dict()
  for i in range(2, 1000) :
    result = divide(1, i)
    if '(' in result :
      rec_length[i] = len(result.split('(')[1].split(')')[0]) 
  longest = max(rec_length.values())
  for k, v in rec_length.items() :
    if v == longest :
      print(k)
      break

main()