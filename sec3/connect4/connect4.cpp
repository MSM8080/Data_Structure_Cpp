#include"connect4.h"

string toString(GameState gs)
{
	if(gs==ENDED) return "ENDED";
	if(gs==OK) return "OK";
	if(gs==REPEAT) return "REPEAT";
	if(gs==RED_WINS) return "RED_WINS";
	if(gs==YELLOW_WINS) return "YELLOW_WINS";
	if(gs==TIE) return "TIE";
	return " ";

}
string toString(Player p)
{
	if(p==RED) return "RED";
	else return "YELLOW";
}

void Connect4::print()
{
	/* add your code here to print the board */
}
Connect4::Connect4(Player first_player)
{
	/* add your code here to initalize the game */
}
Player Connect4::get_current_player()
{
	// return the player who makes the next move
}
GameState Connect4::insert_disc(int column)
{
	// insert a disc into the specified column if possible
/*
 * return values:
 * ENDED:	    game previously ended with a winner.
 * REPEAT:      No empty space in the specified column.
 *				Invalid move. Current player should try again! 
 * 				(Do not switch turns.)
 * RED_WINS:    disc inserted successfully & red wins.
 * YELLOW_WINS: disc inserted successfully & yellow wins.
 * TIE:         no empty cells avaliable & disc insertion fails.
 * OK:	        disc inserted successfully (no winner yet).
 * 
 * Note that the current player remains unchanged after winning.
*/
}