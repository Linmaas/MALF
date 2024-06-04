# We wrote a program that can do the following: 

1. Asking for the name of a person and their crush
2. Printing the first letter of the names in ascii-art
3. ask if you want to send this as a love letter
4. opens the mail program if the answer is yes

The main file takes care of checking for the operating system, so the program can run on windows and mac, it also calls the other functions used in this program. The operating system sets the isWin bool to true.

The lettersCombination function gets called in the ascii.cpp file and checks the array of strings for the first letters of the names. Then it calls the heart function which takes the first letters as input.   

%c is a placeholder for the character given to the function. 

The heart function prints the two ascii art hearts and then ends.

Afterwards the YesOrNo function gets called by the main function.

This function aks if a love letter should be sent. If the answer is yes, the sendMail function gets called. Depending on the state of the isWin bool, either the winmail or the macmail function gets called. They both do the same thing: they open the mail program. 

After this the program is done.

## what we wanted to do

We also wanted to be able to save the ascii art from the console and attatch it to the mail directly. This would require us to use a library, and we already spent 4 hours implementing what we have. 

## how we worked 

We first tried to merge the branches we worked on, but our ides got so many conflicts that we had to start over again. For this project we worked together on one machine to get something done. We really need help with learning how to work together on windows/mac, since they use a very different file structure when a project is created through the ide. 


![alt text](<Bildschirmfoto 2024-06-04 um 20.25.01.png>)