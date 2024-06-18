## Concept 

The idea was to create an application in which the user could write down a text and then it would create some sort of letter collage using a different font for each letter of the text. 

## What did we do 

### Git Hub Problems Solving 

We had a lot of problems at the beginning with the windows/mac IDEs having different filetypes and folder structure. We forgot to add those to the git.ignore so we needed to do it through the console, which took us some time to figure out. We had some small merge conflicts, which we resolved after some time. 

### Linda
I set up the UI elements with the .gui library that comes with open frameworks. The user can enter text in an input field. If a change in text gets detected in the update function Annas part gets executed.
I had some problems with the styling of the UI elements. My override of the default parameters didn't work sadly, so it looks a bit ugly 🥲  
### Anna 
I setup the graphic generation with openframeworks. The text gets splitted and each chaarachter receives a different font from an array of fonts that we selected and are uploaded inside of the application. 
I also wanted to randomize the size of each character, but I didn't manage to do it and I think it is actually not possible inside of our specific case..  (nothing is impossible! Maybe I'll find a way)

When we merged the two parts, Visual Community first detected a directory problem and I could manage to solve it. We then made the last adjustment on Linda's laptop and when I tried to re open the finished project, it didn't open on Visual Community. 

## Result 
Tadaaaa: 
![alt text](<Bildschirmfoto 2024-06-18 um 13.27.51.png>)