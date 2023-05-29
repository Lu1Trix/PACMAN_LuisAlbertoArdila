#ifndef ARCADE_H
#define ARCADE_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <QKeyEvent>
#include <character.h>
#include <escenario.h>
#include <QTimer>
#include <vector>
#include <QMessageBox>
#include <QGraphicsTextItem>

QT_BEGIN_NAMESPACE
namespace Ui { class Arcade; }
QT_END_NAMESPACE

class Arcade : public QMainWindow
{
    Q_OBJECT

public:
    Arcade(QWidget *parent = nullptr);
    ~Arcade();

public slots:
    void animar();
//    void puntuacion();
//    void enemigos();

private:
    Ui::Arcade *ui;
    QGraphicsScene* scene;
    escenario* mapa;
    QTimer* m_timer;
    QTimer* E_Timer;

    bool movement_Up;
    bool movement_Down;
    bool movement_Right;
    bool movement_Left;

    long long int marcador;
    int Frutas_restantes;

    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);

    Character* m_pacman;
    Character* m_bluePhantom;
    Character* m_redPhantom;
    Character* m_purplePhantom;
    Character* m_yellowPhantom;

    std::vector <std::vector <Character*>> fruits;
    std::vector <std::vector <int>> m_map;

    QGraphicsTextItem *score;
    QGraphicsTextItem *Texto;

};
#endif // ARCADE_H
