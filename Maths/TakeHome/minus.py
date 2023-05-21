def minus(filepath, amount):
    with open(filepath, "r+") as file:
        data = file.readlines()
        print(data)
        newNumbs = [float(num.strip()) - amount for num in data]
        print(newNumbs)
        with open(filepath + "new", "w") as newfile:
            for num in newNumbs:
                newfile.write(str(num) + "\n")
    

minus(r"sec3",-7.85)