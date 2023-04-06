def main():
    with open("input.txt") as f:
        lines = f.read().splitlines()
        flags = {}
        for line in lines:
            keyword, flag = line.split(":")
        #print(keyword + " : " + flag)
            if keyword in flags:
                print(flag)
            flags[keyword] = flag
main()