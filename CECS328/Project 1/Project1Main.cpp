#include <iostream>

void userMenu();
void combination(int, int, int, int, int[], int);
int calculateValue(int, int);
bool next_combination(int[], int, int);
void resetArray(int[]);
void printArray(int[]);
void printArraySubset(int[],int k);
float calculateEfficiency(int[]);

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
			while (next_combination(setArray, k, n)) {}
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
					setArray[pos] = input;
					pos++;
				}
				std::cout << "The efficiency of your set is " << calculateEfficiency(setArray) << std::endl;
				break;
			}
			case 4:
				std::cout << "You chose 4.\n";
				break;
		}
	}
}

void combination(int n, int k, int a, int i, int arr[], int j)
{
	//int value = 0;
	if (k == 1)
	{
		arr[j] = a + 1;
		return;
	}
	n--;
	k--;
	while (n >= k)
	{
		//take combination calculation and set to value
		int value = calculateValue(n,k);
		if (i < value)
		{
			arr[j] = a;
			a++;
			j++;
			combination(n, k, a, i, arr, j);
			return;
		}
		else
		{
			n--;
			a++;
			i -= value;
		}

	}
	
}

int calculateValue(int n, int k)
{
	int t = 1;
	int tt = 1;
	for (int i = n; i > (n-k); i--)
	{
		t = t*i;
		//std::cout << "t: " << t << std::endl;
	}
	//std::cout << "k : "<< k << std::endl;
	for (int j = k; j > 0; j--)
	{
		tt = tt*j;
		//std::cout << "tt: " << tt << std::endl;
	}
	t = t / tt;
	//std::cout << "Your combination is: " << t << std::endl;
	return t;
}

//arr[] is the array to write in
//k is the number of subset from the set S
//maxS is the maximum number in the array
bool next_combination(int arr[], int k, int maxS)
{
	printArraySubset(arr, k);
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

float calculateEfficiency(int arr[])
{
	float value = 0;
	for (int i = 0; i < 99; i++)
	{
		if (arr[i] != 0)
			value += arr[i];

	}
	value /= 99;
	return value;
}
