#pragma once
#ifndef EVENTOS_H_
#define EVENTOS_H_

#define EVENTOS_PER_WORM 3 //move_izq, move_der, jump
//modos de los eventos
#define PRESS 1
#define LEAVE 2
enum EVENTOS { EXIT = 0, HELP, REFRESH, LEAVE_MOVEMENT, TOUCHED_MOVEMENT, LEAVE_JUMP, TOUCHED_JUMP, NO_EVENT };

//caracteres especiales para representar eventos

#define LEFT '1'
#define RIGHT '2'
#define UP '3'

#endif // EVENTOS_H_!
