n = 911000

def sum_of_squares(n):
    return (n * (n + 1) * (2 * n + 1)) // 6

def sum_of_odd_squares(n):
    x = sum_of_squares(n)
    y = sum_of_squares(n // 2)
    return x - y * 4

print(sum_of_odd_squares(n))