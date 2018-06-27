#include "stdafx.h"
#include "Strategy.h"
#include<iostream>

using namespace std;

void WhatsAppAudio::makeCall()
{
	cout << "I am on WhatsApp Audio call\n";
}

void SkypeVideo::makeCall()
{
	cout << "I am on Skype Video call\n";
}

void GSMVideo::makeCall()
{
	cout << "I am on GSM Video call\n";
}

void GSMAudio::makeCall()
{
	cout << "I am on GSM Audio call\n";
}
