#ifndef PACMANSPRITE_INCLUDED
#define PACMANSPRITE_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class PacMan{
    private:
        sf::Sprite pacMan;
        sf::Texture pacManImage;
        float x;
        float y;
        int textureMove;

        void PacManAnimate();
    public:
        PacMan(float xPos, float yPos);
        ~PacMan(){cout << "PacMan is dead" << endl;}
        sf::Sprite getSprite(){return pacMan;}
        void movePac(int speed, string direction);
};

#endif // GHOSTS_INCLUDED
