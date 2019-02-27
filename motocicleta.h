#ifndef MOTOCICLETA_H
#define MOTOCICLETA_H

#include <iostream>
#include "vehicul.h"
class motocicleta:public vehicul
{
private:
	bool placute_fata, placute_spate, ulei, ghidon, vechi;
	int arcuri, amortizoare, discuri, bujii;
public:
	motocicleta(float, bool, int, bool, bool, bool, bool, bool, int, int, int, int);
	motocicleta(motocicleta&);
	~motocicleta();
	motocicleta& operator=(motocicleta&);
	float repara();
	void tastatura();
	friend istream& operator>>(istream&, motocicleta&);
	friend ostream& operator<<(ostream&, motocicleta&);
};
motocicleta::motocicleta(float b1 = 0, bool b2 = false, int b3 = 0, bool a1 = false, bool a2 = false, bool a3 = false, bool a4 = false, bool a5 = false,
int a6 = 0, int a7 = 0, int a8 = 0, int a9 = 0):vehicul(b1, b2, b3)
{
	placute_fata = a1;
	placute_spate = a2;
	ulei = a3;
	ghidon = a4;
	vechi = a5;
	arcuri = a6;
	amortizoare = a7;
	discuri = a8;
	bujii = a9;
}
motocicleta::motocicleta(motocicleta &A)
{
	pret = A.pret;
	defectiuneCapitala = A.defectiuneCapitala;
	roti = A.roti;
	placute_fata = A.placute_fata;
	placute_spate = A.placute_spate;
	ulei = A.ulei;
	ghidon = A.ghidon;
	vechi = A.vechi;
	arcuri = A.arcuri;
	amortizoare = A.amortizoare;
	discuri = A.discuri;
	bujii = A.bujii;
}
motocicleta::~motocicleta()
{
	pret = 0;
	defectiuneCapitala = false;
	roti = 0;
	placute_fata = false;
	placute_spate = false;
	ulei = false;
	ghidon = false;
	vechi = false;
	arcuri = 0;
	amortizoare = 0;
	discuri = 0;
	bujii = 0;
}
motocicleta& motocicleta::operator=(motocicleta &A)
{
	pret = A.pret;
	defectiuneCapitala = A.defectiuneCapitala;
	roti = A.roti;
	placute_fata = A.placute_fata;
	placute_spate = A.placute_spate;
	ulei = A.ulei;
	ghidon = A.ghidon;
	vechi = A.vechi;
	arcuri = A.arcuri;
	amortizoare = A.amortizoare;
	discuri = A.discuri;
	bujii = A.bujii;
	return (*this);
}
float motocicleta::repara()
{
	//Se considera toate materialele necesare deja in stoc
	if (defectiuneCapitala)
		return 0;
	//daca se poate repara
	int nr_ore = 0, nr_oameni = 0, suruburi = 0;
	//Frane
	if (placute_fata)
	{
		nr_ore++;
		nr_oameni++;
		pret+=70; //lei
		suruburi+=5;
	}
	if (placute_spate)
	{
		nr_ore++;
		nr_oameni++;
		pret+=70; //lei
		suruburi+=5;
	}
	if (discuri)
	{
		nr_ore++;
		nr_oameni++;
		pret+=(discuri * 170); //lei
		suruburi+=5;
	}
	//Suspensie
	if (arcuri)
	{
		nr_ore++;
		nr_oameni++;
		pret+=(arcuri * 60); //lei
		suruburi+=5;
	}
	if (amortizoare)
	{
		nr_ore++;
		nr_oameni++;
		pret+=(amortizoare * 70); //lei
		suruburi+=5;
	}
	//Motor
	if (ulei)
	{
		nr_ore++;
		nr_oameni++;
		pret+=15; //lei
		//schimbul de ulei nu presupune consum de suruburi
	}
	if (bujii)
	{
		nr_ore++;
		nr_oameni++;
		pret+=(bujii * 5); //lei
		suruburi+=5;
	}
	//Directie
	if (ghidon)
	{
		nr_ore++;
		nr_oameni++;
		pret+= 135; //lei
		suruburi+= 5;
	}
	if (roti)
	{
		nr_ore++;
		nr_oameni++;
		pret+= (roti  *  150); //lei
		suruburi+= 5;
	}
	pret+=(suruburi * 5); //lei
	pret+=(nr_oameni * nr_ore * manopera);
	if (vechi)
		pret*=1.5;
	//daca vehiculul este vechi, reparatia costa mai mult
	return pret;
}
istream& operator>>(istream &in, motocicleta &A)
{
	int n, nn;
	in >> n;
	in.ignore();
	string s;
	for (; n && (!A.defectiuneCapitala); n--)
    {
    	getline(in, s);
        if (s == "Frane")
	    {
	        in >> nn;
	        in.ignore();
	        for (; nn; nn--)
	        {
	            getline(in, s);
	            if (s == "Placute fata uzate")
	            	A.placute_fata = true;
	            else
	            	if (s == "Placute spate uzate")
	                    A.placute_spate = true;
	                else
	                	if (s == "Discuri uzate")
	                    {
	                        in >> A.discuri;
	                        in.ignore();
	                    }
	        }
	    }
	    else
	    	if (s == "Suspensie")
	    	{
            	in >> nn;
            	in.ignore();
	            for (; nn; nn--)
	            {
	            	getline(in, s);
	                if (s == "Arc rupt")
	                {
	                	in >> A.arcuri;
	                	in.ignore();
	                }
                    else
                    	if (s == "Amortizor defect")
                    	{
                    		in >> A.amortizoare;
                    		in.ignore();
                    	}
	            }
	        }
            else
            	if (s == "Motor")
            	{
	                in >> nn;
	                in.ignore();
	                for (; nn; nn--)
	                {
	                	getline(in, s);
	                    if (s == "Bujii defecte")
	                    {
	                    	in >> A.bujii;
	                		in.ignore();
	                    }
	                    else
	                    	A.ulei = true;
	                }
            	}
            	else
            		if(s == "Directie")
	                {
	                	in >> nn;
	                	in.ignore();
		                for (; nn; nn--)
		                {
		                    getline(in, s);
		                    if (s == "Ghidon stramb")
		                    {
		                    	A.ghidon = true;
		                    }
			                else
			                	if (s == "Roata stramba")
			                    {
			                    	in >> A.roti;
			                    	in.ignore();
			                    }

			            }
			        }
			        else
			        	if (s == "Noxe")
			        	{
			            	in >> nn;
			            	in.ignore();
			                for (; nn; nn--)
			                {
			                	getline(in, s);
			                	if (s == "Vehiculul arde ulei")
			                		A.ulei = true;
			                	else
			                		if (s == "Vehiculul este anterior anului 2000")
			                			A.vechi = true;
			                }
			            }
            			else
                			if (s == "Defectiunea Capitala")
                				A.defectiuneCapitala = true;
                				//kaputt
    }
	return in;
}
ostream& operator<<(ostream &out, motocicleta &A)
{
	out << "Motocicleta\n";
    out << "Defectiunea Capitala " << A.defectiuneCapitala << "\n";
    out << "Placute fata " << A.placute_fata << "\n";
    out << "Placute spate " << A.placute_spate << "\n";
    out << "Discuri " << A.discuri << "\n";
    out << "Ulei " << A.ulei << "\n";
    out << "Ghidon " << A.ghidon << "\n";
    out << "Roti " << A.roti << "\n";
    out << "Arcuri " << A.arcuri << '\n';
    out << "Amortizoare " << A.amortizoare << '\n';
    out << "Bujii " << A.bujii << '\n';
    out << "Pret " << A.pret << '\n';
    return out;
}
void motocicleta::tastatura()
{
	int x, n, nn;
	cout << "Cate tipuri de defectiuni? ";
	cin >> n;
	for (; n && (!defectiuneCapitala); n--)
    {
        cout << "Alegeti tipul de defectiune\n1.Frane\n2.Suspensie\n3.Motor\n4.Directie\n5.Noxe\n6.Defectiunea Capitala\n";
        cin >> x;
        switch(x)
        {
            case 1://Frane
	            cout << "Cate probleme? ";
	            cin >> nn;
	            for (; nn; nn--)
	            {
	                cout << "Alegeti tipul de problema\n1.Placute fata uzate\n2.Placute spate uzate\n3.Discuri uzate\n";
	                cin >> x;
	                switch(x)
	                {
	                    case 1:
	                    	placute_fata = true;
	                    	break;
	                    case 2:
	                    	placute_spate = true;
	                        break;
	                    case 3:
	                        cout << "Cate discuri uzate? ";
	                        cin >> x;
	                        discuri = x;
	                        break;
	                }
	            }
	            break;
            case 2://Suspensie
            	cout << "Cate probleme? ";
	            cin >> nn;
	            for (; nn; nn--)
	            {
	            	cout << "Alegeti tipul de problema\n1.Arc rupt\n2.Amortizor defect\n";
	                cin >> x;
	                switch(x)
	                {
	                	case 1:
	                		cout << "Cate arcuri? ";
	                        cin >> x;
	                        arcuri = x;
	                        break;
                        case 2:
                            cout << "Cate amortizoare? ";
	                        cin >> x;
	                        arcuri = x;
	                        break;
	                }
	            }
	            break;
            case 3://Motor
                cout << "Cate probleme? ";
                cin >> nn;
                for (; nn; nn--)
                {
                    cout << "Alegeti tipul de problema\n1.Nivel ulei scazut\n2.Motor topit\n3.Bujii defecte\n";
                    cin >> x;
                    if (x == 3)
                    {
                    	cout << "Cate bujii? ";
                    	cin >> bujii;
                    }
                    else
                    	ulei = true;
                }
                break;
            case 4://Directie
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
            case 5://Noxe
                cout << "Cate probleme? ";
                cin >> nn;
                for (; nn; nn--)
                {
                    cout << "Alegeti tipul problemei\n1.Vehiculul arde ulei\n2.Vehiculul este anterior anului 2000\n";
                    cin >> x;
                    switch(x)
                    {
                        case 1:
                        	ulei = true;
                        	break;
                        case 2:
                        	vechi = true;
              	 			break;
                	}
                }
                break;
            case 6:
                defectiuneCapitala = true;
                break;
                //kaputt
        }
    }
}
#endif