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
#include "stl/maxheap.h"

using namespace std;
void printMenu() {
    cout << "------ Menú ------" << endl;
    cout << "1. Buscar registros por rango de monto" << endl;
    cout << "2. Buscar registros por rango de fechas" << endl;
    cout << "3. Buscar registros por remitente" << endl;
    cout << "4. Buscar registros por destinatario" << endl;
    cout << "5. Extraer registro con el monto más alto" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opción: ";
}


void searchByAmountRange(Blockchain<Record>& chain) {
    float rango_ini, rango_fin;
    cout << "Ingrese el rango inicial de monto: ";
    cin >> rango_ini;
    cout << "Ingrese el rango final de monto: ";
    cin >> rango_fin;

    cout << "Búsqueda por rango de monto" << endl;
    chain.searchByAmountRange(rango_ini, rango_fin);
}

void searchByDateRange(Blockchain<Record>& chain) {
    string fecha_ini, fecha_fin;
    cout << "Ingrese la fecha inicial (mm/dd/yyyy): ";
    cin >> fecha_ini;
    cout << "Ingrese la fecha final (mm/dd/yyyy): ";
    cin >> fecha_fin;

    cout << "Búsqueda por rango de fechas" << endl;
    chain.searchByDateRange(fecha_ini, fecha_fin);
}

void searchByRemitente(ChainHash<string, Record*>& hash) {
    string remitente;
    cout << "Ingrese el nombre del remitente: ";
    cin.ignore();
    getline(cin, remitente);

    cout << "Búsqueda por remitente" << endl;
    hash.searchByRemitente(remitente);
}

void searchByDestinatario(ChainHash<string, Record*>& hash) {
    string destinatario;
    cout << "Ingrese el nombre del destinatario: ";
    cin.ignore();
    getline(cin, destinatario);

    cout << "Búsqueda por destinatario" << endl;
    hash.searchByDestinatario(destinatario);
}

void extractMaxRecord(MaxHeap<Record*>& maxHeap) {
    cout << "Búsqueda del registro con el monto más alto" << endl;
    maxHeap.extraerMaximo();
}


int main() {
    std::vector<std::vector<std::string>> data;
    std::ifstream file("datos_proyecto.csv");
    if (!file) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    std::string line;

    Blockchain<Record>* chain = new Blockchain<Record>();
    Block<Record>* block = new Block<Record>();
    ChainHash<string, Record*> myhash;
    MaxHeap<Record*> maxHeap;

    Record* record;

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string value;

        while (std::getline(ss, value, ',')) {
            row.push_back(value);
        }

        if (block->getSize() == block->getCapacity()) {
            chain->addBlock(block);
            block = new Block<Record>();
        } else {
            Record* new_record = new Record();
            new_record->remitente = row[0];
            new_record->destinatario = row[1];
            new_record->monto = stod(row[2]);
            new_record->fecha = row[3];

            block->insert(new_record);

            myhash.insert(make_pair(new_record->remitente, new_record));

            maxHeap.insertar(new_record->monto, new_record);
        }

        data.push_back(row);
    }

  int option = 0;
    while (option != 6) {
        printMenu();
        cin >> option;

        if (option == 1) {
            searchByAmountRange(*chain);
        } else if (option == 2) {
            searchByDateRange(*chain);
        } else if (option == 3) {
            searchByRemitente(myhash);
        } else if (option == 4) {
            searchByDestinatario(myhash);
        } else if (option == 5) {
            extractMaxRecord(maxHeap);
        } else if (option == 6) {
            cout << "Saliendo del programa..." << endl;
        } else {
            cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
        }

        cout << "--------------------------" << endl;
    }

    delete chain;
    delete block;

    return 0;
}





