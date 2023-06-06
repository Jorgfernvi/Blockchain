#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include "stl/chainhash.h"
#include "stl/bst.h"
#include "openssl"
using namespace std;
/*
int main ()
{
  ChainHash<string, int> myhash;
  myhash.insert (make_pair<string, int>("jorge", 24));
  myhash.insert (make_pair<string, int>("Judith", 22));
  myhash.insert (make_pair<string, int>("juan", 35));
  myhash.insert (make_pair<string, int>("alfredo", 27));
  myhash.insert (make_pair<string, int>("marta", 25));
  myhash.insert (make_pair<string, int>("cristian", 100));
  myhash.insert (make_pair<string, int>("ana", 26));
  myhash.insert (make_pair<string, int>("ronald", 28));
  myhash.insert (make_pair<string, int>("dino", 65));
  myhash.insert (make_pair<string, int>("Juan Jose", 32));
  myhash.insert (make_pair<string, int>("Bruno", 23));
  myhash.insert (make_pair<string, int>("juan", 33));
  myhash.insert (make_pair<string, int>("Jose", 30));
  myhash.insert (make_pair<string, int>("carlos", 31));
  myhash.insert (make_pair<string, int>("roberth",44));  
  myhash.insert (make_pair<string, int>("miguel", 39));

  std::cout << "Buckets:\n";
  for ( int i = 0; i < myhash.bucket_count(); ++i) {
    std::cout << "bucket #" << i << " contains ("<<myhash.bucket_size(i)<<"):";
    for ( auto local_it = myhash.begin(i); local_it!= myhash.end(i); ++local_it )
      std::cout << " (" << local_it->first << ":" << local_it->second <<") ";
    std::cout << std::endl;
  }

  return 0;
}*/

int main(){
  BSTree<int,string> *bstree = new BSTree<int,string>();
  bstree->insert_r(make_pair<int,string>(8,"Bruno"));
  bstree->insert_r(make_pair<int,string>(3,"Daniel"));
  bstree->insert_r(make_pair<int,string>(1,"Roberth"));
  bstree->insert_r(make_pair<int,string>(6,"Raul"));
  bstree->insert_r(make_pair<int,string>(4,"Juan"));
  bstree->insert_r(make_pair<int,string>(7,"Manuel"));
  bstree->insert_r(make_pair<int,string>(10,"Heider"));
  bstree->insert_r(make_pair<int,string>(14,"Jorge"));
  bstree->insert_r(make_pair<int,string>(13,"Thomas"));
  cout<<"Display in order recursivo"<<endl;
  bstree->display_inorder_r();
  cout<<"Display in order iterativo"<<endl;
  bstree->display_inorder_i();
  cout<<"Display pre order recursivo"<<endl;
  bstree->display_preorder_r();
  cout<<"Display pre order iterativo"<<endl;
  bstree->display_preorder_i();
  cout<<"Display pos order recursivo"<<endl;
  bstree->display_postorder_r();
  cout<<"Display pos order iterativo"<<endl;
  bstree->display_postorder_i();
  cout<<"Minima llave: "<<bstree->get_minimum_r().first<<endl;
  cout<<"Minimo valor: "<<bstree->get_minimum_r().second<<endl;
  //cout<<"El sucesor de (8,Bruno) es: "<<bstree->succesor_i(make_pair<int,string>(14,"Bruno")).first<<endl;
}

