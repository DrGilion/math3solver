#include <iostream>
#include <iomanip>
#include <cmath>
#include "Matrix.h"
#include "Vektor.h"

#define PI 3.1415926535897
#define e 2.718281828

#define FUNKaufl(x) 3*x*x+2*x  //Stammfunktion der Funktion für Rechnung immer hier ändern
#define FUNK(x) 3.0*x*x*x-12.0*x*x+13.0*x-(28.0/9)  //Funktion für Rechnung immer hier ändern
#define FUNKabl1(x) 15.0*cos(3*x-3)  //1.Ableitung der Funktion für Rechnung immer hier ändern
#define FUNKabl2(x) 16  //2.Ableitung der Funktion für Rechnung immer hier ändern
#define FUNKabl3(x) x*PI  //3.Ableitung der Funktion für Rechnung immer hier ändern
#define FUNKabl4(x) 0  //4.Ableitung der Funktion für Rechnung immer hier ändern


using namespace std;


void Fixpunktbestimmer(void){
    cout<<"\t\t\t~~Fixpunktbestimmung~~"<<endl;
    double start;
    int iter;
    cout<<"Startwert pls :";
    cin>>start;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Iterationsschritte pls :";
    cin>>iter;
    cin.clear();
    cin.ignore(256,'\n');
    double tmp=start;
    for (int i=1;i<=iter;++i){
        tmp= FUNK(tmp);
        cout<<i<<". "<<setprecision(8)<<fixed<<tmp<<endl;
    }
}

void Fehlerrechner(void){
    cout<<"\t\t\t~~Allgemeine Fehlerbestimmung~~"<<endl;
    double pnaeherung,p;
    cout<<"Exakter Wert pls(double) : ";
    cin>>p;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Näherung pls(double) : ";
    cin>>pnaeherung;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Absoluter Fehler: "<<setprecision(8)<<fixed<<fabs(pnaeherung-p)<<"\nRelativer Fahler: "<<fabs(pnaeherung-p)/fabs(p)<<endl;
}

void BanachFix(void){
    cout<<"\t\t~~Abschätzung mit Banachschen Fixpunktsatz~~"<<endl;
    double L,x0,x1,schritt;
    cout<<"Startwert x0 pls :";
    cin>>x0;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Startwert x1 pls :";
    cin>>x1;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Lipschitz-Konstante pls :";
    cin>>L;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Schrittweite pls :";
    cin>>schritt;
    cin.clear();
    cin.ignore(256,'\n');

    cout<<"Xn-X"<<schritt<<"<= "<<setprecision(8)<<fixed<<(pow(L,schritt)/(1-L))*fabs(x1-x0)<<endl;
}

void KonvergenzFixpunktiteration(void){
    cout<<"\t\t\t~~Konvergenz der Fixpunktiteration~~"<<endl;
    double a,b;
    cout<<"Untere Intervallgrenze pls :";
    cin>>a;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Obere Intervallgrenze pls :";
    cin>>b;
    cin.clear();
    cin.ignore(256,'\n');
    if (FUNK(a)<1&&FUNK(b)<1){
        cout<<"Konvergenz im Intervall ["<<a<<","<<b<<"] nicht erfüllt"<<endl;
    }
    if (FUNK(a)>1&&FUNK(b)>1){
        cout<<"Konvergenz im Intervall ["<<a<<","<<b<<"] erfüllt"<<endl;
    }

}

void KonvergenzNewtonVerfahren(void){
    cout<<"\t\t\t~~Konvergenz des Newtonverfahrens~~"<<endl;
    double a,b;
    cout<<"Intervall von Nullstelle pls (a,b) :";
    cin>>a>>b;
    cin.clear();
    cin.ignore(256,'\n');
    if (FUNKabl1(a)>0|| FUNKabl2(a)>0){
        cout<<"Konvergenzbedingung an die Ableitungen der Funktion ist erfüllt."<<endl;
    }else cout<<"Konvergenzbedingung an die Ableitungen der Funktion ist nicht erfüllt."<<endl;

}

