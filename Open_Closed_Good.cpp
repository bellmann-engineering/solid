#include <iostream>
using namespace std;

//We split the program in more classes

class Personality {
public:
	virtual string greet() = 0;
};

class Greeter {	//We no longer need to change the Greeter class if we want to extend our program
private:
	Personality personality;
public:
	Greeter(Personality personality) {
		this->personality = personality;
	}
	string greet(){
		return this->personality.greet();
	}
};

class CasualPersonality : public Personality {	//If we want to greet more different people we can just add more classes without changing existing ones
public:
	string greet() override {
		return "Sup Bro?";
	}
};

class FormalPersonality : public Personality { 
public:
	string greet() override {
		return "Good evening sir.";
	}
};

class IntimatePersonality : public Personality {
public:
	string greet() override {
		return "Hello Darling!";
	}
};


int main() {

	return 0;
}
