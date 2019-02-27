#ifndef REPARATIE_H
#define REPARATIE_H

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
	// vopsire = true < = > componenta va trebui vopsita
}
void reparatie::schimbare(bool x)
{
	_schimbare = x;
	// schimbare = true < = > componenta va trebui schimbata
}
bool reparatie::vopsire()
{
	return _vopsire;
}
bool reparatie::schimbare()
{
	return _schimbare;
}

#endif