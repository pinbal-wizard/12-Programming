def main():
    with open("input.txt") as f:
        lines = f.read().splitlines()
        newLines = []
        for line in lines:
            a,b = line.split(" ")
            line =','.join([b.upper(),a.upper()])
            line = f"({line})"
            newLines.append(line)
        return("cbrc_CTF{" + ':'.join(newLines) + "}")

print(main())


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