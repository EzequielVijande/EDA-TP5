#include<allegro5\allegro.h>
#include<stdlib.h>
#include<iostream>
#include"worm.h"
#include"Output.h"

using namespace std;

int main(void)
{
	if (!al_init())
	{
		return -1;
	}

	viewer view(70, 100);
	if (view.IsInitOK())
	{
		al_flip_display();
		al_rest(5);
	}
	
	return 0;
}