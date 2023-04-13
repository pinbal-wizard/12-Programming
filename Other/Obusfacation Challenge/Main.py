import base64


#import requests
#requests.post("https://discord.com/api/webhooks/1095512305816571955/hSPjUmwPWrsOHX8nKhOjRlIRyQhRzsdPgad-JWUMMEnvech9cu08oJAOqLdbyQSh3I6z",
#              json={"content": "oops"})

with open("chal1.py", "r") as file:
    lines = file.readlines()
    slices = b""
    decodeStr = lines[-2]

    encodings = decodeStr.split('(Alpha("46esab"[::-1])')
    for i in range(len(encodings) -1 ):
        if (encodings[i])[0] != '.':
            encodings.remove(encodings[i])
        encodings[i] = encodings[i].split('(')[0]
        encodings[i] = encodings[i].replace(".", "")
    for line in lines[8:]:
        if line[0] == '_':
            slice = line.split(' += b')[1]
            slice = slice.replace("\\x", "").replace("\"","")
            sliceB = bytearray.fromhex(slice.strip()).decode()
            slices += sliceB.encode('latin1')
    theCode = slices
    stolenEncodings = {"a85decode":base64.a85decode, "b16decode":base64.b16decode , "b32decode":base64.b32decode , "b64decode":base64.b64decode, "b85decode":base64.b85decode}
    for enconding in encodings[::-1]:
        theCode = stolenEncodings[enconding](theCode)
    print(theCode)