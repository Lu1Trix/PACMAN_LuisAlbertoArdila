#include "escenario.h"

escenario::escenario(QPixmap fondo, int X, int Y, int X2, int Y2)
{
    _width = fondo.width();
    _height = fondo.height();

    std::vector<std::vector<int>> Mat(_width, std::vector<int>(_height));

    m_map = Mat;

    QColor referencia = fondo.toImage().pixelColor(X , Y);
    QColor referencia2 = fondo.toImage().pixelColor(X2 , Y2);

    for(int C = 0; C < _width; ++C)
    {
        for(int K = 0; K < _height; ++K)
        {
            if (referencia == fondo.toImage().pixelColor(C , K) || referencia2 == fondo.toImage().pixelColor(C , K))
            {
                m_map[C][K] = 0;
            }
            else
            {
                m_map[C][K] = 1;
            }
        }
    }
    for(int K = 0; K < _height; ++K)
    {
        m_map[100][K] = 1;
        m_map[600][K] = 1;
    }

    m_map[125][150] = 2; m_map[325][520] = 2; m_map[370][150] = 3;
    m_map[125][180] = 2; m_map[325][550] = 2; m_map[380][180] = 2;
    m_map[125][210] = 3; m_map[295][550] = 2; m_map[380][210] = 2;
    m_map[125][240] = 2; m_map[265][550] = 2; m_map[350][220] = 2;
    m_map[125][270] = 2; m_map[235][550] = 2; m_map[410][220] = 2;

    m_map[155][270] = 2; m_map[265][580] = 2; m_map[440][220] = 2;
    m_map[185][270] = 2; m_map[265][610] = 2; m_map[470][220] = 2;
    m_map[215][270] = 2; m_map[295][610] = 2; m_map[530][150] = 2;

    m_map[215][240] = 2; m_map[325][610] = 2; m_map[560][150] = 2;
    m_map[215][210] = 2; m_map[325][640] = 2; m_map[580][180] = 2;
    m_map[215][180] = 2; m_map[325][660] = 3; m_map[580][210] = 2;
    m_map[215][150] = 2; m_map[355][660] = 2; m_map[580][240] = 2;

    m_map[185][210] = 2; m_map[385][660] = 2; m_map[580][270] = 2;
    m_map[155][210] = 2; m_map[415][660] = 2; m_map[550][220] = 3;
    m_map[155][150] = 2; m_map[445][660] = 2; m_map[520][220] = 2;
    m_map[185][150] = 2; m_map[475][660] = 2; m_map[550][270] = 2;
    m_map[215][150] = 2; m_map[505][660] = 2; m_map[520][270] = 2;
    m_map[245][150] = 2; m_map[535][660] = 2; m_map[520][490] = 2;
    m_map[275][150] = 3; m_map[565][660] = 3; m_map[550][490] = 2;
    m_map[305][150] = 2; m_map[295][660] = 2; m_map[580][490] = 2;
    m_map[325][150] = 2; m_map[265][660] = 2; m_map[460][490] = 2;
    m_map[325][180] = 2; m_map[235][660] = 2; m_map[430][490] = 2;
    m_map[325][220] = 2; m_map[205][660] = 2; m_map[400][490] = 2;
    m_map[295][220] = 2; m_map[175][660] = 2; m_map[380][520] = 2;
    m_map[265][220] = 2; m_map[145][660] = 2; m_map[380][550] = 2;
    m_map[245][220] = 2; m_map[115][660] = 2; m_map[350][550] = 2;

    m_map[215][300] = 2; m_map[115][630] = 2; m_map[410][550] = 2;
    m_map[215][330] = 2; m_map[580][630] = 2; m_map[440][550] = 2;
    m_map[215][360] = 2; m_map[580][600] = 2; m_map[470][550] = 2;
    m_map[215][390] = 3; m_map[550][600] = 2; m_map[540][550] = 2;
    m_map[215][420] = 2; m_map[520][600] = 2; m_map[570][550] = 2;
    m_map[215][450] = 2; m_map[490][600] = 2; m_map[580][520] = 3;
    m_map[215][480] = 2; m_map[490][570] = 2; m_map[430][600] = 2;
    m_map[215][510] = 2; m_map[490][540] = 2; m_map[400][600] = 2;
    m_map[215][540] = 3; m_map[490][510] = 2; m_map[380][630] = 2;
    m_map[215][570] = 2; m_map[490][480] = 2;
    m_map[215][600] = 2; m_map[490][450] = 2;

    m_map[185][600] = 2; m_map[490][420] = 2;
    m_map[155][600] = 2; m_map[490][390] = 2;
    m_map[125][600] = 2; m_map[490][360] = 2;

    m_map[155][570] = 2; m_map[490][330] = 2;
    m_map[155][540] = 2; m_map[490][300] = 3;
    m_map[125][540] = 2; m_map[490][270] = 2;

    m_map[125][510] = 2; m_map[490][240] = 2;
    m_map[155][490] = 2; m_map[490][210] = 2;
    m_map[185][490] = 2; m_map[490][180] = 2;
    m_map[245][490] = 2; m_map[490][150] = 2;

    m_map[275][490] = 2; m_map[460][150] = 2;
    m_map[305][490] = 3; m_map[430][150] = 2;
    m_map[325][490] = 2; m_map[400][150] = 2;


}
bool escenario::valid_movement(int X, int Y, Character* personaje)
{
    int C = personaje->getSquare_size();
    bool UpDown = false;
    bool LeftRight = false;

    if (X == personaje->getCoordenate_X()) UpDown = true;
    else LeftRight = true;

    if (X > _width || Y > _height || X < 0 || Y < 0) return false;
    else
    {
        for (int i = 0; i < (C/2); ++i)
        {
            if(LeftRight)
            {
                if (m_map[X][Y + i] == 1 || m_map[X][Y - i] == 1)
                {
                    return false;
                }
            }
            if(UpDown)
            {
                if (m_map[X + i][Y] == 1 || m_map[X - i][Y] == 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
}

void escenario::search(Character* personaje, Character* enemigo)
{
    int _X = personaje->getCoordenate_X();
    int _Y = personaje->getCoordenate_Y();

    int movement_speed = personaje->getMovement_speed();

    int movement_X;
    int movement_Y;

    int coordenate_X = enemigo->getCoordenate_X();
    int coordenate_Y = enemigo->getCoordenate_Y();

    if(coordenate_X < _X)
    {
        movement_X = coordenate_X - movement_speed;
        if(this->valid_movement(movement_X - 13 - movement_speed, _Y, personaje))
        {
            personaje->setCoordenate_X(movement_X);
            personaje->map_movement();
        }
    }
    else if(coordenate_X > _X)
    {
        movement_X = coordenate_X + movement_speed;
        if(this->valid_movement(movement_X + 13 + movement_speed, _Y, personaje))
        {
            personaje->setCoordenate_X(movement_X);
            personaje->map_movement();
        }
    }
    if(coordenate_Y < _Y)
    {
        movement_Y = coordenate_Y - movement_speed;
        if(this->valid_movement(_X, movement_Y - 13 - movement_speed, personaje))
        {
            personaje->setCoordenate_Y(movement_Y);
            personaje->map_movement();
        }
    }
    else if(coordenate_Y > _Y)
    {
        movement_Y = coordenate_Y + movement_speed;
        if(this->valid_movement(_X, movement_Y + 13 + movement_speed, personaje))
        {
            personaje->setCoordenate_Y(movement_Y);
            personaje->map_movement();
        }
    }
}

bool escenario::valid_position(int X, int Y)
{
    if (m_map[X][Y] == 1) return false;
    else return true;

}

void escenario::PutFruits(QGraphicsScene *scene, int sprite_width, int sprite_height, std::vector<std::vector<Character*>> Mat)
{
    for(int C = 0; C < 700; ++C)
    {
        for(int K = 0; K < 800; ++K)
        {
            if(m_map[C][K] == 2)
            {
                Character* fruit = new Character(12, C, K);
                fruit->setPicture(QPixmap(":/Sprites/pngwing.com.png").copy(0*sprite_width, 0*sprite_height, sprite_width, sprite_height));
                Mat[C][K] = fruit;
                scene->addItem(fruit);
            }
            if(m_map[C][K] == 3)
            {
                Character* fruit = new Character(12, C, K);
                fruit->setPicture(QPixmap(":/Sprites/pngwing.com.png").copy(3*sprite_width, 0*sprite_height, sprite_width, sprite_height));
                Mat[C][K] = fruit;
                scene->addItem(fruit);
            }
        }
    }
}

std::vector<std::vector<int> > escenario::getmap() const
{
    return m_map;
}

void escenario::setMap(const std::vector<std::vector<int> > &newMap)
{
    m_map = newMap;
}

