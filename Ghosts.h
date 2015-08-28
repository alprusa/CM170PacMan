#ifndef GHOSTS_INCLUDED
#define GHOSTS_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Ghosts{
    private:
        bool notGhost;
        sf::Sprite ghostEnemy;
        string enemyName;
        float x;
        float y;
    public:
        Ghosts(sf::Texture& ghostsT, float xPos, float yPos, string enemy);
        ~Ghosts(){cout << "The ghost is dead" << endl;}
        void ghostAi();
        sf::Sprite getSprite(){return ghostEnemy;}
        void moveAnimation(int amount);
        void changeAppearance();
};

#endif // GHOSTS_INCLUDED
