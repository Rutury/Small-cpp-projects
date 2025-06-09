#include <iostream>
#include <string>

using namespace std;

bool isValidSymbol(char c) { return c >= 33 && c <= 126; }

bool isValidPassword(const string& password) {
    if (password.length() < 8 || password.length() > 14) return false;
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasOther = 0;    
    for (char c : password) {
        if (!isValidSymbol(c)) return false;
        if (isupper(c)) hasUpper = 1;
        else if (islower(c)) hasLower = 1;
        else if (isdigit(c)) hasDigit = 1;
        else hasOther = 1;
    }
    
    return hasUpper + hasLower + hasDigit + hasOther >= 3;
}

int main() {
    string password;
    cin >> password;
    if (isValidPassword(password)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
