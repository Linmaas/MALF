### The universe is a cold and empty place... until now!
#


![alt text](<img/Bildschirmfoto 2024-09-26 um 22.18.01.png>)

For the final project of this course I wanted to create something that pulls together what we learned in a nice and interactive way. The idea for the star constellations came to me after visiting the Zeiss planetarium a few weeks ago, learning about constellations and their history. How cool would it be to name my own constellation, I thought. And thats why I created this project!
![alt text](<img/Bildschirmfoto 2024-09-26 um 22.16.48.png>)
The main functionality is letting people put their own star in space and give it a name. When a star is put near it, a constellation gets created, by connecting the two stars with a line. 

It compares that star with every other star.
For each comparison, it calculates the distance between the new star and every other star using their positions. It keeps track of the closest star found that is within the distanceThreshold. This is done by checking if the current distance is less than minDistance.

After iterating through all other stars, if a valid closest star is found, and the maximum number of lines hasn't been reached yet, the function connects the current star to the closest star found by pushing the pair into the line drawing function.

This setup also leads to constellations changing if new stars get added, which wasn't my intention at first, but I decided to keep it, since it leads to a more interesting experience. For the future I would also like to implement naming the constellations, not only the stars. 

In order to keep the stars that each user created, they get saved into a jason file, that gets loaded at the beginning. This way its possible to save the star constellations.

Of course you can also move the camera around to navigate the universe. Or you enter the orbit mode to just orbit around your favorite star and just enjoy the view and music <3 For the look I chose something minimal- luckily space can just be represented with some spheres on a black background. 

I had a lot of fun creating this and really tried to use the concepts we had in class- like objects and vectors. Of course there was a it help of chat-gpt as well, but we had a good time coding together and it really went into detail to explain things to me I didn't understand. So I would say I learned a whole lot and feel now more confident at coding in general. 


If you check out the app there is also a little extra that isn´t shown in the video! 🌟
#
### ->>>>> video: https://drive.google.com/file/d/1CnEt9A0DfBnf1ZM_zVwpWD0Vl9b-YS-i/view?usp=sharing

![alt text](<img/Bildschirmfoto 2024-09-26 um 22.17.34.png>)