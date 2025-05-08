#include <iostream>
using namespace std;

char encryptChar(char p, char k) {
    return ((p + k - 2 * 'A') % 26) + 'A';
}

int main() {
    string plaintext = "HELLOVIGENERE", keyword = "KEY";
    string ciphertext = "";

    for (int i = 0; i < plaintext.length(); i++) {
        ciphertext += encryptChar(plaintext[i], keyword[i % keyword.length()]);
    }

    cout << "Ciphertext: " << ciphertext << endl;
    return 0;
}
