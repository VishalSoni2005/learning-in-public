x = range(6)
print(x)
print(list(x))
for i in x:
    print(i)
for i in range(6):
    print(i)
print(list(range(6)))
print(list(range(1, 6)))
print(list(range(1, 6, 2)))
print(list(range(6, 1, -1)))
print(list(range(6, 1, -2)))  

x = {1: "Vishal", 2: "Vishal2", 3: "Vishal3"}
print(x)
print(x[1])

x = b"Hello"
print(x)

x = bytearray(5)
print(x)
x = memoryview(bytes(5))
print(x)


i = 0
while i in range(6):
  print(i ** 2)
  i += 1
print("End of while loop")
for i in range(6):
    if i == 3:
        continue
    print(i ** 2)
    
    
fruit = ["Apple", "Banana", "Cherry", "Date"]
for i in fruit:
    if i == "Cherry":
        break
    print(i)

for i in "Hello World":
    if i == " ":
        continue
    print(i, end="")