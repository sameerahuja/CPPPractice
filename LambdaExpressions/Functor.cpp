
#include "stdafx.h"
#include "Functor.h"
#include<iostream>
using namespace std;

double Multiply::operator()( double left, double right )
{
	return left * right;
}

void BasicFunctor::operator()()
{
	cout << "This is a BasicFunctor example" << endl;
}
