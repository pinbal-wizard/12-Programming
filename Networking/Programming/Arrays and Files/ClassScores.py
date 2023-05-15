
Lowest_Score = ["","",110]
Highest_score = ["","",0]

with open(r"ClassScores.txt", "r") as Scores:
    for i in Scores:
        i = i.split()
        i = [i[0],i[1],int(i[2])]
        if i[2] > Highest_score[2]:
            Highest_score = i
        if i[2] < Lowest_Score[2]:
            Lowest_Score = i
print(Highest_score)
print(Lowest_Score)

