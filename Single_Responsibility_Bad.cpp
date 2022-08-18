#include <iostream>
using namespace std;

//This program is supposed to create Products and calculate the tax for them
//This all is handled by the product class, which is against the "Single Responsibility Principle"
//-A class should have a single responsibility

class Product {

private:
	string title;
	float price;
	float taxRate;

public:		//This method creates the product
	void Constructor(string title, float price, float taxRate) {
		this->title = title;
		this->price = price;
		this->taxRate = taxRate;
	}

	float calculateTax() {	//This method calculates the tax rate
		return this->price * this->taxRate;
	}

};

int main() {
	return 0;
}
