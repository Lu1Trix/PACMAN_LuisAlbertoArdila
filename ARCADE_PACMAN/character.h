#ifndef CHARACTER_H
#define CHARACTER_H


#include "QPainter"
#include "QGraphicsItem"


class Character : public QGraphicsItem
{
public:
    Character(int size, int X, int Y);
    Character();
    int getMovement_speed() const;
    void setMovement_speed(int newMovement_speed);

    QPixmap picture() const;
    void setPicture(const QPixmap &newPicture);


    int getCoordenate_X() const;
    void setCoordenate_X(int newCoordenate_X);

    int getCoordenate_Y() const;
    void setCoordenate_Y(int newCoordenate_Y);

    void map_movement();

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    qreal getSquare_size() const;
    void setSquare_size(qreal newSquare_size);



private:
    int coordenate_X;
    int coordenate_Y;
    int movement_speed = 2;
    QPixmap m_picture;
    qreal square_size;
};

#endif // CHARACTER_H
