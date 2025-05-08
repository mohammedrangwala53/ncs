#include <iostream>
using namespace std;

char decryptChar(char c, char k) {
    return ((c - k + 26) % 26) + 'A';
}

int main() {
    string ciphertext = "LXFOPVEFRNHR", keyword = "LEMON";
    string plaintext = "";

    for (int i = 0; i < ciphertext.length(); i++) {
        plaintext += decryptChar(ciphertext[i], keyword[i % keyword.length()]);
    }

    cout << "Decrypted text: " << plaintext << endl;
    return 0;
}
