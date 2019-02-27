#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

#include <iostream>
#include "vehicul.h"
#include "tabla.h"
class automobil:public vehicul
{
private:
	bool placute_fata, placute_spate, ulei, carburator, vechi;
	int arcuri, amortizoare, discuri, bujii;
	reparatie bara_fata, bara_spate, capota, plafon, portbagaj;
	tabla aripa, usa;
public:
	automobil();
	automobil(reparatie, reparatie, reparatie, reparatie, reparatie, tabla, tabla, float, bool, int, bool, bool, bool, bool, bool, int, int, int, int);
	automobil(automobil&);
	~automobil();
	automobil& operator=(automobil&);
	float repara();
	void tastatura();
	friend istream& operator>>(istream&, automobil&);
	friend ostream& operator<<(ostream&, automobil&);
};
automobil::automobil():vehicul()
{
	pret = 0;
	defectiuneCapitala = false;
	roti = 0;
    reparatie r;
    bara_fata = r;
    bara_spate = r;
    capota = r;
    plafon = r;
    portbagaj = r;
    tabla t;
    aripa = t;
    usa = t;
    placute_fata = false;
    placute_spate = false;
    ulei = false;
    carburator = false;
    vechi = false;
    arcuri = 0;
    amortizoare = 0;
    discuri = 0;
    bujii = 0;
}
automobil::automobil(reparatie a1, reparatie a2, reparatie a3, reparatie a4, reparatie a5, tabla a6, tabla a7, float b1 = 0, bool b2 = false,
int b3 = 0, bool a8 = false, bool a9 = false, bool a10 = false, bool a11 = false, bool a12 = false, int a13 = 0, int a14 = 0, int a15 = 0, int a16 = 0):vehicul(b1, b2, b3)
{
    bara_fata = a1;
    bara_spate = a2;
    capota = a3;
    plafon = a4;
    portbagaj = a5;
    aripa = a6;
    usa = a7;
    placute_fata = a8;
    placute_spate = a9;
    ulei = a10;
    carburator = a11;
    vechi = a12;
    arcuri = a13;
    amortizoare = a14;
    discuri = a15;
    bujii = a16;
}
automobil::automobil(automobil &A)
{
    defectiuneCapitala = A.defectiuneCapitala;
    roti = A.roti;
    pret = A.pret;
    placute_fata = A.placute_fata;
    placute_spate = A.placute_spate;
    ulei = A.ulei;
    carburator = A.carburator;
    vechi = A.vechi;
    arcuri = A.arcuri;
    amortizoare = A.amortizoare;
    discuri = A.discuri;
    bara_fata = A.bara_fata;
    bara_spate = A.bara_spate;
    capota = A.capota;
    plafon = A.plafon;
    portbagaj = A.portbagaj;
    aripa = A.aripa;
    usa = A.usa;
    bujii = A.bujii;
}
automobil::~automobil()
{
    pret = 0;
	defectiuneCapitala = false;
	roti = 0;
    defectiuneCapitala = false;
    roti = 0;
    pret = 0;
    reparatie r;
    bara_fata = r;
    bara_spate = r;
    capota = r;
    plafon = r;
    portbagaj = r;
    tabla t;
    aripa = t;
    usa = t;
    placute_fata = false;
    placute_spate = false;
    ulei = false;
    carburator = false;
    vechi = false;
    arcuri = 0;
    amortizoare = 0;
    discuri = 0;
    bujii = 0;
}
automobil& automobil::operator=(automobil &A)
{
    defectiuneCapitala = A.defectiuneCapitala;
    roti = A.roti;
    pret = A.pret;
    placute_fata = A.placute_fata;
    placute_spate = A.placute_spate;
    ulei = A.ulei;
    carburator = A.carburator;
    vechi = A.vechi;
    arcuri = A.arcuri;
    amortizoare = A.amortizoare;
    discuri = A.discuri;
    bara_fata = A.bara_fata;
    bara_spate = A.bara_spate;
    capota = A.capota;
    plafon = A.plafon;
    portbagaj = A.portbagaj;
    aripa = A.aripa;
    usa = A.usa;
    bujii = A.bujii;
    return (*this);
}
float automobil::repara()
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
		pret+=(2 * 120); //lei
		suruburi+=5;
	}
	if (placute_spate)
	{
		nr_ore++;
		nr_oameni++;
		pret+=(2 * 120); //lei
		suruburi+=5;
	}
	if (discuri)
	{
		nr_ore++;
		nr_oameni++;
		pret+=(discuri * 80); //lei
		suruburi+=5;
	}
	//Suspensie
	if (arcuri)
	{
		nr_ore++;
		nr_oameni++;
		pret+=(arcuri * 100); //lei
		suruburi+=5;
	}
	if (amortizoare)
	{
		nr_ore++;
		nr_oameni++;
		pret+=(amortizoare * 140); //lei
		suruburi+=5;
	}
	//Motor
	if (ulei)
	{
		nr_ore++;
		nr_oameni++;
		pret+=20; //lei
		//schimbul de ulei nu presupune consum de suruburi
	}
	if (carburator)
	{
		nr_ore++;
		nr_oameni++;
		pret+=60; //lei
		//schimbul de ulei nu presupune consum de suruburi
	}
	if (bujii)
	{
		nr_ore++;
		nr_oameni++;
		pret+=(bujii * 7); //lei
		suruburi+=5;
	}
	//Directie
	if (roti)
	{
		nr_ore++;
		nr_oameni++;
		pret+=(roti * 300); //lei
		suruburi+=5;
	}
	//Caroserie
	if (bara_fata.vopsire())
	{
		nr_ore++;
		nr_oameni+=2;
		pret+=35; //lei
		//doar vopsire
		suruburi+=5;
	}
	if (bara_fata.schimbare())
	{
		nr_ore+=3;
		nr_oameni+=2;
		pret+=(450+35); //lei
		//schimbare + vopsire
		suruburi+=5;
	}
	if (bara_spate.vopsire())
	{
		nr_ore++;
		nr_oameni+=2;
		pret+=35; //lei
		//doar vopsire
		suruburi+=5;
	}
	if (bara_spate.schimbare())
	{
		nr_ore+=3;
		nr_oameni+=2;
		pret+=(320+35); //lei
		//schimbare + vopsire
		suruburi+=5;
	}
	if (capota.vopsire())
	{
		nr_ore++;
		nr_oameni+=2;
		pret+=70; //lei
		//doar vopsire
		suruburi+=5;
	}
	if (capota.schimbare())
	{
		nr_ore+=3;
		nr_oameni+=2;
		pret+=(320+70); //lei
		//schimbare + vopsire
		suruburi+=5;
	}
	if (plafon.vopsire())
	{
		nr_ore++;
		nr_oameni+=2;
		pret+=70; //lei
		//doar vopsire
		suruburi+=5;
	}
	if (plafon.schimbare())
	{
		nr_ore+=3;
		nr_oameni+=2;
		pret+=(300+70); //lei
		//schimbare + vopsire
		suruburi+=5;
	}
	if (portbagaj.vopsire())
	{
		nr_ore++;
		nr_oameni+=2;
		pret+=70; //lei
		//doar vopsire
		suruburi+=5;
	}
	if (portbagaj.schimbare())
	{
		nr_ore+=3;
		nr_oameni+=2;
		pret+=(280+70); //lei
		//schimbare + vopsire
		suruburi+=5;
	}
	pret+=aripa.repara(nr_ore, nr_oameni, suruburi, 250);
	pret+=usa.repara(nr_ore, nr_oameni, suruburi, 300);
	pret+=(suruburi * 5); //lei
	pret+=(nr_oameni * nr_ore * manopera);
	if (vechi)
		pret*=1.5;
	//daca vehiculul este vechi, reparatia costa mai mult
	return pret;
}
void automobil::tastatura()
{
	int x, n, nn, m;
	bool schimba;
	cout << "Cate tipuri de defectiuni? ";
	cin >> n;
	for (; n && (!defectiuneCapitala); n--)
    {
        cout << "Alegeti tipul de defectiune\n1.Frane\n2.Suspensie\n3.Motor\n4.Directie\n5.Noxe\n6.Caroserie\n7.Defectiunea Capitala\n";
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
                    cout << "Alegeti tipul de problema\n1.Nivel ulei scazut\n2.Carburator murdar\n3.Motor topit\n4.Bujii defecte\n";
                    cin >> x;
                    switch(x)
                    {
                    	case 2:
                        	carburator = true;
                        	break;
                    	case 4:
                    		cout << "Cate bujii? ";
                    		cin >> bujii;
                    		break;
                        default:
                        	ulei = true;
                        	break;
                	}
                }
                break;
            case 4://Directie
                cout << "Cate roti strambe? ";
	            cin >> x;
	            roti = x;
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
            case 6://Caroserie
                cout << "Cate probleme? ";
                cin >> nn;
                for (; nn; nn--)
                {
                    cout << "Alegeti tipul problemei\n1.Caroserie corodata de rugina\n2.Caroserie stramba\n";
                    cin >> x;
                    if (x == 2)
                        schimba = true;
                    else
                        schimba = false;
                    cout << "Cate componente sunt afectate? ";
                    cin >> m;
                    for (; m; m--)
                    {
                        cout << "Alegeti componentele afectate\n1.Bara din fata\n2.Bara din spate\n3.Capota\n4.Plafon\n5.Portbagaj\n";
                        cout << "6.Aripa\n7.Usa\n";
                        cin >> x;
                        switch (x)
                        {
                            case 1:
                                if (schimba)
                                	bara_fata.schimbare(true);
                                else
                                	bara_fata.vopsire(true);
                                break;
                            case 2:
                                if (schimba)
                                	bara_spate.schimbare(true);
                                else
                                	bara_spate.vopsire(true);
                                break;
                            case 3:
                                if (schimba)
                                	capota.schimbare(true);
                                else
                                	capota.vopsire(true);
                                break;
                            case 4:
                                if (schimba)
                                	plafon.schimbare(true);
                                else
                                	plafon.vopsire(true);
                                break;
                            case 5:
                                if (schimba)
                                	portbagaj.schimbare(true);
                                else
                                	portbagaj.vopsire(true);
                                break;
                            case 6:
                                aripa.tastatura(schimba);
                                break;
                            case 7:
                                usa.tastatura(schimba);
                                break;
                        }
                    }
                }
                break;
            case 7:
                defectiuneCapitala = true;
                break;
                //kaputt
        }
    }
}
istream& operator>>(istream &in, automobil &A)
{
    int n, nn, m;
	bool schimba;
	string s;
	in >> n;
	in.ignore();
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
                        if (s == "Carburator murdar")
                            A.carburator = true;
                        else
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
                    if (s == "Directie")
                    {
                        in >> A.roti;
                        in.ignore();
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
                                    A.vechi = true;
                            }
                        }
                        else
                            if (s == "Caroserie")
                            {
                                in >> nn;
                                in.ignore();
                                for (; nn; nn--)
                                {
                                    getline(in, s);
                                    if (s == "Caroserie stramba")
                                        schimba = true;
                                    else
                                        schimba = false;
                                    in >> m;
                                    in.ignore();
                                    for (; m; m--)
                                    {
                                        getline(in, s);
                                        if (s == "Bara din fata")
                                        {
                                            if (schimba)
                                                A.bara_fata.schimbare(true);
                                            else
                                                A.bara_fata.vopsire(true);
                                        }
                                        else
                                            if (s == "Bara din spate")
                                            {
                                                if (schimba)
                                                    A.bara_spate.schimbare(true);
                                                else
                                                    A.bara_spate.vopsire(true);
                                            }
                                            else
                                                if (s == "Capota")
                                                {
                                                    if (schimba)
                                                        A.capota.schimbare(true);
                                                    else
                                                        A.capota.vopsire(true);
                                                }
                                                else
                                                    if (s == "Plafon")
                                                    {
                                                        if (schimba)
                                                            A.plafon.schimbare(true);
                                                        else
                                                            A.plafon.vopsire(true);
                                                    }
                                                    else
                                                        if (s == "Portbagaj")
                                                        {
                                                            if (schimba)
                                                                A.portbagaj.schimbare(true);
                                                            else
                                                                A.portbagaj.vopsire(true);
                                                        }
                                                        else
                                                            if (s == "Aripa")
                                                                A.aripa.citire(in, schimba);
                                                            else
                                                                A.usa.citire(in, schimba);
                                    }
                                }

                            }
                            else
                                if (s == "Defectiunea Capitala")
                                    A.defectiuneCapitala = true;
                                    //kaputt
    }
    return in;
}
ostream& operator<<(ostream &out, automobil &A)
{
    out << "Automobil\n";
    out << "Defectiunea Capitala " << A.defectiuneCapitala << "\n";
    out << "Placute fata " << A.placute_fata << "\n";
    out << "Placute spate " << A.placute_spate << "\n";
    out << "Discuri " << A.discuri << "\n";
    out << "Ulei " << A.ulei << "\n";
    out << "Carburator " << A.carburator << "\n";
    out << "Roti " << A.roti << "\n";
    out << "Amortizoare " << A.amortizoare << '\n';
    out << "Arcuri " << A.arcuri << '\n';
    out << "Bujii " << A.bujii << '\n';
    out << "De vopsit Bara din fata " << A.bara_fata.vopsire() << '\n';
    out << "De schimbat Bara din fata " << A.bara_fata.schimbare() << '\n';
    out << "De vopsit Bara din spate " << A.bara_spate.vopsire() << '\n';
    out << "De schimbat Bara din spate " << A.bara_spate.schimbare() << '\n';
    out << "De vopsit Capota " << A.capota.vopsire() << '\n';
    out << "De schimbat Capota " << A.capota.schimbare() << '\n';
    out << "De vopsit Plafon " << A.plafon.vopsire() << '\n';
    out << "De schimbat Plafon " << A.plafon.schimbare() << '\n';
    out << "De vopsit Portbagaj " << A.portbagaj.vopsire() << '\n';
    out << "De schimbat Portbagaj " << A.portbagaj.schimbare() << '\n';
    strcpy(tabla::s, "aripa");
    out << A.aripa;
    strcpy(tabla::s, "usa");
    out << A.usa;
    out << A.pret << '\n';
    return out;
}
#endif