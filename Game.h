/*
 * Game.h
 *
 *  Created on: Oct 11, 2015
 *      Author: Saifl
 */

#ifndef GAME_H_
#define GAME_H_
using namespace std;
#include <iostream>
#include <cstring>
class Game {
	string player1;
	string player2;
	enum {SIZE=3} ;
	char table[SIZE][SIZE];
public:
	Game();
	void findX();
	void setPlayer1(string );
	void setPlayer2(string );
	string getPlayer1() const;
	string getPlayer2() const;
	bool checkifDone() const;
	int playIn(int,int,int);
	void printTable()const;
	int checkWin() const;
};

#endif /* GAME_H_ */
//tEST
