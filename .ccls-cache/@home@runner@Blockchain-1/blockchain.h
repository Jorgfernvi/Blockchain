#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <sstream>
#include <map>
#include "block.h"
using namespace std;

template<typename T>
class Blockchain{
private:
    map<size_t, Block<T>*> block_map;
    ChainHash<int, Record*> unconfirmed_records;
    string string_records;

    Block<T>* last_block;

    int record_index;
    int block_index;
    int block_size;

public:
    Blockchain() {
        block_size = 10;
        block_index = 0;
        record_index = 0;
        string_records = "";
    };
    void addRecord(Record* new_record);
    void addBlock(Block<T> new_block);
    T getBlock(size_t hash_code);
};

template <typename T>
void Blockchain<T>::addRecord(Record new_record) {
    unconfirmed_records.insert(make_pair(record_index, new_record));
    string_records.append(new_record->full_data());

    if (record_index + 1 == block_size) {
        Block<Record>* block = new Block<Record>();
        block->insert(block_index, unconfirmed_records, last_block->getPreviousHashCode(), string_records);
        block->generateHash();
        record_index = 0;
        block_index += 1;
        string_records = "";
    } else {
        record_index += 1;
    }
}

template <typename T>
void Blockchain<T>::addBlock(Block<T> new_block) {
    if (!block_map.empty() && block_map.rbegin()->second->getHashCode() != new_block.getHashCode()) {
        cout << "Error: El hash_code del nuevo bloque no coincide con el bloque anterior." << endl;
        return;
    }

    block_map[block_index] = new Block<T>(new_block);
    last_block = new_block;
    record_index = 0;
}

template <typename T>
T Blockchain<T>::getBlock(size_t hash_code) {
    auto it = block_map.find(hash_code);
    if (it != block_map.end()) {
        return it->second;
    }
    return nullptr;
}

