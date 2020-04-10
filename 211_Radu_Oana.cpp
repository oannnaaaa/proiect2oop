#include <iostream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Data
{
private:
    int zi;
    string luna;
    int an;
public:
    friend class Angajat;

///constructor de initializare
    Data()
{
    zi = 0;
    luna= "septembrie";
    an = 1999;
}

///constructor parametrizat
    Data(int z , string l, int a)
{
        this->zi = z;
        this->luna=l;
        this->an=a;
}

///constructor de copiere
    Data(Data& d);

///destructor
    ~Data();

///set-uri si get-uri
    void setZi(int b){zi = b;}
    int getZi(){return zi;}

    void setLuna(string c){luna = c;}
    string getLuna(){return luna;}

    void setAn(int a){an = a;}
    int getAn(){return an;}

///alte metode
    Data& operator= ( Data& z); //supraincarcarea operatorului =
    friend ostream& operator<<(ostream&, const Data&); //supraincarcarea operatorului <<
    friend istream& operator>>(istream&, Data&);//supraincarcarea operatorului>>

};

Data auxx(0,"sept",1000);

///constructor de copiere
Data::Data(Data &d)
{
    this->zi=d.zi;
    this->luna=d.luna;
    this->an=d.an;
}

///Destructor
Data::~Data()
{
    //cout<<"Destructor is called"<<endl;
}

/// supraincarcarea operatorului =
Data& Data::operator= (Data& z)
{
    if ( this != &z){
      this->zi = z.zi;
      this->luna=z.luna;
      this->an = z.an;}
   return *this;
}

///supraincarcarea operatorului <<
ostream& operator<<(ostream& out, const Data& d)
{
 out << d.zi << "/" << d.luna<<"/"<<d.an<<endl;
 return out;
}

///supraincarcarea operatorului >>
istream& operator>>(istream& in, Data& d)
{
 in >> d.zi;
 in >> d.luna;
 in >> d.an;
 return in;
}

class Angajat
{
protected:
    string nume;
    string prenume;
    float salariu;
    Data data_angajare;
    static int n;

public:
/// metoda statica de afisare a numarului de obiecte
static void numarObiecte(){ cout<<"nr total de angajati este: "<<n<<endl;}

///Constructorul de initializare
Angajat()
{
        n++; ///incrementam in constructor
        nume = "Default";
        prenume = "Default";
        salariu = 0;
        Data aux(0,"sept",1000);
        data_angajare = aux;
}

///Constructorul parametrizat
Angajat(string nume, string prenume, float salariu, Data data_angajare )
{
         n++; ///incrementam in constructor
        this->nume = nume;
        this->prenume = prenume;
        this->salariu = salariu;
        this->data_angajare = data_angajare;
}

///Constructorul de copiere
 Angajat(Angajat& a);

 ///Destructorul
 ~Angajat();

 ///set-uri si get-uri
    void setNume(string num){nume=num;}
    void setPrenume(string p){prenume=p;}
    void setSalariu(float s){salariu=s;}
    void setDataAngajare(Data d){data_angajare=d;}
    string getNume(){return nume;}
    string getPrenume(){return prenume;}
    float getSalariu(){return salariu;}
    Data getDataAngajare(){return data_angajare;}

///alte metode
    Angajat& operator= ( Angajat& z);
    friend ostream& operator<<(ostream&,const Angajat&);
    friend istream& operator>>(istream&, Angajat&);

};

int Angajat::n = 0;

///Constructorul de copiere
Angajat::Angajat(Angajat& a) //constructor de copiere
{
    n++; ///incrementam in constructor
    this->prenume=a.prenume;
    this->nume=a.nume;
    this->salariu=a.salariu;
    this->data_angajare=a.data_angajare;
}

///Destructorul
Angajat::~Angajat(){}

/// supraincarcarea operatorului =
Angajat& Angajat::operator= (Angajat& a)
{
    if ( this != &a)
    {
      this->nume = a.nume;
      this->prenume=a.prenume;
      this->salariu =a.salariu;
      this->data_angajare=a.data_angajare;
    }
   return *this;
}

///supraincarcarea operatorului <<
ostream& operator<<(ostream& out,  const Angajat& d)
{
 out << d.nume << "  " << d.prenume<<" "<<d.salariu<<"  "<<d.data_angajare<<endl;
 return out;
}

///supraincarcarea operatorului >>
istream& operator>>(istream& in, Angajat& a)
{
 in >> a.nume;
 in >> a.prenume;
 in >> a.salariu;
 in >> a.data_angajare;
 return in;
}

