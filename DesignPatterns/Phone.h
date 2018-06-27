#pragma once
#include"Strategy.h"
#include<iostream>

using namespace std;

enum class CallType : unsigned int
{
	WhatsAppAudio,
	SkypeVideo,
	GSMVideo,
	GSMAudio,
	Nothing
};

class Phone
{
	CallBehavior *callBehavior = nullptr;
public:
	void initiateCall();
	void setCallBehavior(CallBehavior *behavior);
};

