


def main2():
    phrases=[]
    phrasesSort = []
    with open ("input.txt") as f:
        for line in f:
            line = line.strip()
            phrase = line.split(" ")
            #print(phrase)
            phrase[0] = phrase[0]
            phrase[1] = phrase[1]
            phrases.append(phrase)
    for item in phrases:
        phrasesSort.append(f"({item[1]},{item[0]})")
    output = "cbrc_CTF{"
    for i in range(len(phrasesSort)-1):
        output += f"{phrasesSort[i]}"
    output+=phrasesSort[-1]
    output+="}"
    print(output)


def main():
    with open("input.txt") as f:
        lines = f.read().splitlines()
        newLines = []
        for line in lines:
            a,b = line.split(" ")
            line =','.join([b.upper(),a.upper()])
            line = f"({line})"
            newLines.append(line)
        return("cbrc_CTF{" + ''.join(newLines) + "}")

print(main())
print()

"""
All Upper : : 
All Upper , : 
All Upper , ,
All Upper : ,
All Upper , ;

B Upper A Lower , :
A Upper B Lower , :

All Lower , :
All Lower , , 
All lower , ;

No case ' ' :
No case ''  : 
No case , , 
No case , ;
"""