#ifndef TABLA_H
#define TABLA_H

#include <iostream>
#include "reparatie.h"
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

#endif