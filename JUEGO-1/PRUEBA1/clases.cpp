#include "clases.h"

Player::Player(){
    x = 0.0 ; y = 0.0;
    BalaImg = al_load_bitmap("imagenes/bala.bmp");
}
Player::Player(float x, float y){
    this->x = x ; this->y = y;
    BalaImg = al_load_bitmap("imagenes/bala.bmp");
}
/*void Player::disparar(){

    /// CREAR POSICION INICIAL DE LA BALA
    //newBala.dibujar(x+23,y-32);

    cout<<"CHICOS"<<endl;
}*/
/// ================================ TECLADO ====================================
bool band = false;
float posY=0;

int Player::teclado(ALLEGRO_EVENT_QUEUE* colaEventos){

    ALLEGRO_EVENT Evento; // eventos
    al_wait_for_event_timed(colaEventos, &Evento,0.01); // esperar por evento
    if(Evento.type == ALLEGRO_EVENT_KEY_DOWN){ /// si el tipo de evento == tecla abajo
        switch(Evento.keyboard.keycode){
            case ALLEGRO_KEY_ESCAPE:
                return -1;
            case ALLEGRO_KEY_RIGHT: // Derecha
                cout<<"Derecha\n";
                x += 10;
                break;
            case ALLEGRO_KEY_LEFT:// Izquierda
                cout<<"Izquierda\n";
                x -=10;
                break;
            case ALLEGRO_KEY_UP:// arriba
                cout<<"Arriba\n";
                y -=10;
                break;
            case ALLEGRO_KEY_DOWN://abajo
                cout<<"abajo\n";
                y +=10;
                break;
            case ALLEGRO_KEY_SPACE:
                cout<<"DISPARO:"<<endl;
                band = true;
                band = true;
                break;}
        };

    if(band){
        al_draw_bitmap(BalaImg,x+20,700-posY,0);

        cout<<posY<<endl;
        posY+=4;
        if(posY>=700){
            band=false;
            cout<<posY<<endl;
            posY=0;
        }
    }
    return 0;
};


float Player::getX(){
    return x;}

float Player::getY(){
    return y;}

Player::~Player(){}

/// =============== ALIEN ==================
Alien::Alien(){
    x = 0.0 ; y = 0.0;
}
/*Player::Player(float x, float y){
    this->x = x ; this->y = y;
}*/
void Alien::alien_move(){
    x +=5;
    if(x>1024){
        x=0;
    }
}
float Alien::alien_getX(){
    return x;}
float Alien::alien_getY(){
    return y;}

Alien::~Alien(){}

/// =============== BALA BALA BALA ==================
Bala::Bala(){
    //BalaImg = al_load_bitmap("imagenes/bala.bmp");}
}
float Bala::bala_getX(){
    return x;}
float Bala::bala_getY(){
    return y;}

Bala::~Bala(){};
