#include <iostream>
using namespace std;

//Here we changed the program, so PenthouseSuite and Studio are no longer child Classes

class PenthouseSuite {
public:
	int squareFootage;
	int numberOfBedrooms;

	PenthouseSuite() {
		numberOfBedrooms = 4;
	}
	void setSquareFootage(int sqft) {
		squareFootage = sqft;
	}
};

class Studio {
public:
	int squareFootage;
	int numberOfBedrooms;

	Studio(){
		numberOfBedrooms = 0;
	}
	void setSquareFootage(int sqft) {
		squareFootage = sqft;
	}
};

class BedroomAdder {	//The BedroomAdder only interacts with Penthouse suite
public:
	void addBedroom(PenthouseSuite penthouse) {
		penthouse.numberOfBedrooms += 1;
	}
};

//The Liskov Substitution principle aims to enforce consistency so that the parent Class or its child Class can be used in the same way without any errors.

int main() {
	return 0;
}
