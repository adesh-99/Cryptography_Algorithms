#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int s) {
    string result = "";

   
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += char(int(text[i] + s - 65) % 26 + 65);
        }
        else if (islower(text[i])) {
            result += char(int(text[i] + s - 97) % 26 + 97);
        }
        else {
            result += text[i];
        }
    }
    return result;
}

string decrypt(string text, int s) {
    return encrypt(text, 26 - s);
}

int main() {
    string text;
    int shift;

    cout << "Enter the text to be encrypted: ";
    getline(cin, text);

    cout << "Enter the shift value: ";
    cin >> shift;

    string encryptedText = encrypt(text, shift);
    string decryptedText = decrypt(encryptedText, shift);

    cout << "Encrypted Text: " << encryptedText << endl;
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
    