// DesignPatterns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"Singleton.h"
#include"Phone.h"
#include"Strategy.h"
#include"Observer.h"
using namespace std;

void SimulateSingleton()
{
	Singleton::ShowTotalInstances();
	Singleton *ss = Singleton::GetObject();
	ss->ShowTotalInstances();
	ss = Singleton::GetObject();
	ss->ShowTotalInstances();
	ss = Singleton::GetObject();
	ss->ShowTotalInstances();
}

void SimulateSyncProblemSingleton()
{
	Singleton::ShowTotalInstances();
	Singleton *ss = Singleton::GetObject();
	ss->ShowTotalInstances();
	ss = Singleton::GetObject();
	ss->ShowTotalInstances();
	ss = Singleton::GetObject();
	ss->ShowTotalInstances();
}

CallBehavior *getDesiredCallBehavior(CallType callType)
{
	switch (callType)
	{
	case CallType::GSMAudio:
		return new GSMAudio();
	case CallType::GSMVideo:
		return new GSMVideo();
	case CallType::WhatsAppAudio:
		return new WhatsAppAudio();
	case CallType::SkypeVideo:
		return new SkypeVideo();
	default:
		cout << "Invalid choice for calltype, returning nullptr \n";
		return nullptr;
	}
	return nullptr;
}

void SimulateStrategy()
{
	CallBehavior   *cb			= nullptr;
	CallType		callType	= CallType::GSMAudio;

	cb = getDesiredCallBehavior( callType );

	Phone			myPhone;

	myPhone.initiateCall();

	cout << "--------Receiving the regular Audio call----------------\n";
	myPhone.setCallBehavior(cb);
	myPhone.initiateCall();
	delete cb;

	cout << "--------------User selected to switch to GSM Video------------\n";
	cb = getDesiredCallBehavior(CallType::GSMVideo);
	myPhone.setCallBehavior(cb);
	myPhone.initiateCall();
	delete cb;

	cout << "-------------User selected to switch to Skype Video------------\n";
	cb = getDesiredCallBehavior(CallType::SkypeVideo);
	myPhone.setCallBehavior(cb);
	myPhone.initiateCall();
	delete cb;

	cout << "-------------User selected to switch to WhatsApp Audio-----------\n";
	cb = getDesiredCallBehavior(CallType::WhatsAppAudio);
	myPhone.setCallBehavior(cb);
	myPhone.initiateCall();
	delete cb;

}

void SimulateObserver()
{
	GenericNotifier *scoreUpdater	= new ScoreUpdater();
	GenericObserver *webClient		= new WebClient();
	GenericObserver *mobileClient	= new MobileClient();

	cout << "-------Notifying observers----------\n";
	scoreUpdater->notifyObservers("10 for 5");

	scoreUpdater->registerObserver(webClient);
	scoreUpdater->registerObserver(mobileClient);
	cout << "-------Notifying observers----------\n";
	scoreUpdater->notifyObservers("100 for 5");

	scoreUpdater->removeObserver(webClient);
	cout << "-------Notifying observers----------\n";
	scoreUpdater->notifyObservers("103 for 5");

	scoreUpdater->removeObserver(mobileClient);
	cout << "-------Notifying observers----------\n";
	scoreUpdater->notifyObservers("108 for 5");
}

int main()
{
	cout << "In Main\n";
	SimulateSingleton();
	SimulateStrategy();

	cout << "sizeof(CallType) = " << sizeof(CallType) << endl;

	SimulateObserver();

    return 0;
}

