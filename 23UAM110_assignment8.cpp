#include <iostream>
#include <fstream>
#include <string>

class FileEncryptor {
private:
    std::string filename;
    int encryptionKey;

    // Caesar Cipher Encryption
    char encryptChar(char ch) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            return (ch - base + encryptionKey) % 26 + base;
        }
        return ch;
    }

    // Caesar Cipher Decryption
    char decryptChar(char ch) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            return (ch - base - encryptionKey + 26) % 26 + base;
        }
        return ch;
    }

public:
    // Constructor
    FileEncryptor(std::string fname, int key) {
        filename = fname;
        encryptionKey = key;
    }

    // Encrypt and write message to file
    void encryptAndWrite(std::string message) {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Error opening file for writing.\n";
            return;
        }

        for (char ch : message) {
            outFile << encryptChar(ch);
        }

        outFile.close();
        std::cout << "Message successfully encrypted and stored in " << filename << "\n";
    }

    // Read and decrypt content from file
    std::string readAndDecrypt() {
        std::ifstream inFile(filename);
        if (!inFile) {
            std::cerr << "Error opening file for reading.\n";
            return "";
        }

        std::string decryptedMessage;
        char ch;
        while (inFile.get(ch)) {
            decryptedMessage += decryptChar(ch);
        }

        inFile.close();
        return decryptedMessage;
    }

    // Display decrypted content
    void displayFileContents() {
        std::string decrypted = readAndDecrypt();
        if (!decrypted.empty()) {
            std::cout << "Decrypted Message: " << decrypted << "\n";
        }
    }
};

// Main function to demonstrate the program
int main() {
    FileEncryptor myEncryptor("data.txt", 3);  // Caesar Cipher with shift 3
    std::string message;

    std::cout << "Enter a message to encrypt: ";
    std::getline(std::cin, message);

    myEncryptor.encryptAndWrite(message);

    std::cout << "\nReading and decrypting file...\n";
    myEncryptor.displayFileContents();

    return 0;
}
