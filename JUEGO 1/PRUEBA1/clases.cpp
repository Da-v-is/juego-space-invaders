#include "clases.h"

Player::Player(){
    x = 0.0 ; y = 0.0;
}
/*Player::Player(float x, float y){
    this->x = x ; this->y = y;
}*/
void Player::move_Right(){
    x+=10;}
void Player::move_Left(){
    x-=10;}
void Player::move_Up(){
    y-=10;}
void Player::move_Down(){
    y+=10;}

float Player::getX(){
    return x;}

float Player::getY(){
    return y;}

void Player::dibujar(float x, float y){
    this->x = x ; this->y = y;
    amongRed = al_load_bitmap("imagenes/RED.png");
    al_draw_bitmap(amongRed,x,y,0);
}
Player::~Player(){}

/// =============== ALIEN ==================
float alien_getX(){
    return x;}
float alien_getY(){
    return y;}

void dibujar(float x, float y){
    this->x = x ; this->y = y;
    Alien = al_load_bitmap("imagenes/RED.png");
    al_draw_bitmap(amongRed,x,y,0);
}

