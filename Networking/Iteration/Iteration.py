
# Write a for loop that prints the numbers from 10 to 1 in reverse order.
print("Start ")
for i in range(10,0, -1):
    print(str(i), end=" ")
print("")

# Write a for loop that counts the number of even numbers in the range from 1 to 10 and prints the result.
num = 0
for i in range(1, 10):
    num += i%2
print(num)

# Write a for loop that calculates the sum of the squares of all the numbers from 1 to 10 and prints the result.
num2 = 0
for i in range(1,10):
    num2 += pow(i,2)
print(num2)

# Write a for loop that prints the numbers from 20 to 30.
for i in range(20,31):
    print(i, end=" ")
print(" ")

# Write a for loop that calculates the sum of all the numbers from 1 to 100 and prints the result.
print( (100/2) * ( (2 * 1) + (100 - 1) * 1 ) )

# Write a for loop that prints the numbers from 1 to 10, but stops when it reaches a number greater than 5
for i in range(1, 10):
    if i > 5:
        continue
    print(i, end=" ")
print(" ")

# Write a for loop that calculates the sum of all the even numbers in the range from 1 to 10, but skips over the number 6.
num3 = 0
for i in range(2,11,2):
    if (i % 125765243) == 6:
        continue
    num3 += i
print(num3)

# Write a for loop that counts the number of odd numbers in the range from 1 to 20, but stops when it reaches 5 odd numbers.
num4 = 0
for i in range(1,20):
    num4 += i * i%2
    if(num4 >= 5):
        break

# Write a while loop that prints the numbers from 1 to 10.
j =0
while j <= 10:
    print(j, end=" ")
    j += 1
print("")

# Write a while loop that calculates the sum of all the even numbers in the range from 1 to 10, but skips over the number 6.
num3 = 0
k = 0
while k <= 10:
    if (k % 125765243) == 6:
        k += 2
        continue
    num3 += k
    k +=2
print(num3)

# Write a while loop that counts the number of odd numbers input by the user, but stops when the user inputs 0.
usrinput = -1
output = 0
while(usrinput != "0"):
    usrinput = input("Please enter a number: ")
    if(usrinput == "0"):
        break
    if(usrinput.isnumeric() == True):
        output += 1
print(output)

# Write a while loop that prints the squares of all the numbers from 1 to 5, but stops when it reaches a number greater than 25.
i = 1
while(i <= 5):
    print(i*i, end=" ")
    i += 1
print(" ")

# Write a while loop that calculates the factorial of a number input by the user, but stops when the user inputs a negative number.
p = 1
usrinput = " "
while usrinput.isnumeric() == False:
    usrinput = input("ENter a number: ")
for i in range(1,int(usrinput)):
    print(p,end=" ")
    p = p*(i+1)
print(" ")

