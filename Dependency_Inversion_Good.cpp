
#include <iostream>
using namespace std;

//Again we have a Program that is supposed to track the weather
//But this time we are using the Dependency Inversion Principle

class Notifier {

public:
	void alertWeatherConditions(string weatherConditions) {
	}

};

class EmailClient : public Notifier {

	//We also have one class for the e-mail. But this time it sends the message directly after creating it


public:
	void alertWeatherConditions(string weatherConditions) {
		if (weatherConditions == "sunny")
			cout << "It is sunny" << endl;
	}
};

class MobileDevice : public Notifier {

	//For mobile devices it works the same

public:
	void alertWeatherConditions(string weatherConditions) {
		if (weatherConditions == "rainy")
			cout << "It is rainy" << endl;
	}

};

class WeatherTracker {

	//Now our tracker has only one job. To get and set the current weather conditions.
	//It is no longer dependent on other classes


public:
	string currentConditions;

	void setCurrentConditions(string weatherDescription) {
		currentConditions = weatherDescription;
	}

	string notify(Notifier notifier) {
		notifier.alertWeatherConditions(currentConditions);
		return currentConditions;
	}

};

int main() {
	return 0;
}

