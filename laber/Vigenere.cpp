#include <iostream>
#include <string>

using namespace std;

string encryptVigenere(string plainText, string key) {
    string text = "";
    int banali = key.length();
    
    for (int i = 0; i < plainText.length(); ++i) {
        char plainChar = plainText[i];
        char keyChar = key[i % banali];
        char encryptedChar = ((plainChar + keyChar) % 26) + 'A'; 
        text += encryptedChar;
    }
    
    return text;
}

string decryptVigenere(string encryptedText, string key) {
    string decryptedText = "";
    int keyLength = key.length();
    
    for (int i = 0; i < encryptedText.length(); ++i) {
        char encryptedChar = encryptedText[i];
        char keyChar = key[i % keyLength];
        char decryptedChar = ((encryptedChar - keyChar + 26) % 26) + 'A'; 
        decryptedText += decryptedChar;
    }
    
    return decryptedText;
}

int main() {
    string original = "HELLO";
    string key = "KEY";
    
    string popoxvac = encryptVigenere(original, key);
    string hetadarc = decryptVigenere(popoxvac, key);
    
    cout << "Original Text: " << original << endl;
    cout << "Encrypted Text: " << popoxvac << endl;
    cout << "Decrypted Text: " << hetadarc << endl;
    
    return 0;
}
