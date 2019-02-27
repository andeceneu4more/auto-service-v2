#ifndef BICICLETA_H
#define BICICLETA_H

#include <iostream>
#include "vehicul.h"
class bicicleta:public vehicul
{
private:
	bool ghidon, lant;
public:
	bicicleta(float, bool, int, bool, bool);
	bicicleta(bicicleta&);
	~bicicleta();
	bicicleta& operator=(bicicleta&);
	float repara();
	void tastatura();
	friend istream& operator>>(istream&, bicicleta&);
	friend ostream& operator<<(ostream&, bicicleta&);
};
bicicleta::bicicleta(float b1 = 0, bool b2 = false, int b3 = 0, bool a1 = false, bool a2 = false):vehicul(b1, b2, b3)
{
	ghidon = a1;
	lant = a2;
}
bicicleta::bicicleta(bicicleta &A)
{
	pret = A.pret;
	defectiuneCapitala = A.defectiuneCapitala;
	roti = A.roti;
	ghidon = A.ghidon;
	lant = A.lant;
}
bicicleta::~bicicleta()
{
	pret = 0;
	defectiuneCapitala = false;
	roti = 0;
	ghidon = false;
	lant = false;
}
bicicleta& bicicleta::operator=(bicicleta &A)
{
	pret = A.pret;
	defectiuneCapitala = A.defectiuneCapitala;
	roti = A.roti;
	ghidon = A.ghidon;
	lant = A.lant;
	return (*this);
}
float bicicleta::repara()
{
	//Se considera toate materialele necesare deja in stoc
	if (defectiuneCapitala)
		return 0;
	//daca se poate repara
	int nr_ore = 0, nr_oameni = 0, suruburi = 0;
	//Directie
	if (ghidon)
	{
		nr_ore++;
		nr_oameni++;
		pret+=50; //lei
		suruburi+=5;
	}
	//Directie
	if (roti)
	{
		nr_ore++;
		nr_oameni++;
		pret+=(roti * 48); //lei
		suruburi+=5;
	}
	//Frane
	if (lant)
	{
		if (!nr_ore)
			nr_ore++;
		if (!nr_oameni)
			nr_oameni++;
		pret+=35; //lei
		suruburi+=5;
	}
	pret+=(suruburi * 5); //lei
	pret+=(nr_oameni * nr_ore * manopera);
	return pret;
}
void bicicleta::tastatura()
{
	int nn, n, x;
	cout << "Cate tipuri de defectiuni? ";
	cin >> n;
	for (; n && (!defectiuneCapitala); n--)
	{
		cout << "Alegeti tipul de defectiune\n1.Frane\n2.Directie\n3.Defectiunea Capitala\n";
        cin >> x;
        switch (x)
        {
            case 1://Frane
            	cout << "Cate probleme? ";
            	cin >> nn;
            	for (; nn; nn--)
            	{
               		cout << "Alegeti tipul problemei\n1.Lant lipsa\n2.Lant tocit\n";
                	cin >> x;
               		lant = true;
            	}
            	break;
            case 2://Directie
            	cout << "Cate probleme? ";
                cin >> nn;
                for (; nn; nn--)
                {
                	cout << "Alegeti tipul problemei\n1.Ghidon stramb\n2.Roata stramba\n";
	                cin >> x;
	                switch (x)
	                {
	                    case 1:
	                        ghidon = true;
	                        break;
	                    case 2:
	                        cout << "Cate roti? ";
	                        cin >> x;
	                        roti = x;
	                        break;
	                }
                }
                break;
            case 3:
                defectiuneCapitala = true;
                break;
                //kaputt
		}
	}
}
istream& operator>>(istream &in, bicicleta &A)
{
	int nn, n;
	string s;
	in >> n;
	in.ignore();
	for (; n && (!A.defectiuneCapitala); n--)
	{
		getline(in, s);
        if (s == "Frane")
        {
            //Frane
            in >> nn;
            in.ignore();
            for (; nn; nn--)
            {
                getline(in, s);
                A.lant = true;
            }
        }
        else
            if (s == "Directie")
            {
                in >> nn;
                in.ignore();
                for (; nn; nn--)
                {
	                getline(in, s);
	                if(s == "Ghidon stramb")
                        A.ghidon = true;
                    else
                        if (s == "Roata stramba")
	                        in >> A.roti;
                }
            }
            else
                if (s == "Defectiunea Capitala")
                    A.defectiuneCapitala = true;
                    //kaputt
    }
	return in;
}
ostream& operator<<(ostream &out, bicicleta &A)
{
    out << "Bicicleta\n";
    out << "Defectiunea Capitala " << A.defectiuneCapitala << '\n';
    out << "Lant " << A.lant << '\n';
    out << "Roti " << A.roti << '\n';
    out << "Ghidon " << A.ghidon << '\n';
    out << "Pret " << A.pret << '\n';
    return out;
}

#endif