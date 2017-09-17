#include<stdlib.h>
#include<iostream>
#include"worm.h"
#include"Output.h"
#include"controller.h"

#define OK_RETURN 0
#define ERROR_RETURN -1

#define WORM_COUNT 2

#define FPS 50


using namespace std;

void dispatch(Cevent& ev);

int main(void)
{
	int ret = OK_RETURN;
	char keysEvWorm1[EVENTOS_PER_WORM] = { 'a', 'd', 'w' };
	char keysEvWorm2[EVENTOS_PER_WORM] = { LEFT, RIGHT, UP };

	if (!al_init())
	{
		ret = ERROR_RETURN;
	}
	Worm worms[WORM_COUNT];
	viewer view(1200, 1080);
	controller control(keysEvWorm1, keysEvWorm2, view.GetDisplay(),FPS);
	Cevent& ev = control.getNextEvent();
	if (ev.getType() != NO_EVENT)
	{
		dispatch(ev);
	}
	return ret;
}

void dispatch(Cevent& ev)
{
	/*switch (ev.getType())
	{
		case TOUCHED_MOVEMENT:
			for(int i = 0; i < WORM_COUNT; i++)
			{
				Worms[i].startMoving(ev.getUd());
			}
			break;
		case LEAVE_MOVEMENT:
			for (int i = 0; i < WORM_COUNT; i++)
			{
				Worms[i].stopMoving(ev.getUd());
			}
			break;
		case TOUCHED_JUMP:
			for (int i = 0; i < WORM_COUNT; i++)
			{
				Worms[i].startJumping(ev.getUd());
			}
			break;
		case LEAVE_JUMP:
			for (int i = 0; i < WORM_COUNT; i++)
			{
				Worms[i].stopJumping(ev.getUd());
			}
			break;
		case REFRESH:
			for (int i = 0; i < WORM_COUNT; i++)
			{
				Worms[i].update();
			}
			break;
		case HELP:
			cout << "HELP" << endl;
		
	}*/
}

