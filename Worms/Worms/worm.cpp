#include "worm.h"
#include "config.h"

enum {IDLE , MONITOR_MOVING , MOVING , END_MOVEMENT , JUMPING };

Worm::Worm(double _x, double _y, int _sentido,Physics physics) {
	frame_count = 0;
	this->pos.x = _x;
	this->pos.y = _y;
	this->sentido = _sentido;
	this->state = IDLE;
	this->physics = physics;
	this->error = 0;
}

void Worm::start_moving(int sentido) {
	if (sentido == -1 || sentido == 1) {
		this->error = 1; // this makes no sense
		return; 
	}

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
				this->state = MOVING;
			}
		break;
		case MOVING:
			this->pos.x += this->sentido * WORM_MOVEMENT_FACTOR;
			this->correct_range();
		break;
		case JUMPING:

		break;
	}
	this->frame_count++;
}
void Worm::correct_range() {
	if (this->pos.x < this->physics.min_coordinates.x) {
		this->pos.x = this->physics.min_coordinates.x;
	}
	if (this->pos.x > this->physics.max_coordinates.x) {
		this->pos.x = this->physics.max_coordinates.x;
	}
	if (this->pos.y < this->physics.min_coordinates.y) {
		this->pos.y = this->physics.min_coordinates.y;
	}
	if (this->pos.y > this->physics.max_coordinates.y) {
		this->pos.y = this->physics.max_coordinates.y;
	}
}
int Worm::get_sentido() { // 1 o -1
	return this->sentido;
}
int Worm::get_state() {
	return this->state;
}
Pos Worm::get_position() {
	return this->pos;
}