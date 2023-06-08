#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
#include <sstream>
#include <iomanip>
#include "stl/bst.h"

#include "blockchain.h"
using namespace std;


int main() {
    std::vector<std::vector<std::string>> data;
    std::ifstream file("datos_proyecto.csv");
    if (!file) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    std::string line;

    Blockchain<int>* chain = new Blockchain<int>();
    Block<Record>* block = new Block<Record>();
    ChainHash<string, Record*> myhash;
  
  
    Record* record;

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string value;
      
        while (std::getline(ss, value, ',')) {
            row.push_back(value);
        }
        
        if (block->getSize() == block->getCapacity()) {
          chain->mine(block);
        } else {
          Record* new_record = new Record();
          new_record->remitente = row[0];
          new_record->destinatario = row[1];
          new_record->monto = stod(row[2]);
          new_record->fecha = row[3];
  
          block->insert(new_record);
          
          myhash.insert(make_pair(new_record->remitente,new_record));
        }
      
        data.push_back(row);
    }
    cout<<"Ingrese nombre de remitente a buscar"<<endl;
    
  
    return 0;

}

