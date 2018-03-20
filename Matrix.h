#include <iostream>
#include <string>
#include <stdexcept>
#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

class Matrix{
    friend ostream& operator<<(ostream& out,const Matrix& m);
    public:
        Matrix(int pheight,int pwidth);
        Matrix(const Matrix& other);
        ~Matrix();
        double Determinante(void) const;
        double ZeilenSummennorm(void)const;
        double SpaltenSummennorm(void)const;
        double Frobeniusnorm(void)const;
        bool Zeilensummenkriterium(void)const;
        ostream& LU(ostream& out)const;
        Matrix& operator=(const Matrix& other);
        double& operator()(int index1,int index2) const;
    private:
        double **matrix;
        int height;
        int width;
};

#endif // MATRIX_H
