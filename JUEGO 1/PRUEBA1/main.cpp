#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "clases.h"
using namespace std;

int main()
{
    int ancho = 1024, largo = 756; // tamaño de la pantalla

    al_init(); // iniciar allegro
    al_init_image_addon(); // iniciar imagen
    al_install_keyboard(); // intalar el teclado


    ALLEGRO_DISPLAY* ventana = al_create_display(ancho, largo); // crear un ventana de juego
    //ALLEGRO_TIMER* fps = al_create_timer(1.0/10); // FPS (no entiendo la funcion de ALLEGRO TIMER)
    ALLEGRO_BITMAP* amongRed = al_load_bitmap("imagenes/RED.png"); // cargar imagen para usarlo luego

    ALLEGRO_EVENT_QUEUE* colaEventos = al_create_event_queue(); //cola de eventos


    //al_register_event_source(colaEventos, al_get_timer_event_source(fps));
    al_register_event_source(colaEventos, al_get_keyboard_event_source());
    //creo que regrista los eventos en la cola (no entiendo como funciona)

    //al_start_timer(fps);

    Player p1; // jugador
    Alien Enemigo; // enemigo
    int x1=0; // contador

    while(true){
        al_clear_to_color(al_map_rgb(0,0,0)); // limpia la pantalla
        p1.dibujar(p1.getX(), p1.getY()); // funcion para dibujar el jugador
        //p1.getX() -> obtener la posicion en x
        //p1.getY() -> obtener la posicion en y
        Enemigo.dibujar(x1,0); // dibujar enemigo
        al_flip_display(); // dibujar las imagens en pantalla

        x1+=10;// contador
        if(x1>ancho){
            x1=0;}


        ALLEGRO_EVENT Evento; // eventos

        al_wait_for_event(colaEventos, &Evento); // esperar por evento
        al_rest(0.001);//esperar

        if(Evento.type == ALLEGRO_EVENT_KEY_DOWN){ /// si el tipo de evento == tecla abajo
            switch(Evento.keyboard.keycode){
                case ALLEGRO_KEY_RIGHT: /// izquierda
                    cout<<"izquierda\n";
                    p1.move_Right();
                    break;
                case ALLEGRO_KEY_LEFT:/// derecha
                    cout<<"Derecha\n";
                    p1.move_Left();
                    break;
                case ALLEGRO_KEY_UP:/// arriba
                    cout<<"Arriba\n";
                    p1.move_Up();
                    break;
                case ALLEGRO_KEY_DOWN:/// abajo
                    cout<<"abajo\n";
                    p1.move_Down();
                    break;
            };
        };
        al_rest(0.001);



    }
    return 0;
}