void Det_berechnen(void){
    cout<<"\t\t\t~~Determinante einer Matrix berechnen~~"<<endl;
    int a,b;
    cout<<"Matrixgroesse festlegen pls (a,b): ";
    cin>>a>>b;
    cin.clear();
    cin.ignore(256,'\n');
    Matrix x(a,b);
    cout<<x.Determinante()<<endl;

}

void LUZerlegung(void){
    cout<<"\t\t\t~~LU-Zerlegung einer Matrix bestimmen~~"<<endl;
    int a,b;
    cout<<"Matrixgroesse festlegen pls (a,b): ";
    cin>>a>>b;
    cin.clear();
    cin.ignore(256,'\n');
    Matrix A(a,b);

    A.LU(cout);
    cout<<endl;

}

void Vektornormen(void){
    cout<<"\t\t\t~~Bestimmung von Vektornormen~~"<<endl;
    int c;
    cout<<"Vektorgroesse festlegen pls : ";
    cin>>c;
    cin.clear();
    cin.ignore(256,'\n');
    Vektor x(c);
    cout<<"\n\nSummennorm: "<<setprecision(8)<<x.Summennorm()<<"\nEuklidsche Norm: "<<x.Euklidnorm()<<"\nMaximumnorm: "<<x.Maximumnorm()<<endl;

}

void Matrixnormen(void){
    cout<<"\t\t\t~~Bestimmung von Matrixnormen~~"<<endl;
    int a,b;
    cout<<"Matrixgroesse festlegen pls (a,b): ";
    cin>>a>>b;
    cin.clear();
    cin.ignore(256,'\n');
    Matrix A(a,b);
    cout<<"\n\nZeilensummennorm: "<<setprecision(8)<<A.ZeilenSummennorm()<<"\nEuklidsche Norm: "<<A.SpaltenSummennorm()<<"\nFrobeniusnorm: "<<A.Frobeniusnorm()<<endl;
}

void LagrangePolynomInterpolation(void){
    cout<<"\t\t~~Polynom-Interpolation nach Lagrange~~"<<endl;
    int g;
    cout<<"Polynomgrad angeben : ";
    cin>>g;
    cin.clear();
    cin.ignore(256,'\n');
    g++;
    double** matrix=new double*[3];
    for (int n=0;n<3;++n){     //Allocate
        matrix[n]=new double[g];
    }

    for (int x=0;x<3;++x){     //mit nullen füllen
        for (int y=0;y<g;++y){
            matrix[x][y]=1337;
        }

    }

    cout<<"Tabelle fuellen pls! "<<endl;
    for (int i=0;i<3;++i){     //Fill
        for (int j=0;j<g;++j){

            for (int p=0;p<3;++p){     //Print von bisherigen Input
                switch(p){
                case (0):
                    cout<<"n ";
                    break;
                case (1):
                    cout<<"Xn";
                    break;
                case (2):
                    cout<<"Yn";
                    break;
                }

                cout<<" |\t";
                for (int q=0;q<g;++q){
                    if(p==i&&q==j){ cout<<" x \t";}
                    else if(matrix[p][q]==1337){ cout<<"{ }\t";}
                    else cout<<matrix[p][q]<<"\t";
                }
                cout<<"\n";
            }

            cout<<"wert fuer x eingeben pls : "<<endl;   //Input
            cin>>matrix[i][j];
            cin.clear();
            cin.ignore(256,'\n');
        }
    }
    cout<<"\n\n";
    for (int p=0;p<3;++p){     //letzter Print von bisherigen Input
        switch(p){
        case (0):
            cout<<"n ";
            break;
        case (1):
            cout<<"Xn";
            break;
        case (2):
            cout<<"Yn";
            break;
        }

        cout<<" |\t";
        for (int q=0;q<g;++q){
            cout<<matrix[p][q]<<"\t";
        }
        cout<<"\n";
    }
    cout<<endl;

    for (int a=0;a<g;++a){      //Berechnungen
        double prod=1;
        for (int b=0;b<g;++b){
            if(a!=b) prod*= (matrix[1][a]-matrix[1][b]);
        }
        prod=1/prod;
        cout<<a<<".Langrangepoylnom : l"<<a<<"(x)="<<prod<<"*";
        for(int b2=0;b2<g;++b2){
            if(a!=b2){
                cout<<"(x-"<<matrix[1][b2]<<")";
            }
        }
        cout<<endl;
    }
    cout<<"\nVollständiges Interpolationpolynom :\np"<<g-1<<"(x)= ";
    for(int z=0;z<g;++z){
        cout<<matrix[2][z]<<"*l"<<z<<"(x)";
        if (z!=(g-1)) cout<<"+ ";
    }
    cout<<endl;


    for(int i = 0; i < 3; ++i){  //delete
        delete [] matrix[i];
    }
    delete[] matrix;
}

