#ifndef PACMANSPRITE_INCLUDED
#define PACMANSPRITE_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class PacMan{
    private:
        sf::Sprite pacMan;
        float x;
        float y;
    public:
        PacMan(sf::Texture& pacManText, float xPos, float yPos);
        ~PacMan(){cout << "PacMan is dead" << endl;}
        sf::Sprite getSprite(){return pacMan;}
};

#endif // GHOSTS_INCLUDED
