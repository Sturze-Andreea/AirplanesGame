#include "MyPlayer.h"

MyPlayer::MyPlayer() {
	deadPlanes = 0;
}


MyPlayer::~MyPlayer() {
	deadPlanes = 0;
}

void MyPlayer::addPlane(char beg[4], char end[4]) {
	if (planesNr() < 3) {
		char* b = new char[4];
		for (int i = 0; i < 4; i++)
			b[i] = beg[i];
		char* e = new char[4];
		for (int i = 0; i < 4; i++)
			e[i] = end[i];
		Plane v(b, e);
		delete[] b, e;
		try {
			table.add(v);
		}
		catch (PlaneException e) {
			throw(e);
		}
	}
}

int MyPlayer::planesNr() {
	return table.repo.getSize();
}

void MyPlayer::resetPlayer() {
	table.clear();
	deadPlanes = 0;
	char hitTable[10][10] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
}

int MyPlayer::getStatus(char pos[4]) {
	return table.getStatus(pos);
}

char** MyPlayer::getTable() {
	char** x = table.getTable();
	return x;
}

char** MyPlayer::getHitTable() {
	char** y;
	y = new char* [10];
	for (int i = 0; i < 10; i++) {
		y[i] = new char[10];
		for (int j = 0; j < 10; j++)
			y[i][j] = this->hitTable[i][j];
	}
	return y;
}

int MyPlayer::otherMove(char pos[4]) {
	int rez = getStatus(pos);
	int c1 = pos[0] - 65;
	int l1;
	if (pos[1] == '1' and pos[2] == '0')
		l1 = 9;
	else
		l1 = pos[1] - 49;
	if (rez == 0)
	{
		if (hitTable[l1][c1] != 'd')
			deadPlanes++;
		hitTable[l1][c1] = 'd';
	}
	else if (rez == 1)
		hitTable[l1][c1] = 'h';
	else if (rez == -1)
		hitTable[l1][c1] = 'a';
	return rez;
	
}