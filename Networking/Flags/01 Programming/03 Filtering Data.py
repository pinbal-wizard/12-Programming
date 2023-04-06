def main():
    with open("input.txt") as f:
        lines = f.read().splitlines()
        sum = 0
        for line in lines:
            if(int(line) < 0):
                continue
            sum += int(line)
        return f"cbrc_CTF{'{'}sum:of:positive:numbers:is:{sum}{'}'}"

print(main())