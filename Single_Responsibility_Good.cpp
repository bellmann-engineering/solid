#include <iostream>
#include <string>

class Product {
private:
    std::string title;
    float price;
    float taxRate;

public:
    Product(const std::string& title, float price, float taxRate)
        : title(title), price(price), taxRate(taxRate) {}

    float getPrice() const {
        return price;
    }

    float getTaxRate() const {
        return taxRate;
    }
};

class TaxCalculator {
public:
    float calculateTax(const Product& p) {
        return p.getPrice() * p.getTaxRate();
    }
};

int main() {
    float germanRate = 19.0f;
    Product tshirt("Hugo Boss Shirt", 19.90f, germanRate);
    TaxCalculator calculator;
    std::cout << calculator.calculateTax(tshirt) << std::endl;

    return 0;
}
