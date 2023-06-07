#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
#include <sstream>
#include <iomanip>
#include "stl/chainhash.h"
#include "stl/bst.h"


#include "blockchain.h"
using namespace std;


int main() {
    std::vector<std::vector<std::string>> data;  // Vector para almacenar los datos del CSV
    std::ifstream file("datos_proyecto.csv");  // Abre el archivo CSV
    if (!file) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(file, line)) {  // Lee cada línea del archivo
        std::vector<std::string> row;  // Vector para almacenar los valores de una línea
        std::stringstream ss(line);
        std::string value;
        while (std::getline(ss, value, ',')) {  // Divide la línea en valores separados por comas
            row.push_back(value);  // Agrega cada valor al vector de la fila
        }

        data.push_back(row);  // Agrega la fila al vector de datos
    }

    Blockchain<int>* blockchain = new Blockchain<int>();

    int block_index = 0;

    // Imprime los datos almacenados
    for (const auto& row : data) {
        Record record;

        record.remitente = row[0];
        record.destinatario = row[1];
        record.monto = stod(row[2]);
        record.fecha = row[3];

        blockchain->addRecord(record);

        for (const auto& value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;

}

