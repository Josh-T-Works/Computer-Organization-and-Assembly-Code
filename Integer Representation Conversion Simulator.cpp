#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool validBin(string); // Functions to check validity of input
bool validBit(string);
bool validDec(string);
bool validDecU(string);
bool validSizeS(int, int);
bool validSizeU(unsigned int, int);

int main() {

	cout << "-----------------------------------------------------------" << endl // Menu with directions
		<< "Welcome to the Integer Representation Conversions Software!" << endl
		<< "Type the text in quotes next to the conversion you want:" << endl
		<< "\"B2U\" : Unsigned Encoding" << endl
		<< "\"B2T\" : Two's Complement Encoding" << endl 
		<< "\"T2U\" : Two's Complement Signed to Unsigned Conversion" << endl
		<< "\"U2T\" : Unsigned to Two's Complement Signed Conversion" << endl
		<< "\"Quit\" : Quits the software" << endl
		<< "-----------------------------------------------------------" << endl;

	bool run = true;
	while (run == true)
	{
		string line = "";
		cout << endl << "Enter a command: ";
		getline(cin, line); // Gets command from menu

		if (line == "B2U" || line == "b2u") // Unsigned Encoding
		{
			bool run2 = true;
			while (run2 == true)
			{
				string num = "";
				cout << endl << "Enter a Binary Number: ";
				getline(cin, num);

				if (validBin(num))
				{
						unsigned int res = 0;
						int exp = num.size() - 1;

						for (int i = 0; i < num.size(); i++)
						{
							if (num[i] == '1') // If binary is a 1, perform step in the algorithm
							{
								res += pow(2, exp);
							}
							exp--;
						}
						cout << "Unsigned Encoding Result: " << res << endl;
						run2 = false;
				}
			}
		}
		else if (line == "B2T" || line == "b2t") // Binary to Two's
		{
			bool run2 = true;
			while (run2 == true)
			{
				string num = "";
				string bit = "";
				int w = 0;
				bool sign = true;
				int res = 0;

				cout << endl << "Enter a Binary Number: ";
				getline(cin, num);
				cout << "Enter the Word Size (in bits): ";
				getline(cin, bit);

				if (validBin(num))
				{
					if (validBit(bit))
					{
						w = stoi(bit);

						if (w > num.size() && num[0] == '1') { // Padding if word size is bigger than number 
							while (w > num.size())
							{
								num.insert(0, "1");
							}
						}
						else if (w > num.size() && num[0] == '0') { // Padding if word size is bigger than number 
							while (w > num.size())
							{
								num.insert(0, "0");
							}
						}
						if (w < num.size()) // Truncating if word size is smaller than number
						{
							while (w < num.size())
							{
								num.erase(0, 1);
							}
						}
						if (sign == true)
						{
							if (num[res] == '1') // If first number is 1, then the number is signed
							{
								res += (pow(2, w - 1) * -1);
							}
							w--;
							num.erase(0, 1);
						}
						for (int i = 0; i < num.size(); i++)
						{
							if (num[i] == '1') // If binary is a 1, perform step in the algorithm
							{
								res += pow(2, w - 1);
							}
							w--;
						}
						cout << "Two's Compliment Encoding Result: " << res << endl;
						run2 = false;
					}
				}
			}
		}
		else if (line == "T2U" || line == "t2u") // Two's to Unsigned
		{
			bool run2 = true;
			while (run2 == true)
			{
				string num = "";
				int res = 0;
				string bit = "";
				int n = 0;
				int w = 0;
				cout << endl << "Enter a Decimal Number: ";
				getline(cin, num);
				cout << "Enter the Word Size (in bits): ";
				getline(cin, bit);
				
				if (validDec(num))
				{
					if (validBit(bit))
					{
						w = stoi(bit);
						n = stoi(num);
						if (validSizeS(n, w)) // Calculates word size range
						{
							if (n >= 0)
							{
								res += n;
								cout << "Two's Complement Signed to Unsigned Conversion: " << res << endl;
								run2 = false;
							}
							else // num < 0
							{
								res += n;
								res += pow(2, w-1);
								cout << "Two's Complement Signed to Unsigned Conversion: " << res << endl;
								run2 = false;
							}
						}
					}
				}
			}
		}
		else if (line == "U2T" || line == "u2t") // Unsigned to Two's
		{
			bool run2 = true;
			while (run2 == true)
			{
				string num = "";
				int res = 0;
				string bit = "";
				unsigned int n = 0;
				int w = 0;
				cout << endl << "Enter an Unsigned Decimal Number: ";
				getline(cin, num);
				cout << "Enter the Word Size (in bits): ";
				getline(cin, bit);

				if (validDecU(num))
				{
					if (validBit(bit))
					{
						w = stoi(bit);
						n = stoi(num);
						if (validSizeU(n, w)) // Calculates valid range
						{
							int tMax = (pow(2, (w - 1)) - 1); 
							if (n <= tMax)
							{
								res += n;
								cout << "Unsigned to Two's Complement Signed Conversion: " << res << endl;
								run2 = false;
							}
							else // n > tMax
							{
								res += n;
								res += pow(2, w) * -1;
								cout << "Unsigned to Two's Complement Signed Conversion: " << res << endl;
								run2 = false;
							}
						}
					}
				}
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

	return 0;
}

bool validBin(string num) {
	for (int i = 0; i < num.size(); i++) // Checks if binary number is valid
	{
		if (num[i] == '0' || num[i] == '1')
		{
			continue;
		}
		else
		{
			cout << "Error: Invalid Binary Number";
			return false;
		}
	}
	if (num.size() <= 32)
	{
		if (num.size() != 0)
		{
			return true;
		}
		else
		{
			cout << "Error: Invalid Binary Number";
			return false;
		}
	}
	else
	{
		cout << "Error: Invalid Binary Number (Out of Range)";
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
			cout << "Error: Invalid Word Size";
			return false;
		}
	}
	if (bit.size() != 0)
	{
		if (stoi(bit) <= 32)
		{
			return true;
		}
	}
	else
	{
		cout << "Error: Invalid Word Size";
		return false;
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
				cout << "Error: Invalid Decimal Number";
				return false;
			}
		}
		else 
		{
			cout << "Error: Invalid Decimal Number";
			return false;
		}
	}
	if (num.size() != 0)
	{
		return true;
	}
	else
	{
		cout << "Error: Invalid Decimal Number";
		return false;
	}
}

bool validDecU(string num) { // Checks for valid unsigned decimal number
	for (int i = 0; i < num.size(); i++)
	{
		if (isdigit(num[i]))
		{
			continue;
		}
		else
		{
			cout << "Error: Invalid Unsigned Decimal Number";
			return false;
		}
	}
	if (num.size() != 0)
	{
		return true;
	}
	else
	{
		cout << "Error: Invalid Unsigned Decimal Number";
		return false;
	}
}

bool validSizeS(int n, int w) { // Calculates word size range
	int tMin = pow(2, (w - 1)) * -1;
	int tMax = (pow(2, (w - 1)) - 1);
	
	if (n >= tMin && n <= tMax)
	{
		return true;
	}
	else 
	{
		cout << "Error: Decimal Number not in Word Size Range";
		return false;
	}
}

bool validSizeU(unsigned int n, int w) { // Calculates word size range
	int uMax = pow(2, w) - 1;

	if (n >= 0 && n <= uMax)
	{
		return true;
	}
	else
	{
		cout << "Error: Unsigned Decimal Number not in Word Size Range";
		return false;
	}
}