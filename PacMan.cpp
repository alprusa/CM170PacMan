#include <SFML/Graphics.hpp>
#include "Ghosts.h"
#include "PacManSprite.h"
#include "TileMap.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(700, 800), "SFML window");

    //create the game Level1
     // define the level with an array of tile indices
    const int level[] =
    {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,2,2,0,2,2,2,0,2,2,0,2,2,0,2,2,2,2,2,2,2,0,
        0,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,
        0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,0,
        0,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,0,2,2,0,
        0,0,0,2,2,0,2,2,2,2,0,2,2,2,2,0,2,2,0,2,2,0,
        0,2,2,2,2,0,2,2,2,2,0,2,2,2,2,0,2,2,2,2,2,0,
        0,2,2,2,2,0,0,0,2,2,0,2,2,0,0,0,2,2,2,2,2,0,
        0,0,0,2,2,0,2,2,2,2,2,2,2,2,2,0,2,2,0,0,0,0,
        2,2,0,2,2,0,2,2,2,2,2,2,2,2,2,0,2,2,0,2,2,2,
        0,0,0,2,2,0,2,2,0,1,1,1,0,2,2,0,2,2,0,0,0,0,
        2,2,2,2,2,2,2,2,0,2,2,2,0,2,2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,0,2,2,2,0,2,2,2,2,2,2,2,2,2,
        0,0,0,2,2,0,2,2,0,0,0,0,0,2,2,0,2,2,0,0,0,0,
        2,2,0,2,2,0,2,2,2,2,2,2,2,2,2,0,2,2,0,2,2,2,
        0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,0,0,0,0,
        0,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,0,
        0,2,2,2,2,2,2,0,2,2,0,2,2,2,2,2,2,2,2,2,2,0,
        0,2,2,0,0,2,2,0,2,2,0,2,2,0,0,0,2,2,2,2,2,0,
        0,2,2,2,0,2,2,2,2,2,0,2,2,2,0,2,2,2,2,2,2,0,
        0,0,2,2,0,2,2,2,2,2,0,2,2,2,0,2,2,2,0,2,2,0,
        0,0,2,2,0,2,2,0,0,0,0,0,2,2,0,2,2,0,0,2,2,0,
        0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,
        0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    };

    // create the tilemap from the level definition
    TileMap mapT;
    if (!mapT.load("LevelWallColors.png", sf::Vector2u(32, 32), level, 22, 25)) //512, 256
        return -1;

    //Create PacMans Enemies
    Ghosts blinky(295, 350,"blinky");
    Ghosts pinky(295, 380,"pinky");
    Ghosts inky(340, 350,"inky");
    Ghosts clyde(340, 380,"clyde");

    //Create PacMan
    PacMan pM(310, 460);

    //for the animations
    int animationMove = 0;

	// Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear();

        window.draw(mapT);

        // Draw the blinky
        window.draw(blinky.getSprite());
        blinky.moveGhosts(animationMove);

        // Draw the pinky
        window.draw(pinky.getSprite());
        pinky.moveGhosts(animationMove);

        // Draw the inky
        window.draw(inky.getSprite());
        inky.moveGhosts(animationMove);

        // Draw the clyde
        window.draw(clyde.getSprite());
        clyde.moveGhosts(animationMove);

        //Draw PacMan
        window.draw(pM.getSprite());
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) pM.movePac(3,"left");
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) pM.movePac(3, "right");
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) pM.movePac(3, "up");
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) pM.movePac(3, "down");

        //to set the sift of the animation
        if(animationMove > 480)animationMove = 0;
        animationMove += 127;

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
