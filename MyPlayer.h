#pragma once
#include "Player.h"

class MyPlayer :public Player {
public:
	MyPlayer();
	int otherMove(char[4]);
	void addPlane(char[4], char[4]);
	int getStatus(char[4]);
	void resetPlayer();
	int planesNr();
	char** getTable();
	char** getHitTable();
	~MyPlayer();
};