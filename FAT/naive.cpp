#include <iostream>
using namespace std;

int main() {
    string text, pattern;
    cin >> text >> pattern;

    int pos = text.find(pattern);

    while(pos != -1) {
        cout << "Found at index: " << pos << endl;
        pos = text.find(pattern, pos + 1);
    }

    return 0;
}