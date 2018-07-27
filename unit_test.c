#include <stdio.h>

#define TRUE 	1
#define FALSE 	2

int sum(int a, int b)
{
	return a+b;
}

int subtraction(int a, int b)
{
	return a-b;
}

int multiplication(int a, int b)
{
	return a*b;
}

int division(int a, int b)
{
	return a/b;
}

void test(int expected, int actual, const char* test_name)
{
	if (expected == actual)
	{
		printf("PASSED %s\n", test_name);
	}
	else
	{
		printf("FAILED %s\n", test_name);
		printf("\t expected:%d actual: %d\n", expected, actual);
	}
}

int main(void)
{
	test( 3, sum(1, 2), "sum() test");
	test( 0, sum(-1, 1), "sum() test");
	test( 1, subtraction(2, 1), "subtraction() test");
	test(-1, subtraction(1, 2), "subtraction() test");
	test( 2, multiplication(1, 2), "multiplication() test");
	test(-2, multiplication(-1, 2), "multiplication() test");
	test( 0, division(1, 2), "division() test");
	test( 0, division(-1, 2), "division() test");

	return 0;
}
