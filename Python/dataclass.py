from dataclasses import dataclass, field



@dataclass
class Details:
    Name: str
    Age: int
    Title: str
    
# name = input("Enter Your Name: ")
# age = int(input("Enter Your Age: "))
# title = input("Enter title . : ")


@dataclass(order = True)
class Investor:
    sort_index: float = field(init = False, repr = False)
    nami: str
    age: int
    cash: float = field(repr=True)
    
    def __post_init__(self):
        self.sort_index = self.cash

i1 = Investor("John", 80, 700)
i2 = Investor("Ben", 40, 1400)
i3 = Investor("John", 80, 700)
i4 = Investor("Tom", 24, 9830)
i5 = Investor("Temmy", 34, 2300)


# list = [i1,i2,i3,i4,i5]
# list.sort()
# print(list)

print(i1.nami)

# @dataclass
# class School:
#     school:str
#     Name: str
#     ID_Num: int
#     age: int
#     Gender: str
#     Club: str
#     Sport_Event: str
#     totalTime: int
 
