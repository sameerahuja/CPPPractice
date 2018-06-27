#pragma once

class Singleton
{
private:
	static int instances;
	static Singleton *singl;
	Singleton();
	Singleton(const Singleton &obj);
public:
	static void ShowTotalInstances();
	static Singleton* GetObject();
};