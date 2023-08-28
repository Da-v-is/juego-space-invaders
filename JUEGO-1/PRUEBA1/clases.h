#include <iostream>
#include <allegro5/allegro.h>
using namespace std;
class Bala{
    private:
        float x , y;

    public:
        Bala();
        float bala_getX();
        float bala_getY();

        ~Bala();
};

class Player
{
    private:
        float x,y;
        ALLEGRO_BITMAP* BalaImg;
    public:
        Player();
        Player(float x, float y);
        void disparar();
        int teclado(ALLEGRO_EVENT_QUEUE* colaEventos);
        float getX();
        float getY();

        ~Player();
};

class Alien
{
    private:
        float x , y;
    public:
        Alien();
        Alien(float x, float y);
        void alien_move();
        float alien_getX();
        float alien_getY();
        ~Alien();
};





