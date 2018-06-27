#pragma once

class CallBehavior
{
public:
	virtual void makeCall() = 0;
};

class WhatsAppAudio : public CallBehavior
{
public:
	void makeCall();
};

class SkypeVideo : public CallBehavior
{
public:
	void makeCall();
};

class GSMVideo : public CallBehavior
{
public:
	void makeCall();
};

class GSMAudio : public CallBehavior
{
public:
	void makeCall();
};