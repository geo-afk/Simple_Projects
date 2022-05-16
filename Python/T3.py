from dataclasses import dataclass
import datetime

while True:
    def get_student_details():  
        Students = [] 
        school = input("Which school Student attend: ")
        Name = input("Input student's Full-Name: ")
        if Name in Students:
            for info in zip(Students):
                print(f"School: {info['school']}\nName: {info['Name']}\nID Number: {info['ID_Num']}\nD.O.B {info['DOB']}\nGender: {info['Gender']}\nClub: {info['Club']}\nEvent: {info['Sport_Event']}\nTotal Time for {info['Name']} is {info['total_time']} Minutes\n With Swim Time of {info['Swim_Time']},Running Time of {info['Running_Time']} and Cycling Time of {info['Cycling_Time']}\n")   
                
        ID_Num = int(input("Enter Student's ID Number: "))
        print("\n----Must be 2007 or Higher BUT Less Than 2016----")
        b_year = int(input("Enter Your Birth Year: "))
        b_month = input("Enter Your Birth Month: ")
        b_day = int(input("Enter Day Of Year: "))
        DOB = f'{b_month} {b_day}, { b_year}'
        age = datetime.datetime.now().year - b_year
        
        gender = input("Enter M for Male and F for female: ")
        while gender.upper() != 'M' and gender.upper() != 'F':
            gender = input("\nINVALID INPUT\nEnter M for Male and F for female: ")
        if gender.upper() == 'M':
            gender = "Male"
        elif gender.upper() == 'F':
            gender = "Female"

        if age >= 6 and age <= 8:
            club = "Kids of steel"
        elif age >= 9 and age <= 11:
            club = "Iron Kids"
        elif age >=12 and age <= 15:
            club = "Cast Iron Kids"

        print("\t--Event Types---\n\tC. Cycling\n\tR.Running\n\tS.Swimming")
        Sport_Event = input("Enter your event of choice: ")
        while Sport_Event.upper() != 'C' and Sport_Event.upper() != 'S' and Sport_Event.upper() != 'R':
            Sport_Event = input("\nINVALID INPUT\nEnter your event of choice: ")
        if Sport_Event.upper() == 'C':
            Sport_Event = "Cycling"
        elif Sport_Event.upper() == 'S':
            Sport_Event = "Swimming"
        elif Sport_Event.upper() == 'R':
            Sport_Event = "Running"
        print("\nEnter Time In __Minuites__")
        swim_time = int(input("Swim Time: "))
        t1 = int(input("First Transition: "))
        cycling_time = int(input("Cycling Time: "))
        t2 = int(input("First Transition: "))
        running_time = int(input("Running Time: "))
        total_time = swim_time + t1 + cycling_time  + t2 + running_time

        eventData = {
            "school": school,
            "Name": Name,
            "ID_Num": ID_Num,
            "DOB": DOB,
            "Gender": gender,
            "Club": club,
            "Sport_Event": Sport_Event,
            "Total_Time": total_time,
            "Swim_Time": swim_time,
            "Running_Time": running_time,
            "Cycling_Time": cycling_time
        } 
        Students.append(eventData)
        return Students
        
    def Saved_Data(Students):
        file = 'triathlete_details.txt'
        with open(file,'a') as athlete_details:
            for info in Students:
                athlete_details.writelines(f"School: {info['school']}\nName: {info['Name']}\nID Number: {info['ID_Num']}\nD.O.B {info['DOB']}\nGender: {info['Gender']}\nClub: {info['Club']}\nEvent: {info['Sport_Event']}\nTotal Time for {info['Name']} is {info['Total_Time']} Minutes\nA Swim Time of {info['Swim_Time'] } Minutes,Running Time of {info['Running_Time']} Minutes and Cycling Time of {info['Cycling_Time']} Minutes\n")

    def Print_Data(Students):
        for info in Students:
            print("\nSchool :->\t", info["school"])
            print("Name :->\t", info["Name"])
            print("ID Number :->\t", info["ID_Num"])
            print("Gender :->\t",info['Gender'])
            print("D.O.B :->\t", info['DOB'])
            print("Club :->\t",info['Club'])
            print("Event :->\t", info['Sport_Event'])
            print("Total Time :->\t", info['Total_Time'])
            print("Swim Time :->\t", info['Swim_Time'])
            print("Running Time :->",info['Running_Time'])
            print("Cycling Time :->",info['Cycling_Time']) 
        
        for info in Students:
            gender = info['Gender']
            swim_time = info['Swim_Time']
            cycling_time = info['Cycling_Time']
            total_time = info['Total_Time']
            running_time = info['Running_Time']
            
            
            
        if gender == "Male":
            if swim_time <= 15 and swim_time <= 30: 
                print(f"\nCome First for Swimming with a time of: {swim_time}")
            elif swim_time <= 30 and swim_time <= 45:
                print(f"\nnCome Second for Swimming with a time of: {swim_time}")
            elif swim_time <= 45 and swim_time <= 60:
                print(f"\nCome Third for Swimming with a time of: {swim_time}")
            elif swim_time > 60:
                print(f"\nYou Lost Swim Event with a time of: {swim_time}") 
                    
            if cycling_time <= 30 and cycling_time <= 60:
                print(f"Come First for Cycling with a time of: {cycling_time}")
            elif cycling_time <= 60 and cycling_time <= 130:
                print(f"Come Second for Cycling with a time of: {cycling_time}")
            elif cycling_time <= 130 and cycling_time <= 160:
                print(f"Come Third for Cycling with a time of: {cycling_time}")
            elif cycling_time > 160:
                print(f"You Lost Cycling Event with a time of: {cycling_time}")  
                
            if running_time <= 20 and running_time <= 40:
                print(f"Come First for Running with a time of: {running_time}")
            elif running_time <= 40 and running_time <= 60:
                print(f"Come Second for Running with a time of: {running_time}")
            elif running_time <= 60 and running_time <= 80:
                print(f"Come Third for Running with a time of: {running_time}")
            elif running_time > 80:
                print(f"You Lost Swim Event with a time of: {running_time}")   
                
            if total_time <=65 and total_time <=130:
                print(f"With A time of {total_time}.You Have won the Event at First Place\n") 
            elif total_time <=130 and total_time <=235:
                print(f"With A time of {total_time}.You Have won the Event at Second Place\n")    
            elif total_time <=235 and  total_time<=345:
                print(f"With A time of {total_time}.You Have won the Event at Third Place\n")  
            else:
                print(f"With A time of {total_time}.You Came in Fourth or Below Place.\n")
            
        if gender == "Female":
            if swim_time <= 20 and swim_time <= 35:
                print(f"\nCame First for Swimming with a time of {swim_time}")
            elif swim_time <= 35 and swim_time <= 50:
                print(f"\nCame Second for Swimming with a time of {swim_time}")
            elif swim_time <= 50 and swim_time <= 65:
                print(f"\nCame Third for Swimming with a time of {swim_time}")
            elif swim_time > 65:
                print(f"\nYou Lost Swim Event with a time of {swim_time}") 
                    
            if cycling_time <= 35 and cycling_time <= 65:
                print(f"Came First for Cycling with a time of {cycling_time}")
            elif cycling_time <= 65 and cycling_time <= 125:
                print(f"Came Second for Cycling with a time of {cycling_time}")
            elif cycling_time <= 125 and cycling_time <= 145:
                print(f"Came Third for Cycling with a time of {cycling_time}")
            elif cycling_time > 145:
                print(f"You Lost Cycling Event with a time of {cycling_time}")  
                
            if running_time <= 25 and running_time <= 45:
                print(f"Came First for Running with a time of {running_time}")
            elif running_time <= 45 and running_time <= 85:
                print(f"Came Second for Running with a time of {running_time}")
            elif running_time <= 85 and running_time <= 105:
                print(f"Came Third for Running with a time of {running_time}")
            elif running_time > 105:
                print(f"You Lost Swim Event with a time of {running_time}")   
                
            if total_time <=80 and total_time <=145:
                print(f"With A time of {total_time}.You Have won the Event at First Place\n") 
            elif total_time <=145 and total_time <=260:
                print(f"With A time of {total_time}.You Have won the Event at Second Place\n")    
            elif total_time <=260 and  total_time<=315:
                print(f"With A time of {total_time}.You Have won the Event at Third Place\n")  
            else:
                print(f"With A time of {total_time}.You Came in Fourth or Below Place.\n")
                
    def main():
        Students = get_student_details()
        Saved_Data(Students)
        Print_Data(Students)
        
    if __name__ == '__main__':
        main()







