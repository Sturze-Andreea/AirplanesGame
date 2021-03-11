#include "Service.h"
#include <random>
#include "Plane.h"

char **Service::getTable() {
	char **x = myPlayer->getTable();
	return x;
}

void Service::addPlane(char beginning[4], char end[4]) {
	if (myPlayer->planesNr() < 3) {
		try {
			myPlayer->addPlane(beginning, end);
		}
		catch(PlaneException e){
			throw(e);
		}
	}
}


void Service::createComputerTable() {
	while (computerPlayer->planesNr()<3) {
		string a[] = { "B1", "C1", "D1", "E1", "F1", "G1", "H1", "I1","J1", "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2", "I2", "J2","A3", "B3", "C3", "D3", "E3","F3", "G3", "H3", "I3", "J3", "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4", "I4", "J4", "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5", "I5", "J5" , "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6", "I6", "J6" , "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7", "I7", "J7" , "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8", "I8", "J8" , "A9", "B9", "C9", "D9", "E9", "F9", "G9", "H9", "I9", "J9", "B10", "C10", "D10", "E10", "F10", "G10", "H10", "I10" };
		std::random_device rd;
		std::mt19937 eng(rd());
		std::uniform_int_distribution<> distr(0, 3);
		int i = distr(eng);
		char* beg;
		char* end;
		while (true) {
			distr = std::uniform_int_distribution<>(0, 95);
			int index1 = distr(eng);
			string pos = a[index1];
			beg = new char[pos.length() + 1];
			strcpy_s(beg, pos.length() + 1, pos.c_str());
			if (i == 0) {
				if (beg[1] != '1' and beg[1] != '2' and beg[1] != '9') {
					end = new char[strlen(beg) + 1];
					strcpy_s(end, strlen(beg) + 1, beg);
					end[0] += 3;
					break;
				}
			}
			else if (i == 1) {
				if (beg[1] != '1' and beg[1] != '2' and beg[1] != '9')
				{
					end = new char[strlen(beg) + 1];
					strcpy_s(end, strlen(beg) + 1, beg);
					end[0] -= 3;
					break;
				}
			}
			else if (i == 2) {
				if (beg[0] != 'A' and beg[0] != 'B' and beg[0] != 'I' and beg[0] != 'J') {
					end = new char[strlen(beg) + 1];
					strcpy_s(end, strlen(beg) + 1, beg);
					end[1] += 3;
					break;
				}
			}
			else {
				if (beg[0] != 'A' and beg[0] != 'B' and beg[0] != 'I' and beg[0] != 'J') {
					end = new char[strlen(beg) + 1];
					strcpy_s(end, strlen(beg) + 1, beg);
					end[1] -= 3;
					break;
				}
			}
		}
		try {
			computerPlayer->addPlane(beg, end);
		}
		catch(PlaneException){}
	}
}


int Service::playerTurn(char pos[4]) {
	int rez = -3;
	if (computerPlayer->deadPlanes == 3) {
		winner = 0;
	}
	else if (myPlayer->deadPlanes == 3)
		winner = 1;
	else {
		rez = computerPlayer->otherMove(pos);
	}
	return rez;
}

void Service::computerTurn() {
	if (myPlayer->deadPlanes == 3)
		winner = 1;
	else if (computerPlayer->deadPlanes == 3)
		winner = 0;
	else {
		char* pos;
		int l1 = 0, c1 = 0;
		string a[] = { "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1", "I1", "J1", "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2", "I2", "J2","A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3", "I3", "J3", "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4", "I4", "J4", "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5", "I5", "J5" , "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6", "I6", "J6" , "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7", "I7", "J7" , "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8", "I8", "J8" , "A9", "B9", "C9", "D9", "E9", "F9", "G9", "H9", "I9", "J9" , "A10", "B10", "C10", "D10", "E10", "F10", "G10", "H10", "I10", "J10" };
		std::random_device rd;
		std::mt19937 eng(rd());
		std::uniform_int_distribution<> distr(0, 99);
		while (true) {
			int index1 = distr(eng);
			string pos1 = a[index1];
			pos = new char[pos1.length()];
			strcpy_s(pos, pos1.length() + 1, pos1.c_str());
			c1 = pos[0] - 65;
			if (pos[1] == '1' and pos[2] == '0')
				l1 = 9;
			else
				l1 = pos[1] - 49;
			if (myPlayer->hitTable[l1][c1] != 'd' and myPlayer->hitTable[l1][c1] != 'h' and myPlayer->hitTable[l1][c1] != 'a')
			{	
				break;
			}
		}
		myPlayer->otherMove(pos);
	}
	if (computerPlayer->deadPlanes == 3) {
		winner = 0;
	}
	else if (myPlayer->deadPlanes == 3)
		winner = 1;
}


char** Service::getTableComp() {
	char** x = computerPlayer->getTable();
	return x;
}

void Service::newGame() {
	myPlayer->resetPlayer();
	computerPlayer->resetPlayer();
	winner = -1;}

char** Service::getHitComp() {
	char** y = myPlayer->getHitTable();
	return y;
}
int Service::playerPlanes() {
	return myPlayer->planesNr();
}