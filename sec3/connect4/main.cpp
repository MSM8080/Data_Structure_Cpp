#include<iostream>
#include"connect4.h"
using namespace std;

GameState g1[]={OK, OK, OK, OK, OK, OK, REPEAT, REPEAT, REPEAT, OK, OK, OK, OK, RED_WINS, ENDED, ENDED, ENDED};
Player p1[]={YELLOW, RED, YELLOW, RED, YELLOW, RED, RED, RED, RED, YELLOW, RED, YELLOW, RED, RED, RED, RED, RED};
GameState g2[]={OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, YELLOW_WINS, ENDED};
Player p2[]={RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, YELLOW, YELLOW};
GameState g3[]={OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, OK, TIE, TIE};
Player p3[]={RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, RED, YELLOW, YELLOW, YELLOW};


Player* ps[]={p1, p2, p3};
GameState* gs[]={g1, g2, g3};

void check(int index, GameState ggs, Player p, bool reset=false)
{
	static int count=0;
	if(reset) count=0;
	if(gs[index][count]!=ggs)
	{
		cout<<"Invalid return of insert_disc No."<<count+1<<" in C"<<index+1<<endl;
		cout<<"Expected"<<toString(gs[index][count])<<endl;
		cout<<"returned"<<toString(ggs)<<endl;
		exit(-1);
	}
	if(ps[index][count]!=p)
	{
		cout<<"Invalid current player after insert_disc No."<<count+1<<" in C"<<index+1<<endl;
		cout<<"Expected"<<toString(ps[index][count])<<endl;
		cout<<"returned"<<toString(p)<<endl;
		exit(-2);
	}
	count++;
}

int main()
{
	Connect4 c1(RED);
	GameState gs;
	Player p;
	gs=c1.insert_disc(1);p= c1.get_current_player();check(0, gs, p, true);
	gs=c1.insert_disc(1);p= c1.get_current_player();check(0, gs, p);
	gs=c1.insert_disc(1);p= c1.get_current_player();check(0, gs, p);
	gs=c1.insert_disc(1);p= c1.get_current_player();check(0, gs, p);
	gs=c1.insert_disc(1);p= c1.get_current_player();check(0, gs, p);
	gs=c1.insert_disc(1);p= c1.get_current_player();check(0, gs, p);
	gs=c1.insert_disc(1);p= c1.get_current_player();check(0, gs, p);
	gs=c1.insert_disc(1);p= c1.get_current_player();check(0, gs, p);
	gs=c1.insert_disc(1);p= c1.get_current_player();check(0, gs, p);
	gs=c1.insert_disc(2);p= c1.get_current_player();check(0, gs, p);
	gs=c1.insert_disc(2);p= c1.get_current_player();check(0, gs, p);
	gs=c1.insert_disc(3);p= c1.get_current_player();check(0, gs, p);
	gs=c1.insert_disc(3);p= c1.get_current_player();check(0, gs, p);
	gs=c1.insert_disc(4);p= c1.get_current_player();check(0, gs, p);
	gs=c1.insert_disc(4);p= c1.get_current_player();check(0, gs, p);
	gs=c1.insert_disc(4);p= c1.get_current_player();check(0, gs, p);
	gs=c1.insert_disc(4);p= c1.get_current_player();check(0, gs, p);
	c1.print();
	cout<<"c1 ENDED successfully."<<endl;

	Connect4 c2(YELLOW);
	gs=c2.insert_disc(1);p= c2.get_current_player();check(1, gs, p, true);
	gs=c2.insert_disc(1);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(1);p= c2.get_current_player();check(1, gs, p);

	gs=c2.insert_disc(2);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(2);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(2);p= c2.get_current_player();check(1, gs, p);

	gs=c2.insert_disc(4);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(4);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(5);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(4);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(4);p= c2.get_current_player();check(1, gs, p);

	gs=c2.insert_disc(5);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(6);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(5);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(6);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(5);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(5);p= c2.get_current_player();check(1, gs, p);

	gs=c2.insert_disc(3);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(3);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(6);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(3);p= c2.get_current_player();check(1, gs, p);
	gs=c2.insert_disc(3);p= c2.get_current_player();check(1, gs, p);
	c2.print();
	cout<<"c2 ENDED successfully."<<endl;

	Connect4 c3(YELLOW);
	gs=c3.insert_disc(0);p= c3.get_current_player();check(2, gs, p, true);
	gs=c3.insert_disc(0);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(0);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(0);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(0);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(0);p= c3.get_current_player();check(2, gs, p);

	gs=c3.insert_disc(1);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(1);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(1);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(1);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(1);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(1);p= c3.get_current_player();check(2, gs, p);

	gs=c3.insert_disc(6);p= c3.get_current_player();check(2, gs, p);

	gs=c3.insert_disc(2);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(2);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(2);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(2);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(2);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(2);p= c3.get_current_player();check(2, gs, p);

	gs=c3.insert_disc(3);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(3);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(3);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(3);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(3);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(3);p= c3.get_current_player();check(2, gs, p);

	gs=c3.insert_disc(6);p= c3.get_current_player();check(2, gs, p);

	gs=c3.insert_disc(4);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(4);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(4);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(4);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(4);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(4);p= c3.get_current_player();check(2, gs, p);

	gs=c3.insert_disc(5);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(5);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(5);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(5);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(5);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(5);p= c3.get_current_player();check(2, gs, p);

	gs=c3.insert_disc(6);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(6);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(6);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(6);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(6);p= c3.get_current_player();check(2, gs, p);
	gs=c3.insert_disc(6);p= c3.get_current_player();check(2, gs, p);

	c3.print();
	cout<<"c3 ENDED successfully."<<endl;
    return 0;
}