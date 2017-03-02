#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>

void userMenu();
int freshmanAlgorithm(int[], int);
int sophmoreAlgorithm(int[], int);
int juniorAlgorithm(int[], int, int);
int juniorAlgorithmMiddle(int[], int, int, int);
int seniorAlgorithm(int[], int);

int main()
{
	userMenu();
	return 0;
}

void userMenu()
{
	int arr[99] = {};
	int counter = 0;
	int arraySize = 0;
	std::string userStr;
	//Get the user input

	std::string delim = ",";
	std::string token;
	size_t pos = 0;

	std::cout << std::endl;
	int userChoice = 1;
	while (userChoice != 0)
	{
		std::cout << "Make a selection\n";
		std::cout << "1: Enter array of integers and prints MSS for each algorithm\n";
		std::cout << "2: ---\n";
		std::cout << "3: Quit\n";
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 3:
			std::cout << "You chose 3. Quitting\n";
			return;
			break;
		case 1:
			std::cout << "Enter signed integers seperated by commas(i.e -2,11,-4,13,-5,-2): ";
			std::cin.ignore(99, '\n');
			std::getline(std::cin, userStr);
			//the delimiter to be extracted
			//append a comma at the end to include last number
			userStr.append(",");
			//Go through string, remove delimer and set into token, then convert it to a signed integer and input into the array
			while ((pos = userStr.find(delim)) != std::string::npos)
			{
				token = userStr.substr(0, pos);
				arr[counter] = std::stoi(token);
				counter++;
				userStr.erase(0, pos + delim.length());
			}
			arraySize = counter;
			std::cout << std::endl;
			std::cout << "Freshman algorithm: " << freshmanAlgorithm(arr, arraySize) << std::endl;
			std::cout << "Sophmore algorithm: " << sophmoreAlgorithm(arr, arraySize) << std::endl;
			//std::cout << "Junior algorithm: " << juniorAlgorithm(arr, arraySize) << std::endl;
			std::cout << "Senior algorithm: " << seniorAlgorithm(arr, arraySize) << std::endl;
			break;
		case 2:
			break;
		}
	}
}

int freshmanAlgorithm(int arr[], int size)
{
	int max_sum = 0;
	int this_sum = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			this_sum = 0;
			for (int k = i; k <= j; k++)
				this_sum += arr[k];

			if(this_sum > max_sum)
				max_sum = this_sum;
		}
	}
	return max_sum;
}

int sophmoreAlgorithm(int arr[], int size)
{
	int max_sum = 0;
	int this_sum = 0;
	for (int i = 0; i < size; i++)
	{
		this_sum = 0;
		for (int j = i; j < size; j++)
		{
			this_sum += arr[j];
			if (this_sum > max_sum)
				max_sum = this_sum;
		}
	}
	return max_sum;
}

int juniorAlgorithm(int arr[], int left, int right)
{
	int tempMax = 0;
	//Base case 1
	if (right == left)
		return arr[left];
	//Base case 2
	if (right == left + 1)
	{
		tempMax = std::max(arr[left], arr[right]);
		return std::max(tempMax, (arr[left] + arr[right]));
	}

	int mid = (left + right) / 2;

	//Find the MSS that occurs in the left half of arr
	int mss_left = juniorAlgorithm(arr, left, mid);

	//Find the MSS that occurs in the right half of arr
	int mss_right = juniorAlgorithm(arr, mid + 1, right);
	
	//Find the MSS that intersects both the left and right halves
	//EXERCISE: implement juniorAlgorithmMiddle()
	int mss_middle = juniorAlgorithmMiddle(arr, left, mid, right);

	tempMax = std::max(mss_left, mss_right);
	return std::max(tempMax, mss_middle);
}

int juniorAlgorithmMiddle(int arr[], int left, int right, int middle)
{
	int biggestLeft = 0;
	int biggestRight = 0;
	int tempSum = 0;
	for (int i = left; i >= 0; i--)
	{
		tempSum += arr[i];
		if (tempSum > biggestLeft)
			biggestLeft = tempSum;
	}
	return 0;
}

int seniorAlgorithm(int arr[], int size)
{
	int max_sum = 0;
	int this_sum = 0;
	for (int i = 0; i < size; i++)
	{
		this_sum += arr[i];
		if (this_sum > max_sum)
			max_sum = this_sum;
		else if (this_sum < 0)
			this_sum = 0;
	}
	return max_sum;
}