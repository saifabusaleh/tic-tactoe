/*
 * Game.cpp
 *
 *  Created on: Oct 11, 2015
 *      Author: Saif
 */

#include "Game.h"
void Game::findX()
{

}
Game::Game()
{
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			table[i][j] = ' ';//empty tic-tac toe is 0
		}
	}
}
void Game::setPlayer1(string newplayer)
{
	this->player1 = newplayer;
}
void Game::setPlayer2(string newplayer2)
{
	this->player2 = newplayer2;
}
string Game::getPlayer1() const
{
	return player1;
}
string Game::getPlayer2() const
{
	return player2;
}
bool Game::checkifDone() const
{
	for(int i=0;i<SIZE;i++)
		for(int j=0;j<SIZE;j++)
			if(table[i][j] == ' ')
				return false;
	return true;
}

//player: 0 - 'x' ,,,,,,, 1  -  'y'
int Game::playIn(int x,int y,int player)
{
	if(x>SIZE || y>SIZE || x<1 || y<1)
	{
		cout<<"index out of range! " << endl;
		return 1;//FAIL
	}
	if(table[x-1][y-1] !=' ')
	{
		cout<< "you can't choose this place because its already chosen!" << endl;
		return 1;//FAIL
	}
	if(player==0)
		table[x-1][y-1] = 'x';
	else
		table[x-1][y-1] ='o';
	return 0;//SUCESS

}

void Game::printTable() const
{
	cout << "=====" << endl;
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			if(table[i][j] == ' ')
			{
				if(j<SIZE-1)
					cout<< "-"<< "|";
				else
					cout << "-";
			}
			else
			{
				if(j<SIZE-1)
					cout<< table[i][j] << "|";
				else
					cout << table[i][j];
			}
		}
		cout << endl;
	}
	cout << "=====" << endl;
}
int Game::checkWin() const
// 'x' won --> player1
// 'o' won --player 2
{
	if(table[0][0] == 'x'&& table[0][1] == 'x' && table[0][2] == 'x')
		return 1;
	if(table[1][0] == 'x'&& table[1][1] == 'x' && table[1][2] == 'x')
		return 1;
	if(table[2][0] == 'x'&& table[2][1] == 'x' && table[2][2] == 'x')
		return 1;
	if(table[0][0] == 'x'&& table[1][0] == 'x' && table[2][0] == 'x')
		return 1;
	if(table[0][1] == 'x'&& table[1][1] == 'x' && table[2][1] == 'x')
		return 1;
	if(table[0][2] == 'x'&& table[1][2] == 'x' && table[2][2] == 'x')
		return 1;
	if(table[0][0] == 'x'&& table[1][1] == 'x' && table[2][2] == 'x')
		return 1;
	if(table[0][2] == 'x'&& table[1][1] == 'x' && table[2][0] == 'x')
		return 1;


	if(table[0][0] == 'o'&& table[0][1] == 'o' && table[0][2] == 'o')
		return 2;
	if(table[1][0] == 'o'&& table[1][1] == 'o' && table[1][2] == 'o')
		return 2;
	if(table[2][0] == 'o'&& table[2][1] == 'o' && table[2][2] == 'o')
		return 2;
	if(table[0][0] == 'o'&& table[1][0] == 'o' && table[2][0] == 'o')
		return 2;
	if(table[0][1] == 'o'&& table[1][1] == 'o' && table[2][1] == 'o')
		return 2;
	if(table[0][2] == 'o'&& table[1][2] == 'o' && table[2][2] == 'o')
		return 2;
	if(table[0][0] == 'o'&& table[1][1] == 'o' && table[2][2] == 'o')
		return 2;
	if(table[0][2] == 'o'&& table[1][1] == 'x' && table[2][0] == 'o')
		return 2;

	return 0;//none won
	//returns 1 if 'x' won
	//returns 2 if 'o' won
	//return 0 if none won yet
}
int main()
{
	Game g;
	string p1,p2;
	cout << "Enter player1 name: ";
	cin >> p1;
	cout << "Enter player2 name: ";
	cin >> p2;
	g.setPlayer1(p1);
	g.setPlayer2(p2);
	cout << "Playing " << p1 << " as 'x' and " << p2 << " as 'o' " << endl;
	int x,y;

	while(true)
	{
		cout<< p1 << " play, choose location [1-3,1-3]" << endl;//x
		cin>> x;
		cin >> y;
		while(g.playIn(x,y,0)==1)
		{
			cout<< p1 << " play, choose location [1-3,1-3]" << endl;//x
			cin>> x;
			cin >> y;
		}
		g.printTable();
		int winstatus = g.checkWin();
		if(winstatus == 1)
		{
			cout<< p1 << " won, congratulations!!" << endl;
			return 0;
		}
		if(winstatus == 2)
		{
			cout<< p2 << " won, congratulations!!" << endl;
			return 0;
		}
		if(g.checkifDone() == true)//print
		{
			cout << "no one won, exiting" << endl;
			return 0;
		}

		cout << p2 << " play, choose location [1-3, 1-3]" << endl;
		cin >> x;
		cin >> y;
		while(g.playIn(x,y,1)==1)
		{
			cout << p2 << " play, choose location [1-3, 1-3]" << endl;
			cin >> x;
			cin >> y;
		}
		g.printTable();
		winstatus = g.checkWin();
		if(winstatus == 1)
		{
			cout<< p1 << " won, congratulations!!" << endl;
			return 0;
		}
		if(winstatus == 2)
		{
			cout<< p2 << " won, congratulations!!" << endl;
			return 0;
		}
		if(g.checkifDone() == true)//print
		{
			cout << "no one won, exiting" << endl;
			return 0;
		}
	}
}
