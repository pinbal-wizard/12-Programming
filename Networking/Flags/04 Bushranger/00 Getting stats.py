from statistics import mean, median, mode

with open("alice.txt", 'r') as alice:
    words = []
    numLines = 0
    wordsPerLine = []
    for line in alice.read().splitlines():
        lineWords = line.split()
        for word in lineWords:
            if word == "":
                lineWords.remove(word)
        if lineWords == []:
            continue
        words.extend(lineWords)
        if(lineWords.__len__() > 0):
            print(lineWords)
            wordsPerLine.append(lineWords.__len__())
        numLines+=1    
    for word in words:
        if word.isalnum():
            continue
        print(word)
    print(f"cbrc_CTF{'{'}{words.__len__()}:{numLines}:{mean(wordsPerLine)}:{median(wordsPerLine)}:{mode(wordsPerLine)}:{mode(words).upper()}{'}'}")
