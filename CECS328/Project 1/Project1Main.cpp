#include <iostream>

void userMenu();
void combination(int, int, int, int, int[], int);
int calculateValue(int, int);
long long calculateFactorial(int, int);
long long choose(int, int);

int main()
{
	userMenu();
	system("PAUSE");
	return 0;
}

void userMenu()
{
	int userChoice = 1;
	int n = 0, k = 0, a = 0, i = 0, j = 0;
	int arr[6] = {};
	while (userChoice != 0)
	{
		std::cout << "Make a selection\n";
		std::cout << "1: \n";
		std::cout << "2: \n";
		std::cout << "3: \n";
		std::cout << "4: \n";
		std::cout << "0: Quit\n";
		std::cin >> userChoice;
		switch (userChoice)
		{
			case 0:
				std::cout << "You chose 0.\n";
				return; 
				break;
			case 1:
				std::cout << "You chose 1.\n";
				calculateValue(0, 0);
				//combination(n, k, a, i, arr, j);
				break;
			case 2:
				std::cout << "You chose 2.\n";
				break;
			case 3:
				std::cout << "You chose 3.\n";
				break;
			case 4:
				std::cout << "You chose 4.\n";
				break;
		}
	}
}

void combination(int n, int k, int a, int i, int arr[], int j)
{
	int value = 0;
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
		value = 0;
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
	/*
	int xx = 0;
	int result = 1;
	std::cout << "Enter number for factorial\n";
	std::cin >> xx;
	std::cout << "Your number factorialized: " << calculateFactorial(xx, result) << std::endl;
	*/
	int nn = 0;
	int kk = 0;
	std::cout << "Enter number for n\n";
	std::cin >> nn;
	std::cout << "Enter number for k\n";
	std::cin >> kk;
	std::cout << "Your 'choose' number: " << choose(nn, kk) << std::endl;
	return 0;
}

long long calculateFactorial(int x, int result = 1)
{
	if (x == 1)
		return result;
	else
		return(calculateFactorial(x - 1, x*result));
}

long long choose(int n, int k)
{
	int a = 1;
	int b = 1;
	int c = 1;
	return (     calculateFactorial(n, a) / ((calculateFactorial(n-k, b))*(calculateFactorial(k, c)))               );
}
