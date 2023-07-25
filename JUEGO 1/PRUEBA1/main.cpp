#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "clases.h"
using namespace std;

int main()
{
    int ancho = 1024, largo = 756;

    al_init();
    al_init_image_addon();
    al_install_keyboard();


    ALLEGRO_DISPLAY* ventana = al_create_display(ancho, largo);
    //ALLEGRO_TIMER* fps = al_create_timer(1.0/10);
    ALLEGRO_BITMAP* amongRed = al_load_bitmap("imagenes/RED.png");

    ALLEGRO_EVENT_QUEUE* colaEventos = al_create_event_queue();


    //al_register_event_source(colaEventos, al_get_timer_event_source(fps));
    al_register_event_source(colaEventos, al_get_keyboard_event_source());
    //al_start_timer(fps);

    Player p1;
    Alien Enemigo;
    int x1=0;

    while(true){
        al_clear_to_color(al_map_rgb(0,0,0));
        p1.dibujar(p1.getX(), p1.getY());
        Enemigo.dibujar(x1,0);
        al_flip_display();

        x1+=10;
        if(x1>ancho){
            x1=0;}


        ALLEGRO_EVENT Evento;

        al_wait_for_event(colaEventos, &Evento);
        al_rest(0.001);

        if(Evento.type == ALLEGRO_EVENT_KEY_DOWN){
            switch(Evento.keyboard.keycode){
                case ALLEGRO_KEY_RIGHT:
                    cout<<"izquierda\n";
                    p1.move_Right();
                    break;
                case ALLEGRO_KEY_LEFT:
                    cout<<"Derecha\n";
                    p1.move_Left();
                    break;
                case ALLEGRO_KEY_UP:
                    cout<<"Arriba\n";
                    p1.move_Up();
                    break;
                case ALLEGRO_KEY_DOWN:
                    cout<<"abajo\n";
                    p1.move_Down();
                    break;
            };
        };
        al_rest(0.001);



    }
    return 0;
}
