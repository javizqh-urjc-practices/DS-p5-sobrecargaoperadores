/* Coleccion.cpp
Practical exercise 5.
Coleccion class member -and friend- function definitions.
*/
#include <iostream>
#include <iomanip> // I/O manipulation library
#include "Coleccion.h" // Coleccion class definition

using namespace std;

ostream &operator<< (std::ostream &output, const Coleccion &coleccion){
  for (size_t i = 0; i < coleccion.getSize(); ++i)
    output << coleccion[i] << " ";
  return output;
}

istream &operator>> (std::istream &input, Coleccion &coleccion){
  for (size_t i = 0; i < coleccion.getSize(); ++i)
    input >> coleccion[i];
    input.ignore(1);
  return input;
}

// default constructor for class Coleccion (default size 10)
// considering arraySize > 0, otherwise an exception should be thrown
Coleccion::Coleccion (int arraySize): size (arraySize), ptr (new int [size]) {
  for (size_t i = 0; i < size; ++i)
    ptr [i] = 0; // set pointer-based array element
} // end Coleccion default constructor

// copy constructor for class Coleccion; must receive a reference to a Coleccion
Coleccion::Coleccion (const Coleccion &arrayToCopy): size (arrayToCopy.size), ptr (new int [size]) {
  for (size_t i = 0; i < size; ++i)
    ptr [i] = arrayToCopy.ptr [i]; // copy into object
} // end Coleccion copy constructor

size_t Coleccion::getSize () const {
  return size;
}

const Coleccion & Coleccion::operator= (const Coleccion &coleccion){
  for (size_t i = 0; i < size; ++i)
    ptr [i] = coleccion.ptr [i]; // copy into object
}

bool Coleccion::operator== (const Coleccion &coleccion) const{
  if (this->getSize() != coleccion.getSize()) return false; // If the size is different, then they are not the same

  for (size_t i = 0; i < coleccion.getSize(); ++i){
    if (coleccion[i] != (*this)[i]) return false; // If an element is different, then they are not the same
  }

  return true; // If all the previous elements are the same, then they are the same
}

int & Coleccion::operator[] (int index){
  if (index < 0 || index >= this->getSize()) throw std::logic_error("nullptr");
  return ptr[index];
}

int Coleccion::operator[] (int index) const {
  if (index < 0 || index >= this->getSize()) throw std::logic_error("Bigger size than before");
  return ptr[index];
}

// destructor for class Coleccion
Coleccion::~Coleccion() {
  delete [] ptr; // release pointer-based array space
} // end destructor
