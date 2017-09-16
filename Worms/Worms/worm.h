#ifndef WORM_H
#define WORM_H

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
		float x, y;
		int sentido;
		int frame_count;
		int state;
		int error;
		Physics physics;
	public:
		Worm(double _x, double _y, int _sentido , Physics _physics);

		void start_moving(int sentido);
		void stop_moving();
		void start_jumping();
		void stop_jumping();
		void update();
};

#endif //WORM_H