// INFORMATION STORAGE CONVERSIONS - BY JOSH THOMAS

#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <stack>

using namespace std;

bool run = true;

map<char, string> HexBi = { // Map for Hex to Bi
	{'0', "0000"},
	{'1', "0001"},
	{'2', "0010"},
	{'3', "0011"},
	{'4', "0100"},
	{'5', "0101"},
	{'6', "0110"},
	{'7', "0111"},
	{'8', "1000"},
	{'9', "1001"},
	{'A', "1010"},
	{'a', "1010"},
	{'B', "1011"},
	{'b', "1011"},
	{'C', "1100"},
	{'c', "1100"},
	{'D', "1101"},
	{'d', "1101"},
	{'E', "1110"},
	{'e', "1110"},
	{'F', "1111"},
	{'f', "1111"}
};

map<string, char> BiHex = { // Map for Bi to Hex
	{"0000", '0'},
	{"0001", '1'},
	{"0010", '2'},
	{"0011", '3'},
	{"0100", '4'},
	{"0101", '5'},
	{"0110", '6'},
	{"0111", '7'},
	{"1000", '8'},
	{"1001", '9'},
	{"1010", 'A'},
	{"1011", 'B'},
	{"1100", 'C'},
	{"1101", 'D'},
	{"1110", 'E'},
	{"1111", 'F'}
};

map<char, int> HexDec = { // Map for Hex to Dec
	{'0', 0},
	{'1', 1},
	{'2', 2},
	{'3', 3},
	{'4', 4},
	{'5', 5},
	{'6', 6},
	{'7', 7},
	{'8', 8},
	{'9', 9},
	{'A', 10},
	{'a', 10},
	{'B', 11},
	{'b', 11},
	{'C', 12},
	{'c', 12},
	{'D', 13},
	{'d', 13},
	{'E', 14},
	{'e', 14},
	{'F', 15},
	{'f', 15}
};

map<int, char> DecHex = { // Map for Dec to Hex
	{0, '0'},
	{1, '1'},
	{2, '2'},
	{3, '3'},
	{4, '4'},
	{5, '5'},
	{6, '6'},
	{7, '7'},
	{8, '8'},
	{9, '9'},
	{10, 'A'},
	{11, 'B'},
	{12, 'C'},
	{13, 'D'},
	{14, 'E'},
	{15, 'F'}
};

