def rule(filepath):
    with open(filepath, "r") as data:
        numbers = data.readlines()

        h = 1
        total = 0
        nextCoefficient = 4

        if len(numbers) % 2 == 0:
            print(f"wrong number points")
            return 0 
        total += float(numbers[0])
        for point in numbers[1:-1]:
            total +=  nextCoefficient * abs(float(point))
            nextCoefficient = (4,2)[nextCoefficient == 4]
        total += float(numbers[-1])
        print(f"Area of {filepath} is: " + str(round((total / 3 * h)*10000,0)) + "m^2")
        return (total / 3 * h)
        
total = 0
total += rule(r"sec1")
total -= rule(r"sec1neg")
total += rule(r"sec1.5")
total += rule(r"sec2new")
total += rule(r"sec3new")
total += rule(r"sec4")
total += rule(r"sec5new")

total *= 10000

print("Total Area of woden valley: " + str(round(total,2)) + "m^2")

print("Calculated area has an error of " + str(round(((total / 2.78e+7)*100)-100,2)) + r"%")