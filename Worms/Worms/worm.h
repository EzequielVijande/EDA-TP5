#ifndef WORM_H
#define WORM_H

/// We assume frame counts increments each 20 ms

struct Pos {
	double x, y;
};

struct Physics {
	float speed; // speed
	float gravity;
	float angle;
	Pos max_coordinates , min_coordinates;

};

class Worm {
	private:
		Pos pos;
		int sentido;
		int frame_count;
		int state;
		int error;
		Physics physics;

		void correct_range();
	public:
		Worm(double _x, double _y, int _sentido , Physics _physics);

		void start_moving(int sentido);
		void stop_moving();
		void start_jumping();
		void stop_jumping();
		void update();

		int get_sentido(); // 1 o -1
		int get_state();
		Pos get_position();
};

#endif //WORM_H