# Find the sum of the event-valued Fibonacci terms that do not exceed four million

sum = 0
for i in range(1000):
  if (i % 3 == 0) or (i % 5 == 0):
    print(i)
    sum += i
print("Sum %d", sum)
