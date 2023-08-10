import numpy

gunCars = 100
philCars = 100
cityCars = 200

gunProb =  numpy.array([0.5,0.3,0.2])
philProb = numpy.array([0.2, 0.4, 0.4])
cityProb = numpy.array([0.1, 0.2, 0.7])

gens = 0

#while gunCars > 0 and philCars > 0 and cityCars > 0:
#for i in range(1,50000):
while True:
    
    for i in range(1,cityCars):
        if cityCars > 0:
            choice = numpy.random.choice(numpy.array(["G","P","C"]),p = cityProb)
            if choice == "G":
                cityCars -= 1
                gunCars += 1
            if choice == "P":
                cityCars -= 1
                philCars += 1
            if choice == "C":
                cityCars -= 1
                cityCars += 1


    for i in range(1,gunCars):
        if gunCars > 0:
            choice = numpy.random.choice(numpy.array(["G","P","C"]),p = gunProb)
            if choice == "G":
                gunCars -= 1
                gunCars += 1
            if choice == "P":
                gunCars -= 1
                philCars += 1
            if choice == "C":
                gunCars -= 1
                cityCars += 1

    for i in range(1,philCars):
        if philCars > 0:
            choice = numpy.random.choice(numpy.array(["G","P","C"]),p = philProb)
            if choice == "G":
                philCars -= 1
                gunCars += 1
            if choice == "P":
                philCars -= 1
                philCars += 1
            if choice == "C":
                philCars -= 1
                cityCars += 1

    for i in range(1,cityCars):
        if cityCars > 0:
            choice = numpy.random.choice(numpy.array(["G","P","C"]),p = cityProb)
            if choice == "G":
                cityCars -= 1
                gunCars += 1
            if choice == "P":
                cityCars -= 1
                philCars += 1
            if choice == "C":
                cityCars -= 1
                cityCars += 1
    gens+=1

    if (gens % 10) == 0:
        print(f"simulated for {gens} generations \n gunCars {gunCars} \n philcars {philCars} \n citycars {cityCars}")
