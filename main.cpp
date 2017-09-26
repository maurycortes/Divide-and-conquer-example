#include <iostream>
#include <fstream>

using namespace std;

bool DivideYVenceras(char ArrChar[10], int &LetrasA, int &LetrasB, int &it, int dimension)
{
    int Bajo=0, Alto=dimension, Pivote=0, SegPivote;
    if(ArrChar[0]=='b')
    {
        it++;
        LetrasB=dimension;
        return true;
    }
    if(ArrChar[dimension-1]=='a')
    {
        it++;
        LetrasA=dimension;
        return true;
    }
    while(Bajo<=Alto)
    {
        Pivote=(Bajo+Alto)/2;
        if('b' == ArrChar[Pivote])
        {
            it++;
            if('a' == ArrChar[Pivote-1])
            {
                LetrasA = Pivote;
                LetrasB = dimension - LetrasA;
                return true;
            }
            Alto=Pivote-1;
        }
        else if('a' == ArrChar[Pivote])
        {
            it++;
            Bajo=Pivote+1;
        }
    }
}

int main()
{
    char ArrChar[10], Caracter;
    ifstream ArchivoEntrada;
    int it=0, LetrasA=0, LetrasB=0, dimension=0, cont=0;
    ArchivoEntrada.open("AB.txt");
    while(!ArchivoEntrada.eof())
    {
        ArchivoEntrada >> Caracter;
        ArrChar[cont] = Caracter;
        dimension++;
        cont++;
    }
    ArchivoEntrada.close();
    if(DivideYVenceras(ArrChar, LetrasA, LetrasB, it, dimension-1))
    {
       cout << "Hay " << LetrasA << " letras a " << endl;
       cout << "Hay " << LetrasB << " letras b " << endl;
       cout << "Se hicieron " << it << " iteraciones" << endl;
    }
    return 0;
}
