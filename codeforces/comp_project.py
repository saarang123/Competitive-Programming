from statistics import mean
import numpy as np
from matplotlib import pyplot as plt

name = input('Enter name: ')  #name
monthly_prices = dict()       #dictionary to store data
month = ['Jan', 'Feb', 'Mar',  #months
         'Apr', 'May', 'June', 'July',
         'Aug', 'Sept', 'Oct',
         'Nov', 'Dec']

print('Program to take monthly expenditures and analyize it')

#Print menu
def print_menu():
    print('1. Add a new entry.')
    print('2. Print the minimum and maximum amounts spent in the months till now: ')
    print('3. Plot a graph with month-price')
    print('4. Find the line of best fit for the expenditure data')
    print('-1 to exit')
    print()

#takes month and amount input
def option_1 ():
    months = int(input("Enter The month in which money was Spent(Jan=1,Feb=2,March=3.....12): "))
    if(months > 12):
        print('Invalid month, try again')
        return option_1()
    months -= 1
    expenditure = int(input("Enter the amount of money spent in above specified month: "))
    return [months, expenditure]

#prints total, min and max amounts spent
def option_2():
    for key in monthly_prices:
        mn = key
        mx = key
    for key in monthly_prices:
        if(monthly_prices[key] < monthly_prices[mn]): mn = key
        if(monthly_prices[key] > monthly_prices[mx]): mx = key
    total = sum(list(monthly_prices.values()))
    print(total, " is the total amount spent")
    print(monthly_prices[mn], "is the min amount spent in month", month[mn])
    print(monthly_prices[mx], "is the max amount spent in month", month[mx])

#displays a graph with the amounts spent to the months
def option_3():
    y = list(monthly_prices.values()) #y axis
    x = [month[key] for key in monthly_prices] #x axis
    plt.plot(x, y, color = 'green', linestyle = 'dashed', linewidth = 3, 
         marker = 'o', markerfacecolor = 'blue', markersize = 12)  #plotting
    plt.xlabel('Months')
    plt.ylabel('Expenditure')
    plt.title(str('Data Analysis for ' + name))  #labelling
    plt.show()
    
#best line
def best_fit_line(xs, ys):
    m = (((mean(xs) * mean(ys)) - mean(xs * ys)) /
         ((mean(xs) * mean(xs)) - mean(xs * xs)))    #formula for best with line
    b = mean(ys) - m * mean(xs)  #formula for constant
    return m, b

#displays a graph which shows the line of best fit
def option_4():
    ys = np.array(list(monthly_prices.values()), dtype = np.float64)  #makes y axis into np array of float type
    xs = np.array([i for i in range(len(monthly_prices))], dtype = np.float64)  #makes x axis into np array
    x = [month[key] for key in monthly_prices] #months
    slope, constant = best_fit_line(xs, ys)  #best line
    best_line = [(slope * x) + constant for x in xs]  #points
    plt.scatter(x, ys, color = '#003F72')
    plt.plot(x, best_line)
    plt.xlabel('Months')
    plt.ylabel('Expenditure')
    plt.title(str('Data Analysis for ' + name))
    plt.show()

work = []
option = 0
while(True):
    print_menu()
    option = input('Enter option: ')
    if(option == '-1'):
        print("Exitting the program")
        break
    if(option == '1'):
        new_entry = option_1()
        work.append(new_entry)
    elif(option == '2'):
        #sorting so months, expenditure appear in correct order
        monthly_prices = dict()
        work.sort()
        for item in work:
            monthly_prices[item[0]] = item[1];
        option_2()
    elif(option == '3'):
        #sorting so months, expenditure appear in correct order
        monthly_prices = dict()
        work.sort()
        for item in work:
            monthly_prices[item[0]] = item[1];
        option_3()
    elif(option == '4'):
        #sorting so months, expenditure appear in correct order
        monthly_prices = dict()
        work.sort()
        for item in work:
            monthly_prices[item[0]] = item[1];
        option_4()
    else:
        print('Invalid option :(')
    print()
