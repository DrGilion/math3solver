#include "Vektor.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;


// Standard-Konstruktor
Vektor::Vektor(int a) {
    this->sz=a;
    elems = new double[a];
    cout<<"\nVektor fuellen pls! "<<endl;
    for (int n=0;n<sz;++n){
        cout<<"Wert "<<n+1<<" pls: ";
        cin>>elems[n];
        cin.clear();
        cin.ignore(256,'\n');
    }
}

// Weiterer Konstruktor
Vektor::Vektor(const double values[]) {
    this->sz=sizeof(values)/sizeof(values[0]);
  elems = new double[sz];
  for (int i = 0; i < sz; ++i)
    elems[i] = values[i];
}

// Copy-Konstruktor
Vektor::Vektor(const Vektor& v) {
  elems = NULL;  // Undefinierten Wert überschreiben, damit das
      // delete[] elems in operator= nicht abstuerzt
      // (delete NULL oder delete[] NULL hat keine Wirkung)
  *this = v;  // Zuweisungsoperator nutzen vermeidet redundanten Code
}

//Getter/Setter

double Vektor::size(){
    return sz;
}

//Rechenfunktionen

double Vektor::Summennorm()const{
    double norm=0;
    for (int i=0;i!=sz;++i){
        norm+=fabs(elems[i]);
    }
    return norm;
}

double Vektor::Euklidnorm()const{
    double norm=0;
    for (int i=0;i!=sz;++i){
        norm+=pow(elems[i],2);
    }
    return sqrt(norm);
}

double Vektor::Maximumnorm()const{
    double norm=0;
    for (int i=0;i!=sz;++i){
        if (fabs(elems[i])>norm) norm=fabs(elems[i]);
    }
    return norm;
}

// Zuweisungsoperatoren

Vektor& Vektor::operator = (const Vektor& v) {
  if (this ==  &v) return *this;   // Nichts zu tun
  delete[] elems;
  this->sz=v.sz;
  elems = new double[sz];
  for (int i = 0; i < sz; ++i)
    elems[i] = v.elems[i];
  return *this;
}

Vektor& Vektor::operator += (const Vektor& v) {
  if (this ==  &v) return *this;   // Nichts zu tun
   for (int i = 0; i < sz; ++i)
     elems[i] += v.elems[i];
   return *this;
}

Vektor& Vektor::operator += (const double d[]) {
  Vektor v(d);
  return *this += v;  // operator+=(const Vektor&) nutzen vermeidet Code-Redundanz
}

// Vergleichsoperatoren

bool Vektor::operator == (const Vektor& v) const {
  return *this == v.elems;  // Überladenen operator== aufrufen vermeidet Redundanz
}

bool Vektor::operator == (const double d[]) const {
  for (int i = 0; i < sz; ++i)
    if (elems[i] != d[i])
  return false;
  return true;
}

// Destruktor
Vektor::~Vektor() {
  delete[] elems;
}

// Weitere Operatoren

Vektor Vektor::operator + (const Vektor& v) const {
   Vektor result(*this);  // Copy-Konstruktor
   result += v;  // operator+= nutzen vermeidet Code-Redundanz
   return result;
}

double& Vektor::operator [] (int index) const {
  if (index < 0 || index >= sz)
    throw invalid_argument("Indexfehler");
 return elems[index];
}


bool operator == (const double d[], const Vektor& v) {
  return v == d; // v.operator==(double[]) aufrufen
}

ostream& operator << (ostream& out, const Vektor& v) {
   out << "(" << v.elems[0];
   for (int i = 1; i < v.sz; ++i) {
     out << ", " << v.elems[i];
   }
   out << ")";
   return out;
}

//Version für beliebiges N:
istream& operator >> (istream& in, Vektor& v) {
  double* values=new double[v.sz];
  for (int i = 0; i < v.sz; ++i)
    in >> values[i];
  v = Vektor(values); //  ruft Vektor::operator=(double[]) auf
  delete[] values;
  return in;
}
