#pragma once
#include "Table.h"
#include "MyPlayer.h"
#include "ComputerPlayer.h"

class Service {
private:
	Player* myPlayer;
	Player* computerPlayer;
public:
	int winner;
	Service() { myPlayer = new MyPlayer; computerPlayer = new ComputerPlayer; winner = -1; }
	~Service(){}
	char **getTable();
	void addPlane(char[4], char[4]);
	void createComputerTable();
	int playerPlanes();
	void computerTurn();
	int playerTurn(char[4]);
	char** getTableComp();
	char** getHitComp();
	void newGame();
};