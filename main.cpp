#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "bicicleta.h"
#include "motocicleta.h"
#include "automobil.h"
int main()
{
	int i, ok, total = 0;
	string s;
	vector <vehicul *> vec;
    bicicleta *B;
    motocicleta *M;
    automobil *A;
    cout << "Alegeti de unde sa se preia datele:\n1.de la tastatura\n2.din fisier\n";
    cin >> ok;
    if (ok == 1)
    {
        cout << "Pentru fiecare dintre urmatoarele optiuni, introduceti doar numarul optiuni!\n";
        cout << "Cate vehicule? ";
        cin >> (vehicul::n);
        for (i = 1; i <= (vehicul::n); i++)
        {
            cout << "Alegeti tipul de vehicul\n1.Bicicleta\n2.Motocicleta\n3.Automobil\n";
            cin >> ok;
            switch(ok)
            {
                case 1:
                    B = new bicicleta();
                    B->tastatura();
                    vec.push_back(B);
                    break;
                case 2:
                    M = new motocicleta();
                    M->tastatura();
                    vec.push_back(M);
                    break;
                case 3:
                    A = new automobil();
                    A->tastatura();
                    vec.push_back(A);
                    break;
            }
            total+=vec[i-1]->repara();
        }
        vehicul::numar();
        cout << "Pretul total va fi de " << total << " lei\n";
        for (i = 0; i < (vehicul::n); i++)
            delete vec[i];
        vec.clear();
    }
    else
    {
        ifstream fin("atelier.in");
        ofstream fout("atelier.out");
        fin >> (vehicul::n);
        for (i = 1; i <= (vehicul::n); i++)
        {
            fin >> s;
            if (s == "Bicicleta")
            {
                B = new bicicleta();
                fin >> (*B);
                vec.push_back(B);
            }
            else
            {
                if (s == "Motocicleta")
                {
                    M = new motocicleta();
                    fin >> (*M);
                    vec.push_back(M);
                }
                else
                    if (s == "Automobil")
                    {
                        A = new automobil();
                        fin >> (*A);
                        vec.push_back(A);
                    }

            }
            total+=vec[i-1]->repara();
        }
        fout << "Pretul total va fi de " << total << " lei\n";
        for (i = 0; i < (vehicul::n); i++)
        {
            B = dynamic_cast<bicicleta *>(vec[i]);
            if (B)
            {
                B = (bicicleta*)vec[i];
                fout << (*B);
            }
            else
            {
                M = dynamic_cast<motocicleta *>(vec[i]);
                if (M)
                {
                    M = (motocicleta*)vec[i];
                    fout << (*M);
                }
                else
                {
                    A = dynamic_cast<automobil *>(vec[i]);
                    if (A)
                    {
                        A = (automobil *)vec[i];
                        fout << (*A);
                    }
                }
            }
            delete vec[i];
        }
        vec.clear();
        fin.close();
        fout.close();
    }
    return 0;
}
