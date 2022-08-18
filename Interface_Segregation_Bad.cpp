#include <iostream>
using namespace std;

class Bird {		//Here we created a class "Bird". It handles everything a bird does.
public:
	void fly();
	void molt();

};

class Eagle : Bird {	//This works for an eagle. it can fly and molt, so it uses every action of the class.
public:
	string currentLocation;
	int numberOfFeathers;
	Eagle(int initialFeatherCount) {
		numberOfFeathers = initialFeatherCount;
	}
	void fly() {
		currentLocation = "in the air";
	}
	void molt() {
		numberOfFeathers -= 1;
	}
};

class Penguin : Bird{		//But the penguin is not a normal bird
public:
	string currentLocation;
	int numberOfFeathers;
	Penguin(int initialFeatherCount) {
		numberOfFeathers = initialFeatherCount;
	}

	void molt() {	//It can lose its feathers
		numberOfFeathers -= 1;
	}

	void swim() {	//And it can even swim
		currentLocation = "in the water";
	}
	void fly() {		//But the action "fly" does not work for a penguin
		throw new exception;
	}

};

//	When a Class is required to perform actions that are not useful,
//	it is wasteful and may produce unexpected bugs
//	if the Class does not have the ability to perform those actions.
//
//	A Class should perform only actions that are needed to fulfill its role.
//	Any other action should be removed completely or moved somewhere else if it might be used by another Class in the future.
//	This is called the "Interface Segregation Principle"


int main() {
	return 0;
}
