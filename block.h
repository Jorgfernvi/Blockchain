#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <sstream>
#include <map>
#include "record.h"
using namespace std;

template<typename TK>
class Block {
  private:
    int numero_bloque;
    double nonce;
    Registro<TK> datos;
    size_t current_hash_code;
    size_t previous_hash_code;
  
  public:
    Block(int numero_bloque, double nonce, Registro<TK>& datos, size_t previous_hash_code) :
      numero_bloque(numero_bloque), nonce(nonce), datos(datos), previous_hash_code(previous_hash_code) {
      hash<string> hasher;
      stringstream ss;
      ss << numero_bloque << nonce << datos;
      current_hash_code = hasher(ss.str());
    }
  
    int getNumeroBloque(){
      return numero_bloque;
    }
  
    double getNonce(){
      return nonce;
    }
  
    string getDatos(){
      return datos;
    }
  
    size_t getHashCode(){
      return current_hash_code;
    }
  
    size_t getPreviousHashCode(){
      return previous_hash_code;
    }
  
    void insert(int nuevo_numero_bloque, double nuevo_nonce, Registro<TK>& nuevos_datos) {
      numero_bloque = nuevo_numero_bloque;
      nonce = nuevo_nonce;
      datos = nuevos_datos;
  
      hash<string> hasher;
      stringstream ss;
      ss << numero_bloque << nonce << datos;
      current_hash_code = hasher(ss.str());
    }

    void compute_hash(){
      
    }
};
