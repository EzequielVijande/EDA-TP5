#include "Cevent.h"



Cevent::Cevent(eventType type_, userData ud_)
{
	type = type_;
	ud = ud_;

}

void Cevent::setEvent(char ev, int modo)
{
	bool foundedEv = false;
	if ((ev == EXIT) || (ev == HELP) || (ev == REFRESH) || (ev == NO_EVENT))
	{
		type = (int)ev;
	}
	else
	{
		for (int i = 0; i < EVENTOS_PER_WORM && (!foundedEv); i++)  //recorro los eventos validos posibles
		{
			for (int j = 0; j < 2 && (!foundedEv); j++) //j se limita por el numero de worms(en este caso 2)
			{
				if (ev == validData[j][i])
				{
					switch (i) //i me dice que evento fue, 0 representa izquierda, 1 representa derecha, 2 representa saltar
					{
					case 0:					//si se agregaran mas eventos posibles, solo bastaria con agregar mas casos al switch
					case 1:
						if (modo == PRESS)
						{
							type = TOUCHED_MOVEMENT;
						}
						else if (modo == LEAVE)
						{
							type = LEAVE_MOVEMENT;
						}
						break;
					case 2:
						if (modo == PRESS)
						{
							type = TOUCHED_JUMP;
						}
						else if (modo == LEAVE)
						{
							type = LEAVE_JUMP;
						}
						break;
					}
				}
			}

		}
		if (foundedEv)
		{
			ud = ev;
		}
		else
		{
			ud = '\0'; //significa que no hay eventos
			type = NO_EVENT;
		}
	}
}
void Cevent::setValidData(char evw1[EVENTOS_PER_WORM], char evw2[EVENTOS_PER_WORM])
{
	for (int i = 0; i < EVENTOS_PER_WORM; i++) //relleno validData
	{
		validData[0][i] = evw1[i];
	}
	for (int i = 0; i < EVENTOS_PER_WORM; i++)
	{
		validData[1][i] = evw2[i];
	}
}
int Cevent::getType(void)
{
	return type;
}
userData Cevent::getUd(void)
{
	return ud;
}

Cevent::~Cevent()
{
}
