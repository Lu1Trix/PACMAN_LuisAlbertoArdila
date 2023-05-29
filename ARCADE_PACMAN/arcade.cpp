#include "arcade.h"
#include "ui_arcade.h"

int screen_width = 700;
int screen_height = 800;

int sprite_width = 875;
int sprite_height = 964;

Arcade::Arcade(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Arcade)
{
    ui->setupUi(this);

    movement_Up = false;
    movement_Down = false;
    movement_Left = false;
    movement_Right = false;

    score = new QGraphicsTextItem;
    Texto = new QGraphicsTextItem;

    marcador = 0;
    Frutas_restantes = 134;

    score->setPlainText(QString("SCORE: ") + QString::number(marcador));
    score->setDefaultTextColor(Qt::darkMagenta);
    score->setFont(QFont("Eras Bold ITC", 16));
    score->setPos(50, 700);

    Texto->setPlainText(QString("¡COMETE LAS ") + QString::number(Frutas_restantes) + QString(" FRUTAS PARA GANAR!"));
    Texto->setDefaultTextColor(Qt::darkCyan);
    Texto->setFont(QFont("Eras Bold ITC", 16));
    Texto->setPos(115, 50);

    // Making the scene and GraphicsView configurations
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, screen_width, screen_height);
    setFixedSize(screen_width, screen_height);

    ui->graphicsView->resize(screen_width, screen_height);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QPixmap(":/Sprites/Maze.png").scaled(screen_width, screen_height));

    m_pacman = new Character(28, 350, 435);
    m_bluePhantom = new Character(26, 311, 380);
    m_redPhantom = new Character(26, 337, 380);
    m_purplePhantom = new Character(26, 362, 380);
    m_yellowPhantom = new Character(26, 387, 380);

    m_pacman->setPicture(QPixmap(":/Sprites/pngwing.com.png").copy(3*sprite_width, 1*sprite_height, sprite_width, sprite_height));
    m_bluePhantom->setPicture(QPixmap(":/Sprites/pngwing.com.png").copy(1*sprite_width, 2*sprite_height, sprite_width, sprite_height));
    m_redPhantom->setPicture(QPixmap(":/Sprites/pngwing.com.png").copy(0*sprite_width, 2*sprite_height, sprite_width, sprite_height));
    m_purplePhantom->setPicture(QPixmap(":/Sprites/pngwing.com.png").copy(2*sprite_width, 2*sprite_height, sprite_width, sprite_height));
    m_yellowPhantom->setPicture(QPixmap(":/Sprites/pngwing.com.png").copy(3*sprite_width, 2*sprite_height, sprite_width, sprite_height));

    scene->addItem(m_pacman);
    scene->addItem(m_bluePhantom);
    scene->addItem(m_redPhantom);
    scene->addItem(m_purplePhantom);
    scene->addItem(m_yellowPhantom);

    mapa = new escenario (QPixmap(":/Sprites/Maze.png").scaled(screen_width, screen_height), 0, 0, 340, 345);

    std::vector<std::vector<Character*>> Mat(screen_width, std::vector<Character*>(screen_height));
    fruits = Mat;

    m_map = mapa->getmap();

    for(int C = 0; C < 700; ++C)
    {
        for(int K = 0; K < 800; ++K)
        {
            if(m_map[C][K] == 2)
            {
                Character* fruit = new Character(12, C, K);
                fruit->setPicture(QPixmap(":/Sprites/pngwing.com.png").copy(0*sprite_width, 0*sprite_height, sprite_width, sprite_height));
                Mat[C][K] = fruit;
                scene->addItem(Mat[C][K]);
            }
            if(m_map[C][K] == 3)
            {
                Character* fruit = new Character(12, C, K);
                fruit->setPicture(QPixmap(":/Sprites/pngwing.com.png").copy(3*sprite_width, 0*sprite_height, sprite_width, sprite_height));
                Mat[C][K] = fruit;
                scene->addItem(Mat[C][K]);
            }
        }
    }
    fruits = Mat;

    m_timer = new QTimer;
    E_Timer = new QTimer;
    connect(m_timer,SIGNAL(timeout()),this,SLOT(animar()));
    //connect(E_Timer,SIGNAL(timeout()),this,SLOT(enemigos()));
    m_timer->start(10);
    E_Timer->start(10);
    scene->addItem(score);
    scene->addItem(Texto);
}

