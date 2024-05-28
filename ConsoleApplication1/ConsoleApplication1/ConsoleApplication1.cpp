// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class animal {

public:
	animal(){
		/*cout << "animal" << endl;*/
	}

	virtual ~animal(){
		/*cout << "~animal" << endl;*/
	}

	void eat() {
		cout << "Eating." << endl;
	}

	void sleep() {
		cout << "Sleeping." << endl;
	}

	virtual void sharking() {
		cout << "Eww." << endl;
	}
};

class bird :public animal
{
public:
	void sharking() {
		cout << "Cheep." << endl;
	}
};

class dog :public animal
{
public:
	void sharking() {
		cout << "Wooh." << endl;
	}
};

class cat :public animal
{
public:
	void sharking() {
		cout << "Meow." << endl;
	}
};

void AddAnimal(vector<animal*> &zoo, int intCount){

	for (int i = 0; i < intCount; i++)
	{
		int intanimalNO = rand() % 4;

		switch (intanimalNO)
		{
		case 1:
			zoo.push_back(new cat());
			break;

		case 2:
			zoo.push_back(new dog());
			break;

		default:
			zoo.push_back(new bird());
			break;
		}

	}
}


void AnimalAction(string strno, const vector<animal*> &zoo){

	cout << "Zoo" << strno << endl;

	for (int i = 0; i < zoo.size(); i++){
		zoo[i]->sharking();
	}

	cout << "============================================" << endl;
}

void ZooClear(vector<animal*> &zoo){

	for (auto it = zoo.begin(); it != zoo.end();){
		// Erase the element and update the iterator
		it = zoo.erase(it);
	}

}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<animal*> zoo_1;
	vector<animal*> zoo_2;
	vector<animal*> zoo_3;

	AddAnimal(zoo_1, 5);
	AddAnimal(zoo_2, 10);
	AddAnimal(zoo_3, 15);

	AnimalAction("1", zoo_1);
	AnimalAction("2", zoo_2);
	AnimalAction("3", zoo_3);

	ZooClear(zoo_1);
	ZooClear(zoo_2);
	ZooClear(zoo_3);

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();

	return 0;
}


