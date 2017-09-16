#include "output.h"

bool InitializeAllegroOutput(void);
//Inicializa los  addons necesarios de allegro para
//utilizar el modulo de output.


ALLEGRO_BITMAP * load_image_at_size(char* image_name, int size_x, int size_y);
//Devuelve el bitmap de la imagen cargada en el tamano deseado.
//En caso de error devuelve NULL.

void destroy_images(ALLEGRO_BITMAP  **imagen, unsigned int num_imagenes);
//Libera toda la memoria utilizada por las imagenes creadas.


viewer::viewer(unsigned int height_, unsigned int width_)
{
	height = height_;
	width = width_;
	char* jump_path[J_FRAMES] = {J_F0, J_F1, J_F2, J_F3, J_F4, J_F5, J_F6, J_F7, J_F8, J_F9}; //Paths de las imagenes de jump
	char* walk_path[W_FRAMES] = {W_F0, W_F1, W_F2, W_F3, W_F4, W_F5, W_F6, W_F7, W_F8, W_F9, W_F10, W_F11, W_F12, W_F13, W_F14}; //paths de las imagenes de walk

	init = InitializeAllegroOutput();
	if (init)
	{
		init = InitializeResources(BACKGROUND_PATH, jump_path, walk_path);
	}

}

viewer:: ~viewer()
{
	if (init)
	{
		al_destroy_bitmap(background);
		destroy_images(worm_jump, J_FRAMES);
		destroy_images(worm_walk, W_FRAMES);
		al_destroy_display(display);
		
	}
}

bool viewer::IsInitOK(void)
{
	return init;
}

void viewer::UpdateDisplay(Worm* worms, unsigned int worm_count)
{
	ALLEGRO_BITMAP* current_target = al_get_target_bitmap(); //guarda el target actual para no perderlo.

	al_set_target_backbuffer(display);
	al_draw_bitmap(background, 0.0, 0.0, 0);
	unsigned int offset = 0;
	double direction = 0.0;
	for (unsigned int i = 0; i < worm_count; i++)
	{
		

	}

	al_set_target_bitmap(current_target);
}


bool InitializeAllegroOutput(void)
{
	if (!al_init_image_addon())
	{
		return false;
	}
	
	return true;
}
ALLEGRO_DISPLAY* viewer::GetDisplay(void)
{
	return display;
}

bool viewer::InitializeResources(char* b_image, char** worm_jumps, char** worm_walks)
{
	display = al_create_display(width*(UNIT), height*(UNIT));
	if (display == NULL)
	{
		return false;
	}


	background = load_image_at_size(b_image, width*(UNIT), height*(UNIT)); //crea el bitmap con el background
	if (background == nullptr)
	{
		al_destroy_display(display);
		return false;
	}
	for (unsigned int i = 0; i < W_FRAMES; i++) //Crea los bitmaps con los frames del worm walk.
	{
		worm_walk[i] = load_image_at_size(worm_walks[i], WORM_SIZE, WORM_SIZE);
		if ((worm_walk[i]) == nullptr)
		{
			al_destroy_display(display);
			al_destroy_bitmap(background);
			destroy_images(worm_walk, i);
			return false;
		}
	}

	for (unsigned int i = 0; i < J_FRAMES; i++) //Crea los bitmaps con los frames del worm jump.
	{
		worm_jump[i] = load_image_at_size(worm_jumps[i], WORM_SIZE, WORM_SIZE);
		if ((worm_jump[i]) == nullptr)
		{
			al_destroy_display(display);
			al_destroy_bitmap(background);
			destroy_images(worm_walk, W_FRAMES);
			destroy_images(worm_jump, i);
			return false;
		}
	}

	return true;

}

void destroy_images(ALLEGRO_BITMAP  **imagen, unsigned int num_imagenes)
{
	unsigned int i;
	for (i = 0; i<num_imagenes; i++)
	{
		al_destroy_bitmap(imagen[i]);
	}
}

ALLEGRO_BITMAP * load_image_at_size(char* image_name, int size_x, int size_y)
{
	ALLEGRO_BITMAP * image = nullptr;
	ALLEGRO_BITMAP * current_target = nullptr;
	ALLEGRO_BITMAP * resized_image = nullptr;

	current_target = al_get_target_bitmap(); //salva el target original para no perderlo

	image = al_load_bitmap(image_name);
	if (image == NULL)
	{
		return nullptr;
	}

	resized_image = al_create_bitmap(size_x, size_y);
	if (resized_image == NULL)
	{
		al_destroy_bitmap(image);
		return nullptr;


	}

	al_set_target_bitmap(resized_image);
	al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image),
		0, 0, size_x, size_y, 0);

	al_set_target_bitmap(current_target); //vuelve al target original
	al_destroy_bitmap(image);
	return resized_image;
}
