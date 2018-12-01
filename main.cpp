#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#define manopera 90
// 90 lei/ora
using namespace std;
class reparatie
{
    bool _vopsire, _schimbare;
public:
    reparatie(bool, bool);
    reparatie(reparatie&);
    ~reparatie();
    reparatie& operator=(reparatie&);
    void vopsire(bool);
    void schimbare(bool);
    bool vopsire();
    bool schimbare();
};
reparatie::reparatie(bool a1 = false, bool a2 = false)
{
    _vopsire = a1;
    _schimbare = a2;
}
reparatie::reparatie(reparatie &A)
{
	_vopsire = A._vopsire;
    _schimbare = A._schimbare;
}
reparatie::~reparatie()
{
    _vopsire = _schimbare = false;
}
reparatie& reparatie::operator=(reparatie &A)
{
    _vopsire = A._vopsire;
    _schimbare = A._schimbare;
    return (*this);
}
void reparatie::vopsire(bool x)
{
	_vopsire = x;
	//vopsire = true <= > componenta va trebui vopsita
}
void reparatie::schimbare(bool x)
{
	_schimbare = x;
	//schimbare = true <= > componenta va trebui schimbata
}
bool reparatie::vopsire()
{
	return _vopsire;
}
bool reparatie::schimbare()
{
	return _schimbare;
}
class tabla
{
    reparatie fata_st, fata_dr, spate_st, spate_dr;
public:
	static char s[10];
    tabla();
    tabla(reparatie, reparatie, reparatie, reparatie);
    tabla(tabla&);
    ~tabla();
    tabla& operator=(tabla&);
    void citire(istream&, bool);
    int repara(int&, int&, int&, int);
    friend ostream& operator<<(ostream&, tabla&);
    void tastatura(bool);
};
char tabla::s[10];
tabla::tabla()
{
    fata_st.vopsire(false); fata_st.schimbare(false);
    fata_dr.vopsire(false); fata_dr.schimbare(false);
    spate_st.vopsire(false); spate_st.schimbare(false);
    spate_dr.vopsire(false); spate_dr.schimbare(false);
}
tabla::tabla(reparatie a1, reparatie a2, reparatie a3, reparatie a4)
{
    fata_st = a1;
    fata_dr = a2;
    spate_st = a3;
    spate_dr = a4;
}
tabla::tabla(tabla &A)
{
    fata_st = A.fata_st;
    fata_dr = A.fata_dr;
    spate_st = A.spate_st;
    spate_dr = A.spate_dr;
}
tabla::~tabla()
{
    fata_st.vopsire(false); fata_st.schimbare(false);
    fata_dr.vopsire(false); fata_dr.schimbare(false);
    spate_st.vopsire(false); spate_st.schimbare(false);
    spate_dr.vopsire(false); spate_dr.schimbare(false);
}
tabla& tabla::operator=(tabla &A)
{
    fata_st = A.fata_st;
    fata_dr = A.fata_dr;
    spate_st = A.spate_st;
    spate_dr = A.spate_dr;
    return (*this);
}
void tabla::citire(istream &in, bool schimba)
{
	char s[50];
	in >> s;
    if (!strcmp(s, "fata"))
    {
    	in >> s;
        if (!strcmp(s, "stanga"))
        {
        	if (schimba)
        		fata_st.schimbare(true);
        	else
        		fata_st.vopsire(true);
        }
        else
        	if (!strcmp(s, "dreapta"))
        	{
        		if (schimba)
         			fata_dr.schimbare(true);
        		else
        			fata_dr.vopsire(true);
      		}
    }
    else
    	if (!strcmp(s, "spate"))
    	{
    		in >> s;
    		if (!strcmp(s, "stanga"))
    		{
    			if (schimba)
    				spate_st.schimbare(true);
    			else
    				spate_st.vopsire(true);
    		}
    		else
    			if (!strcmp(s, "dreapta"))
      			{
    				if (schimba)
    					spate_dr.schimbare(true);
    				else
     					spate_dr.vopsire(true);
				}
		}
}
int tabla::repara(int &nr_ore, int &nr_oameni, int &suruburi, int basePice)
{
	int pret = 0;
	if (fata_st.vopsire())
	{
		nr_ore++;
		nr_oameni+=2;
		pret+=35; //lei
		//doar vopsire
		suruburi+=5;
	}
	if (fata_st.schimbare())
	{
		nr_ore+=3;
		nr_oameni+=2;
		pret+=(basePice+35); //lei
		//schimbare + vopsire
		suruburi+=5;
	}
	if (fata_dr.vopsire())
	{
		nr_ore++;
		nr_oameni+=2;
		pret+=35; //lei
		//doar vopsire
		suruburi+=5;
	}
	if (fata_dr.schimbare())
	{
		nr_ore+=3;
		nr_oameni+=2;
		pret+=(basePice+35); //lei
		//schimbare + vopsire
		suruburi+=5;
	}
	if (spate_st.vopsire())
	{
		nr_ore++;
		nr_oameni+=2;
		pret+=35; //lei
		//doar vopsire
		suruburi+=5;
	}
	if (spate_st.schimbare())
	{
		nr_ore+=3;
		nr_oameni+=2;
		pret+=(basePice+35); //lei
		//schimbare + vopsire
		suruburi+=5;
	}
	if (spate_dr.vopsire())
	{
		nr_ore++;
		nr_oameni+=2;
		pret+=35; //lei
		//doar vopsire
		suruburi+=5;
	}
	if (spate_dr.schimbare())
	{
		nr_ore+=3;
		nr_oameni+=2;
		pret+=(basePice+35); //lei
		//schimbare + vopsire
		suruburi+=5;
	}
	return pret;
}
ostream& operator<<(ostream& out, tabla &A)
{
    out << "De vopsit " << A.s << " fata stanga " << A.fata_st.vopsire() << '\n';
    out << "De schimbat " << A.s << " fata stanga " << A.fata_st.schimbare() << '\n';
    out << "De vopsit " << A.s << " fata dreapta " << A.fata_dr.vopsire() << '\n';
    out << "De schimbat " << A.s << " fata dreapta " << A.fata_dr.schimbare() << '\n';
    out << "De vopsit " << A.s << " spate stanga " << A.spate_st.vopsire() << '\n';
    out << "De schimbat " << A.s << " spate stanga " << A.spate_st.schimbare() << '\n';
    out << "De vopsit " << A.s << " spate dreapta " << A.spate_dr.vopsire() << '\n';
    out << "De schimbat " << A.s << " spate dreapta " << A.spate_dr.schimbare() << '\n';
    return out;
}
void tabla::tastatura(bool schimba)
{
	int x;
	cout << "Alegeti partea afectata\n1.Fata stanga\n2.Fata dreapta\n3.Spate stanga\n4.Spate dreapta\n";
	cin >> x;
	switch(x)
	{
		case 1:
			if (schimba)
				fata_st.schimbare(true);
			else
				fata_st.vopsire(true);
			break;
		case 2:
			if (schimba)
				fata_dr.schimbare(true);
			else
				fata_dr.vopsire(true);
			break;
		case 3:
			if (schimba)
				spate_st.schimbare(true);
			else
				spate_st.vopsire(true);
			break;
		case 4:
			if (schimba)
				spate_dr.schimbare(true);
			else
				spate_dr.vopsire(true);
			break;
	}
}
class vehicul
{
protected:
    float pret;
    bool defectiuneCapitala;
    int roti;
public:
    static int n;
	vehicul(float, bool, int);
	vehicul(vehicul&);
	virtual ~vehicul();
	virtual vehicul& operator=(vehicul&);
	virtual float repara() = 0;
    virtual void tastatura() = 0;
    static void numar();
};
int vehicul::n = 0;
vehicul::vehicul(float a1 = 0, bool a2 = false, int a3 = 0)
{
	pret = a1;
	defectiuneCapitala = a2;
	roti = a3;
}
vehicul::vehicul(vehicul &A)
{
	pret = A.pret;
	defectiuneCapitala = A.defectiuneCapitala;
	roti = A.roti;
}
vehicul::~vehicul()
{
	pret = 0;
	defectiuneCapitala = false;
	roti = 0;
}
vehicul& vehicul::operator=(vehicul &A)
{
	pret = A.pret;
	defectiuneCapitala = A.defectiuneCapitala;
	roti = A.roti;
	return (*this);
}
void vehicul::numar()
{
    cout << "Am citit " << n << " obiecte" << '\n';
}
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
int main()
{
	int i, ok, total = 0;
	string s;
	vector <vehicul *> vec;
    bicicleta  *B;
    motocicleta  *M;
    automobil  *A;
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
            B = dynamic_cast<bicicleta*>(vec[i]);
            if (B)
            {
                B = (bicicleta*)vec[i];
                fout << (*B);
            }
            else
            {
                M = dynamic_cast<motocicleta * >(vec[i]);
                if (M)
                {
                    M = (motocicleta*)vec[i];
                    fout << (*M);
                }
                else
                {
                    A = dynamic_cast<automobil * >(vec[i]);
                    if (A)
                    {
                        A = (automobil*)vec[i];
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
