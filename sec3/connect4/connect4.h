#ifndef CONNECT4_H
#define CONNECT4_H
#include <iostream>
#include <string>
using namespace std;

enum GameState{ENDED, OK, REPEAT, RED_WINS, YELLOW_WINS, TIE};
enum Player{RED, YELLOW};

string toString(GameState gs);
string toString(Player p);

class Connect4
{
	private:
		/* add your variables here */
	public:
			Connect4(Player first_player);
			void print();
			Player get_current_player();
			GameState insert_disc(int column);
};
#endif