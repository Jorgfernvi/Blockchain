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
    string string_records;

    Block<Record>* last_block;

    int record_index;
    int block_index;
    int block_size;

public:
    Blockchain() {
        block_size = 2;
        block_index = 0;
        record_index = 0;
        string_records = "";
    };
    void addRecord(Record* new_record);
    void addBlock(Block<Record>* new_block);
    void mine(Block<Record>* block);
    int getBlockSize();
    Block<T> getBlock(int block_index);
};


template <typename T>
Block<T> Blockchain<T>::getBlock(int block_index) {
    auto it = block_map.find(block_index);
    if (it != block_map.end()) {
        return it->second;
    }
    return nullptr;
}

template <typename T>
int Blockchain<T>::getBlockSize() {
  return block_size;
}

template <typename T>
void Blockchain<T>::mine(Block<Record>* block) {
  string previous_hash_code = last_block !=nullptr ? last_block->getHashCode() : "";
  block->setIndex(block_index);
  block->setPreviousHashCode(previous_hash_code);
  block->proofOfWork();

  last_block = block;
  block_index += 1;

  cout << "ID " << block->getIndex() << endl;
  cout << "PreviousHashCode " << block->getPreviousHashCode() << endl;
  cout << "CurrentHashCode " << block->getHashCode() << endl;
  cout << "--" << endl;
}

