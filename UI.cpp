#include "UI.h"
#include <windows.h>


void UI::printMenu() {
	cout << endl;
	cout << "Menu:" << endl;
	cout << "\t 1.Add" << endl;
	cout << "\t 2.Play" << endl;
	cout << "\t 3.New Game" << endl;
	cout << "\t 0.Exit" << endl;
	cout << "Choose option: ";
}

void UI::run() {
	char option;
	bool works = true;
	showTable(serv.getTable());
	while (works != false)
	{
		printMenu();
		cin >> option;
		switch (option)
		{
		case '1': {
			add();
			break;
		}
		case '2': {
			if (serv.playerPlanes()==3)
			{
				serv.createComputerTable();
				showTable(serv.getTableComp());
				play();
			}
			break;
		}
		case '3': {
			newGame();
			break;
		}
		case '0': {
			works = false;
			break;
		}
		default: {
			cout << "There is no such option." << endl;
		}
	}
	}
}

void UI::showTable(char **table) {
	int x = 1;
	char y = 'A';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	cout << "   | ";
	for (int j = 0; j < 10; j++)
	{
		cout << y << " | ";
		y += 1;
	}
	cout << endl;
	cout << "--------------------------------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5); 
		if(x==10)
			cout << x << " | ";
		else
			cout << " "<< x <<" | ";
		x++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		for (int j = 0; j < 10; j++)
			cout << table[i][j] << " | ";
		cout << endl;
		cout << "--------------------------------------------" << endl;
	}
}

void UI::add() {
	char* begin = new char[4];
	cout << "Head: ";
	cin >> begin;
	char* end = new char[4];
	cout << "End: ";
	cin >> end;
	try {
		serv.addPlane(begin, end);
	}
	catch (PlaneException e) {
		for (int i = 0; i < e.getErrors().size(); i++)
			cout << e.getErrors()[i];
	}
	char **x = serv.getTable();
	showTable(x);
}

void UI::play() {
	int option;
	bool works = true;
	while (works != false)
	{
		if (serv.winner != -1)
		{
			if (serv.winner == 0)
				cout << "You win!" << endl;
			else
				cout << "Computer wins!" << endl;
			break;
		}
		if (serv.winner == -1) {
			char* pos = new char[4];
			cout << "Position: ";
			cin >> pos;
			int rez = serv.playerTurn(pos);
			if (rez == -1)
				cout << "aer" << endl;
			else if (rez == 1)
				cout << "lovit" << endl;
			else if (rez == 0)
				cout << "distrus" << endl;
			else if (rez == -2)
			{
				cout << "Wrong position!" << endl;
				play();
				break;
			}
			serv.computerTurn();
		}
		if (serv.winner == -1) {
			cout << "Computers moves table:" << endl;
			showTable(serv.getHitComp());
		}
	}
}

void UI::newGame() {
	serv.newGame();
	showTable(serv.getTable());
}