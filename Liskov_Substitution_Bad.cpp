#include <iostream>
using namespace std;

//This program handles the management of apartments

class Apartment {
public:
	string apartmentName;
	int squareFootage;
	int numberOfBedrooms;

	void setSquareFootage(int sqft);
};

class PenthouseSuite:Apartment {	//If the apartment is a penthouse suite we can ad bedrooms to it
public:
	PenthouseSuite() {
		numberOfBedrooms = 4;
	}
	void Name() {
			apartmentName = "Penthouse";
	}

	void setSquareFootage(int sqft) {
		squareFootage = sqft;
	}
};

class Studio:Apartment {	//If the apartment is a studio we don't need bedrooms
public:
	Studio() {
		numberOfBedrooms = 0;
	}
	void Name() {
		apartmentName = "Studio";
	}

	void setSquareFootage(int sqft) {
		squareFootage = sqft;
	}
};

class UnitUpgrader {	//This class can upgrade the apartment with more bedrooms, but if the apartment is a studio this should not happen.
public:
	void upgrade (Apartment apartment) {
		apartment.squareFootage += 40;

		if(apartment.apartmentName != "Studio")
			apartment.numberOfBedrooms += 1;
	}
};

//When a child Class cannot perform the same actions as its parent Class, this can cause bugs.
//The child Class should be able to process the same requests and deliver the same result as the parent Class or it could deliver a result that is of the same type.

//Here the child Class "Apartment" can not perform a bedroom upgrade, so it violates the "Liskov Substitution Principle"
//"If S is a subtype of T, then objects of type T in a program may be replaced with objects of type S without altering any of the desirable properties of that program."

int main() {
	return 0;
}
