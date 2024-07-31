**Creative Coding II**

Prof. Dr.-Ing. Angela Brennecke | a.brennecke@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*   
Anna Brauwers | anna.s.brauwers@filmuniversitaet.de | Film University Babelsberg *KONRAD WOLF*

---

# Snake Game Development 

We wanted to make an ant-game! You can watch a screencast of the game here: https://youtube.com/shorts/x0s_Lousxic?feature=share

All Assets where created in C4D by us :) 

## Code explanation: 
### ofSnake 

Constructor: Initializes the snake with one segment, no speed, white color, loads segment images, and sets up animation timing.

Destructor: Logs a message when the snake is destroyed.

loadSegmentImages: Loads images for the snake's segments from files.

updateSnake: Updates the snake's position, handles screen wrapping.

drawSnake: Draws the snake on the screen, animates segment images, and rotates the head based on direction.

setDir: Sets the snake's movement direction.

grow: Adds a new segment to the snake's body.

eat: Checks if the snake's head is close enough to eat food.

checkSelfCollision: Detects if the snake collides with itself.

resetSnake: Resets the snake to its initial state.

The class utilizes ofVec2f for positions, manages direction and movement with xSpeed and ySpeed, and handles animation frames.

### ofFood
Constructor: Initializes the food color, loads food images, and randomly picks an initial location for the food.


loadFoodImages: Loads food images from specified files, logs success or failure, and ensures images are loaded.

selectRandomFoodImage: Randomly selects an image from the loaded food images to be the current food image.

pickLocation: Randomly selects a grid position on the screen for the food, ensuring it aligns with the grid. It also selects a random food image.

drawFood: Draws the current food image at its location if the image is properly loaded.

The class uses ofVec2f for positions, manages a collection of food images, and ensures that the food's position and appearance are correct.