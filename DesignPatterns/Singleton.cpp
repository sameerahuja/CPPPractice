#include "stdafx.h"
#include "Singleton.h"
#include <iostream>

using namespace std;

int Singleton::instances = 0;
Singleton* Singleton::singl = nullptr;

Singleton::Singleton()
{
	++instances;
	cout << "Created one instance, total = " << instances << endl;
}

Singleton::Singleton(const Singleton &obj)
{
	++instances;
	cout << "Created one instance, total = " << instances << endl;
}

void Singleton::ShowTotalInstances()
{
	cout << "Total instances = " << instances << endl;
}

Singleton* Singleton::GetObject()
{
	if ( !singl )
		singl = new Singleton();

	return singl;
}
