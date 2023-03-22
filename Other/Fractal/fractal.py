#csv and math are both inbuild libs
import csv
import math

def modulus(x, y): 
  x -= 128 #offset
  x /= 512 #scale
  y -= 128
  y /= 512  #number offsets so loop goes from 0 to 256
  j = 1
  z = complex(x, y)
  z1 = complex(-0.162 , 1.04) #fractal seed
  while abs(z) <= 2: #loop until real z is larger than 2
    if j > 97: #unless number of iters is greater than 97
      return 00
    z = (z * z) + z1
    j = j + 1
  return j

def modulusAtIter(x, y):
  x -= 128
  x /= 512
  y -= 128
  y /= 512
  j = 1
  z = complex(x, y)
  z1 = complex(-0.162 , 1.04)
  ans = []
  while math.isinf(abs(z)) == False: #check if real z is inf
    if j > 50:  #or 50 iters have passed
      return ans
    z = (z * z) + z1
    try:  #python will crash if you try to take the real part of an infinite number
       math.isinf(abs(z))
    except:
       z = math.inf
    ans.append(format(abs(z), '.4e') ) #round to 4 decimal places of scientific notation
    j = j + 1
  return ans


table  = [[0 for x in range(256)] for y in range(256)] #make a table to hold the values
with open (r"table.csv",'w',newline='') as txt:
    writer = csv.writer(txt)
    for i in range(0, 256):
        for j in range(0, 256):
            table[i][j] = modulus(float(j), float(i))  #populate table
            print(modulus(float(j), float(i)), end=" ")
        print("")
    writer.writerows(table) #write values from temp table to file


with open("Table.txt", "w") as table:
    for i in range(0, 256):
        for j in range(0, 256):
            print( modulusAtIter(i,j) )
            table.write(f"{(i-128)/512}, {(j-128)/512} = { modulusAtIter(i,j)} \n") #populate another file with all values and iterations
