#pragma once
#ifndef CEVENT_H_
#define CEVENT_H_

#include "eventos.h"

typedef int eventType;
typedef char userData;


class Cevent
{
public:
	Cevent(eventType type_ = NO_EVENT, userData ud_ = '\0');
	~Cevent();
	void setEvent(char ev, int modo);
	void setValidData(char evw1[EVENTOS_PER_WORM], char evw2[EVENTOS_PER_WORM]);
	int getType(void);
	userData getUd(void);

private:
	eventType type;
	userData ud;
	//datos válidos
	char validData[2][EVENTOS_PER_WORM];
};


#endif // CEVENT_H_!

