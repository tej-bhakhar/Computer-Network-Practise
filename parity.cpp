#include <iostream>
using namespace std;

bool Parity(int n)
{
	int a = 0;
	int number = n;

	while (number >= 2)
	{
		if (number & 1)
			a++;
		number = number >> 1;
	}
	return (a % 2) ? true : false;
}

int main()
{
	int n;
	cout << "Enter a number: ";
	cin >> n;
	cout << "Parity of number " << n << " is = " << (Parity(n) ? "ODD" : "EVEN");
}