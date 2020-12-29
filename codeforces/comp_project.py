from matplotlib import pyplot as plt

name = input('Enter name: ')
monthly_prices = dict()
month = ['January', 'Febuary', 'March',
         'April', 'May', 'June', 'July',
         'August', 'September', 'October',
         'November', 'December']

print('Program to take monthly expenditures and analyize it')

def print_menu():
    print('1. Add a new entry.')
    print('2. Print the minimum and maximum amounts spent in the months till now: ')
    print('3. Plot a graph with month-price')
    print('-1 to exit')


option = 0
while(True):
    print_menu()
    option = int(input('Enter option: '))
    if(option == 1):
        new_entry = option_1()
        monthly_prices[month[new_entry[0]]] = new_entry[1]
    elif(option == 2):
        option_2()
    elif(option == 3):
        option_3()
