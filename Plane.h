#pragma once
#include <iostream>
using namespace std;

class Plane {
private:
	char beginning[4];
	char end[4];
public:
	Plane();
	Plane(char*, char*);
	~Plane();
	char* getBeginning();
	char* getEnd();
	void setBeginning(char*);
	void setEnd(char*);
	Plane& operator=(const Plane&);
	bool operator==(const Plane&);
};