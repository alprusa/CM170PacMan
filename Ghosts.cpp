#include <SFML/Graphics.hpp>
#include "Ghosts.h"

using namespace std;

Ghosts::Ghosts(float xPos, float yPos, string enemy):x(xPos), y(yPos), enemyName(enemy){
    // Load pacMan enemies to display
    if (!ghostsT.loadFromFile("PACMANGhosts.png"))
        return;

    notGhost = true;
    ghostEnemy = sf::Sprite(ghostsT);
    if(enemyName == "blinky") ghostEnemy.setTextureRect(sf::IntRect(197,70,120,115));
    else if(enemyName == "pinky") ghostEnemy.setTextureRect(sf::IntRect(197,196,120,115));
    else if(enemyName == "inky") ghostEnemy.setTextureRect(sf::IntRect(197,324,120,115));
    else ghostEnemy.setTextureRect(sf::IntRect(197,451,120,115));
    ghostEnemy.setScale(sf::Vector2f(0.3,0.3));
    ghostEnemy.setPosition(sf::Vector2f(x,y));
}

void Ghosts::ghostAi(){
    cout << "we are ghosts" << endl;
}

void Ghosts::moveAnimation(int shift){
    if(notGhost == false) ghostEnemy.setTextureRect(sf::IntRect(197+shift,576,120,115));
    else if(enemyName == "blinky") ghostEnemy.setTextureRect(sf::IntRect(197+shift,70,120,115));
    else if(enemyName == "pinky") ghostEnemy.setTextureRect(sf::IntRect(197+shift,196,120,115));
    else if(enemyName == "inky") ghostEnemy.setTextureRect(sf::IntRect(197+shift,324,120,115));
    else ghostEnemy.setTextureRect(sf::IntRect(197+shift,451,120,115));
}

void Ghosts::moveGhosts(int speed){
    moveAnimation(speed);
}

void Ghosts::changeAppearance(){
    notGhost = !notGhost;
    if(notGhost == false) ghostEnemy.setTextureRect(sf::IntRect(197,576,120,115));
    else if(enemyName == "blinky") ghostEnemy.setTextureRect(sf::IntRect(197,70,120,115));
    else if(enemyName == "pinky") ghostEnemy.setTextureRect(sf::IntRect(197,196,120,115));
    else if(enemyName == "inky") ghostEnemy.setTextureRect(sf::IntRect(197,324,120,115));
    else ghostEnemy.setTextureRect(sf::IntRect(197,451,120,115));
}
