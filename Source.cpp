#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>

int main()
{
	double start, end, t;
	start = clock();
	double sum=0;
	double begin, limit, step;
	std::cout << "Enter begin: " << std::endl;
	std::cin >> begin;
	std::cout << "Enter limit: " << std::endl;
	std::cin >> limit;
	std::cout << "Enter step: " << std::endl;
	std::cin >> step;
	for (double i = begin; i < limit; i += step)
	{
		double output;
		output = sin(cos(sqrt(i) + 1));
		sum += output;
	}
	end = clock();
	t = (end - start);
	printf("C time %f seconds\n", t/1000);
	printf("Sum = %f\n",sum);


	int one = 1;
	double sum1 = 0;
	start = clock();
	_asm finit
	for (double x = begin; x < limit; x+=step)
	{
		double output = 0;
		_asm {
			FLD x
			FSQRT
			FIADD one
			FCOS
			FSIN

			FSTP output
		}
		_asm fwait
		sum1 += output;
	}

	end = clock();
	t = (end - start);
	printf("Assembler time %f seconds\n", t/1000);
	printf("Sum = %f\n", sum1);
	system("Pause");
}