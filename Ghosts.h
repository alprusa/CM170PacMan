#ifndef GHOSTS_INCLUDED
#define GHOSTS_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Ghosts{
    private:
        bool notGhost;
        sf::Sprite ghostEnemy;
        float x;
        float y;
    public:
        Ghosts(bool ghost, sf::Texture& ghostsT, float xPos, float yPos);
        ~Ghosts(){cout << "The ghost is dead" << endl;}
        void ghostAi();
        sf::Sprite getSprite(){return ghostEnemy;}
        void moveAnimation(int amount);
};

#endif // GHOSTS_INCLUDED
