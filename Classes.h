
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;

struct expr{  //expression - dlia analisa virazhenia
int a[3];
char s[128];  //virazhenie
bool b; //proverka na correctnist'
};


class Sotrudnik
{
private:
    int ID_sotr;  //(PK)
public:
    int ID_fil;  //(FK)
    string name;
    string surname;
    string position;
    Sotrudnik(const int & t_ID_sotr, const string& t_name, const string& t_surname, const string& t_position, const int & t_ID_fil){
        ID_sotr = t_ID_sotr;
        name = t_name;
        surname = t_surname;
        position = t_position;
        ID_fil = t_ID_fil;
    }
    int get_ID_sotr() const{
        return ID_sotr;
    }
    ~Sotrudnik(){;}
};

class DataBase1{
public:
    vector<Sotrudnik> mass;
    DataBase1() {;}
    ~DataBase1() {;}
    void add_sotrudnik(const string& t_name, const string& t_surname, const string& t_position, const int & t_ID_fil){
        Sotrudnik t_sotr(mass.size(), t_name, t_surname, t_position, t_ID_fil);
        mass.push_back(t_sotr);
    }
    friend ofstream & operator<<(ofstream &out, const DataBase1 &db){
        for (unsigned i = 0; i < db.mass.size(); ++i){
            out << db.mass[i].get_ID_sotr() << " " << db.mass[i].name << " " << db.mass[i].surname
                << " " << db.mass[i].position << " " << db.mass[i].ID_fil << endl;
        }
        return out;
    }
};

class Spisanie
{
private:
    int ID_sp;  //(PK)
public:
    int number;
    int month;
    int year;
    int ID_sotr; //(FK)
    int ID_fil;  //(FK)
    Spisanie(const int & t_ID_sp, const int& t_number, const int& t_month, const int& t_year, const int & t_ID_sotr){
        ID_sp = t_ID_sp;
        ID_sotr = t_ID_sotr;
        number = t_number;
        month = t_month;
        year = t_year;
    }
    int get_ID_sp() const{
    return ID_sp;
    }
};

class DataBase2{
public:
    vector<Spisanie> mass;
    DataBase2() {;}
    ~DataBase2() {;}
    void add_spisanie(const int& t_number, const int& t_month, const int& t_year, const int& t_ID_sotr){
        Spisanie t_spisanie(mass.size(), t_number, t_month, t_year, t_ID_sotr);
        mass.push_back(t_spisanie);
    }
    friend ofstream & operator<<(ofstream &out, const DataBase2 &db){
        for (unsigned i = 0; i < db.mass.size(); ++i){
            out << db.mass[i].get_ID_sp() << " " << db.mass[i].number << " " << db.mass[i].month << " " << db.mass[i].year << " " << db.mass[i].ID_sotr << " " << db.mass[i].ID_fil << endl;
        }
    return out;
    }
};

class Filial
{
private:
    int ID_fil;  //(PK)
public:
    string nazv;
    string adr;
    Filial(const int & t_ID_fil, const string& t_nazv, const string &t_adr){
    ID_fil = t_ID_fil;
    nazv = t_nazv;
    adr=t_adr;
    }
    int get_ID_fil() const{
    return ID_fil;
    }
};

class DataBase3
{
public:
    vector<Filial> mass;
    DataBase3() {;}
    ~DataBase3() {;}
    void add_fil(const string& t_nazv, const string t_adr){
        Filial t_filial(mass.size(), t_nazv, t_adr);
        mass.push_back(t_filial);
    }
    friend ofstream & operator<<(ofstream &out, const DataBase3 &db){
    for (unsigned i = 0; i < db.mass.size(); ++i){
        out << db.mass[i].get_ID_fil() << " " << db.mass[i].nazv << " " << db.mass[i].adr << endl;
    }
    return out;
    }
};

class StrokaSpisania
{
private:
    int ID_str_sp;  //(PK)
public:
    int ID_sp;  //(FK)
    int ID_kn_ek;  //(FK)
    StrokaSpisania(const int & t_ID_sp_str, const int & t_ID_sp){
        ID_str_sp = t_ID_sp_str;
        ID_sp = t_ID_sp;
    }
    int get_ID_str_sp() const{
        return ID_str_sp;
    }
};

