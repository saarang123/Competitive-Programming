import pickle

def fill():
    f = open('emp.dat', 'wb+')
    data = {}
    for _ in range(int(input('Enter number of entries: '))):
        empno = input('Enter employee number: ')
        data[empno] = []
        data[empno].append(input('Enter employee name: '))
        data[empno].append(int(input('Enter hourly wage rate: ')))
        data[empno].append(int(input('Hours worked per week: ')))
    print(data)
    pickle.dump(data, f)
    f.close()

def new_entry():
    f = open('emp.dat', 'wb+')
    data = pickle.load(f)
    empno = input('Enter employee number: ')
    data[empno] = []
    data[empno].append(input('Enter employee name: '))
    data[empno].append(int(input('Enter hourly wage rate: ')))
    data[empno].append(int(input('Hours worked per week: ')))
    f.seek(0, 0)
    pickle.dump(data, f)
    f.close()

def delete():
    x = input('Enter employee number to delete: ')
    f = open('emp.dat', 'wb+')
    data = pickle.load(f)
    del data[x]
    f.seek(0, 0)
    pickle.dump(data, f)
    f.close()

def modify():
    x = input('Enter employee number to modify: ')
    val = int(input('Enter new hourly wage rate: '))
    f = open('emp.dat', 'wb+')
    data = pickle.load(f)
    data[x][1] = val
    f.seek(0, 0)
    pickle.dump(data, f)
    f.close()

def calc(cost, hrs):
    regular = cost * hrs
    bonus = 30 * cost / 100 * max(0, hrs - 40)
    total = regular + wage
    return bonus, total

def displaywage():
    f = open('emp.dat', 'rb')
    f.seek(0, 0)
    data = pickle.load(f)
    for no in data:
        details = data[no]
        bonus, total = calc(details[1], details[2])
        print("Employee:", no, "has bonus and total wage of", bonus, total)
    f.close()

def table():
    f = open('emp.dat', 'rb')
    data = pickle.load(f)
    print('{:<10}{:<10}{:<10}{:<10}{:<10}{:<10}'.format("Emp no", "Name", "Wage Rate", "Hours", "Bonus", "Total Wage"))
    for no in data:
        details = data[no]
        bonus, total = calc(details[1], details[2])
        print('{:<10}{:<10}{:<10}{:<10}{:<10}{:<10}'.format(no, details[0], details[1], details[2], bonus, total))
    f.close()

menu = '''1.Enter the records of the file
2.Display wages of each employee
3.Display the file in a tabular format
4.Delete a record from the file
5.Modify a record of the file
6.Append a record to the file
0.exit'''
c = 100
while c > 0:
    print(menu)
    c = int(input('Enter choice: '))
    if c == 1: 
        fill()
    elif c == 2: 
        displaywage()
    elif c == 3: 
        table()
    elif c == 4: 
        delete()
    elif c == 5:
        modify()
    elif c == 6:
        new_entry()

