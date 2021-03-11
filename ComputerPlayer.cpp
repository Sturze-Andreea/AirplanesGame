#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer() {
	deadPlanes = 0;
}


ComputerPlayer::~ComputerPlayer() {
	deadPlanes = 0;
}

void ComputerPlayer::addPlane(char beg[4], char end[4]) {
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

int ComputerPlayer::planesNr() {
	return table.repo.getSize();
}

void ComputerPlayer::resetPlayer() {
	table.clear();
	deadPlanes = 0;
	char hitTable[10][10] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
}

int ComputerPlayer::getStatus(char pos[4]) {
	return table.getStatus(pos);
}

char** ComputerPlayer::getTable() {
	char** x = table.getTable();
	return x;
}

char** ComputerPlayer::getHitTable() {
	char** y;
	y = new char* [10];
	for (int i = 0; i < 10; i++) {
		y[i] = new char[10];
		for (int j = 0; j < 10; j++)
			y[i][j] = this->hitTable[i][j];
	}
	return y;
}

int ComputerPlayer::otherMove(char pos[4]) {
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
	if (!(0 <= c1 and c1 <= 9 and 0 <= l1 and l1 <= 9))
		rez = -2;
	return rez;

}