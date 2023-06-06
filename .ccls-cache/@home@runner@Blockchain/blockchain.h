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

template<typename TK>
class Blockchain{
  private:
    map<size_t, Block<TK>*> block_map;

  public:
    void add(Block<TK>& new_block) {
  
      if (!block_map.empty() && block_map.rbegin()->second->getHashCode() != new_block.getHashCode()) {
          cout << "Error: El hash_code del nuevo bloque no coincide con el bloque anterior." << endl;
          return;
      }
  
      block_map[new_block.getHashCode()] = new Block<TK>(new_block);
    }
  
    Block<TK>* getBlock(size_t hash_code) {
      auto it = block_map.find(hash_code);
      if (it != block_map.end()) {
          return it->second;
      }
      return nullptr;
    }

    double proof_of_work(Block<TK>& block){
      computed_hash = block.compute_hash()
      
    }
};