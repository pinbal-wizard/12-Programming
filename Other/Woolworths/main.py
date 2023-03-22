from bs4 import BeautifulSoup
import requests

import os
from datetime import date
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
import time
import openpyxl

fruit = 'https://www.woolworths.com.au/shop/browse/fruit-veg'
today = date.today()
#print(today)
#curl = f'curl "https://www.woolworths.com.au/shop/browse/fruit-veg" -H "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:102.0) Gecko/20100101 Firefox/102.0" -H "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8" -H "Accept-Language: en-US,en;q=0.5" -H "Accept-Encoding: gzip, deflate, br" -H "DNT: 1" -H "Connection: keep-alive" --output {today}.gz'
#os.system(curl)
#os.system(f"7z e {today}.gz")
#file = open(f"../shopscrape/{today}",'r')

#parsed = BeautifulSoup(file, 'html.parser')
Products = {"NULL","NULL"}

driver = webdriver.Firefox()
driver.get(fruit)
time.sleep(10)
"""
prices = driver.find_elements(By.CLASS_NAME,"product-tile-price")
for price in prices:
    pricesplit = price.text.split('\n')
    pricesplit[0] = pricesplit[0].replace("$","")
    price = pricesplit[0]

names = driver.find_elements(By.CLASS_NAME,"product-title-link")
for name in names:
    namesplit = name.text.split('\n')
    name = namesplit[0]
"""


print("hello?")
#button = driver.find_element(By.CLASS_NAME,"paging-next")
#button.click()

#time.sleep(10)
prices = driver.find_elements(By.CLASS_NAME,"product-tile-price")
for  i in range(len(prices)-1):
    pricesplit = prices[i].text.split('\n')
    pricesplit[0] = pricesplit[0].replace("$","")
    pricesplit[0] = pricesplit[0].replace("\n","")
    prices[i] = pricesplit[0]
    

names = driver.find_elements(By.CLASS_NAME,"product-title-link")
for i in range(len(names)-1):
    namesplit = names[i].text.split('\n')
    #namesplit[0] = namesplit[0].replace("\n","")
    names[i] = namesplit[0]
    

workbook = openpyxl.Workbook()
sheet = workbook.active
for i in range(len(names)-1):
    #print(names[i])
    try: 
        c1 = sheet.cell(row = 1, column = i+1)
        c1.value = names[i]
    except:
        c1.value = -1
    #print(prices[i])
    #print(type(prices[i]))
    
    try: 
        c2 = sheet.cell(row = 2, column = i+1)
        c2.value = prices[i]
    except:
        c2.value = -1
        
workbook.save(r'C:\Users\azzhu\Documents\programming\python\shopscrape\fruit.xlsx')