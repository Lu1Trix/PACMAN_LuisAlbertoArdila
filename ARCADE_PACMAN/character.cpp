#include "character.h"
Character::Character( int size, int X, int Y)
{
    square_size = size;
    coordenate_X = X;
    coordenate_Y = Y;
    setPos(X, Y);
}

Character::Character()
{
    square_size = 5;
    coordenate_X = 0;
    coordenate_Y = 0;
    setPos(0, 0);
}

int Character::getMovement_speed() const
{
    return movement_speed;
}

void Character::setMovement_speed(int newMovement_speed)
{
    movement_speed = newMovement_speed;
}

QPixmap Character::picture() const
{
    return m_picture;
}

void Character::setPicture(const QPixmap &newPicture)
{
    m_picture = newPicture;
}

int Character::getCoordenate_X() const
{
    return coordenate_X;
}

void Character::setCoordenate_X(int newCoordenate_X)
{
    coordenate_X = newCoordenate_X;
}

int Character::getCoordenate_Y() const
{
    return coordenate_Y;
}

void Character::setCoordenate_Y(int newCoordenate_Y)
{
    coordenate_Y = newCoordenate_Y;
}

void Character::map_movement()
{
    this->setPos(coordenate_X, coordenate_Y);
}

QRectF Character::boundingRect() const
{
    return QRectF(-square_size / 2, -square_size / 2, square_size, square_size);
}

void Character::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),m_picture,m_picture.rect());
}

qreal Character::getSquare_size() const
{
    return square_size;
}

void Character::setSquare_size(qreal newSquare_size)
{
    square_size = newSquare_size;
}
