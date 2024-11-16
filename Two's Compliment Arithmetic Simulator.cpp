#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool validDec(string);
bool validDec2(string);
bool validBit(string);
bool validSize(int, int);
bool validPow(string);

int main()
{
	cout << "-------------------------------------------------------" << endl // Menu with directions
		<< "Welcome to the Integer Arithmetic Software!" << endl
		<< "Type the text in quotes next to the operation you want:" << endl
		<< "\"TCA\" : Two's Complement Addition" << endl
		<< "\"TCN\" : Two's Complement Negation" << endl
		<< "\"TCM\" : Two's Complement Multiplication" << endl
		<< "\"TCD\" : Two's Complement Division" << endl
		<< "\"Quit\" : Quits the software" << endl
		<< "--------------------------------------------------------" << endl;

	bool run = true;
	while (run == true)
	{
		string line = "";
		cout << endl << "Enter a command: ";
		getline(cin, line); // Gets command from menu

		if (line == "TCA" || line == "tca") // addition
		{
			bool run2 = true;
			while (run2 == true)
			{
				string num = "";
				string num2 = "";
				string bit = "";
				cout << endl << "Enter first decimal number: ";
				getline(cin, num);
				cout << "Enter second decimal number: ";
				getline(cin, num2);
				cout << "Enter the Word Size (in bits): ";
				getline(cin, bit);

				if (validDec(num))
				{
					if (validDec(num2))
					{
						if (validBit(bit))
						{
							int a = stoi(num);
							int b = stoi(num2);
							int w = stoi(bit);

							if (a >= (pow(2, w - 1) * -1) && b <= (pow(2, w - 1) - 1))
							{
								int res = a + b;

								if (res >= (pow(2, w - 1) * -1) && res < pow(2, w - 1)) // normal
								{
									cout << "Two's Complement Addition Result: " << res << endl;
									run2 = false;
								}
								else if (res >= pow(2, w - 1)) // positive overflow
								{
									res = res - pow(2, w);
									cout << "Two's Complement Addition Result: " << res << endl;
									run2 = false;
								}
								else // negative overflow
								{
									res = res + pow(2, w);
									cout << "Two's Complement Addition Result: " << res << endl;
									run2 = false;
								}
							}
							else cout << "Error: Invalid Decimal Numbers (Out of Range)";
						}
						else cout << "Error: Invalid Word Size";
					}
					else cout << "Error: Invalid Second Decimal Number";
				}
				else cout << "Error: Invalid First Decimal Number";
			}
		}
		else if (line == "TCN" || line == "tcn") // negation
		{
			bool run2 = true;
			while (run2 == true)
			{
				string num = "";
				string bit = "";
				cout << endl << "Enter a decimal number: ";
				getline(cin, num);
				cout << "Enter the word size (in bits): ";
				getline(cin, bit);

				if (validDec(num))
				{
					if (validBit(bit))
					{
						int n = stoi(num);
						int w = stoi(bit);
						if (validSize(n, w))
						{
							if (n == pow(2, (w - 1)) * -1) // n = tmin
							{
								cout << "Two's Complement Negation Result: " << n << endl;
								run2 = false;
							}
							else // n > tmin
							{
								cout << "Two's Complement Negation Result: " << (n * -1) << endl;
								run2 = false;
							}
						}
						else cout << "Error: Decimal Number Not In Word Size Range";
					}
					else cout << "Error: Invalid Word Size";
				}
				else cout << "Error: Invalid Decimal Number";
			}
		}
		else if (line == "TCM" || line == "tcm") // multiplication
		{
			bool run2 = true;
			while (run2 == true)
			{
				string num = "";
				string num2 = "";
				string bit = "";
				cout << endl << "Enter first decimal number: ";
				getline(cin, num);
				cout << "Enter second decimal number: ";
				getline(cin, num2);
				cout << "Enter the Word Size (in bits): ";
				getline(cin, bit);

				if (validDec(num))
				{
					if (validDec(num2))
					{
						if (validBit(bit))
						{
							int a = stoi(num);
							int b = stoi(num2);
							int w = stoi(bit);
							int tMin = pow(2, (w - 1)) * -1;
							int tMax = pow(2, (w - 1)) - 1;

							if (a >= tMin && a <= tMax && b >= tMin && b <= tMax)
							{
								int mod = pow(2, w);
								int res = (a * b) % mod;
								int res2 = 0;

								if (res <= tMax)
								{
									res2 += res;
									cout << "Two's Complement Multiplication Result: " << res2 << endl;
									run2 = false;
								}
								else // res > tMax
								{
									res2 += res;
									res2 += pow(2, w) * -1;
									cout << "Two's Complement Multiplication Result: " << res2 << endl;
									run2 = false;
								}
							}
							else cout << "Error: Invalid Decimal Numbers (Out of Range)";
						}
						else cout << "Error: Invalid Word Size";
					}
					else cout << "Error: Invalid Second Decimal Number";
				}
				else cout << "Error: Invalid First Decimal Number";
			}
		}
		else if (line == "TCD" || line == "tcd") // division
		{
			bool run2 = true;
			while (run2 == true)
			{
				string num = "";
				string power = "";
				string bit = "";
				cout << endl << "Enter the decimal number: ";
				getline(cin, num);
				cout << "Enter the power of 2 to divide by: ";
				getline(cin, power);
				cout << "Enter the Word Size (in bits): ";
				getline(cin, bit);

				if (validDec(num))
				{
					if (validPow(power))
					{
						if (validBit(bit))
						{
							int x = stoi(num);
							int k = stoi(power);
							int w = stoi(bit);

							if (0 <= k && k < w)
							{
								
								if (x >= 0) // positive
								{
									cout << "Two's Complement Division Result: " << (x >> k) << endl; 
									run2 = false;
								}
								else // negative
								{
									cout << "Two's Complement Division Result: " << ((x + (1 << k) - 1) >> k) << endl;
									run2 = false;
								}
							}
							else cout << "Error: Invalid Power Number (Out of Range)";
						}
						else cout << "Error: Invalid Word Size";
					}
					else cout << "Error: Invalid Power Number";
				}
				else cout << "Error: Invalid Decimal Number";
			}
		}
		else if (line == "Quit" || line == "quit") // Checks if user wants to quit
		{
			cout << endl << "*** You have quit the program. ***" << endl;
			run = false;
		}
		else
		{
			cout << "Error: Invalid Command";
		}
	}
}

bool validDec(string num) { // Checks for valid decimal number
	for (int i = 0; i < num.size(); i++)
	{
		if (isdigit(num[i]))
		{
			continue;
		}
		else if (num[i] == '-')
		{
			if (i == 0)
			{
				continue;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	if (num.size() != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool validBit(string bit) { // Checks for valid word size
	for (int i = 0; i < bit.size(); i++)
	{
		if (isdigit(bit[i]))
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	if (bit.size() != 0)
	{
		if (stoi(bit) <= 32 && stoi(bit) != 0)
		{
			return true;
		}
		else return false;
	}
	else
	{
		return false;
	}
}

bool validSize(int n, int w) { // Calculates word size range
	int tMin = pow(2, (w - 1)) * -1;
	int tMax = (pow(2, (w - 1)) - 1);

	if (n >= tMin && n <= tMax)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool validPow(string p) { // Checks for valid power value
	for (int i = 0; i < p.size(); i++)
	{
		if (isdigit(p[i]))
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}