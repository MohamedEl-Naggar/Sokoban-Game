#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
using namespace sf;
using namespace std;

class Sokoban_game
{
private:
	string level[5] = { "level 1.txt", "level 2.txt", "level 3.txt", "level 4.txt", "level 5.txt" };
	enum directions { left, right, up, down, previous, next, restart };
	enum objects { player, brick, box, destination, floor, space };
	int xplayer, yplayer, no_destinations, no_movements, n, c_level = 0;
	Clock c;
	const int size = 12, tile_size = 40;
	int map[12][12];
	Sprite player_s, brick_s, box_s, destination_s, floor_s;
	Texture player_t, brick_t, box_t, destination_t, floor_t;
	Text txt, txt2;
	Font fnt;
	bool change_level;
	RenderWindow window;
public:
	Sokoban_game();
	void input_level(string);
	void load_sprites();
	void draw_map();
	int check_movement();
	void update(int);
	void check_conditions();
	void run();
};