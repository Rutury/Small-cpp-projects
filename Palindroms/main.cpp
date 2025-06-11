#include <iostream>
#include <string>

using namespace std;

bool isPalindrom(string& s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] == ' ') {
            ++i;
        } else if (s[j] == ' ') {
            --j;
        } else if (s[i] == s[j]) {
            ++i;
            --j;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    if (isPalindrom(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
