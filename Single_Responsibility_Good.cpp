#include <iostream>
using namespace std;

//We created a new class for the tax calculation
//Now every class has a single function

class Product{	//This class only creates a product

private:
	string title;
	float price;
	float taxRate;

public:
	Product(const string& title, float price, float taxRate){
		this->title = title;
		this->price = price;
		this->taxRate = taxRate;
	}

	float getPrice(){
		return this->price;
	}

	float getTaxRate(){
			return this->taxRate;
		}
};

class TaxCalculator {	//This class calculates only the tax

public:
	float calculateTax(Product p) {
		return p.getPrice() * p.getTaxRate();
	}
};

//If a class has many responsibilities,
//it increases the possibility of bugs because making changes to one of its responsibilities,
//could affect the other ones without you knowing.

//This principle aims to separate behaviours so that if bugs arise as a result of your change,
//it won’t affect other unrelated behaviours.


int main() {

	float germanRate = 19.0f;
	Product tshirt("Hugo Boss Shirt", 19.90f, germanRate);
	TaxCalculator calculator;
	cout << calculator.calculateTax(tshirt) << endl;

	return 0;
}
