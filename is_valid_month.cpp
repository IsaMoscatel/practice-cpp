#include <iostream>
#include <string>
using namespace std;

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

int main() {
    string input;
    cout << "Enter a month: ";
    cin >> input;

    if (isValidMonth(input))
        cout << input << " is a valid month." << endl;
    else
        cout << input << " is not a valid month." << endl;

    return 0;
}
