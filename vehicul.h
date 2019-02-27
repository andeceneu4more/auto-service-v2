#ifndef VEHICUL_H
#define VEHICUL_H

#include <iostream>
#define manopera 90
// 90 lei/ora
using namespace std;
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

#endif
