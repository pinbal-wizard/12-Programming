from bs4 import BeautifulSoup
import requests

import os
from datetime import date
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
import time
from openpyxl import load_workbook


def scrapePage(driver):
    products = {}
    productTiles = driver.find_elements(By.CLASS_NAME,"product-tile-v2")
    for product in productTiles:
        title = product.find_element(By.CLASS_NAME,"product-title-link").text
        try:
            price = product.find_element(By.CLASS_NAME,"product-tile-price")
            pricenumber = price.text.split('\n')[0].replace("$","")
        except:
            pricenumber = -1
        products[title] = pricenumber
        print(f"{title}: {pricenumber}")
    return products


def nextPage(driver):
    button = driver.find_element(By.CLASS_NAME,"paging-next")
    button.click()

    time.sleep(10)
    driver.execute_script("""
    var element = document.querySelector(".container-carousel");
    if (element)
        element.parentNode.removeChild(element);
    """)

URL = 'https://www.woolworths.com.au/shop/browse/fruit-veg'
start_date = date.fromisocalendar(2023, 12, 3)
today = date.today()
print((today - start_date).days + 2)

products = {}

driver = webdriver.Firefox()
driver.get(URL)

time.sleep(10)
driver.execute_script("""
var element = document.querySelector(".container-carousel");
if (element)
    element.parentNode.removeChild(element);
""")
try:
    exit = ''
    while exit != 'q': 
        products.update(scrapePage(driver))
        #nextPage(driver)
        exit = 'q'
    raise Exception("cum")
except:
    print("\n\n saving...")
    row = (today - start_date).days + 2
    workbook = load_workbook("fruit.xlsx")
    sheet = workbook.active

    """if(sheet.max_column < len(products)):
        sheet.insert_cols(len(products) - sheet.max_column)
        sheet.insert_rows(row)
    sheet.insert_cols(2,10)
    sheet.insert_rows(2,10)

    sheet.cell(row, column)
    sheet._cells_by_col(0, 0, len(products) + 1, row + 1)"""

    print(sheet.dimensions)

    for i in range(len(products)):
        for cell in sheet.iter_cols(min_col=2, max_col=len(products) + 1, max_row=1, min_row=1):
            print(cell[0].value)
            print(list(products.keys())[i])
            if cell[0].value == None:
                cell[0].value = list(products.keys())[i]
                break
    workbook.save(r'fruit.xlsx')
