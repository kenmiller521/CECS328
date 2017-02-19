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
	std::getline(std::cin, userStr);
	
	int userChoice = 1;
	while (userChoice != 0)
	{
		std::cout << "Make a selection\n";
		std::cout << "1: Enter n & k, print all k subsets\n";
		std::cout << "2: ---\n";
		std::cout << "0: Quit\n";
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 0:
			std::cout << "You chose 0.\n";
			return;
			break;
		case 1:

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

int juniorAlgorithmMiddle(int[], int, int, int)
{
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

std::vector<std::string> split(const std::string, char sep)
{

	return std::vector<std::string>();
}