class Part_time:public Angajat
{
    private:
        int nr_ore_zi;
        Data final_contract;
    public:
///constructor de initializare
    Part_time():Angajat()
{
    nr_ore_zi=0;
    Data aux(0,"sept",1000);
    final_contract=aux;
}
///constructor parametrizat
    virtual Part_time(string,string,float,Data,int,Data);

///Constructor de copiere
    virtual Part_time(Part_time& a);

///Destructor
    ~Part_time();

///Alte metode
Part_time& operator= ( Part_time& z);
friend ostream& operator<<(ostream&,const Part_time&);
friend istream& operator>>(istream&, Part_time&);
};
///Constrcutor parametrizat
Part_time::Part_time(string nume, string prenume, float salariu,Data data_angajare,int ore=0,Data finalc=auxx):Angajat(nume,prenume,salariu,data_angajare)
{
    nr_ore_zi=ore;
    final_contract=finalc;
}

///Constructorul de copiere
Part_time::Part_time(Part_time& a):Angajat() //constructor de copiere
{
    this->nr_ore_zi=a.nr_ore_zi;
    this->final_contract=a.final_contract;
}

///Destructor
Part_time::~Part_time(){}

/// supraincarcarea operatorului =
Part_time& Part_time::operator= (Part_time& t)
{
    if ( this != &t)
    {
      this->nume =t.nume;
      this->prenume=t.prenume;
      this->salariu =t.salariu;
      this->data_angajare=t.data_angajare;
      this->nr_ore_zi= t.nr_ore_zi;
      this->final_contract=t.final_contract;
    }
   return *this;
}

///supraincarcarea operatorului <<
ostream& operator<<(ostream& out,  const Part_time& d)
{
 out << d.nume << "  " << d.prenume<<" "<<d.salariu<<"  "<<d.data_angajare<<d.nr_ore_zi<<d.final_contract<<endl;
 return out;
}

///supraincarcarea operatorului >>
istream& operator>>(istream& in, Part_time& a)
{
 in >> a.nume;
 in >> a.prenume;
 in >> a.salariu;
 in >> a.data_angajare;
 in >> a.nr_ore_zi;
 in >> a.final_contract;
 return in;
}

class Permanent:public Angajat
{
    private:
        int nr_minori_intretinere;
    public:
///constructor de initializare
    Permanent():Angajat()
{
    nr_minori_intretinere=0;
}
///constructor parametrizat
    Permanent(string,string,float,Data,int);

///Constructor de copiere
    Permanent(Permanent& a);

///Destructor
    ~Permanent();

///Alte metode
Permanent& operator= ( Permanent& z);
friend ostream& operator<<(ostream&,const Permanent&);
friend istream& operator>>(istream&, Permanent&);
};
///Constrcutor parametrizat
Permanent::Permanent(string nume, string prenume, float salariu,Data data_angajare,int minori=0):Angajat(nume,prenume,salariu,data_angajare)
{
    nr_minori_intretinere=minori;
}

///Constructorul de copiere
Permanent::Permanent(Permanent& a):Angajat()
{
    this->nr_minori_intretinere=nr_minori_intretinere;
}

///Destructor
Permanent::~Permanent(){}

/// supraincarcarea operatorului =
Permanent& Permanent::operator= (Permanent& p)
{
    if ( this != &p)
    {
      this->nume =p.nume;
      this->prenume=p.prenume;
      this->salariu =p.salariu;
      this->data_angajare=p.data_angajare;
      this->nr_minori_intretinere=p.nr_minori_intretinere;
    }
   return *this;
}

///supraincarcarea operatorului <<
ostream& operator<<(ostream& out,  const Permanent& d)
{
 out << d.nume << "  " << d.prenume<<" "<<d.salariu<<"  "<<d.data_angajare<<d.nr_minori_intretinere<<endl;
 return out;
}

///supraincarcarea operatorului >>
istream& operator>>(istream& in, Permanent& a)
{
 in >> a.nume;
 in >> a.prenume;
 in >> a.salariu;
 in >> a.data_angajare;
 in >> a.nr_minori_intretinere;
 return in;
}

int main()
{

    Part_time a1;
    Permanent a2;
    Angajat::numarObiecte(); ///apelarea metodei statice
    cout<<"\n";
    cout<<"poo ul e groaznic!!"<<endl;

 return 0;
}
