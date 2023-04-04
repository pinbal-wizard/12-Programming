def main():
    with open("input.txt") as f:
        lines = f.read().splitlines()
        newLines = []
        for line in lines:
            line = line.lower()
            line = line[::-1]
            newLines.extend(line.split(" "))
        return (f"cbrc_CTF{'{'}{','.join(newLines)}{'}'}")


print(main())