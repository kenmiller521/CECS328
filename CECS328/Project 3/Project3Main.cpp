#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <unordered_map>
unsigned int hashValue(std::string str, int size);

struct Token
{
	std::string token = "abcd"; //token being stored
	int a_count; //total occurences in A training docs.
	int b_count; //total occurences in B training docs.
};

int main()
{
	int menuInput = 1;
	std::string userStr;
	int tableSize = 0;
	std::string delim = " ";
	std::string token;
	size_t pos = 0;

	int counter = 0;
	//std::unordered_map<int, std::string> table;
	std::vector< std::list< int > > myVectorOfLists;
	while (menuInput != 0)
	{
		std::cout << "1: " << std::endl;
		std::cout << "2: " << std::endl;
		std::cout << "3: " << std::endl;
		std::cout << "4: " << std::endl;
		std::cout << "5: " << std::endl;
		std::cin >> menuInput;
		std::cout << "-----------------------------------" << std::endl;
		switch (menuInput)
		{
		case 1:
			std::cout << "Enter a string: ";
			std::cin.ignore(99, '\n');
			std::getline(std::cin, userStr);
			std::cout << "Hash Value: " << hashValue(userStr, userStr.length());
			break;
		case 2:
			std::cout << "Enter size of table: ";
			std::cin >> tableSize;
			std::cout << "Enter words: ";
			std::cin.ignore(99, '\n');
			std::getline(std::cin, userStr);

			userStr.append(" ");
			while ((pos = userStr.find(delim)) != std::string::npos)
			{
				token = userStr.substr(0, pos);
				std::cout << token << " ";
				//userStr[counter] = std::stoi(token);
				//counter++;
				userStr.erase(0, pos + delim.length());
			}
			//for (int i = 0; i < userStr.length(); i++)
			//{
			//	myVectorOfLists[]
			//}
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		}
	}
	std::cout << "You entered 0. Quitting." << std::endl;
	return 0;
}

unsigned int hashValue(std::string str, int size)
{
	unsigned int h_value = 0;
	for (int i = 0; i < size; i++)
	{
		h_value = 37 * h_value + str[i];
	}
	return h_value;
}
