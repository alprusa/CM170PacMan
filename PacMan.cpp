#include <SFML/Graphics.hpp>
#include "Ghosts.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Load pacMan enemies to display
    sf::Texture ghostsT;
    if (!ghostsT.loadFromFile("PACMANGhosts.jpg"))
        return EXIT_FAILURE;

    //Create PacMans Enemies
    Ghosts blinky(true, ghostsT, 5, 10);
    int blinkyAnimation = 0;

    //temp background color change
    sf::RectangleShape fillerScreen(sf::Vector2f(800, 600));
    fillerScreen.setFillColor(sf::Color::White);
    fillerScreen.setPosition(0, 0);

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
        blinky.moveAnimation(blinkyAnimation);
        if(blinkyAnimation > 480)blinkyAnimation = 0;
        blinkyAnimation += 120;

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
