
#ifndef OUTPUT_H
#define OUTPUT_H
//Este modulo asume que ya se incializo exitosamente Allegro.

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_color.h>


#define WORM_SIZE 40
#define UNIT 10
#define J_FRAMES 10
#define W_FRAMES 15
class viewer //Se ocupa de todo lo relacionado con el output de la simulacion
{
public:
	viewer(unsigned int height_, unsigned int width_);
	~viewer();
	void UpdateDisplay(worm* worms, unsigned int worm_count);
	bool IsInitOK(void);				//deveulve true si todos los recursos se crearon exitosamente.
	ALLEGRO_DISPLAY* GetDisplay(void);

private:

	unsigned int height;
	unsigned int width;
	ALLEGRO_DISPLAY * display;
	ALLEGRO_BITMAP* background;
	ALLEGRO_BITMAP* worm_jump[J_FRAMES]; //guarda los bitmaps con las imagenes correspondientes al salto
	ALLEGRO_BITMAP* worm_walk[W_FRAMES]; //guarda los bitmaps con las imagenes correspondientes al desplazamiento en tierra.
	bool init; //indica si hubo o no error en la inicializacion.
	bool InitializeResources(char* image, char** worms, unsigned int n_worms);

};

#endif //OUTPUT_H