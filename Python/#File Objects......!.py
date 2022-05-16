# #File Objects......!




# with open('Idea.txt', 'r') as f: # r= read. w= write. r+ = read+write

#     # for line in f:
#     #     print(line, end='')

#     sizetoRead = 5  # will grab the first 100 letters of the file
#     contents = f.read(sizetoRead)  # or just read everything in file
    
#     #while loop runs through each each char until all is printed
#     while len(contents) > 0:
#         print(contents, end='') # Will print with new lines do if lines not needed use (, end="")
#         contents = f.read(sizetoRead)  # make sure it stops at the end of file


# with open('Idea1.txt', 'a') as af:
#     af.write('\n11) Hello Again')
    
# def smallestnum(numbers):
#     smallest_mum = numbers[0]
    
#     for num in numbers:
#         if num < smallest_mum:
#             smallest_mum = num
#     return smallest_mum

# print(smallestnum([23,23,121,5,454,1]))

import os; from playsound import playsound; import random; import time

songs = os.listdir("./songs")

while True:
    song = "./songs/" + songs[random.randint(0, len(songs))]
    print("Now playing " + song)
    playsound(song)
    time.sleep(1)
