def main():
    with open("input.txt") as f:
        lines = f.read().splitlines()
        sum = 0
        for line in lines:
            #print(line)
            if(line.isalpha() or int(line) < 0):
                continue
            if(int(line) % 4 == 0 or int(line) % 7 == 0):
                continue
            sum += int(line)
        return f"cbrc_ctf{'{'}{sum}{'}'}"

print(main())