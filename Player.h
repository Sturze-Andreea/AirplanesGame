#pragma once
#include "Table.h"

class Player {
protected:
	Table table;
public:
	char hitTable[10][10]= { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };;
	int deadPlanes;
	Player();
	~Player();
	virtual int getStatus(char[4]) = 0;
	virtual void resetPlayer() = 0;
	virtual int otherMove(char[4]) = 0;
	virtual char** getTable() = 0;
	virtual char** getHitTable() = 0;
	virtual int planesNr() = 0;
	virtual void addPlane(char[4], char[4]) = 0;
};