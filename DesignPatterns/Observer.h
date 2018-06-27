#pragma once

#include<vector>

using namespace std;

class GenericObserver;

class GenericNotifier
{
public:
	virtual void registerObserver(GenericObserver *observer) = 0;
	virtual void removeObserver  (GenericObserver *observer) = 0;
	virtual void notifyObservers (string score) = 0;
};

class GenericObserver
{
public:
	virtual void notify(string str) = 0;
};

class ScoreUpdater : public GenericNotifier
{
	vector<GenericObserver *> observerList;
public:
	virtual void registerObserver	(GenericObserver *observer);
	virtual void removeObserver		(GenericObserver *observer);
	virtual void notifyObservers	(string score);
};


class WebClient: public GenericObserver
{
public:
	virtual void notify(string str);
};

class MobileClient: public GenericObserver
{
public:
	virtual void notify(string str);
};