#include <iostream>
using namespace std;

//We split the program in more classes

class Greeter {
public:
	virtual string greet() = 0;
};

class CasualPersonality : public Greeter {	//If we want to greet more different people we can just add more classes without changing existing ones
public:
	string greet() override {
		return "Sup Bro?";
	}
};

class FormalPersonality : public Greeter { 
public:
	string greet() override {
		return "Good evening sir.";
	}
};

class IntimatePersonality : public Greeter {
public:
	string greet() override {
		return "Hello Darling!";
	}
};


int main() {

	FormalPersonality fp;
	cout << fp.greet() << endl;
	
	return 0;
}
