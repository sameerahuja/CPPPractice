#include "stdafx.h"
#include "Observer.h"
#include<algorithm>
#include<iostream>
using namespace std;


void ScoreUpdater::registerObserver(GenericObserver *observer)
{
	observerList.push_back( observer );
}

void ScoreUpdater::removeObserver(GenericObserver *observer)
{
	observerList.erase( remove(observerList.begin(), observerList.end(), observer), observerList.end() );
}

void ScoreUpdater::notifyObservers(string score)
{
	short objects = 0;
	for (auto &element : observerList)	
	{
		element->notify(score);
		objects++;
	
	}

	vector<GenericObserver*>::iterator it;
	//for (auto el = observerList.begin(), it = observerList.begin(); el != observerList.end() || it != observerList.end(); el++, it++ )
	//{
	//	(*el)->notify(score);
	//	(*it)->notify(score);
	//}

	cout << "No of objects notified = " << objects << endl;
}

void WebClient::notify(string score)
{
	cout << "WebClient notified, score = " << score.c_str() << endl;
}

void MobileClient::notify(string score)
{
	cout << "MobileClient notified, score = " << score.c_str() << endl;
}
