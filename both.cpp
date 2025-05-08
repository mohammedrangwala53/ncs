#include <iostream>
using namespace std;

// Function to repeat keyword to match message length
string repeatKeyword(string keyword, int length) {
    string repeated = "";
    for (int i = 0; i < length; i++) {
        repeated += keyword[i % keyword.length()];
    }
    return repeated;
}

// Encrypt one character
char encryptChar(char p, char k) {
    return ((p + k - 2 * 'A') % 26) + 'A';
}

// Decrypt one character
char decryptChar(char c, char k) {
    return ((c - k + 26) % 26) + 'A';
}

int main() {
    string input, keyword, output = "";
    int choice;

    cout << "Vigenère Cipher Program\n";
    cout << "1. Encrypt\n2. Decrypt\nEnter choice (1 or 2): ";
    cin >> choice;

    cout << "Enter text (UPPERCASE letters only): ";
    cin >> input;

    cout << "Enter keyword (UPPERCASE letters only): ";
    cin >> keyword;

    string fullKey = repeatKeyword(keyword, input.length());

    for (int i = 0; i < input.length(); i++) {
        if (choice == 1)
            output += encryptChar(input[i], fullKey[i]);
        else if (choice == 2)
            output += decryptChar(input[i], fullKey[i]);
        else {
            cout << "Invalid choice.\n";
            return 1;
        }
    }

    cout << ((choice == 1) ? "Encrypted" : "Decrypted") << " text: " << output << endl;
    return 0;
}
