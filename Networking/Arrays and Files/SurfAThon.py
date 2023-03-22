

highest_score = float(0)
lowest_score = float(11)
with open(r"report.txt", "r") as input:
    for i in input:
        if float(highest_score) <= float(i):
            highest_score = i
        elif float(lowest_score) >= float(i):
            lowest_score = i
print(f"Highest score: {highest_score} lowest score: {lowest_score}")