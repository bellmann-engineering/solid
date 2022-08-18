

#include <iostream>
using namespace std;

//This program is supposed to send weather notifications to an email or mobile phone
//The mobile phone is alerted if it is rainy, the e-mail is alerted if it is sunny

class Phone { 	//This class is creating a text alert for the mobile phone

public:
	string generateWeatherAlert(string weatherConditions) {
		string alert = "It is " + weatherConditions;
		return alert;
	}

};

class Emailer {		//This class is creating a text message for an e-mail

public:
	string generateWeatherAlert(string weatherConditions) {
		string alert = "It is " + weatherConditions;
		return alert;
	}

};

class WeatherTracker {

	//This class is supposed to track the current weather
	//and it also sends out messages to a mobile device or an email
	//but it is dependent on the Phone and Emailer class to create these messages first


public:
	string currentConditions;

	Phone phone;
	Emailer emailer;

	void setCurrentConditions(string weatherDescription) {		//The weather conditions are tracked
		currentConditions = weatherDescription;

		if (weatherDescription == "rainy") {	//and the text message created by the Phone class is send
			string alert = phone.generateWeatherAlert(weatherDescription);
			cout << alert << endl;
		}
		if (weatherDescription == "sunny") {	//same for the e-mail
			string alert = emailer.generateWeatherAlert(weatherDescription);
			cout << alert << endl;
		}

		//This class should not be dependent on the other classes to do its job
		//The "Dependency Inversion Principle" states
		//"High-level modules should not depend on low-level modules. Both should depend on the abstraction"
		//and "Abstractions should not depend on details. Details should depend on abstractions."

	}

};

int main() {
	return 0;
}
