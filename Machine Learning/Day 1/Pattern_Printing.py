print("Enter the number")
n = 9

for i in range(0, n):
  for j in range(0, n - 1 - i):
    print(end=" ")
  for j in range(0, 2 * i + 1):
    print("*", end="")
  print()


for i in range(0, n):
  for j in range(0, ( i)):
    print(end=" ")
  for j in range(2 * (n - i) - 1):
    print("*", end="")
  print()
  
for i in range(0, n):
  for j in range(0, i + 1):
    if j % 2 == 0: print("1", end="")
    else: print("0", end="")
  print()