void NewtonPolynomInterpolation(void){
    cout<<"\t\t~~Polynom-Interpolation nach Newton~~"<<endl;
    int g;
    cout<<"Polynomgrad angeben : ";
    cin>>g;
    cin.clear();
    cin.ignore(256,'\n');
    g++;
    double** matrix=new double*[3];
    for (int n=0;n<3;++n){     //Allocate
        matrix[n]=new double[g];
    }

    for (int x=0;x<3;++x){     //mit nullen füllen
        for (int y=0;y<g;++y){
            matrix[x][y]=1337;
        }

    }

    cout<<"Tabelle fuellen pls! "<<endl;
    for (int i=0;i<3;++i){     //Fill
        for (int j=0;j<g;++j){

            for (int p=0;p<3;++p){     //Print von bisherigen Input
                switch(p){
                case (0):
                    cout<<"n ";
                    break;
                case (1):
                    cout<<"Xn";
                    break;
                case (2):
                    cout<<"Yn";
                    break;
                }

                cout<<" |\t";
                for (int q=0;q<g;++q){
                    if(p==i&&q==j){ cout<<" x \t";}
                    else if(matrix[p][q]==1337){ cout<<"{ }\t";}
                    else cout<<matrix[p][q]<<"\t";
                }
                cout<<"\n";
            }

            cout<<"wert fuer x eingeben pls : "<<endl;   //Input
            cin>>matrix[i][j];
            cin.clear();
            cin.ignore(256,'\n');
        }
    }
    cout<<"\n\n";
    for (int p=0;p<3;++p){     //letzter Print von bisherigen Input
        switch(p){
        case (0):
            cout<<"n ";
            break;
        case (1):
            cout<<"Xn";
            break;
        case (2):
            cout<<"Yn";
            break;
        }

        cout<<" |\t";
        for (int q=0;q<g;++q){
            cout<<matrix[p][q]<<"\t";
        }
        cout<<"\n";
    }
    cout<<endl;

    double* tmp=new double[g];
    double* result=new double[g];
    result[0]=matrix[2][0];

    for(int i=0;i!=g;++i){
        tmp[i]=matrix[2][i];
    }

    for(int x=0;x!=(g-1);++x){      //rechnen
        for(int y=0;y!=(g-1-x);++y){
            tmp[y]=((tmp[y+1]-tmp[y])/(matrix[1][y+x+1]-matrix[1][y]));
        }
        result[x+1]=tmp[0];
    }

    cout<<"p"<<g-1<<"(x)=\n"<<result[0]<<"+\n";
    for(int m=1;m!=g;++m){  //output
        cout<<result[m]<<"* ";
        for(int n=0;n!=m;++n){
            cout<<"(x-"<<matrix[1][n]<<")";
        }
        if(m!=(g-1)) cout<<"+";
        cout<<endl;
    }

    for(int i = 0; i < 3; ++i){  //delete
        delete [] matrix[i];
    }
    delete[] matrix;
    delete[] tmp;
    delete[] result;
}

