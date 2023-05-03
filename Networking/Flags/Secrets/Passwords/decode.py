def encrypt(text,s):
    result = ""
   # transverse the plain text
    for i in range(len(text)):
      char = text[i]
      # Encrypt uppercase characters in plain text
      
      if (char.isupper()):
         result += chr((ord(char) + s-65) % 26 + 65)
      # Encrypt lowercase characters in plain text
      else:
         result += chr((ord(char) + s - 97) % 26 + 97)
      return result
    
def tryDecrpt():
   encrpyted = "SIWWGCAIMOQKSAKGOQMIECYEWIU" 
   i = 6
   print(encrpyted)
   for letter in encrpyted:
      print(encrypt(letter,i),end="")
      
#6 shift 


tryDecrpt()