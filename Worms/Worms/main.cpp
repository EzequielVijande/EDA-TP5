#include <iostream>
#include "allegro5\allegro.h"
#include "allegro5\allegro_primitives.h"
#include "allegro5\allegro_image.h"
#include "allegro5\allegro_font.h"
#include "allegro5\allegro_ttf.h"

#include "worm.h"
#include "Output.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main() {
	if (!al_init()) {
		return 0;
	}
	if (!al_init_primitives_addon()) {
		return 0;
	}
	if (!al_install_keyboard()) {
		return 0;
	}
	if (!al_install_keyboard()) {
		return 0;
	}

	//ALLEGRO_DISPLAY *display = al_create_display(SCREEN_WIDTH , SCREEN_HEIGHT);
	viewer view(SCREEN_WIDTH, SCREEN_HEIGHT, 1);
	if (!(view.IsInitOK()))
	{
		return -1;
	}
	ALLEGRO_DISPLAY *display = view.GetDisplay();

	ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
	ALLEGRO_TIMER *timer = al_create_timer(0.02);
	if (display == NULL || queue == NULL || timer == NULL) {
		return 0;
	}
	
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_start_timer(timer);

	Physics physics;
	physics.gravity = 0.24 * 500;
	physics.jump_angle = 60;
	physics.jump_speed = 2.4 * 50;
	physics.speed = 27;
	physics.max_coordinates.x = 800;
	physics.max_coordinates.y = 600;
	physics.min_coordinates.x = 0;
	physics.min_coordinates.y = 0;
	physics.TIME_PER_UPDATE = 0.02;

	Worm worm_test(300, 400, 1, physics , 50);
	al_set_target_backbuffer(display);

	int quit = 0;

	while (!quit) {
		ALLEGRO_EVENT ev;
		//float x1, x2, y1, y2;

		if (al_get_next_event(queue, &ev)) {
			switch (ev.type) {
				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					quit = 1;
				break;
				case ALLEGRO_EVENT_TIMER:


					
					
					worm_test.update();
					view.UpdateDisplay(&worm_test, 1);
					
					//cout << worm_test.get_move_stage_animation() << '\n';
					/*
					al_clear_to_color(al_map_rgb(255,255,255));
					Pos pos = worm_test.get_position();
					x1 = pos.x - 5;
					x2 = pos.x + 5;
					y1 = pos.y - 5;
					y2 = pos.y + 5;
					al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(0, 0, 255), 1);
					*/
					
					al_flip_display();
				break;
				case ALLEGRO_EVENT_KEY_DOWN:
					if (ev.keyboard.keycode == ALLEGRO_KEY_UP) {
						worm_test.start_jumping();
					}else if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT) {
						worm_test.start_moving(-1);
					}else if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
						worm_test.start_moving(1);
					}
				break;
				case ALLEGRO_EVENT_KEY_UP:
					if (ev.keyboard.keycode == ALLEGRO_KEY_UP) {
						worm_test.stop_jumping();
					}else if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT) {
						worm_test.stop_moving();
					}else if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
						worm_test.stop_moving();
					}
				break;
			}
		}
	}

	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
	al_shutdown_primitives_addon();
}