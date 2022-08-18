#include <iostream>
using namespace std;

//This program is supposed to greet people according to how well we know them
//It works, but we can't extend it without modifying it.
//This is against the "Open-Closed Principle" ("Classes should be open for extension, but closed for modification")

class Greeter {
public:
	string formality;

	string greet() {
		if(formality == "formal"){
			return "Good evening, sir.";
		}
		else if(formality == "casual"){
			return "Sup bro?";
		}
		else if(formality == "intimate"){
			return"Hello Darling!";
		}
		else {
			return "Hello.";
		}
	}

	void setFormality(string formality){
		this->formality = formality;
	}

	//Changing the current behaviour of this Class will affect all the systems using that Class.
	//we should change this
};

int main() {
	return 0;
}
