import time
import statistics


#slow ass function
def findDoubleWord():
    with open(r"C:\Users\thomw\Documents\Programming\Networking\Learning Brief 2.1\wiki-10k.txt", "r") as text:
        words = text.read().splitlines()
        words.sort()
        for i in words:
            if(words.count(i) > 1):
                print(f"{i}")
                text.close()


#much much faster chad sigma male christion bale function
def findDoubleWord2():
    with open(r"C:\Users\thomw\Documents\Programming\Networking\Learning Brief 2.1\wiki-10k.txt", "r") as text:
        words = text.read().splitlines()
        words.sort()
        for i in range(0,len(words) - 1):
            if(words[i] == words[i+1]):
                print(f"{words[i]}")
                text.close()
                return


#cringe azhar function
def findDoubleWord3():
    with open(r"C:\Users\thomw\Documents\Programming\Networking\Learning Brief 2.1\wiki-10k.txt", "r") as text:
        words = text.read().splitlines()
        words.sort()
        wordsCached = []
        for i in range(len(words) - 1):
            if(words[i] not in wordsCached):
                wordsCached.append(words[i])
            else:
                print(f"{words[i]}")


def findAverageTime(func,num):
    times = []
    for i in range(1,num):
        start = time.time()
        func()
        end = time.time()
        times.append(end - start)
    print(f"Function takes avg of { statistics.fmean(times) } to complete {num} times")
    return statistics.fmean(times)


time1 = findAverageTime(findDoubleWord, 2)
time2 = findAverageTime(findDoubleWord2, 2000)
time3 = findAverageTime(findDoubleWord3, 2)

print(f"{time1} secs and {time2} secs and {time3} secs")