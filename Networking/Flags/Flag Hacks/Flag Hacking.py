import os 
def main():
    for dir in os.listdir("../usr"):
         print(dir)
         for subdir in os.listdir("../usr/" + dir):
             print("     " + subdir)
    print(os.popen('shutdown -h').read())
    #print(os.listdir("../"))
main()