int main()
{
	cout << "--------------------------------------------------------" << endl // Menu with directions
		<< "Welcome to the Information Storage Conversions Software!" << endl
		<< "Type the text in quotes next to the conversion you want:" << endl
		<< "\"H->B\" : Hexadecimal to Binary Conversion" << endl
		<< "\"B->H\" : Binary to Hexadecimal Conversion" << endl
		<< "\"H->D\" : Hexadecimal to Decimal Conversion" << endl
		<< "\"D->H\" : Decimal to Hexadecimal Conversion" << endl
		<< "\"Quit\" : Quits the software" << endl
		<< "--------------------------------------------------------" << endl;

	while (run == true) // While user does not type "quit"
	{
		string line = "";
		cout << endl << "Enter a command: ";
		getline(cin, line); // Gets command from menu

		if (line == "H->B" || line == "h->b")
		{
			bool run2 = true;
			while (run2 == true)
			{
				string num = "";
				cout << endl << "Enter a Hexadecimal Number: ";
				getline(cin, num);

				string res = "";
				for (int i = 0; i < num.size(); i++)
				{
					for (auto j : HexBi)
					{
						if (num[i] == j.first)
						{
							res += j.second; // Adds corresponding map value to result if found
						}
					}
				}
				int k = num.size() * 4;
				if (res.size() == k) // Checks if there are invalid values based on results size
				{
					cout << "Binary Conversion: " << res << endl;
					run2 = false;					
				}
				else
				{
					cout << "Error: Invalid Hexadecimal Number";
				}
			}
		}
		else if (line == "B->H" || line == "b->h")
		{
		
			bool run2 = true;
			while (run2 == true)
			{
				string num = "";
				cout << endl << "Enter a Binary Number: ";
				getline(cin, num);

				int a = num.size() % 4;

				string num2 = ""; // Function to pad zeros for function to use
				if (a != 0)
				{
					int b = 4 - a;
					while (b != 0)
					{
						num2 += '0';
						b--;
					}
				}
				for (int i = 0; i < num.size(); i++)
				{
					num2 += num[i]; // Adds original value to padded zeros if needed
				}
				string res = "";
				string num3 = "";
				for (int i = 0; i < num2.size(); i++)
				{
					if (num2[i] == '0' || num2[i] == '1') // Check if valid binary is used
					{
						num3 += num2[i];
					}
					else break;
					if (num3.size() == 4) // Once four binary num are read, get their corresponding map value
					{
						for (auto j : BiHex)
						{
							if (num3 == j.first)
							{
								res += j.second;
							}
						}
						num3 = "";
					}
				}
				int k = num2.size() / 4; 
				if (res.size() == k) // Checks if there are invalid values based on results size
				{
					cout << "Hexadecimal Conversion: " << res << endl;
					run2 = false;
				}
				else
				{
					cout << "Error: Invalid Binary Number";
				}
			}
		}
		else if (line == "H->D" || line == "h->d")
		{
			bool run2 = true;
			while (run2 == true) {
				
				bool run3 = true;
				string num = "";
				cout << endl << "Enter a Hexadecimal Number (from 0 - FFFFFFFF): ";
				getline(cin, num);

				if (num.size() <= 8)
				{
					unsigned long int res = 0;
					for (int i = 0; i < num.size(); i++)
					{
						if (run3 == true) { // As long as values entered are valid

							bool valid = false;
							for (auto a : HexDec) // Checks if all values entered are valid
							{
								if (num[i] == a.first)
								{
									valid = true;
								}
							}
							if (valid == true)
							{
								int j = num.size() - i - 1; // Gets all necessary values to convert from hex to dec
								int k = HexDec[num[i]];
								unsigned long int l = pow(16, j);

								if (j == 0) // If last num, just add it to the result
								{
									res += k;
								}
								else // Add the product of hexadecimal place and value in that place
								{
									res += (k * l);
								}
							}
							else
							{
								cout << "Error: Invalid Hexadecimal Number";
								run3 = false;
							}
						}
					}
					if (run3 == true)
					{
						cout << "Decimal Conversion: " << res << endl;
						run2 = false;
					}
				}
				else {
					cout << "Error: Invalid Hexadecimal Number (Out of Range)";
				}
			}
		}
		else if (line == "D->H" || line == "d->h")
		{
			bool run2 = true;
			while (run2 == true) {

				bool run3 = true;
				string num = "";
				string res = "";
				cout << endl << "Enter a Decimal Number (from 0 - 2147483647): ";
				getline(cin, num);

				if (num.size() <= 10)
				{
					for (int i = 0; i < num.size(); i++)
					{
						if (!(isdigit(num[i]))) // Checks if values are valid
						{
							run3 = false;
						}
					}
					if (run3 == true)
					{
						stack<char>DecHexS;
						int rem = 0; // Variables for remainder, current value, and next value to use
						unsigned long int number = stoi(num);
						unsigned long int next = number;
						while (number != number % 16) // As long as the number can be divided at least once
						{
							next = number / 16;
							rem = number % 16;
							DecHexS.push(DecHex[rem]); // Puts resulting values in a stack for easy reformating
							number = next;
						}
						DecHexS.push(DecHex[number]); // Puts last remainder into stack

						while (!DecHexS.empty()) // Forms together result from the stack
						{
							res += DecHexS.top();
							DecHexS.pop();
						}
						cout << "Hexadecimal Conversion: " << res << endl;
						run2 = false;
					}
					if (run3 == false)
					{
						cout << "Error: Invalid Decimal Number";
					}
				}
				else 
				{
					cout << "Error: Invalid Decimal Number (Out of Range)";
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