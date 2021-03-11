#include "PlaneValidator.h"
using namespace std;

PlaneException::PlaneException(vector<string> _errors) : errors{ _errors }
{
}

vector<string> PlaneException::getErrors() const
{
	return this->errors;
}

void PlaneValidator::validate(Plane s, char** table)
{
	vector<string> errors;
	char beginning[4] = { ' ' };
	for (int i = 0; i < strlen(s.getBeginning()); i++)
		beginning[i] = s.getBeginning()[i];
	char ending[4];
	for (int i = 0; i < strlen(s.getEnd()); i++)
		ending[i] = s.getEnd()[i];
	int c1 = beginning[0] - 65;
	int c2 = ending[0] - 65;
	int l1;
	if (beginning[1] == '1' and beginning[2] == '0')
		l1 = 9;
	else
		l1 = beginning[1] - 49;
	int l2;
	if (ending[1] == '1' and ending[2] == '0')
		l2 = 9;
	else
		l2 = ending[1] - 49;
	if (0 > l1 or 0 > l2 or 0 > c1 or 0 > c2 or 9 < l1 or 9 < l2 or 9 < c1 or 9 < c2)
		errors.push_back("You can't add a plane in that position!\n");
	else {
		bool ok = true;
		if (l1 == l2 and 0 <= l1 - 2 and l1 - 2 <= 9 and 0 <= l1 + 2 and l1 + 2 <= 9)
		{
			if (c1 < c2 and c2 - c1 == 3)
			{
				if (table[l1][c1] != ' ')
					ok = false;
				for (int i = l1 - 2; i <= l1 + 2; i++)
					if (table[i][c1 + 1] != ' ')
						ok = false;
				if (table[l1][c1 + 2] != ' ')
					ok = false;
				for (int i = l1 - 1; i <= l1 + 1; i++)
					if (table[i][c2] != ' ')
						ok = false;

			}
			else if (c1 > c2 and c1 - c2 == 3)
			{
				if (table[l1][c1] != ' ')
					ok = false;
				for (int i = l1 - 2; i <= l1 + 2; i++)
					if (table[i][c1 - 1] != ' ')
						ok = false;
				if (table[l1][c1 - 2] != ' ')
					ok = false;
				for (int i = l1 - 1; i <= l1 + 1; i++)
					if (table[i][c2] != ' ')
						ok = false;

			}
			else
				ok = false;
		}
		else if (c1 == c2 and 0 <= c1 - 2 and c1 - 2 <= 9 and 0 <= c1 + 2 and c1 + 2 <= 9) {
			if (l1 < l2 and l2 - l1 == 3)
			{
				if (table[l1][c1] != ' ')
					ok = false;
				for (int i = c1 - 2; i <= c1 + 2; i++)
					if (table[l1 + 1][i] != ' ')
						ok = false;
				if (table[l1 + 2][c1] != ' ')
					ok = false;
				for (int i = c1 - 1; i <= c1 + 1; i++)
					if (table[l2][i] != ' ')
						ok = false;

			}
			else if (l1 > l2 and l1 - l2 == 3)
			{
				if (table[l1][c1] != ' ')
					ok = false;
				for (int i = c1 - 2; i <= c1 + 2; i++)
					if (table[l1 - 1][i] != ' ')
						ok = false;
				if (table[l1 - 2][c1] != ' ')
					ok = false;
				for (int i = c1 - 1; i <= c1 + 1; i++)
					if (table[l2][i] != ' ')
						ok = false;

			}
			else
				ok = false;
		}
		else 
			errors.push_back("You can't add a plane in that position!\n");
		if (ok == false)
			errors.push_back("You can't add a plane in that position!\n");
	}
	if (errors.size() > 0)
		throw PlaneException(errors);
}