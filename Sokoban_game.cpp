#include "Sokoban_game.h"

Sokoban_game::Sokoban_game()
{
	c_level = 0;
}
void Sokoban_game::input_level(string s)
{
	ifstream source(s.c_str());
	char c;
	if (source.fail())
		cout << "error" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			source.get(c);
			map[i][j] = int(c) - 48;
		}
		source.ignore();
	}
}
void Sokoban_game::load_sprites()
{
	switch (c_level)
	{
	case 0:
		player_t.loadFromFile("player.png", IntRect(0, 0, 32, 40));
		player_s.setTexture(player_t);
		brick_t.loadFromFile("brick 1.png");
		brick_s.setTexture(brick_t);
		box_t.loadFromFile("box 1.png");
		box_s.setTexture(box_t);
		destination_t.loadFromFile("destination 1.png");
		destination_s.setTexture(destination_t);
		floor_t.loadFromFile("floor 1.png");
		floor_s.setTexture(floor_t);
		fnt.loadFromFile("font.otf");
		txt.setFont(fnt);
		txt2.setFont(fnt);
		break;
	case 1:
		player_t.loadFromFile("player.png", IntRect(0, 0, 32, 40));
		player_s.setTexture(player_t);
		brick_t.loadFromFile("brick 2.png");
		brick_s.setTexture(brick_t);
		box_t.loadFromFile("box 2.png");
		box_s.setTexture(box_t);
		destination_t.loadFromFile("destination 2.png");
		destination_s.setTexture(destination_t);
		floor_t.loadFromFile("floor 2.png");
		floor_s.setTexture(floor_t);
		fnt.loadFromFile("font.otf");
		txt.setFont(fnt);
		txt2.setFont(fnt);
		break;
	case 2:
		player_t.loadFromFile("player.png", IntRect(0, 0, 32, 40));
		player_s.setTexture(player_t);
		brick_t.loadFromFile("brick 3.png");
		brick_s.setTexture(brick_t);
		box_t.loadFromFile("box 3.png");
		box_s.setTexture(box_t);
		destination_t.loadFromFile("destination 3.png");
		destination_s.setTexture(destination_t);
		floor_t.loadFromFile("floor 3.png");
		floor_s.setTexture(floor_t);
		fnt.loadFromFile("font.otf");
		txt.setFont(fnt);
		txt2.setFont(fnt);
		break;
	case 3:
		player_t.loadFromFile("player.png", IntRect(0, 0, 32, 40));
		player_s.setTexture(player_t);
		brick_t.loadFromFile("brick 4.png");
		brick_s.setTexture(brick_t);
		box_t.loadFromFile("box 4.png");
		box_s.setTexture(box_t);
		destination_t.loadFromFile("destination 4.png");
		destination_s.setTexture(destination_t);
		floor_t.loadFromFile("floor 4.png");
		floor_s.setTexture(floor_t);
		fnt.loadFromFile("font.otf");
		txt.setFont(fnt);
		txt2.setFont(fnt);
		break;
	case 4:
		player_t.loadFromFile("player.png", IntRect(0, 0, 32, 40));
		player_s.setTexture(player_t);
		brick_t.loadFromFile("brick 5.png");
		brick_s.setTexture(brick_t);
		box_t.loadFromFile("box 5.png");
		box_s.setTexture(box_t);
		destination_t.loadFromFile("destination 5.png");
		destination_s.setTexture(destination_t);
		floor_t.loadFromFile("floor 5.png");
		floor_s.setTexture(floor_t);
		fnt.loadFromFile("font.otf");
		txt.setFont(fnt);
		txt2.setFont(fnt);
		break;
	}

}
void Sokoban_game::draw_map()
{
	no_destinations = 0;
	window.clear(Color::Black);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (map[i][j] == player)
			{
				xplayer = i;
				yplayer = j;
				floor_s.setPosition(j*tile_size + 60, i*tile_size + 60);
				window.draw(floor_s);
				map[i][j] = floor;
			}
			else 
				if (map[i][j] == brick)
				{
					brick_s.setPosition(j*tile_size + 60, i*tile_size + 60);
					window.draw(brick_s);
				}
				else 
					if (map[i][j] == box)
					{
						box_s.setPosition(j*tile_size + 60, i*tile_size + 60);
						window.draw(box_s);
					}
					else
						if (map[i][j] == destination)
						{
							no_destinations++;
							destination_s.setPosition(j*tile_size + 60, i*tile_size + 60);
							window.draw(destination_s);
						}
						else
							if (map[i][j] == floor)
							{
								floor_s.setPosition(j*tile_size + 60, i*tile_size + 60);
								window.draw(floor_s);
							}
	player_s.setPosition(yplayer*tile_size + 60, xplayer*tile_size + 60);
	window.draw(player_s);
	txt2.setString("Use the arrows to control the player\nYou should try to place the boxes at the destinations\nPress n to move to the next level\nPress p to move to the previous level\nPress Space to restart the level\n");
	txt2.setFillColor(Color::White);
	txt2.setCharacterSize(15);
	txt2.setPosition(0, 500);
	window.draw(txt2);
	txt.setString(to_string(no_movements));
	txt.setFillColor(Color::White);
	txt.setCharacterSize(120);
	window.draw(txt);
	window.display();
}
int Sokoban_game::check_movement()
{
	while (c.getElapsedTime().asMilliseconds() < 500);
	if (Keyboard::isKeyPressed(Keyboard::Left))
		return left;
	else
		if (Keyboard::isKeyPressed(Keyboard::Right))
			return right;
		else
			if (Keyboard::isKeyPressed(Keyboard::Up))
				return up;
			else
				if (Keyboard::isKeyPressed(Keyboard::Down))
					return down;
				else
					if (Keyboard::isKeyPressed(Keyboard::P))
						return previous;
					else
						if (Keyboard::isKeyPressed(Keyboard::N))
							return next;
						else
							if (Keyboard::isKeyPressed(Keyboard::Space))
							{
								c.restart();
								window.close();
								run();
							}
							else
								return 100;
}
void Sokoban_game::update(int direction)
{
	int newx = 0, newy = 0;
	switch (direction)
	{
	case left:
		newx = 0;
		newy = -1;
		break;
	case right:
		newx = 0;
		newy = 1;
		break;
	case up:
		newx = -1;
		newy = 0;
		break;
	case down:
		newx = 1;
		newy = 0;
		break;
	case previous:
		if (c_level >= 1)
		{
			no_movements = 50;
			c_level--;
			change_level = false;
			c.restart();
		}
		break;
	case next:
		if (c_level < 4)
		{
			no_movements = 50;
			c_level++;
			change_level = false;
			c.restart();
		}
		break;
	}
	if ((newx != 0) || (newy != 0))
		if ((map[xplayer + newx][yplayer + newy] != brick) && (map[xplayer + newx][yplayer + newy] != box))
		{
			c.restart();
			no_movements--;
			xplayer = xplayer + newx;
			yplayer = yplayer + newy;
			player_s.setPosition(xplayer*tile_size + 60, yplayer*tile_size + 60);
			window.draw(player_s);
		}
		else
			if ((map[xplayer + newx][yplayer + newy] == box) && (map[xplayer + newx * 2][yplayer + newy * 2] != brick) && (map[xplayer + newx * 2][yplayer + newy * 2] != box) && (map[xplayer + newx][yplayer + newy] != player))
			{
				c.restart();
				no_movements--;
				xplayer = xplayer + newx;
				yplayer = yplayer + newy;
				map[xplayer][yplayer] = floor;
				player_s.setPosition(xplayer*tile_size + 60, yplayer*tile_size + 60);
				window.draw(player_s);
				map[xplayer + newx][yplayer + newy] = box;
			}
}
void Sokoban_game::check_conditions()
{
	if (no_destinations == 0)
	{
		window.clear(Color::Black);
		txt.setString("WINNER");
		txt.setCharacterSize(120);
		txt.setPosition(0, 0);
		window.draw(txt);
		window.display();
	}
	if (no_movements == -1)
	{
		window.clear(Color::Black);
		txt.setString("LOSER");
		txt.setCharacterSize(120);
		txt.setPosition(0, 0);
		window.draw(txt);
		window.display();
	}
}
void Sokoban_game::run()
{
	window.create(VideoMode(600, 600), "Sokoban Game");
	no_movements = 50;
	change_level = false;
	while (window.isOpen())
	{
		Event evnt;
		while(window.pollEvent(evnt))
			if ((evnt.type == evnt.Closed) || (evnt.key.code == Keyboard::Escape))
				window.close();
		if (!change_level)
		{
			input_level(level[c_level]);
			load_sprites();
			draw_map();
			change_level = true;
		}
		n = check_movement();
		if (n != 100)
		{
			update(n);
			draw_map();
			check_conditions();
		}
	}
}