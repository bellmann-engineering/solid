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

public:		//This creates the product
	Product(string title, float price, float taxRate) {
		this->title = title;
		this->price = price;
		this->taxRate = taxRate;
	}

	float calculateTax() {	//This method calculates the tax rate
		return this->price * this->taxRate;
	}

};

int main() {
	Product tshirt = Product("Hugo Boss", 20.00, 19.00);
	float taxesForShirt = tshirt.calculateTax();
	return 0;
}
