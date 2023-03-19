with open("Networking\Flags\Sequences.txt", 'r') as sequences:
    for line in sequences:
        tag, hash = line.split(':')
        if(hash.__contains__("drere ")):
            print(f"cbrcCTF{'{'}{tag}{'}'}")

#cbrcCTF{genip}