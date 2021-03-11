#pragma once
#include "Player.h"

class ComputerPlayer :public Player {
public:
	ComputerPlayer();
	int otherMove(char[4]);
	void addPlane(char[4], char[4]);
	int getStatus(char[4]);
	void resetPlayer();
	int planesNr();
	char** getTable();
	char** getHitTable();
	~ComputerPlayer();
};