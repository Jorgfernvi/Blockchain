# Desarrollo de BlockChain utilizando estructura de datos 

### Descripción
Este proyecto es un ejemplo de implementación de un blockchain básico que utiliza una estructura de datos específica para almacenar y gestionar las transacciones. Proporciona una representación simplificada de cómo funcionan las transacciones en un entorno de blockchain, junto con la implementación de una estructura de datos adecuada para su almacenamiento eficiente.

El objetivo principal de este ejemplo es demostrar cómo una estructura de datos puede mejorar la eficiencia y la gestión de las transacciones en un blockchain. Además de los conceptos fundamentales de las transacciones y la verificación criptográfica, este ejemplo incorpora una estructura de datos específica para la organización y el acceso rápido a las transacciones.

### Características

1.-Creación y gestión de billeteras (wallets)  
2.-Generación de transacciones  
3.-Verificación de firmas digitales  
4.-Validación y registro de transacciones en la cadena de bloques  

## Tabla de contenidos

- [Instalación](#instalación)
- [Uso](#uso)
- [Ejemplos](#ejemplos)
- [Contribución](#contribución)
- [Licencia](#licencia)

## Instalación

1. Clona el repositorio:

```bash
git clone https://github.com/Jorgfernvi/Blockchain-1
```

### Generador de hash SHA-256 para bloques de datos
Este programa implementa un generador de hash utilizando el algoritmo SHA-256 para bloques de datos. El código está escrito en C++ y utiliza la biblioteca estándar de C++.

#### Requisitos y dependencias
1.-Compilador que admita el estándar C++    
2.- Bibliotecas estándar de C++  

#### Explicación del código
El código consta de dos archivos: "main.cpp" y "block.cpp". "main.cpp" contiene la función principal y "block.cpp" implementa la clase Block.

La función generateHash calcula el hash SHA-256 para un bloque de datos proporcionado. Toma como parámetro un objeto Block<TK> y realiza los siguientes pasos:

1.- Obtiene el hash anterior y el hash actual del bloque.  
2.-Inicializa el timestamp y el patrón inicial para los hashes.  
3.-Itera hasta encontrar un valor de nonce válido que genere un hash que coincida con el patrón.  
4.-Concatena los datos del bloque, incluyendo el número de bloque, el hash anterior, el hash actual, el timestamp, el nonce y los datos adicionales.  
5.-Utiliza la función sha256 para calcular el hash SHA-256 del bloque.  
6.-Imprime el nonce encontrado y el hash resultante.  
La función sha256 implementa el algoritmo SHA-256, que divide el mensaje en bloques de 64 bytes y realiza varias operaciones para generar el hash final.  
  
  
#### Uso del código
Para utilizar el generador de hash en tu programa o proyecto, sigue estos pasos:

1.-Incluye los archivos de encabezado necesarios, como "block.h".  
2.-Crea un objeto Block<TK> con los datos que deseas procesar.  
3.-Llama a la función generateHash pasando el objeto Block<TK> como parámetro.  
4.-El resultado se mostrará en la salida estándar.  
  
#### Bloque
  La clase Block es una implementación de un bloque en una cadena de bloques, que se utiliza comúnmente en tecnologías como blockchain. Un bloque contiene un conjunto de registros y tiene propiedades como un índice, un código hash, un código hash anterior, un nonce, entre otros.
  
  
#### Atributos de la clase Block
index: Representa el índice del bloque en la cadena.  
nonce: Es un número utilizado en la minería de bloques para encontrar un código hash válido.  
records: Un contenedor de registros que se almacenan en el bloque.  
string_records: Una representación en cadena de los registros dentro del bloque.  
current_hash_code: El código hash actual del bloque.  
previous_hash_code: El código hash del bloque anterior en la cadena.  
record_index: El índice actual utilizado para insertar registros.  
capacity: La capacidad máxima de registros que puede almacenar el bloque.  

  
  
#### Métodos de la clase Block
setIndex(int index): Establece el índice del bloque.  
setPreviousHashCode(string previous_hash_code): Establece el código hash del bloque anterior.  
getIndex(): Devuelve el índice del bloque.  
getNonce(): Devuelve el nonce del bloque.  
getDatos(): Devuelve los datos del bloque.  
getHashCode(): Devuelve el código hash actual del bloque.  
getPreviousHashCode(): Devuelve el código hash del bloque anterior.  
getSize(): Devuelve la cantidad de registros almacenados en el bloque.  
getCapacity(): Devuelve la capacidad máxima del bloque.  
insert(Record* new_record): Inserta un nuevo registro en el bloque.  
generateHash(): Genera el código hash del bloque utilizando el algoritmo SHA-256.  

  
#### Uso de la clase Block
Para utilizar la clase Block, se siguen los siguientes pasos:

Crear un objeto Block, por ejemplo: Block<Record> block;  
Establecer el índice y el código hash del bloque anterior utilizando los métodos setIndex() y setPreviousHashCode(), respectivamente.  
Insertar registros en el bloque utilizando el método insert(), pasando un puntero al registro.  
Generar el código hash del bloque utilizando el método generateHash().  
Acceder a los atributos del bloque según sea necesario, utilizando los métodos getIndex(), getHashCode(), getNonce(), etc. 
