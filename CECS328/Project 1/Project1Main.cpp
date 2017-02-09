#include <iostream>

void userMenu();
bool next_combination(int[], int, int);
void resetArray(int[]);
void printArray(int[]);
void printArraySubset(int[],int k);
void setArraySubset(int[], int[], int k);
float calculateEfficiency(int[],int,int);
void GreatestEfficiency(int[],int[],int);
int greedyAlgorithm(int[], int,int);

int main()
{
	userMenu();
	return 0;
}

void userMenu()
{
	int userChoice = 1;
	//S = {1,2,3,...,n}
	//n is the size of the set
	//k is the subset size of S
	//a is the starting number, after 1, of S
	//i is the i-th subset of A
	int n = 0, k = 0, a = 0, i = 2, j = 0;
	int setArray[99] = {};
	int tempSetArray[99] = {};

	while (userChoice != 0)
	{
		std::cout << "Make a selection\n";
		std::cout << "1: Enter n & k, print all k subsets\n";
		std::cout << "2: ---\n";
		std::cout << "3: Input coin denomination S, print efficiency\n";
		std::cout << "4: Input n, returns coin denomination S of best efficiency\n";
		std::cout << "0: Quit\n";
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 0:
			std::cout << "You chose 0.\n";
			return;
			break;
		case 1:
			resetArray(setArray);
			std::cout << "You chose 1.\n";
			std::cout << "Enter number for n\n";
			std::cin >> n;
			std::cout << "Enter number for k\n";
			std::cin >> k;
			for (int i = 0; i < n; i++)
			{
				setArray[i] = i + 1;
			}
			std::cout << "The set: ";
			printArray(setArray);
			std::cout << "All subsets of " << k << "-combination:" << std::endl;
			printArraySubset(setArray, k);
			while (next_combination(setArray, k, n)) 
			{
				printArraySubset(setArray, k);
			}
			break;
		case 2:
			break;
		case 3:
			{
				std::cout << "You chose 3.\n";
				int pos = 0;
				int input = 1;

				while (pos != 99 && input != 0)
				{
					std::cout << "Enter coin denomination for set position " << pos << " (0 to stop)" << std::endl;
					std::cin >> input;
					if (input != 0)
					{
						setArray[pos] = input;
						pos++;
					}
				}
				std::cout << "The efficiency of your set is " << calculateEfficiency(setArray,pos,99) << std::endl;
				break;
			}
			case 4:
				std::cout << "You chose 4.\n";
				std::cout << "Enter max coin denomination: ";
				std::cin >> n;
				while (n > 99)
				{
					std::cout << "Max coin denomination cannot exceed 99. Try again: ";
					std::cin >> n;
				}
				GreatestEfficiency(setArray, tempSetArray, n);
				break;
		}
	}
}

//arr[] is the array to write in
//k is the number of subset from the set S
//maxS is the maximum number in the array
bool next_combination(int arr[], int k, int maxS)
{
	//printArraySubset(arr, k);
	int value = 0;
	for (int j = (k - 1); j >= 0; j--)
	{
		if (arr[j]+(k-j) <= maxS)
		{
			value = arr[j] + 1;
			for (int r = j; r <= (k - 1); r++)
			{
				arr[r] = value;
				value++;
			}
			return true;
		}
	}
	return false;
}

void resetArray(int arr[])
{
	for (int i = 0; i < 99; i++)
		arr[i] = 0;
}

void printArray(int arr[])
{
	std::cout << "{";
	for (int i = 0; i < 99; i++)
	{
		if (arr[i] != 0)
			std::cout << arr[i];
		if (arr[i] != 0 && arr[i + 1] != 0 && i != 98)
			std::cout << ",";
	}
	std::cout << "}" << std::endl;
}

void printArraySubset(int arr[], int k)
{
	std::cout << "{";
	for (int i = 0; i < k; i++)
	{	
		if (arr[i] != 0)
			std::cout << arr[i];
		if (i+1 != k)
			std::cout << ",";
	}
	std::cout << "}" << std::endl;
}
void setArraySubset(int arr[], int arr2[],int k)
{
	for (int i = 0; i <= k; i++)
	{
		if (arr[i] != 0)
			arr2[i] = arr[i];
	}
}
//returns the number of coins of denomation set
float calculateEfficiency(int arr[],int arraySize,int c)
{
	float value = 0;
	for (int i = 1; i <= 99; i++)
	{
		value += greedyAlgorithm(arr, arraySize, i);
		//std::cout << value << std::endl;
	}
	value /= 99;
	return value;
}

void GreatestEfficiency(int arr[],int tempArr[],int centChange)
{	
	//biggest number of coins that can be returned is equal to the cents given
	//so anything smaller than this will be set equal
	float value = 99;
	float temp = 0;
	int pos = 0;
	//initialize array 1,2,3,...,n
	resetArray(arr);
	for (int i = 0; i < centChange; i++)
	{
		arr[i] = i+1;
	}
	//std::cout << "/////////////////////\n";
	////for (int i = 0; i < centChange; i++)
	//{
	//	std::cout << arr[i];
	//}
	//std::cout << "\n/////////////////////\n";
	//k-subset i
	for (int i = 1; i <= centChange; i++)
	{
		//resetArray(arr);
		for (int j = 0; j < centChange; j++)
		{
			arr[j] = j+1;
		}
		//printArraySubset(arr, i);
		//std::cout << calculateEfficiency(arr, centChange, centChange) << std::endl;
		//std::cout << "Coins returned: " << greedyAlgorithm(arr, i, centChange) << std::endl;
		while (next_combination(arr, i, centChange))
		{
			//printArraySubset(arr, i);
			temp = calculateEfficiency(arr, centChange, centChange);
			//std::cout << temp << std::endl;
			if (temp < value)
			{
				value = temp;
				setArraySubset(arr, tempArr, i);
				pos = i;
			}
		}
	}
	std::cout << "Greatest efficiency: " << value << std::endl;
	std::cout << "The set: ";
	printArraySubset(tempArr,pos);
}

int greedyAlgorithm(int arr[], int arraySize, int c)
{
	int numbOfCoins = 0;
	int i = arraySize-1;
	while (i != -1)
	{
		if (c / arr[i] >= 1)
		{
			numbOfCoins += c / arr[i];
			c = c%arr[i];
		}
		else
			i--;
	}
	if (c == 0)
		return numbOfCoins;
	else
		return 0;
}
