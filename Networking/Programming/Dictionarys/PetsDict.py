dog = {
    "Name" : "Minh",
    "Age" : "24",
    "Breed" : "Stray",
    "Owner" : "Minh's Mum"
}

dog2 = {
    "Name" : "Minh",
    "Age" : "24",
    "Breed" : "Stray",
    "Owner" : "Minh's Mum"
}

dog3 = {
    "Name" : "Minh",
    "Age" : "24",
    "Breed" : "Stray",
    "Owner" : "Minh's Mum"
}

pets = [dog,dog2,dog3]

for pet in pets:
    print(f"\nPet:")
    for i in pet:
        print(f"{i}, {pet[i]}")