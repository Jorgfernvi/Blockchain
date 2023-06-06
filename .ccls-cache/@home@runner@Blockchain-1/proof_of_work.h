#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
// #include <openssl/sha.h>
#include <openssl>

std::string sha256(const std::string& str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.length());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
    }
    return ss.str();
}

int main() {
    // Datos del bloque
    int version = 1;
    std::string prev_block = "0000000000000000000000000000000000000000000000000000000000000000";
    std::string merkle_root = "6dcd83d15efad1c376cd9a42a1694c0dc3e7498c6634b7a0414f4a285b7b5c77";
    int timestamp = 1622152949;
    std::string pattern = "0000";  // Patrón inicial deseado

    // Bucle de minería
    int nonce = 0;
    while (true) {
        // Concatenar los datos del bloque con el nonce
        std::stringstream ss;
        ss << version << prev_block << merkle_root << timestamp << nonce;
        std::string data = ss.str();

        // Calcular el hash del bloque utilizando SHA-256
        std::string block_hash = sha256(data);

        // Verificar si el hash del bloque cumple con el patrón inicial
        if (block_hash.substr(0, pattern.length()) == pattern) {
            break;
        }

        nonce++;
    }

    // Imprimir el resultado
    std::cout << "Nonce encontrado: " << nonce << std::endl;
    std::cout << "Hash del bloque: " << block_hash << std::endl;

    return 0;
}