#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <sstream>
#include <map>
using namespace std;

template<typename TK>
struct Registro {
  string remitente;
  string destinatario;
  double monto;
  string fecha;

};