void IntegralRechteckregel(void){
    cout<<"\t\t\t~~Integral mit Recheckregel nähern~~"<<endl;
    int N;
    double a,b,h;
    cout<<"Wieviele Intervalle? ";
    cin>>N;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Intervallgrenzen pls (a,b): ";
    cin>>a>>b;
    cin.clear();
    cin.ignore(256,'\n');
    h=((b-a)/N);

    double sum=0;
    for(int i=0;i<N;++i){
        sum+= FUNK((double)(((a+i*h)+(a+(i+1)*h))/2));
    }
    sum *=h;
    cout<<"\nNäherung des Integrals mit Rechteckregel ist: "<<setprecision(6)<<fixed<<sum<<endl;

}

void IntegralTrapezregel(void){
    cout<<"\t\t\t~~Integral mit Trapezregelregel nähern~~"<<endl;
    int N;
    double a,b,h;
    cout<<"Wieviele Intervalle? ";
    cin>>N;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Intervallgrenzen pls (a,b): ";
    cin>>a>>b;
    cin.clear();
    cin.ignore(256,'\n');
    h=((b-a)/N);

    double sum=0;
    for(int i=1;i<=N-1;++i){
        double tmp1= FUNK((double)(a+i*h));
        sum+=tmp1;
    }
    double t=FUNK(a);
    double u=t/2;
    sum+=u;
    t=FUNK(b);
    u=t/2;
    sum+=u;
    sum *=h;
    cout<<"\nNäherung des Integrals mit Trapezregel ist: "<<setprecision(6)<<fixed<<sum<<endl;
}

void IntegralSimpsonregel(void){
    cout<<"\t\t\t~~Integral mit Simpsonregel nähern~~"<<endl;
    int N;
    double a,b,h;
    cout<<"Wieviele Intervalle? ";
    cin>>N;
    cin.clear();
    cin.ignore(256,'\n');
    if(N%2!=0){
        cout<<"nur für eine gerade Anzahl von Intervallen anwendbar!"<<endl;

    }else{
    cout<<"Intervallgrenzen pls (a,b): ";
    cin>>a>>b;
    cin.clear();
    cin.ignore(256,'\n');
    h=((b-a)/N);

    double sum=0;
    for(int i=0;i<(N/2);++i){
        sum+=FUNK((double)(a+(2*i)*h));
        sum+=(FUNK((double)(a+(i*2+1)*h)))*4;
        sum+=FUNK((double)(a+(i*2+2)*h));
    }
    sum *= (h/3);
    cout<<"\nNäherung des Integrals mit Simpsonregel ist: "<<setprecision(6)<<fixed<<sum<<endl;
    }
}

void RechteckregelFehler(void){
    cout<<"\t\t\t~~Fehler der Rechteckregel berechnen~~"<<endl;
    int N;
    double a,b,h;
    cout<<"Wieviele Intervalle? ";
    cin>>N;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Intervallgrenzen pls (a,b): ";
    cin>>a>>b;
    cin.clear();
    cin.ignore(256,'\n');
    h=((b-a)/N);
    double mx=0;
    for (double i=a;i<=b;i+=0.00001){
        double tmp=fabs(FUNKabl2((double)i));
        if (tmp>mx) mx=tmp;
    }
    double x= ((b-a)/24)*h*h*mx;
    cout<<"\nDer Fehler beträgt: "<<x<<endl;
}

void TrapezregelFehler(void){
    cout<<"\t\t\t~~Fehler der Trapezregel berechnen~~"<<endl;
    int N;
    double a,b,h;
    cout<<"Wieviele Intervalle? ";
    cin>>N;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Intervallgrenzen pls (a,b): ";
    cin>>a>>b;
    cin.clear();
    cin.ignore(256,'\n');
    h=((b-a)/N);
    double mx=0;
    for (double i=a;i<=b;i+=0.00001){
        double tmp=fabs(FUNKabl2((double)i));
        if (tmp>mx) mx=tmp;
    }

    double x= ((b-a)/12)*h*h*mx;
    cout<<"\nDer Fehler beträgt: "<<x<<endl;
}

