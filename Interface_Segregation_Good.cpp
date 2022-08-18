#include <iostream>
using namespace std;

//Here we used "Interface Segregation"
//This principle aims at splitting a set of actions into smaller sets so that a Class executes ONLY the set of actions it requires.
//Clients are no longer forced to depend on methods that they do not use

class FeatheredCreature {	//instead of a bird class we are using extra classes for feathered creatures
public:
	virtual void molt() = 0;
};

class FlyingCreature {		//for flying creatures
public:
	virtual void fly() = 0;
};

class SwimmingCreature {		//and for swimming creatures
public:
	virtual void swim() = 0;
};

class Eagle : FlyingCreature, FeatheredCreature{	//The eagle only uses what he needs to fulfill its role
public:
	string currentLocation;
	int numberOfFeathers;

	Eagle(int initialNumberOfFeathers){
		numberOfFeathers = initialNumberOfFeathers;
	}

	void fly(){
		currentLocation = "in the air";
	}

	void molt(){
		numberOfFeathers -= 1;
	}
};

class Penguin : SwimmingCreature,FeatheredCreature {	//And now the same is true for the penguin.
public:
	string currentLocation;
	int numberOfFeathers;

	Penguin(int initialNumberOfFeathers){
		numberOfFeathers = initialNumberOfFeathers;
	}

	void fly(){
		currentLocation = "in the water";
	}

	void molt(){
		numberOfFeathers -= 2;
	}
};

int main() {
	return 0;
}
