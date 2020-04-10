///Radu Oana, grupa 211,proiect 2 poo :)
#include <iostream>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

//---------------------------------------------------------------
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
    Data(const Data& d);

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

Data auxx(0,"sept",1000); //ajuta constructorul parametrizat din clasa Part-time

///constructor de copiere
Data::Data(const Data &d)
{
    zi=d.zi;
    luna=d.luna;
    an=d.an;
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
 cout<<endl<<"\tZi (int): "; in >> d.zi;
 cout<<"\tLuna (string): "; in >> d.luna;
 cout<<"\tAn (int): "; in >> d.an;
 return in;
}

//-----------------------------------------------------------------------------
class Angajat
{

protected:
    static int n,suma_standard;;
    string nume;
    string prenume;
    float salariu;
    Data data_angajare;

public:
/// metoda statica de afisare a numarului de obiecte
static void numarObiecte(){ cout<<"Numarul total de angajati este: "<<n<<endl;}

///Constructorul de initializare
Angajat()
{
        n++;
        nume = "Default";
        prenume = "Default";
        salariu = 0;
        Data aux(0,"sept",1000);
        data_angajare = aux;
}

///Constructorul parametrizat
Angajat(string nume, string prenume, float salariu, Data data_angajare )
{
        n++;
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
    string getNume(){return nume;}

    void setPrenume(string p){prenume=p;}
    string getPrenume(){return prenume;}

    void setSalariu(float s){salariu=s;}
    float getSalariu(){return salariu;}

    void setDataAngajare(Data d){data_angajare=d;}
    Data getDataAngajare(){return data_angajare;}

    void setSumaStandard(int n) {suma_standard = n;}
    int getSumaStandard(){return suma_standard;}

///alte metode
    Angajat& operator= ( Angajat& z);
    friend ostream& operator<<(ostream&, Angajat&);
    friend istream& operator>>(istream&, Angajat&);
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);


};

int Angajat::n = 0;
int Angajat::suma_standard = 500;

void Angajat::citire(istream &in)
{
    cout<<"Nume: ";
    in>>nume;

    cout<<"Prenume: ";
    in>>prenume;

    cout<<"Salariu: ";
    in>>salariu;

    cout<<"Data angajarii: ";
    in>>data_angajare;
}

void Angajat::afisare(ostream &out){
    out<<"Nume: "<<nume<<"\n";
    out<<"Prenume: "<<prenume<<"\n";
    out<<"Salariu: "<<salariu<<"\n";
    out<<"Data angajarii: "<<data_angajare;
}

///Constructorul de copiere
Angajat::Angajat(Angajat& a)
{
    n++;
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

//--------------------------------------------------------------------------------
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

float prima( Part_time& t)
{
    int prima = 0;

    string luna_curenta = t.final_contract.getLuna();
    Data final_luna(30,"aprilie",2020);

    if (t.final_contract.getAn() < 2020 || (t.final_contract.getAn() == 2020 && ( luna_curenta == "ianuarie" || luna_curenta == "februarie" || luna_curenta == "martie" || luna_curenta == "aprilie")))
        prima = 0.75 * t.suma_standard;
    else
        prima = t.suma_standard;

    return prima;
}

};

void Part_time::citire(istream &in){
    Angajat::citire(in);
    cout<<"Dati numarul orelor de lucru pe zi: ";
    in>>nr_ore_zi;
    cout<<"Dati data expirarii contractului: ";
    in>>final_contract;
}
void Part_time::afisare(ostream &out){
    Angajat::afisare(out);
    out<<"Numarul orelor de lucru pe zi: ";
    out<<nr_ore_zi<<"\n";
    out<<"Contractul expira la: ";
    out<<final_contract<<"\n";
    out<<"Prima pe care o ia de sarbatori este: ";
    out<<this->prima(*this);
}

///Constrcutor parametrizat
Part_time::Part_time(string nume, string prenume, float salariu,Data data_angajare,int ore=0,Data finalc= auxx):Angajat(nume,prenume,salariu,data_angajare)
{
    nr_ore_zi=ore;
    final_contract=finalc;
}

///Constructorul de copiere
Part_time::Part_time(Part_time& a):Angajat()
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

float prima( Permanent& t)
{
    float suma = t.getSumaStandard(), spor = 0, vechime;
    Data final_an(31,"decembrie",2020);
    Data data_ang = t.getDataAngajare();

    vechime = final_an.getAn() - data_ang.getAn();
    if (t.nr_minori_intretinere != 0)
        spor = (vechime/100) * suma_standard * t.nr_minori_intretinere;
    else
        spor = (vechime/100) * suma_standard;

    return suma + spor;
}

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
    out<<"Prima pe care o ia de sarbatori este: ";
    out<<this->prima(*this);
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


///Functie cu care incepe programul(nu este metoda a vreunei clase)
void tip(Angajat *&p, int &i) {

    string s;
    cout<<"Introduceti tipul angajatului "<<i+1<<" (Part-time, Permanent): "<<endl;
    cin>>s;

    try{
        if(s=="Part-time" || s=="part-time"){
                p=new Part_time;
                cin>>*p;
                i++;
        }
        else
            if(s=="Permanent" || s=="permanent"){
                p=new Permanent;
                cin>>*p;
                i++;
            }
            else
                /*if (s=="Angajat" || s=="angajat"){
                    p=new Angajat;
                    cin>>*p;
                    i++;
                }
                else*/
                    throw 10;
    }
    catch (bad_alloc var){
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j){
        cout<<"Nu ati introdus un post valid. Incercati Part-time sau Permanant.\n ";
    }
}


int main()
{

    Angajat **ang;

    int n;
    cout<<"Introduceti numarul de angajati. "; cin>>n; cout<<endl;

    try{
        ang=new Angajat*[n];
        for(int i=0;i<n;)
            tip(ang[i],i);

        cout<<"\n\nDatele angajatilor au fost citite cu succes!\n\n";

        _sleep(3000);  //asteapta 4 secunde
        system("cls"); // curata ecranul din consola

        int opt = 0;


        cout<<"\n-----------------MENIU-----------------\n\n";
        cout<<"\t 1. Afisati datele angajatilor;\n";
        cout<<"\t 2. Curatati ecranul. \n";
        cout<<"\t 3. Iesiti din program. \n";

        while (opt != -1)
        {
        if (opt == 1)
        cout<<"\n  Introduceti optiunea dorita: \n  1 - afisati toti angajatii; 2 - curatati ecranul;\n  3 - inchideti programul; \n";
        cin >> opt;

            switch (opt)
            {
                case 1:
                    {
                            cout<<"\nAfisam personalul citit anterior:\n";

                        for(int i=0;i<n;i++)
                            {
                            cout<<"\n Angajat id: "<<i+1<<" \n"<<*ang[i]; ///afisez personalul de pe pozitia i
                            cout<<"--------------------------\n";
                            }
                    }
                    break;

                case 2:
                    {
                        system("cls");
                        cout<<"\n-----------------MENIU-----------------\n\n";
                        cout<<"\t 1. Afisati datele angajatilor;\n";
                        cout<<"\t 2. Curatati ecranul. \n";
                        cout<<"\t 3. Iesiti din program. \n";
                    }
                    break;
                case 3:
                    return 0;
                default:
                    cout<<"Ati ales o optiune invalida. \n";

            }
        }
    }
    catch (bad_alloc var){
        cout<<"Numarul introdus trebuie sa fie pozitiv. Bad Alloc!\n";
        exit(EXIT_FAILURE);
    }
    return 0;

 return 0;
}