void SimpsonregelFehler(void){
    cout<<"\t\t\t~~Fehler der Simpsonregel berechnen~~"<<endl;
    int N;
    double a,b,h;
    cout<<"Wieviele Intervalle? ";
    cin>>N;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Intervallgrenzen pls (a,b): ";
    cin>>a>>b;
    cin.clear();
    cin.ignore(256,'\n');
    h=((b-a)/N);
    double mx=0;
    for (double i=a;i<=b;i+=0.00001){
        double tmp=fabs(FUNKabl4((double)i));
        if (tmp>mx) mx=tmp;
    }

    double x= ((b-a)/180)*h*h*h*h*mx;
    cout<<"\nDer Fehler beträgt: "<<x<<endl;
}

void Bisektion(void){
    cout<<"\t\t\t\t~~Bisektionsverfahren~~"<<endl;
    double a,b;
    int it;
    cout<<"Startwert x0 pls: ";
    cin>>a;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Startwert x1 pls: ";
    cin>>b;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Wieviele Iterationsschritte?: ";
    cin>>it;
    cin.clear();
    cin.ignore(256,'\n');

    double x=((a+b)/2);
    for(int i=1;i<=it;++i){
        cout<<i<<".Wert: "<<x<<endl;
        if((FUNK(a))*(FUNK(x))<0) b=x;
        else a=x;
        x=((a+b)/2);
    }
}

void KonvergenzBisektion(void){
    cout<<"\t\t\t~~Konvergenz des Bisektionsverfahren~~"<<endl;
    double a,b,gen;
    cout<<"Startgrenze a pls: ";
    cin>>a;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Startgrenze b pls: ";
    cin>>b;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Genauigkeit pls (bitte dezimal eingeben)?: ";
    cin>>gen;
    cin.clear();
    cin.ignore(256,'\n');

    double x=b-a;
    double n=log2(x/gen);
    cout<<"Die Anzahl an Iterationschritten beträgt: "<<n<<endl;
}

void NewtonVerfahren(void){
    cout<<"\t\t\t\t~~Newtonverfahren~~"<<endl;
    double xalt,xneu,x0;
    int it;
    cout<<"Startwert x0 pls: ";
    cin>>x0;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Wieviele Iterationsschritte?: ";
    cin>>it;
    cin.clear();
    cin.ignore(256,'\n');
    xalt=x0;
    for(int i=1;i<=it;++i){
        xneu=xalt-( (FUNK(xalt))/(FUNKabl1(xalt)) );
        cout<<i<<".Wert: "<<setprecision(7)<<fixed<<xneu<<endl;
        xalt=xneu;
    }
}

void SekantenVerfahren(void){
    cout<<"\t\t\t\t~~Sekantenverfahren~~"<<endl;
    double xalt,xneu;
    int it;
    cout<<"Startwert x0 pls: ";
    cin>>xalt;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Startwert x1 pls: ";
    cin>>xneu;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Wieviele Iterationsschritte?: ";
    cin>>it;
    cin.clear();
    cin.ignore(256,'\n');
    for(int i=1;i<=it;++i){
        double tmp=xneu;
        xneu=xalt-( (xneu-xalt)/((FUNK(xneu))-(FUNK(xalt))) )*(FUNK(xalt));
        cout<<i<<".Wert: "<<setprecision(7)<<fixed<<xneu<<endl;
        xalt=tmp;
    }
}

void RegulaFalsi(void){
    cout<<"\t\t\t\t~~Regula-Falsi-Verfahren~~"<<endl;
    double xalt,xneu;
    int it;
    cout<<"Startwert x0 pls: ";
    cin>>xalt;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Startwert x1 pls: ";
    cin>>xneu;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Wieviele Iterationsschritte?: ";
    cin>>it;
    cin.clear();
    cin.ignore(256,'\n');
    for(int i=1;i<=it;++i){
        double tmp=xneu;
        xneu=xalt-( (xneu-xalt)/((FUNK(xneu))-(FUNK(xalt))) )*(FUNK(xalt));
        cout<<i<<".Wert: "<<setprecision(7)<<fixed<<xneu<<endl;
        xalt=tmp;
    }
}

