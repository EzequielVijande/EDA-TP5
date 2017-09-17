#include "controller.h"



controller:: controller(char evw1[EVENTOS_PER_WORM], char evw2[EVENTOS_PER_WORM], ALLEGRO_DISPLAY * display, int fps_)
{
	fps = fps_;
	timer = al_create_timer(1.0 / fps);
	ev.setValidData(evw1, evw2);
	al_install_mouse();
	al_install_keyboard();
	cola = al_create_event_queue();
	al_register_event_source(cola, al_get_display_event_source(display));
	al_register_event_source(cola, al_get_keyboard_event_source());
	al_start_timer(timer);

}

Cevent& controller::getNextEvent(void)
{
	if (al_get_next_event(cola, &al_ev))
	{
		if (al_ev.type == ALLEGRO_EVENT_TIMER)
		{
			ev.setEvent(REFRESH, 0);
		}
		else if (al_ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			ev.setEvent(EXIT, 0);
		}
		else if (al_ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			if (al_ev.keyboard.keycode == ALLEGRO_KEY_LEFT)
			{
				ev.setEvent(LEFT, LEAVE);
			}
			else if (al_ev.keyboard.keycode == ALLEGRO_KEY_RIGHT)
			{
				ev.setEvent(RIGHT, LEAVE);
			}
			else if (al_ev.keyboard.keycode == ALLEGRO_KEY_UP)
			{
				ev.setEvent(UP, LEAVE);
			}
			else
			{
				ev.setEvent(al_ev.keyboard.unichar, LEAVE);
			}
		}
		else if (al_ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (al_ev.keyboard.keycode == ALLEGRO_KEY_H)
			{
				ev.setEvent(HELP, 0);
			}
			else if (al_ev.keyboard.keycode == ALLEGRO_KEY_LEFT)
			{
				ev.setEvent(LEFT, PRESS);
			}
			else if (al_ev.keyboard.keycode == ALLEGRO_KEY_RIGHT)
			{
				ev.setEvent(RIGHT, PRESS);
			}
			else if (al_ev.keyboard.keycode == ALLEGRO_KEY_UP)
			{
				ev.setEvent(UP, PRESS);
			}
			else
			{
				ev.setEvent(al_ev.keyboard.unichar, PRESS);
			}
			
		}
		else
		{
			ev.setEvent(NO_EVENT, 0);
		}
	}
	return ev;
}

controller::~controller()
{

}
