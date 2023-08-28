#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
int moveP(int dir, float &x, float &y, ALLEGRO_BITMAP* pacman){
    for(int i=1;i<=15;i++){
        al_clear_to_color(al_map_rgb(0,0,0));
        al_draw_bitmap(pacman,x,y,0);
        switch(dir){
            case 1:x-=1; break;
            case 2:x+=1; break;
            case 3:y-=1; break;
            case 4:y+=1; break;}
        al_flip_display();

    }
}
using namespace std;
int main()
{
    int largo = 1024, alto = 756;
    al_init();
    al_init_image_addon();
    al_install_keyboard();

    ALLEGRO_DISPLAY* ventana = al_create_display(largo, alto); // crear un ventana de juego
    ALLEGRO_EVENT_QUEUE* colaEventos = al_create_event_queue(); //cola de eventos
    al_register_event_source(colaEventos, al_get_keyboard_event_source());

    ALLEGRO_BITMAP* pacman = al_load_bitmap("imagenes/pacman.bmp");
    ALLEGRO_BITMAP* ghostRED = al_load_bitmap("imagenes/ghostRED.bmp");
    /*ALLEGRO_BITMAP* gost2;
    */

    float x = 512;
    float y = 325;
    float gX = 0, gY = 0;
    while(true){
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(pacman,x,y,0);
    al_draw_bitmap(ghostRED,gX,gY,0);
    al_flip_display();


    ALLEGRO_EVENT Evento;
    al_wait_for_event_timed(colaEventos, &Evento,0.01);
    if(Evento.type == ALLEGRO_EVENT_KEY_DOWN){
        switch(Evento.keyboard.keycode){
            case ALLEGRO_KEY_LEFT:
                moveP(1,x,y,pacman);
                cout<<"Izquierda"<<endl;
                break;
            case ALLEGRO_KEY_RIGHT:
                moveP(2,x,y,pacman);
                cout<<"Derecha"<<endl;
                break;
            case ALLEGRO_KEY_UP:
                moveP(3,x,y,pacman);
                cout<<"Arriba"<<endl;
                break;
            case ALLEGRO_KEY_DOWN:
                moveP(4,x,y,pacman);
                cout<<"Abajo"<<endl;
                break;
        }
        cout<<"X: " <<x<<" - "<<"Y: "<<y<<endl;
    }
    if(x<28){
        x=27;
    }
    if(y<18){
        y=17;
    }
    };
    return 0;
}
