// LambdaExpressions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<functional>
#include<vector>
#include"Functor.h"
#include <WebServices.h>

using namespace std;

// Using Lambda as a parameter
void UseLambdaAsParam(function<string(int) > &lambda)
{
	cout << "13 is " << lambda(13).data() << endl;
}

int main()
{
	WS_SERVICE_PROXY *px;
	int i = 1;
	function<string (int) > oddEven = [&i](int number) -> string
	{
		cout << "In lambda body i = " << ++i << endl;
		return (number % 2) == 0 ? "Even" : "Odd";
	};

	cout << oddEven(10).data() << " length = " << strlen(oddEven(10).data()) << endl;
	cout << oddEven(11).c_str() << " length = " << strlen(oddEven(11).c_str()) << endl;


	cout << " 5 * 6 = " << Multiply()(5, 6) << endl;

	// Passing lambda as a parameter
	UseLambdaAsParam( oddEven );

	//cout << "Invoking BasicFunctor" << endl;
	//BasicFunctor *ptr = new BasicFunctor();
	//(*ptr)();

	//BasicFunctor &basicFuncRef = BasicFunctor();
	//basicFuncRef();


	// Lambda pass by Copy
	BasicExample be;

	auto lamdaParCopy = [&]() {
		be.show();
		be.~BasicExample();
		//bf();
		cout << "Inside lamdaParCopy\n";
	};

	vector<int> v1 = {3,4,5,1,2,8,9,10};


	for (auto &var : v1)
	{
		cout << ++var << endl;
	}

	cout << "After for each loop 1" << endl;
	for (auto var : v1)
	{
		cout << var << endl;
	}

	auto j = "KKKKKKKKKKK\
		";
	string str = j;

	cout << "str = " << str.data() << endl;
	cout << "j = " << j << endl;


	function<int (int)> rec_lambda = [&](int num) {

		if (num >= 0)
		{
			cout << num << endl;
			return rec_lambda(num - 1);
		}
		else
		{
			cout << " num = " << num << endl;
			return 0;
		}
	};

	rec_lambda(10);

	function<int(int)> rec_factorial;
	
	rec_factorial = [&rec_factorial](int number) {

		if (number > 1)
			return number * rec_factorial(number - 1);

		return 1;
	};

	int num = 10;
	cout << "Factorial of " << num << " = " << rec_factorial(num) << endl;

    return 0;
}
