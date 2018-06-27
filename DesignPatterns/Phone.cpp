#include "stdafx.h"
#include "Phone.h"
#include<iostream>
using namespace std;

void Phone::initiateCall()
{
	if (callBehavior)
		callBehavior->makeCall();
	else
		cout << "No behavior found. Correct the code\n";
}

void Phone::setCallBehavior(CallBehavior *behavior)
{
	callBehavior = behavior;
}
