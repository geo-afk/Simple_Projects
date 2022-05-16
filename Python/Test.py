# created by Elias Kamakas, reworked by Lothar
from datetime import datetime

def compare(num1,num2):
    max_ = max(num1,num2)
    min_ = min(num1,num2)
    if min_ == max_:
        print('The numbers are equal')
    else:
        print(f'min number is {min_}')
        print(f'max number is {max_}')
    return min_, max_
   
def file(num1, num2):
    with open("test1file.txt", "w+") as f:
        f.write(f'The maximum was {num1} and the minimum wa {num2} on {datetime.now()}')

ans1 = int(input("Enter the first number: "))
ans2 = int(input("Enter the second number: "))
res1, res2 = compare(ans1,ans2)
file(res1, res2)

