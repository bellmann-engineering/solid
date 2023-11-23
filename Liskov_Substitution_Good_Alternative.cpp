#include <iostream>
using namespace std;

class Apartment {
public:
    string apartmentName;
    int squareFootage;
    int numberOfBedrooms;

    virtual void setSquareFootage(int sqft) {
        squareFootage = sqft;
    }

    virtual void upgrade() {
        // Default upgrade behavior
    }

    virtual void displayDetails() const {
        cout << "Apartment Name: " << apartmentName << endl;
        cout << "Square Footage: " << squareFootage << " sqft" << endl;
        cout << "Number of Bedrooms: " << numberOfBedrooms << endl;
    }
};

class PenthouseSuite : public Apartment {
public:
    PenthouseSuite() {
        numberOfBedrooms = 4;
        apartmentName = "Penthouse";
    }

    void setSquareFootage(int sqft) override {
        squareFootage = sqft;
    }

    void upgrade() override {
        // Upgrade behavior for PenthouseSuite
        squareFootage += 50;  // Different upgrade for PenthouseSuite
        numberOfBedrooms += 2;  // Different upgrade for PenthouseSuite
    }
};

class Studio : public Apartment {
public:
    Studio() {
        numberOfBedrooms = 0;
        apartmentName = "Studio";
    }

    void setSquareFootage(int sqft) override {
        squareFootage = sqft;
    }

    void upgrade() override {
        // Studio apartments do not have additional bedrooms in the upgrade
        squareFootage += 30;  // Different upgrade for Studio
    }
};

int main() {
    PenthouseSuite penthouse;
    Studio studio;

    penthouse.displayDetails();
    penthouse.upgrade();
    penthouse.displayDetails();

    studio.displayDetails();
    studio.upgrade();
    studio.displayDetails();

    return 0;
}
