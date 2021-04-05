#include<iostream>
using namespace std;

void Print(int array1[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(array1 + i) << " ";
	}
	cout << endl;
}

class arithmetic {

public:

	int number1;
	int number2;

	int* primeFactors(int number)
	{

		int* array1 = new int[200];
			int k = 0;
			int a = number;
			for (int i = 2; i <= number; i++)
			{
				if (a % i == 0)
				{
					while (a % i == 0)
					{
						a /= i;
						array1[k] = i;
						k++;
					}
				}
			}
		return array1;

		delete[] array1;
		array1 = NULL;
	}

	int Size(int number)
	{
		int* array1 = new int[200];
		int k = 0;
		int count = 0;
		int a = number;
			for (int i = 2; i <= number; i++)
			{
				if (a % i == 0)
				{
					while (a % i == 0)
					{
						a /= i;
						array1[k] = i;
						k++;
						count++;
					}
				}
			}
		return count;
	}

	int LCM()
	{
		int multiply = number1 * number2;

		if (HCF() == 1)
			return multiply;
		else
		return multiply / HCF();
	}

	int HCF()
	{
		int multiply = 1;
		int* ptr1 = primeFactors(number1);
		int a = Size(number1);
		int n = number2;

		for (int i = 0; i < a; i++)
		{
			if (n % *(ptr1 + i) == 0)
			{
				multiply *= *(ptr1 + i);
				n /= *(ptr1 + i);
			}
		}
		return multiply;
	}
	arithmetic(int n1, int n2)
	{
		number1 = n1;
		number2 = n2;
	}
};

int main()
{
	int a, b;
	cout << "Enter two numbers: "<<endl;
	cin >> a >> b;
	if (a < 2 || b < 2)
		cout << "Number must be greater than 1"<<endl;
	else
	{
		arithmetic A(a, b);
		cout << a << " = ";
		Print(A.primeFactors(a), A.Size(a));
		cout << b << " = ";
		Print(A.primeFactors(b), A.Size(b));

		cout << "HCF: " << A.HCF() << endl;
		cout << "LCM: " << A.LCM() << endl;
	}


	system("pause>0");
	return 0;
}