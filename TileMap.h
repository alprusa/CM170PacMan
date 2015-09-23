#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

//base tilemaps class from the sfml 2.1 vertexarray tutorial
class TileMap : public sf::Drawable, public sf::Transformable
{
public:

    bool load(const string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
    bool collisionDetection();

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    map<int, int> mVerticesIndexs; //first int is the number or id for the color tile second int is where it is in the m_vertices
};

#endif
