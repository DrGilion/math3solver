#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include "Misc.h"
#define PI 3.1415926535897
#define e 2.718281828


using namespace std;

void optionen(){
    cout<<"+++++++NUMERIK+++++++ "<<endl;
    cout<<"\n0.Allgemeine Fehlerberechnung\n1.Fixpunktbestimmung (f)\n2.Abschätzung mit dem Banachschen Fixpunktsatz\n";
    cout<<"3.Konvergenz der Fixpunktiteration (f)\n4.Konvergenz des Newton-Verfahrens (f',f'')\n5.Determinante einer Matrix berechnen (Maximal 3x3)\n";
    cout<<"6.LU-Zerlegung einer Matrix(ohne Pivotisierung)\n7.Vektornormen berechnen\n8.Matrixnormen berechnen\n";
    cout<<"9.Polynom-Interpolation nach Lagrange\n10.Polynom-Interpolation nach Newton\n11.Rechteckregel fuer ein Integral berechnen (f)\n";
    cout<<"12.Fehler der Rechteckregel (f'')\n";
    cout<<"13.Trapezregel fuer ein Integral berechnen (f)\n14.Fehler der Trapezregel (f'')\n15.Simpsonregel fuer ein Integral berechnen (f)\n";
    cout<<"16.Fehler der Simpsonregel (f'''')\n17.Bisektionsverfahren (f)\n18.Konvergenz des Bisektionsverfahrens\n19.Newtonverfahren (f,f')\n";
    cout<<"20.Sekantenverfahren (f)\n21.Regula Falsi (f)\n22.Jacobi-Verfahren (nur fuer 3x3 Matrix)\n";
    cout<<"23.Konvergenz des Jacobi-Verfahrens\n24.Gauss-Seidel-Verfahren (nur fuer 3x3 Matrix)\n25.Konvergenz des Gauss-Seidel-Verfahrens\n";
    cout<<endl;
    cout<<"+++++++STATISTIK+++++++"<<endl;
    cout<<"\n26.Arithmetisches Mittel bilden\n27.Mittelwert eines anwachsenden Datensatzes berechnen\n28.Median bilden\n";
    cout<<"29.Wahrscheinlichkeitsdichte einer gleichverteilten Zufallsvariable berechnen\n30.Normalverteilung berechnen\n";
    cout<<endl;
    cout<<"+++++++Legende+++++++"<<endl;
    cout<<"F : Benoetigt die Stammfunktion\nf : Benoetigt eine Funktion\nf' : Benoetigt die 1.Ableitung der Funktion\nf'' : Benoetigt die 2.Ableitung der Funktion\n";
    cout<<"f''' : Benoetigt die 3.Ableitung der Funktion\nf'''' : Benoetigt die 4.Ableitung der Funktion\n";
}

int main(){
    int wahl;
    string ans="y";
    void (*funcs[])(void)={
        &Fehlerrechner,
        &Fixpunktbestimmer,
        &BanachFix,
        &KonvergenzFixpunktiteration,
        &KonvergenzNewtonVerfahren,
        &Det_berechnen,
        &LUZerlegung,
        &Vektornormen,
        &Matrixnormen,
        &LagrangePolynomInterpolation,
        &NewtonPolynomInterpolation,
        &IntegralRechteckregel,
        &RechteckregelFehler,
        &IntegralTrapezregel,
        &TrapezregelFehler,
        &IntegralSimpsonregel,
        &SimpsonregelFehler,
        &Bisektion,
        &KonvergenzBisektion,
        &NewtonVerfahren,
        &SekantenVerfahren,
        &RegulaFalsi,
        &JacobiVerfahren,
        &KonvergenzJacobi,
        &GaussSeidelVerfahren,
        &KonvergenzGaussSeidel,

        &ArithmetischesMittel,
        &AnwachsendMittelwert,
        &Median,
        &WdichteGleichverteilt,
        &Normalverteilung,
    };

    cout<<"\t\tMicha's Numerik und Statistik Mathematik III Rechner"<<endl;
    while(ans[0]=='y'){
        optionen();
        cout<<"\nWas darf es sein? ";
        cin>>wahl;
        cin.clear();
        cin.ignore(256,'\n');
        cout<<endl;
        (funcs[wahl])();
        cout<<"\n\nmehr rechnen? (y/n)"<<endl;
        cin>>ans;
        cin.clear();
        cin.ignore(256,'\n');

    }
    return 0;
}
