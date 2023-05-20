def rule(filepath):
    with open(filepath, "r") as data:
        numbers = data.readlines()

        h = 1
        total = 0
        nextCoefficint = 4

        #print(f"there are {len(numbers)} points")
        #print(f"with spacing of {h} between i.e step size")

        if len(numbers) % 2 == 0:
            print(f"wrong number points")
            return 0 
        total += float(numbers[0])
        #print(f"first number is {numbers[0]}")
        for point in numbers[1:-1]:
            total +=  nextCoefficint * float(point)
            #print(f"adding {nextCoefficint}*{point}",end="")
            nextCoefficint = (4,2)[nextCoefficint == 4]
        #print(f"last number is {numbers[-1]}")
        total += float(numbers[-1])
        print(round(total / 3 * h,2))
        return (total / 3 * h)
        
toatal = 0
toatal += rule(r"sec1")
toatal += rule(r"sec2new")
toatal += rule(r"sec3new")
toatal += rule(r"sec4")
toatal += rule(r"sec5new")

toatal *= 10000

print(str(round(toatal,2)) + "m^2")

print(str(round((toatal / 2.78e+7)*100-100,2)) + r"% error")