#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "clases.h"
using namespace std;
/*void colision(int x1, int x2, int y1m int y2){
    int unoX = p1.getX()+50 , dos = Enemigo.alien_getX() ;
    cout<< unoX<<" - "<< dos<<endl;
    if(unoX > dos && unoX-50< dos+100){
        cout<<"CHOQUE"<<endl;}

}*/
void bala1(float x, float y){
    //al_draw_bitmap(bala,x,y,0);
}
int main()
{
    int ancho = 1024, largo = 756; // tamaño de la pantalla

    al_init(); // iniciar allegro
    al_init_image_addon(); // iniciar imagen
    al_install_keyboard(); // intalar el teclado

    ALLEGRO_DISPLAY* ventana = al_create_display(ancho, largo); // crear un ventana de juego
    ALLEGRO_EVENT_QUEUE* colaEventos = al_create_event_queue(); //cola de eventos
    al_register_event_source(colaEventos, al_get_keyboard_event_source());
    //creo que regrista los eventos en la cola (no entiendo como funciona)
    ALLEGRO_BITMAP* naveImg = al_load_bitmap("imagenes/nave.bmp");
    ALLEGRO_BITMAP* AlienImg = al_load_bitmap("imagenes/rival.bmp");


    Player p1(512,700); // jugador
    Alien Enemigo; // enemigo
    float y1=0;
    while(true){
        al_clear_to_color(al_map_rgb(0,0,0)); // limpia la pantalla
        al_draw_bitmap(naveImg,p1.getX(),p1.getY(),0);
        al_draw_bitmap(AlienImg,Enemigo.alien_getX(),Enemigo.alien_getY(),0);
        /*if(p1.teclado(colaEventos)){
            while(y1<700){
                al_draw_bitmap(BalaImg,700,700-y1,0);
                al_flip_display();
                y1+=0.01;
           }
           y1=0;
        }*/
        /*for(int i = 0;i<500;i+=50){
        al_draw_bitmap(AlienImg,x1+i,y1,0);}*/
        Enemigo.alien_move();

        p1.teclado(colaEventos);
        al_flip_display(); // dibujar las imagens en pantalla


        /*if(c==0){
            x1+=2;
            if(x1+500>1024){c=1;y1+=10;}
        }
        if(c==1){
            x1-=2;
            if(x1<0){c=0;y1+=10;}
        }*/

    }

    al_destroy_display(ventana);
    al_destroy_event_queue(colaEventos);
    al_destroy_bitmap(naveImg);
    al_destroy_bitmap(AlienImg);
    //al_destroy_bitmap(BalaImg);

    return 0;
}
