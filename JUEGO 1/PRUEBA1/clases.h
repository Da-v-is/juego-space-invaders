#include <iostream>
#include <allegro5/allegro.h>
using namespace std;

class Player
{
    private:
        float x,y;
        ALLEGRO_BITMAP* amongRed;
    public:
        Player();
        Player(float x, float y);
        void move_Right();
        void move_Left();

        void move_Up();
        void move_Down();

        float getX();
        float getY();

        void dibujar(float x, float y);
        ~Player();

};

class Alien
{
    private:
        float x,y;
        ALLEGRO_BITMAP* Alien;
    public:
        Alien();
        Alien(float x, float y);

        float alien_getX();
        float alien_getY();

        void dibujar(float x, float y);
        ~Player();

};

