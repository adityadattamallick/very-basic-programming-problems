#include <iostream>
#include <string>

std::string encrypt(std::string message, std::string alphabet, std::string encryption_key);

std::string decrypt(std::string message, std::string encryption_key, std::string alphabet);

int main() {
    const std::string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789"};
    const std::string encrytion_key{"qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM)_+=-[]{}"};

    std::string message{};
    std::string encrypted_message{};
    std::string decrypted_message{};

    getline(std::cin, message);

    encrypted_message = encrypt(message, alphabet, encrytion_key);

    std::cout << encrypted_message << std::endl;

    decrypted_message = decrypt(encrypted_message, encrytion_key, alphabet);

    std::cout << decrypted_message << std::endl;

    return 0;
}

std::string encrypt(std::string message, std::string alphabet, std::string encryption_key) {
    std::string encrypted_message{};

    for (char c: message) {
        if (alphabet.find(c) != std::string::npos) {
            encrypted_message += encryption_key.at(alphabet.find(c));
        } else {
            encrypted_message += c;
        }
    }

    return encrypted_message;
}

std::string decrypt(std::string encrypted_message, std::string encryption_key, std::string alphabet) {
    std::string decrypted_message{};

    for (char c: encrypted_message) {
        if (encryption_key.find(c) != std::string::npos) {
            decrypted_message += alphabet.at(encryption_key.find(c));
        } else {
            decrypted_message += c;
        }
    }

    return decrypted_message;
}