class DataBase4{
public:
    vector <StrokaSpisania> mass;
    DataBase4() {;}
    ~DataBase4() {;}
    void add_strsp(const int& t_ID_sp){
        StrokaSpisania t_strsp(mass.size(), t_ID_sp);
        mass.push_back(t_strsp);
    }
    friend ofstream & operator<<(ofstream &out, const DataBase4 &db){
        for (unsigned i = 0; i < db.mass.size(); ++i){
            out << db.mass[i].get_ID_str_sp() << " " << db.mass[i].ID_sp << " " << db.mass[i].ID_kn_ek << endl;
        }
    return out;
    }
};

class Kniga_op{
private:
    int ID_kn_op;  //(PK)
public:
    string avt;
    string nazv;
    int god;
    Kniga_op(const int & t_ID_kn_op, const string& t_avt, const string& t_nazv, const int & t_god){
        ID_kn_op = t_ID_kn_op;
        avt = t_avt;
        nazv = t_nazv;
        god=t_god;
    }
    int get_ID_kn_op() const{
        return ID_kn_op;
    }
};

class DataBase5
{
public:
    vector<Kniga_op> mass;
    DataBase5() {;}
    ~DataBase5() {;}
    void add_kniga_op(const string& t_avt, const string& t_nazv, int t_god){
        Kniga_op t_kniga_op (mass.size(), t_avt, t_nazv, t_god);
        mass.push_back(t_kniga_op);
    }
    friend ofstream & operator<<(ofstream &out, const DataBase5 &db){
        for (unsigned i = 0; i < db.mass.size(); ++i){
            out << db.mass[i].get_ID_kn_op() << " " << db.mass[i].avt << " " << db.mass[i].nazv<< " " << db.mass[i].god << endl;
        }
        return out;
    }
};

class Kniga_ek{
private:
    int ID_kn_ek;  //(PK)
public:
    int ID_kn_op;  //(FK)
    Kniga_ek(const int & t_ID_kn_ek, const int & t_ID_kn_op){
        ID_kn_ek = t_ID_kn_ek;
        ID_kn_op=t_ID_kn_op;
    }
    int get_ID_kn_ek() const{
        return ID_kn_ek;
    }
};

class DataBase6
{
public:
    vector<Kniga_ek> mass;
    DataBase6() {;}
    ~DataBase6() {;}
    void add_kniga_ek(int t_ID_kn_op){
        Kniga_ek t_kniga_ek (mass.size(),t_ID_kn_op);
        mass.push_back(t_kniga_ek);
    }
    friend ofstream & operator<<(ofstream &out, const DataBase6 &db){
        for (unsigned i = 0; i < db.mass.size(); ++i){
            out << db.mass[i].get_ID_kn_ek() << " " << db.mass[i].ID_kn_op << endl;
        }
        return out;
    }
};

class Dictionary{
public:
    const char* classes[6];
    const char* atr_sotr[5];
    const char* atr_sp[6];
    const char* atr_fil[3];
    const char* atr_str_sp[3];
    const char* atr_kniga_op[4];
    const char* atr_kniga_ek[2];
    const char* tabs[6];
    Dictionary(){
    classes[0]= "Sotr";
    classes[1]= "Sp";
    classes[2]= "Fil";
    classes[3]= "Str";
    classes[4]= "KnOp";
    classes[5]= "KnEk";
    atr_sotr[0]= "PK";
    atr_sotr[1]= "fil";
    atr_sotr[2]= "name";
    atr_sotr[3]= "surname";
    atr_sotr[4]= "position";
    atr_sp[0]= "PK";
    atr_sp[1]= "number";
    atr_sp[2]= "month";
    atr_sp[3]= "year";
    atr_sp[4]= "sotr";
    atr_sp[5]= "fil";
    atr_fil[0]= "PK";
    atr_fil[1]= "name";
    atr_fil[2]= "adr";
    atr_str_sp[0]= "PK";
    atr_str_sp[1]= "sp";
    atr_str_sp[2]= "kn_ek";
    atr_kniga_op[0]= "PK";
    atr_kniga_op[1]= "avt";
    atr_kniga_op[2]= "nazv";
    atr_kniga_op[3]= "god";
    atr_kniga_ek[0]= "PK";
    atr_kniga_ek[1]= "kn_op";
    tabs[0]= "TSotr";
    tabs[1]= "TSp";
    tabs[2]= "TFil";
    tabs[3]= "TStr";
    tabs[4]= "TKnOp";
    tabs[5]= "TKnEk";
    }
    ~Dictionary(){;}
};
