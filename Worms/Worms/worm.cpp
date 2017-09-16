#include "worm.h"

enum {IDLE , MONITOR_MOVING , MOVING , END_MOVEMENT , JUMPING };

Worm::Worm(double _x, double _y, int _sentido,Physics physics) {
	frame_count = 0;
	this->x = _x;
	this->y = _y;
	this->sentido = _sentido;
	this->state = IDLE;
	this->physics = physics;
	this->error = 0;
}

void Worm::start_moving(int sentido) {
	if (this->state == IDLE) {
		this->state = MONITOR_MOVING;
		this->sentido = sentido;
		this->frame_count = 0;
	}else if (this->state = END_MOVEMENT) {
		this->state = MOVING;
	}else {
		this->error = 1; // this call is strange
	}
}
void Worm::stop_moving() {
	if (this->state == MOVING) {
		this->state = END_MOVEMENT;
	}else if (this->state == MONITOR_MOVING) {
		this->state = IDLE;
	}else {
		this->error = 1;
	}
}
void Worm::start_jumping() {
	if (this->state == IDLE) {
		this->state = JUMPING;
		this->frame_count = 0;
	}else {
		this->error = 1;
	}
}
void Worm::stop_jumping() {
	if (this->state == JUMPING) {
		this->state = IDLE;
	}else {
		this->error = 1;
	}
}

void Worm::update() {
	switch (this->state) {
		case MONITOR_MOVING:
			if (this->frame_count >= 5) {

			}else {
				
			}
		break;
		case MOVING:
		break;
		case JUMPING:
		break;
	}
	this->frame_count++;
}