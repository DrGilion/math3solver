#include <iostream>
#ifndef VEKTOR_H
#define VEKTOR_H

using namespace std;

class Vektor{
    friend ostream& operator << (ostream& out, const Vektor& v);
    friend istream& operator >> (istream& in, Vektor& v);
    friend bool operator == (const double d[], const Vektor& c);
    public:
        Vektor(int a);
        Vektor(const double values[]);
        Vektor(const Vektor& v);
        double size(void);
        double Summennorm(void)const;
        double Euklidnorm(void)const;
        double Maximumnorm(void)const;
        Vektor& operator = (const Vektor& v);
        Vektor& operator += (const Vektor& v);
        Vektor& operator += (const double d[]);
        bool operator == (const Vektor& v) const;
        bool operator == (const double d[]) const;
        Vektor operator + (const Vektor& v) const;
        double& operator [] (int index) const;
        ~Vektor();
    private:
        double* elems;
        int sz;
};

#endif // VEKTOR_H
