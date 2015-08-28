#include <SFML/Graphics.hpp>
#include "Ghosts.h"
#include "PacManSprite.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Load pacMan enemies to display
    sf::Texture ghostsT;
    if (!ghostsT.loadFromFile("PACMANGhosts.png"))
        return EXIT_FAILURE;

    //Create PacMans Enemies
    Ghosts blinky(ghostsT, 5, 10,"blinky");
    Ghosts pinky(ghostsT, 15, 150,"pinky");
    Ghosts inky(ghostsT, 105, 250,"inky");
    Ghosts clyde(ghostsT, 205, 350,"clyde");

    //load the pacman texture
    sf::Texture pacManText;
    if (!pacManText.loadFromFile("PacManSheet.png"))
        return EXIT_FAILURE;

    //Create PacMan
    PacMan pM(pacManText, 250, 90);

    //temp background color change
    sf::RectangleShape fillerScreen(sf::Vector2f(800, 600));
    fillerScreen.setFillColor(sf::Color::White);
    fillerScreen.setPosition(0, 0);

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

        window.draw(fillerScreen);//delete later

        // Draw the blinky
        window.draw(blinky.getSprite());
        blinky.moveAnimation(animationMove);

        // Draw the pinky
        window.draw(pinky.getSprite());
        pinky.moveAnimation(animationMove);

        // Draw the inky
        window.draw(inky.getSprite());
        inky.moveAnimation(animationMove);

        // Draw the clyde
        window.draw(clyde.getSprite());
        clyde.moveAnimation(animationMove);

        //Draw PacMan
        window.draw(pM.getSprite());

        //to set the sift of the animation
        if(animationMove > 480)animationMove = 0;
        animationMove += 127;

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
