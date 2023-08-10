import numpy

gunCars = 10000
philCars = 10000
cityCars = 20000

gunProb =  numpy.array([0.5,0.3,0.2])
philProb = numpy.array([0.2, 0.4, 0.4])
cityProb = numpy.array([0.1, 0.2, 0.7])

gens = 0

#while gunCars > 0 and philCars > 0 and cityCars > 0:
#for i in range(1,50000):
while True:
    carsForGun = 0
    carsForCity = 0
    carsForPhil = 0    

    carsForGun += int(gunCars * gunProb[0])
    carsForPhil += int(gunCars * gunProb[1])
    carsForCity += int(gunCars * gunProb[2])

    carsForGun += int(philCars * philProb[0])
    carsForPhil += int(philCars * philProb[1])
    carsForCity += int(philCars * philProb[2])

    carsForGun += int(cityCars * cityProb[0])
    carsForPhil += int(cityCars * cityProb[1])
    carsForCity += int(cityCars * cityProb[2])

    gunCars = carsForGun
    philCars = carsForPhil
    cityCars = carsForCity

    gens+=1

    if (gens % 1000) == 0:
        print(f"simulated for {gens} generations \n gunCars {gunCars} \n philcars {philCars} \n citycars {cityCars}")
