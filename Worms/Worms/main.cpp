#include<stdlib.h>
#include<iostream>
#include"worm.h"
#include"Output.h"
#include"controller.h"
#include "allegro5\allegro.h"
#include "allegro5\allegro_primitives.h"
#include "allegro5\allegro_image.h"
#include "allegro5\allegro_font.h"
#include "allegro5\allegro_ttf.h"

#define OK_RETURN 0
#define ERROR_RETURN -1

#define WORM_COUNT 2

#define FPS 50.0


using namespace std;

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 696;

void dispatch(Cevent& ev, Worm * Worms, int n_worms, viewer& view);

int main(void)
{
	int ret = OK_RETURN;
	char keysEvWorm1[EVENTOS_PER_WORM] = { 'a', 'd', 'w'};
	char keysEvWorm2[EVENTOS_PER_WORM] = { IZQ, DER, UP };

	Physics physics;
	physics.gravity = 0.24 * 500;
	physics.jump_angle = 60;
	physics.jump_speed = 2.4 * 50;
	physics.speed = 27;
	physics.max_coordinates.x = 1212;
	physics.max_coordinates.y = 800;
	physics.min_coordinates.x = 701;
	physics.min_coordinates.y = 0;
	physics.TIME_PER_UPDATE = (1.0 / FPS);

	if (!al_init())
	{
		ret = ERROR_RETURN;
	}
	Worm worms[WORM_COUNT];

	worms[0].set_keys(keysEvWorm1);
	worms[1].set_keys(keysEvWorm2);
	worms[0].set_physics(physics);
	physics.jump_angle = 30;  //al segundo worm le ponemos otro angulo de salto
	worms[1].set_physics(physics);
	cout << (worms[0].get_position().x) << endl;
	cout << (worms[0].get_move_stage_animation()) << endl;
	viewer view(SCREEN_WIDTH, SCREEN_HEIGHT, WORM_COUNT);
	if (!(view.IsInitOK()))
	{
		ret = ERROR_RETURN;
	}
	else
	{
		
		controller control(keysEvWorm1, keysEvWorm2, view.GetDisplay(), FPS);
		Cevent& ev = control.getNextEvent();
		do
		{
			ev = control.getNextEvent();
			if (ev.getType() != NO_EVENT)
			{
				
				dispatch(ev, worms, WORM_COUNT, view);
			}
		} while (ev.getType() != EXIT);
	}

	return ret;
}

void dispatch(Cevent& ev, Worm * Worms, int n_worms, viewer& view)
{
	switch (ev.getType())
	{
		case TOUCHED_MOVEMENT:
			for(int i = 0; i < n_worms; i++)
			{
				Worms[i].start_moving(ev.getUd());
			}
			break;
		case LEAVE_MOVEMENT:
			for (int i = 0; i < n_worms; i++)
			{
				Worms[i].stop_moving(ev.getUd());
			}
			break;
		case TOUCHED_JUMP:
			for (int i = 0; i < n_worms; i++)
			{
				Worms[i].start_jumping(ev.getUd());
			}
			break;
		case LEAVE_JUMP:
			for (int i = 0; i < n_worms; i++)
			{
				Worms[i].stop_jumping(ev.getUd());
			}
			break;
		case REFRESH:
			for (int i = 0; i < n_worms; i++)
			{
				Worms[i].update();
				view.UpdateDisplay(Worms, n_worms);
				view.flipViewer();
			}
			break;
		case HELP:
			cout << "HELP" << endl;
		//view.help();
	}
}

