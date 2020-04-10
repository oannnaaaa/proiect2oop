#include <iostream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Data
{
protected:
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
     static int n;
protected:
    string nume;
    string prenume;
    float salariu;
    Data data_angajare;

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
    friend ostream& operator<<(ostream&, Angajat&);
    friend istream& operator>>(istream&, Angajat&);
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
};

int Angajat::n = 0;
void Angajat::citire(istream &in)
{
    cout<<"Nume:";
    in>>nume;

    cout<<"Prenume:";
    in>>prenume;
    /*in.get();
    string p;
    //getline(in,p); ///citire string pana la enter (permite sa avem spatii)
    prenume=p;*/

    cout<<"Salariu:";
    in>>salariu;

    cout<<"Data angajare:";
    in>>data_angajare;
}
void Angajat::afisare(ostream &out){
    out<<"Nume: "<<nume<<"\n";
    out<<"Prenume: "<<prenume<<"\n";
    out<<"Salariu: "<<salariu<<"\n";
    out<<"Data angajarii: "<<data_angajare<<"\n";
}

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
ostream& operator<<(ostream& out, Angajat& d)
{
 d.afisare(out);
 return out;
}

///supraincarcarea operatorului >>
istream& operator>>(istream& in, Angajat& a)
{
 a.citire(in);
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
    Part_time(string,string,float,Data,int,Data);

///Constructor de copiere
    Part_time(Part_time& a);

///Destructor
    ~Part_time();

///Alte metode
Part_time& operator= ( Part_time& z);
friend ostream& operator<<(ostream&, Part_time&);
friend istream& operator>>(istream&, Part_time&);
void citire(istream &in);
void afisare(ostream &out);
};

void Part_time::citire(istream &in){
    Angajat::citire(in);
    cout<<"Dati numarul orelor de lucru pe zi: ";
    in>>nr_ore_zi;
    cout<<"Dati data expirarii contract: ";
    in>>final_contract;
}
void Part_time::afisare(ostream &out){
    Angajat::afisare(out);
    out<<"Numarul orelor de lucru pe zi: ";
    out<<nr_ore_zi<<"\n";
    out<<"Contractul expira la: ";
    out<<final_contract<<"\n";
}

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
ostream& operator<<(ostream& out,  Part_time& d)
{
d.afisare(out);
 return out;
}

///supraincarcarea operatorului >>
istream& operator>>(istream& in, Part_time& a)
{
 a.citire(in);
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
friend ostream& operator<<(ostream&, Permanent&);
friend istream& operator>>(istream&, Permanent&);
void citire(istream &in);
void afisare(ostream &out);
};


void Permanent::citire(istream &in){
    Angajat::citire(in);
    cout<<"Dati numarul minorilor: ";
    in>>nr_minori_intretinere;
}
void Permanent::afisare(ostream &out){
    Angajat::afisare(out);
    out<<"Numarul minorilor este: ";
    out<<nr_minori_intretinere<<"\n";
}

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
ostream& operator<<(ostream& out, Permanent& d)
{
d.afisare(out);
 return out;
}

///supraincarcarea operatorului >>
istream& operator>>(istream& in, Permanent& a)
{
 a.citire(in);
 return in;
}



void tip(Angajat *&p, int &i) {
    string s;
    cout<<"\n";
    cout<<"Introduceti tipul angajatului "<<i+1<<": ";
    cin>>s;
    try{
        if(s=="Part-time"){
                p=new Part_time;
                cin>>*p;
                i++;
        }
        else
            if(s=="Permanent"){
                p=new Permanent;
                cin>>*p;
                i++;
            }
            else
                if (s=="Angajat"){
                    p=new Angajat;
                    cin>>*p;
                    i++;
                }
                else
                    throw 10;
    }
    catch (bad_alloc var){
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j){
        cout<<"Nu ati introdus un post valid. Incercati Part-time, Permanant sau Angajat.\n ";
    }
}


int main()
{

    Angajat **ang;

    int n;
    cout<<"Introduceti numarul de angajati. "; cin>>n; cout<<endl;

    try{
        ang=new Angajat*[n]; ///aloc memorie pentru n obiecte de tip personal apoi pentru fiecare obiect de tip personal etichetez tipul (adica il pot lasa personal
                                                                                                                            /// sau il pot face regizor/actor)
        for(int i=0;i<n;)
            tip(ang[i],i); ///etichetez tipul, citesc, retin fiind transmis prin adresa
        cout<<"\nAfisam personalul citit anterior:\n";
        for(int i=0;i<n;i++){
            cout<<"\n"<<*ang[i]; ///afisez personalul de pe pozitia i
            cout<<"--------------------------\n";
        }
    }
    catch (bad_alloc var){
        cout<<"Numarul introdus trebuie sa fie pozitiv. Bad Alloc!\n";
        exit(EXIT_FAILURE);
    }
    return 0;

 return 0;
}
