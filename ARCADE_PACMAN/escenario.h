#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <character.h>
#include <vector>

class escenario
{
public:
    escenario(QPixmap fondo, int X, int Y, int X2, int Y2);
    bool valid_movement(int X, int Y, Character* personaje);
    void search(Character *personaje, Character *enemigo);
    bool valid_position(int X, int Y);
    void PutFruits(QGraphicsScene*scene, int sprite_width, int sprite_height, std::vector<std::vector<Character *> > Mat);

    std::vector<std::vector<int> > getmap() const;
    void setMap(const std::vector<std::vector<int> > &newMap);

private:
    int _width;
    int _height;
    std::vector <std::vector <int>> m_map;
};

#endif // ESCENARIO_H
