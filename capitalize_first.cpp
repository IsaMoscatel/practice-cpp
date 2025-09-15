#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to capitalize first letter and lowercase the rest
string capitalizeFirst(string str) {
    if (str.empty())
        return str;

    for (char& c : str) {
        c = tolower(c);
    }

    str[0] = toupper(str[0]);
    return str;
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    cout << "Result: " << capitalizeFirst(word) << endl;

    return 0;
}