void JacobiVerfahren(void){
    cout<<"\t\t\t\t~~Jacobi-Verfahren~~"<<endl;
    int it;
    double x1,x2,x3;
    Matrix m(3,3);
    Vektor x(3);
    Vektor start(x);
    cout<<"\nStartvektor bitte fuellen : \n";
    for(int n=0;n<start.size();++n){
        cout<<"Wert "<<n+1<<" pls: ";
        cin>>start[n];
        cin.clear();
        cin.ignore(256,'\n');
    }

    cout<<"\nIterationsschritte festlegen pls : ";
    cin>>it;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<endl;

    for(int i=0;i<it;++i){
        cout<<i+1<<".Iteration:"<<endl;
        x1=((-1*m(0,1)*start[1])/m(0,0))+((-1*m(0,2)*start[2])/m(0,0))+(x[0]/m(0,0));
        cout<<"x1= "<<x1<<endl;
        x2=((-1*m(1,0)*start[0])/m(1,1))+((-1*m(1,2)*start[2])/m(1,1))+(x[1]/m(1,1));
        cout<<"x2= "<<x2<<endl;
        x3=((-1*m(2,0)*start[0])/m(2,2))+((-1*m(2,1)*start[1])/m(2,2))+(x[2]/m(2,2));
        cout<<"x3= "<<x3<<endl;
        start[0]=x1;
        start[1]=x2;
        start[2]=x3;
        cout<<endl;
    }
}

void GaussSeidelVerfahren(void){
    cout<<"\t\t\t~~Gauss-Seidel-Verfahren~~"<<endl;
    int it;
    double x1,x2,x3;
    Matrix m(3,3);
    Vektor x(3);
    Vektor start(x);
    cout<<"\nStartvektor bitte fuellen : \n";
    for(int n=0;n<start.size();++n){
        cout<<"Wert "<<n+1<<" pls: ";
        cin>>start[n];
        cin.clear();
        cin.ignore(256,'\n');
    }

    cout<<"\nIterationsschritte festlegen pls : ";
    cin>>it;
    cin.clear();
    cin.ignore(256,'\n');
    for(int i=0;i<it;++i){
        cout<<i+1<<".Iteration:"<<endl;
        x1=((-1*m(0,1)*start[1])/m(0,0))+((-1*m(0,2)*start[2])/m(0,0))+(x[0]/m(0,0));
        cout<<"x1= "<<x1<<endl;
        start[0]=x1;
        x2=((-1*m(1,0)*start[0])/m(1,1))+((-1*m(1,2)*start[2])/m(1,1))+(x[1]/m(1,1));
        cout<<"x2= "<<x2<<endl;
        start[1]=x2;
        x3=((-1*m(2,0)*start[0])/m(2,2))+((-1*m(2,1)*start[1])/m(2,2))+(x[2]/m(2,2));
        cout<<"x3= "<<x3<<endl;
        start[2]=x3;
        cout<<endl;
    }
}

void KonvergenzJacobi(void){
    cout<<"\t\t~~Bestimmung der Konvergenz des Jacobi-Verfahrens~~"<<endl;
    int a,b;
    cout<<"Matrixgroesse festlegen pls (a,b): ";
    cin>>a>>b;
    cin.clear();
    cin.ignore(256,'\n');
    Matrix A(a,b);
    cout<<"\n\nZeilensummenkriterium erfuellt?: "<<boolalpha<<A.Zeilensummenkriterium()<<endl;
}

