#pragma once
#include "Plane.h"
#include "RepoTemplate.h"
#include "PlaneValidator.h"

class Table {
private:
	PlaneValidator val;
	char table[10][10] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
public:
	RepoTemplate<Plane> repo;
	Table() {}
	~Table(){}
	char **getTable();
	void add(Plane);
	int getStatus(char[4]);
	void clear();
};