import requests
import json

url = 'https://cbrc.ctfd.io/api/v1/challenges/attempt'


json = {
    "challenge_id":35,
    "submission":"Hi adam"}

headers = {
'Host': 'cbrc.ctfd.io',
'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:109.0) Gecko/20100101 Firefox/111.0',
'Accept': 'application/json',
'Accept-Language': 'en-GB,en;q=0.5',
'Accept-Encoding': 'gzip, deflate, br',
'Referer': 'https://cbrc.ctfd.io/challenges',
'Content-Type': 'application/json',
'CSRF-Token': 'fb774a26b48749e96c28d00993f5dde0a4fba8a3a42123c4c5d2f3874c5922a5',
'Content-Length': '289',
'Origin': 'https://cbrc.ctfd.io',
'Connection': 'keep-alive',
'Cookie': 'session=b6fefb13-2613-4f7e-bdad-4a869f3a28d7.cUFjW7AaA6dyRqQJ8gFqWvvGajg',
'Sec-Fetch-Dest': 'empty',
'Sec-Fetch-Mode': 'cors',
'Sec-Fetch-Site': 'same-origin'
}

for i in range(1,1000):
    r = requests.post(url=url,json=json,headers=headers)
    print(r.text)