Arcade::~Arcade()
{
    delete ui;
}

void Arcade::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        movement_Left = true;
    }
    else if(ev->key()==Qt::Key_S)
    {
        movement_Down = true;
    }
    else if(ev->key()==Qt::Key_W)
    {
        movement_Up = true;
    }
    else if(ev->key()==Qt::Key_D)
    {
        movement_Right = true;
    }
}

void Arcade::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_A)
    {
        movement_Left = false;
    }
    else if(ev->key()==Qt::Key_S)
    {
        movement_Down = false;
    }
    else if(ev->key()==Qt::Key_W)
    {
        movement_Up = false;
    }
    else if(ev->key()==Qt::Key_D)
    {
        movement_Right = false;
    }
}

void Arcade::animar()
{
    int _X = m_pacman->getCoordenate_X();
    int _Y = m_pacman->getCoordenate_Y();

    if (movement_Up && mapa->valid_movement(_X , _Y - 14 - m_pacman->getMovement_speed(), m_pacman))
    {
        m_pacman->setCoordenate_Y(_Y - m_pacman->getMovement_speed());
        m_pacman->map_movement();
    }
    if (movement_Down && mapa->valid_movement(_X , _Y + 14 + m_pacman->getMovement_speed(), m_pacman))
    {
        m_pacman->setCoordenate_Y(_Y + m_pacman->getMovement_speed());
        m_pacman->map_movement();
    }
    if (movement_Right && mapa->valid_movement(_X + 14 + m_pacman->getMovement_speed(), _Y, m_pacman))
    {
        m_pacman->setCoordenate_X(_X + m_pacman->getMovement_speed());
        m_pacman->map_movement();
    }
    if (movement_Left && mapa->valid_movement(_X - 14 - m_pacman->getMovement_speed(), _Y, m_pacman))
    {
        m_pacman->setCoordenate_X(_X - m_pacman->getMovement_speed());
        m_pacman->map_movement();
    }
    for (int C = _Y - 14; C < _Y + 14; ++C)
    {
        for (int K = _X - 14; K < _X + 14; ++K)
        {
            if (m_map[K][C] == 2)
            {
                m_map[K][C] = 0;
                fruits[K][C]->hide();
                marcador += 50;
                Frutas_restantes -=1;
                score->setPlainText(QString("SCORE: ") + QString::number(marcador));
                score->setDefaultTextColor(Qt::darkMagenta);
                score->setFont(QFont("Eras Bold ITC", 16));

                Texto->setPlainText(QString("¡COMETE LAS ") + QString::number(Frutas_restantes) + QString(" FRUTAS PARA GANAR!"));
                Texto->setDefaultTextColor(Qt::darkCyan);
                Texto->setFont(QFont("Eras Bold ITC", 16));
            }
            if (m_map[K][C] == 3)
            {
                m_map[K][C] = 0;
                fruits[K][C]->hide();
                marcador += 100;
                Frutas_restantes -=1;;
                score->setPlainText(QString("SCORE: ") + QString::number(marcador));
                score->setDefaultTextColor(Qt::yellow);
                score->setFont(QFont("Eras Bold ITC", 16));

                Texto->setPlainText(QString("¡COMETE LAS ") + QString::number(Frutas_restantes) + QString(" FRUTAS PARA GANAR!"));
                Texto->setDefaultTextColor(Qt::darkCyan);
                Texto->setFont(QFont("Eras Bold ITC", 16));
            }
        }
    }
    if (Frutas_restantes == 0)
    {
        QMessageBox::information(this, "¡FELICIDADES!", "¡COMPLESTASTE EL JUEGO!");
    }

}



//void Arcade::enemigos()
//{
//    mapa->search(m_bluePhantom, m_pacman);
//}
