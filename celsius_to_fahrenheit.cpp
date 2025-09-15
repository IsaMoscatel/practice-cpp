// This program converts Celcius temperatures to Farenheit tempetures

#include <iostream>

using namespace std; 
//Prototypes

double convertFahrenheitTemp(double temp);

int main()
{
	double celsiusInput;
	double fahrenheit;

	cout << "--------Convert Celsius to Fahrenheit--------\n\n\n";

	cout << "Enter a Celsius numbers to convert to Fahrenheit: \n\n";
	cin >> celsiusInput;
	cout << endl;

	fahrenheit = convertFahrenheitTemp(celsiusInput);
	
	cout << celsiusInput << " Celsius is " << fahrenheit << " Fahrenheit.\n\n";


}

double convertFahrenheitTemp(double temp) {

	double C = temp;

	double F = 9.0 / 5 * C + 32;

	return F;
}
