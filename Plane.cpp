#include "Plane.h"

Plane::Plane() {
}

Plane::Plane(char* begin, char* ending) {
	strcpy_s(beginning, strlen(begin) + 1, begin);
	strcpy_s(end, strlen(ending) + 1, ending);
}

char* Plane::getBeginning() {
	return this->beginning;
}

char* Plane::getEnd() {
	return this->end;
}

void Plane::setBeginning(char* newB) {
	strcpy_s(beginning, strlen(newB) + 1, newB);
}

void Plane::setEnd(char* newE) {
	strcpy_s(end, strlen(newE) + 1, newE);
}

Plane::~Plane() {
}

Plane& Plane::operator=(const Plane& c) {
	if (this == &c)
		return *this;
	strcpy_s(beginning, strlen(c.beginning) + 1, c.beginning);
	strcpy_s(end, strlen(c.end) + 1, c.end);
	return *this;
}

bool Plane::operator==(const Plane& c) {
	return (strcmp(beginning, c.beginning) == 0 and strcmp(end, c.end) == 0);
}