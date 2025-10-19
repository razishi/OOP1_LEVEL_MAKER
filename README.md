code explanation :
 
This code describes a  planner map of a mouse and cat game, so 
we can choose a character
 from the toolbar from the side and Design our new map by 
insertion the character into the map
Also, the user can save the map that s\he design, on the
 other side user can choose to delete all of
the map that he drew. 


-The created files : 

1- Controler.h / Controler.cpp 
The Controller class manages the application's main loop,
 handling user input and rendering the board and background
 using SFML. It facilitates interaction with a Board object
 and processes events like mouse clicks and window closure.



2-Toolsbar.h / Toolsbar.cpp
The Toolsbar class in SFML is designed for creating and managing
 a toolbar of icons for a graphical application. It loads images
 into sprites, arranges them on the toolbar, and scales them
 appropriately. The class supports drawing these icons on a 
window, identifying icons based on their screen location, and
 retrieving the sprite of an icon. This functionality is crucial
 for graphical interfaces with interactive tool selections.

3-Board.h / Board.cpp

The Board class, utilizing SFML, manages a graphical board or 
grid layout for applications. It handles board initialization,
 configuration loading, user interactions for icon placement
 or removal, and visual rendering of the board and its components.
 The class integrates with a Toolsbar for icon selection and 
employs Row objects for row management. Features include reading
 and saving board states to a file, interactive editing through
 mouse clicks, and automatic board layout adjustments. It's 
designed for creating and managing interactive, grid-based 
environments in graphical applications.

4- Row. h / Row.cpp

The Row class manages a dynamic array of Tile objects, 
providing functionalities for initialization, copying, 
accessing, and modifying the array. It supports operations
 like constructing with a predefined size and value, copying
 via a copy constructor and assignment operator, accessing 
elements with boundary checks, adding elements, and querying
 their size and emptiness. The class ensures deep copies and 
proper memory management to prevent leaks.



5- Tile. h / Tile.cpp

The Tile class encapsulates a single tile with a character
 symbol for use in board games or grid layouts. It offers
 constructors for initialization and copying, alongside a
 destructor. The class allows for the manipulation and
 retrieval of the tile's symbol through a getter and setter,
 facilitating its representation and modification without 
managing complex resources.

6- main.cpp
Run the game.


Data structures : 
-use a Vector of 'Row' that each row has a Denamyic array of 
'Tile', that saves characters on 'Map'.
-use a 'Board' class to manage all the logic of the code, and 
a 'Contorler' class to update the game.




Algorithms :

Designs :
 a 'Board' class managing the application's logic and internal
 state, serving as the backend. A 'Controller' class handles 
the user interface, processing user inputs and rendering visuals,
 operating as the front end. The 'Controller' updates the game 
state based on user interactions through the Board, maintaining
 a clear division between logic management and user interaction.