void KonvergenzGaussSeidel(void){
    cout<<"\t\t~~Bestimmung der Konvergenz des Gauss-Seidel-Verfahrens~~"<<endl;
    int a,b;
    cout<<"Matrixgroesse festlegen pls (a,b): ";
    cin>>a>>b;
    cin.clear();
    cin.ignore(256,'\n');
    Matrix A(a,b);
    cout<<"\n\nZeilensummenkriterium erfuellt?: "<<boolalpha<<A.Zeilensummenkriterium()<<endl;
}

void ArithmetischesMittel(void){
    cout<<"\t\t\t~~Arithmetisches Mittel berechnen~~"<<endl;
    int anz;
    cout<<"Wieviele Zahlen? ";
    cin>>anz;
    cin.clear();
    cin.ignore(256,'\n');
    double sum,tmp=0;
    for (int i=0;i!=anz;++i){
        cout<<"Wert "<<i+1<<" pls : ";
        cin>>tmp;
        cin.clear();
        cin.ignore(256,'\n');
        sum+=tmp;
    }
    sum=(sum/(double)anz);
    cout<<"Arithmetisches Mittel dieser Zahlen ist: "<<sum<<endl;
}

void AnwachsendMittelwert(void){
    cout<<"\t\t~~Mittelwert eines anwachsenden Datensatzes~~"<<endl;
    int anz;
    double mit,mit2;
    cout<<"Groesse des Datensatzes pls : ";
    cin>>anz;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Mittelwert des Datensatzes pls : ";
    cin>>mit;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Mittelwert des neuen Datensatzes pls : ";
    cin>>mit2;
    cin.clear();
    cin.ignore(256,'\n');
    double tmp=anz*mit;
    double tmp2=mit2*(anz+1);
    double sum=tmp2-tmp;
    cout<<"Der hinzugekommene Wert ist: "<<sum<<endl;
}

void Median(void){
    cout<<"\t\t\t~~Median berechnen~~"<<endl;
    int anz;
    cout<<"Wieviele Zahlen? ";
    cin>>anz;
    cin.clear();
    cin.ignore(256,'\n');
    double* arr= new double[anz];
    double tmp=0;
    for (int i=0;i!=anz;++i){   //input
        cout<<"Wert "<<i+1<<" pls : ";
        cin>>tmp;
        cin.clear();
        cin.ignore(256,'\n');
        arr[i]=tmp;
    }

    for (int n=0;n<anz;++n){    //sortieren: Selectionsort
        int mi=n;
        for(int i=n;i<anz;++i){
            if (arr[i]<arr[n]) mi=i;
        }
        double temp=arr[n];
        arr[n]=arr[mi];
        arr[mi]=temp;

    }
    if (anz%2==0){
        tmp=((arr[anz/2])+(arr[anz/2-1]))/2;
        cout<<"\nDer Median ist: "<<tmp<<endl;
    }else{
        cout<<"\nDer Median ist: "<<arr[anz/2]<<endl;
    }
    delete[] arr;


}

void WdichteGleichverteilt(void){
    cout<<"\t~~Wahrscheinlichkeitsdichte einer gleichverteilten Zufallsvariable~~"<<endl;
    double a,b;
    cout<<"Intervallgrenzen pls (a,b): ";
    cin>>a>>b;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"\nWahrscheinlichkeitsdichte f(x)= 1/"<<(b-a)<<endl;
}

void Normalverteilung(void){
    cout<<"\t~~Wahrscheinlichkeit einer normalverteilten Zufallsvariable~~"<<endl;
    double erw,varianz,X;
    cout<<"\nErwartungswert pls : ";
    cin>>erw;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Varianz  pls (o^2): ";
    cin>>varianz;
    cin.clear();
    cin.ignore(256,'\n');
    cout<<"Zufallsvariable X pls P(X<=?) : ";
    cin>>X;
    cin.clear();
    cin.ignore(256,'\n');
    double tmp= ((X-erw)/sqrt(varianz));
    cout<<"\nDie Zufallsvariable Z ist "<<tmp<<"\nIn der folgenden Tabelle den richtigen Wert ablesen:\nhttp://de.wikipedia.org/wiki/Tabelle_Standardnormalverteilung"<<endl;
}
