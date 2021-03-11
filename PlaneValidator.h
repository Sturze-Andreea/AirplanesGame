#pragma once
#include "Plane.h"
#include <list>
#include <vector>

class PlaneException {
private:
	vector<string> errors;

public:
	PlaneException(vector<string>);
	vector<string> getErrors() const;
};

class PlaneValidator {
public:
	PlaneValidator(){}
	void validate(Plane, char**);
	~PlaneValidator() {}
};