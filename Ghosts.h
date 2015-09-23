#ifndef GHOSTS_INCLUDED
#define GHOSTS_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Ghosts{
    private:
        float x;
        float y;
        bool notGhost;
        sf::Sprite ghostEnemy;
        sf::Texture ghostsT;
        string enemyName;

        void moveAnimation(int shift);
    public:
        Ghosts(float xPos, float yPos, string enemy);
        ~Ghosts(){cout << "The ghost is dead" << endl;}
        void ghostAi();
        sf::Sprite getSprite(){return ghostEnemy;}
        void moveGhosts(int speed);
        void changeAppearance();
};

#endif // GHOSTS_INCLUDED
