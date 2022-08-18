#include <iostream>
using namespace std;

//Here we used "Interface Segregation"
//This principle aims at splitting a set of actions into smaller sets so that a Class executes ONLY the set of actions it requires.
//Clients are no longer forced to depend on methods that they do not use

class featheredCreature{	//instead of a bird class we are using extra classes for feathered creatures
public:
	void molt();
};

class flyingCreature{		//for flying creatures
public:
	void fly();
};

class swimmingCreature{		//and for swimming creatures
public:
	void swim();
};

class eagle:flyingCreature,featheredCreature{	//The eagle only uses what he needs to fulfill its role
public:
	string currentLocation;
	int numberOfFeathers;

	void Eagle(int initialNumberOfFeathers){
		numberOfFeathers = initialNumberOfFeathers;
	}

	void fly(){
		currentLocation = "in the air";
	}

	void molt(){
		numberOfFeathers -= 1;
	}
};

class penguin:swimmingCreature,featheredCreature{	//And now the same is true for the penguin.
public:
	string currentLocation;
	int numberOfFeathers;

	void Penguin(int initialNumberOfFeathers){
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
