def main():
    with open("input.txt") as f:
        lines = f.read().splitlines()
        newLines = []
        for line in lines:
            line = line.upper()
            newLines.extend(line.split(" "))
        print(f"cbrc_CTF{'{'}{':'.join(newLines)}{'}'}")


main()