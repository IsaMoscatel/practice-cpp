// This program outputs a monthly sales tax report listing sales for the month and sales tax collected.

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype> // declares a set of functions to classify and transform individual characters (in this case, provides tolower and to upper)

using namespace std;

int main()
{
	//Function Prototypes
	string capitalizeFirst(string str);
	bool isValidMonth(const string & month);

	//Variables 
	string month;
	int year;
	double totalCollected, totalIncome, stateTaxAmout, countyTaxAmount, sales, totalTax;
	const double STATE_TAX = 0.04, COUNTY_TAX = 0.02;
	bool valid = false; // Tracks whether the input matches a month

	cout << "--------Monthly Sales Tax Report-------- \n\n\n";

	while (!valid) {
		cout << "Enter the month for sales tax report: \n\n";
		getline(cin, month);

		//validate input
		if (month.empty()) {
			cout << "You did not type anything. Please try again. \n";
			continue;
		}
		//Capitalize
		month = capitalizeFirst(month);

		//validate months
		if (isValidMonth(month))
			valid = true;

		cout << endl;
	}

	//get year
	cout << "Enter the year for sales tax report: \n\n";
	cin >> year;
	cout << endl;

	//validate year input
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Enter the year for sales tax report. \n\n";
		cin >> year;
		cout << endl;
	}

	//get total collected/total income
	cout << "Enter the total amount collected at cash register: \n\n";
	cin >> totalCollected;
	cout << endl;
	cout << endl;


	//calculate product sales
	sales = totalCollected / 1.06;

	//calculate taxes
	stateTaxAmout = sales * STATE_TAX;
	countyTaxAmount = sales * COUNTY_TAX;
	totalTax = stateTaxAmout + countyTaxAmount;


	//format output
	cout << fixed << setprecision(2);
	cout << "Month: " << month << " " << year << endl;
	cout << "--------------------\n\n";
	cout << "Total Collected:" << setw(15) << "$ " << totalCollected << endl;
	cout << "Sales: " << setw(24) << "$ " << sales << endl;
	cout << "County Sales Tax: " << setw(15) << "$ " << countyTaxAmount << endl;
	cout << "State Sales Tax: " << setw(16) << "$ " << stateTaxAmout << endl;
	cout << "Total Sales Tax: " << setw(15) << "$ " << totalTax << endl;
}




/****************************************************
Transforms the fisrt letter of the word in Uppercase

*****************************************************
*/

string capitalizeFirst(string str) {
	if (str.empty())
		return str;

	for (char& c : str) {
		c = tolower(c);
	}
	str[0] = toupper(str[0]);
	return str;
}

/****************************************************
Checks if a string is a valid month

*****************************************************
*/

bool isValidMonth(const string &month) {
	string months[] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};

	for (string m : months) {
		if (month == m)
			return true;
	}
	return false;
}

