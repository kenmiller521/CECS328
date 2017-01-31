#include <iostream>

void userMenu();
void combination(int, int, int, int, int[], int);
int calculateValue(int, int);
int calculateCombination(int, int);

int main()
{
	userMenu();
	return 0;
}

void userMenu()
{
	int userChoice = 1;
	int n = 0, k = 0, a = 2, i = 0, j = 0;
	int arr[99] = {};
	arr[0] = 1;
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
				std::cout << "Enter number for n\n";
				std::cin >> n;
				std::cout << "Enter number for k\n";
				std::cin >> k;
				combination(n, k, a, i, arr, j);
				arr[0] = 1;
				std::cout << "{";
				for (int i = 0; i < 99; i++)
				{
					if (arr[i] != 0)
						std::cout << arr[i];
					if (arr[i + 1] != 0 && i != 98)
						std::cout << ",";
				}
				std::cout << "}" << std::endl;

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
		arr[j+1] = a + 1;
		return;
	}
	n--;
	k--;
	while (n >= k)
	{
		//take combination calculation and set to value
		value = calculateCombination(n,k);
		if (i < value)
		{
			arr[j+1] = a;
			a++;
			j++;
			combination(n, k, a, i, arr, j+1);
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
	std::cout << "Your 'choose' number: " << calculateCombination(nn, kk) << std::endl;
	return 0;
}

int calculateCombination(int n, int k)
{
	int t = 1;
	int tt = 1;
	for (int i = n; i > (n-k); i--)
	{
		t = t*i;
		std::cout << "t: " << t << std::endl;
	}
	std::cout << "k : "<< k << std::endl;
	for (int j = k; j > 0; j--)
	{
		tt = tt*j;
		std::cout << "tt: " << tt << std::endl;
	}
	t = t / tt;
	std::cout << "Your combination is: " << t << std::endl;
	return t;
}
