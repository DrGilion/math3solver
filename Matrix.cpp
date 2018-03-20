#include "Matrix.h"
#include <iostream>
#include <math.h>
#include <limits>
#include <stdexcept>

using namespace std;

ostream& operator<<(ostream& out,const Matrix& m){
    for (int i=0;i<m.height;++i){     //Print
        out<<"[";
        for (int j=0;j<m.width;++j){
            out<<m.matrix[i][j];
            if (j!=m.width-1) out<<",\t";
        }
        out<<"]\n";
    }
    out<<endl;
    return out;
}
//Konstruktor
Matrix::Matrix(int pheight,int pwidth):
    height(pheight),width(pwidth){
    matrix=new double*[height];
    for (int n=0;n<height;++n){     //Allocate
        matrix[n]=new double[width];
    }
    cout<<"\nMatrix fuellen pls! "<<endl;
    for (int i=0;i<height;++i){     //Fill
        for (int j=0;j<width;++j){
            cout<<"["<<i<<"]["<<j<<"] pls: ";
            cin>>matrix[i][j];
            cin.clear();
            cin.ignore(256,'\n');
        }

    }
}
//Copy-Konstruktor
Matrix::Matrix(const Matrix& other){
    matrix=NULL;
    *this=other;
}

//Rechenfunktionen

double Matrix::Determinante() const{
    if(height!=width){
        cout<<"Determinanten nur bei NxN Matrizen"<<endl;
        return sqrt(-1);
    }
    if (height==1){throw invalid_argument("Indexfehler");
        return matrix[0][0];
    }
    if (height==2){
        return (matrix[0][0]*matrix[1][1])-(matrix[1][0]*matrix[0][1]);
    }
    if (height==3){
        return (matrix[0][0]*matrix[1][1]*matrix[2][2])+(matrix[0][1]*matrix[1][2]*matrix[2][0])+(matrix[0][2]*matrix[1][0]*matrix[2][1])-(matrix[0][2]*matrix[1][1]*matrix[2][0])-(matrix[0][1]*matrix[1][0]*matrix[2][2])-(matrix[0][0]*matrix[1][2]*matrix[2][1]);
    }
    return 1;
}

double Matrix::ZeilenSummennorm()const{
    double norm=0;
    for (int i=0;i<height;++i){
        double tmp=0;
        for(int j=0;j<width;++j){
            tmp+=fabs(matrix[i][j]);
        }
        if(tmp>norm) norm=tmp;
    }
    return norm;
}

double Matrix::SpaltenSummennorm()const{
    double norm=0;
    for (int i=0;i<width;++i){
        double tmp=0;
        for(int j=0;j<height;++j){
            tmp+=fabs(matrix[j][i]);
        }
        if(tmp>norm) norm=tmp;
    }
    return norm;
}

double Matrix::Frobeniusnorm()const{
    double norm=0;
    for (int i=0;i<height;++i){
        for(int j=0;j<width;++j){
            norm+=pow(matrix[i][j],2);
        }
    }
    return sqrt(norm);
}

bool Matrix::Zeilensummenkriterium()const{
    for(int i=0;i<height;++i){
        double tmp=0;
        for(int j=0;j<width;++j){
            tmp+=fabs(matrix[i][j]);
        }
        tmp-=matrix[i][i];
        if(tmp>=matrix[i][i]) return false;
    }
    return true;
}

ostream& Matrix::LU(ostream& out)const{
    Matrix result(*this);
    if(height!=width){
        out<<"nope! Matrix muss quadratisch sein!\n";
        return out;
    }

    for(int i=0;i<(width-1);++i){   //rechnen

        for(int x=i+1;x<width;++x){
            result.matrix[x][i]=result.matrix[x][i]/result.matrix[i][i];
            for(int y=i+1;y<width;++y){
                result.matrix[x][y]=result.matrix[x][y]-(result.matrix[x][i]*result.matrix[i][y]);
            }
        }
    }

    Matrix result2(result);

    //Matrizen dem LU-Format anpassen
    for(int i=0;i<width;++i){
        for(int j=i;j<width;++j){
            if (j==i) result.matrix[i][j]=1;
            else result.matrix[i][j]=0;
        }
    }

    for(int i=0;i<width;++i){
        for(int j=0;j<i;++j){
            result2.matrix[i][j]=0;
        }
    }

    out<<"\nL=\n"<<result<<"U=\n"<<result2<<endl;
    return out;

}

//Operatoren
Matrix& Matrix::operator=(const Matrix& other){
    if (this == &other) return *this; // handle self assignment
    delete[] matrix;
    height=other.height;
    width=other.width;
    matrix=new double*[height];
    for (int n=0;n<height;++n){     //Allocate
        matrix[n]=new double[width];
    }

    for (int i=0;i<height;++i){     //Fill
        for (int j=0;j<width;++j){
            matrix[i][j]=other.matrix[i][j];
        }
    }
    return *this;
}

double& Matrix::operator()(int index1,int index2)const {
    if (index1<0 || index2<0 || index1>=height || index2>=width)
        throw invalid_argument("Indexfehler");
    return matrix[index1][index2];
}
//Destruktor
Matrix::~Matrix(){
    for(int i = 0; i < height; ++i){
        delete [] matrix[i];
    }
    delete[] matrix;
}
