#ifndef WORM_H
#define WORM_H

#define LEFT -1
#define RIGHT 1

enum { IDLE, MONITOR_MOVING, MOVING, END_MOVEMENT, JUMPING, MONITOR_JUMPING };

//// We as

struct Pos {
	double x, y;
};

struct Physics {
	float speed; // speed
	float jump_speed;
	float jump_angle;
	float gravity;
	Pos max_coordinates , min_coordinates;

	float TIME_PER_UPDATE;
};

class Worm {
	private:
		Pos pos , original_pos;
		int sentido;
		int frame_count;
		int state;
		int error;
		Physics physics;

		int move_stage;
		int jump_stage;

		int jump_stage_period;
		int move_stage_period;

		void correct_range();
		void update_jump_period();
	public:
		Worm(double _x, double _y, int _sentido, Physics physics, int move_stage_period);

		void start_moving(int sentido);
		void stop_moving();
		void start_jumping();
		void stop_jumping();

		void update();

		int get_sentido(); // 1 o -1
		int get_state();
		Pos get_position();
		Pos get_original_position();
		int get_jump_stage_animation();
		int get_move_stage_animation();
		int get_if_error();
};

#endif //WORM_H