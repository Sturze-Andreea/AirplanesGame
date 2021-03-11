#include "Table.h"
#include <iostream>
#include <string>
using namespace std;


char **Table::getTable() {
	char **y;
	y = new char* [10];
	for (int i = 0; i < 10; i++){
		y[i] = new char[10];
		for (int j = 0; j < 10; j++)
			y[i][j] = this->table[i][j];
	}
	return y;
}

void Table::add(Plane v) {
	val.validate(v, getTable());
	char beginning[4] = { ' ' };
	for (int i = 0; i < strlen(v.getBeginning()); i++)
		beginning[i] = v.getBeginning()[i];
	char ending[4] = { ' ' };
	for (int i = 0; i < strlen(v.getEnd()); i++)
		ending[i] = v.getEnd()[i];
	int c1 = beginning[0] - 65;
	int c2 = ending[0] - 65;
	int l1;
	if (beginning[1] == '1' and beginning[2] == '0')
		l1 = 9;
	else
		l1 = beginning[1] - 49;
	int l2;
	if (ending[1]=='1' and ending[2]=='0')
		l2 = 9;
	else
		l2 = ending[1] - 49;
	if (0 <= l1 and l1 <= 9 and 0 <= l2 and l2 <= 9 and 0 <= c1 and c1 <= 9 and 0 <= c2 and c2 <= 9)
	{
		if (l1 == l2 and 0<= l1-2 and l1 - 2 <= 9 and 0<=l1+2 and l1 + 2 <= 9)
		{
			if (c1 < c2 and c2 - c1 == 3)
			{
				table[l1][c1] = '*';
				for (int i = l1 - 2; i <= l1 + 2; i++)
					table[i][c1 + 1] = '#';
				table[l1][c1 + 2] = '#';
				for (int i = l1 - 1; i <= l1 + 1; i++)
					table[i][c2] = '#';
				repo.addElem(v);

			}
			else if (c1 > c2 and c1 - c2 == 3)
			{
				table[l1][c1] = '*';
				for (int i = l1 - 2; i <= l1 + 2; i++)
					table[i][c1 - 1] = '#';
				table[l1][c1 - 2] = '#';
				for (int i = l1 - 1; i <= l1 + 1; i++)
					table[i][c2] = '#';
				repo.addElem(v);

			}
		}
		if (c1 == c2 and 0<=c1-2 and c1 - 2 <= 9 and 0<=c1+2 and c1 + 2 <= 9) {
			if (l1 < l2 and l2 - l1 == 3)
			{
				table[l1][c1] = '*';
				for (int i = c1 - 2; i <= c1 + 2; i++)
					table[l1 + 1][i] = '#';
				table[l1 + 2][c1] = '#';
				for (int i = c1 - 1; i <= c1 + 1; i++)
					table[l2][i] = '#';
				repo.addElem(v);

			}
			else if (l1 > l2 and l1 - l2 == 3)
			{
				table[l1][c1] = '*';
				for (int i = c1 - 2; i <= c1 + 2; i++)
					table[l1 - 1][i] = '#';
				table[l1 - 2][c1] = '#';
				for (int i = c1 - 1; i <= c1 + 1; i++)
					table[l2][i] = '#';
				repo.addElem(v);

			}
		}
	}
}

int Table::getStatus(char pos[4]) {
	int c1 = pos[0] - 65;
	int l1;
	if (pos[1] == '1' and pos[2] == '0')
		l1 = 9;
	else
		l1 = pos[1] - 49;
	if (table[l1][c1] == '*')
		return 0;
	else if (table[l1][c1] == '#')
		return 1;
	else if (table[l1][c1] == ' ')
		return -1;
}

void Table::clear() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			table[i][j] = ' ';
	repo.clear();
}