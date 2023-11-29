#include <iostream>
#include <string>

using namespace std;

string encryptVigenere(string plainText, string key) {
    string encryptedText = "";
    int keyLength = key.length();
    
    for (int i = 0; i < plainText.length(); ++i) {
        char plainChar = plainText[i];
        char keyChar = key[i % keyLength];
        char encryptedChar = ((plainChar + keyChar) % 128); 
        encryptedText += encryptedChar;
    }
    
    return encryptedText;
}

string decryptVigenere(string encryptedText, string key) {
    string decryptedText = "";
    int keyLength = key.length();
    
    for (int i = 0; i < encryptedText.length(); ++i) {
        char encryptedChar = encryptedText[i];
        char keyChar = key[i % keyLength];
        char decryptedChar = ((encryptedChar - keyChar + 128) % 128); 
        decryptedText += decryptedChar;
    }
    
    return decryptedText;
}

int main() {
    string plainText = "HELLO, World! 123";
    string key = "KEY";
    
    string encryptedText = encryptVigenere(plainText, key);
    string decryptedText = decryptVigenere(encryptedText, key);
    
    cout << "Original Text: " << plainText << endl;
    cout << "Encrypted Text: " << encryptedText << endl;
    cout << "Decrypted Text: " << decryptedText << endl;
    
    return 0;
}
