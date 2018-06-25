#pragma once

#include<iostream>
using namespace std;

class Multiply
{
public:
	Multiply() {};
	double operator() ( double left, double right );
};


class BasicFunctor
{
public:
	void operator()();
	void show() { cout << "BasicFunctor show()\n"; };
	BasicFunctor()
	{
		cout << "BasicFunctor ctor\n";
	}
	~BasicFunctor()
	{
		cout << "BasicFunctor destructor\n";
	}
};

class BasicExample
{
public:
	BasicExample() { cout << "BasicExample constructor\n"; };
	~BasicExample() { cout << "BasicExample destructor\n"; };
	void show() { cout << "BasicExample show()\n"; };
};