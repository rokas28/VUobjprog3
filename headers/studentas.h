#ifndef UNTITLED_STUDENTAS_H
#define UNTITLED_STUDENTAS_H

#include "main_header.h"

class Studentas {
private:
    string vardas, pavarde;
    int egzaminas;
    std::vector<int > nd;
public:
    Studentas() : egzaminas(0) { };
    double vidGalutinis = 0;
    double medGalutinis = 0;
    void set_name(string &a){ vardas = a; };
    void set_lastname (string &a) {pavarde = a; };
    string get_name() {return vardas; };
    string get_lastname() {return pavarde; };
    void set_exam (int a);
    int get_exam() {return egzaminas; };
    void set_mark(int a);
    double ndSum(int x);
    double mediana(int x, int y);

};

double mediana(std::vector<Studentas> stud, int x, int y);
bool netinkamasPav(const string a);
void ndGen(std::vector<Studentas>& stud, int x, int y);
void egGen(std::vector<Studentas>& stud, int y);
void galutinis(std::vector<Studentas>& stud, int x, int y);
void varTikrinimas(std::vector<Studentas>& stud, int y);
void pavTikrinimas(std::vector<Studentas>& stud, int y);
void fTikrinimas(int &f);
void egzIvedimas(std::vector<Studentas>& stud, int y, int f);
void ndIvedimas(std::vector<Studentas>& stud, int y, int f);
void generate( std::vector<Studentas>& stud, int &ilgVar, int &ilgPav );
void stringTikrinimas (std::ifstream &df, string a, bool &fail, int eil);
void nd(std::ifstream &df,std::vector<Studentas> &stud, int x, int y, bool &fail, int eil);
void egz(std::ifstream &df,std::vector<Studentas> &stud, int y, bool &fail, int eil);
int ndSk(std::ifstream &df);
void fileGenerate(int x);
void failoSkaitymas(std::vector<Studentas> &stud, int &ilgVar, int &ilgPav, int N);
void rikiavimas(std::vector<Studentas>& stud);
void rusiavimas(std::vector<Studentas>& stud);
void skirstymas(std::vector<Studentas>& stud, std::vector<Studentas>& vargsiukai, int x);
void skirstymas2(std::vector<Studentas>& stud, std::vector<Studentas>& vargsiukai, std::vector<Studentas>& galvociai, int x);
bool negavoSkolos(const Studentas& s);
std::vector<Studentas> vargsiukai(std::vector<Studentas>& stud);
void isvedimas( std::vector<Studentas> stud, std::vector<Studentas> vargsiukai, int ilgVar, int ilgPav);
void start_c(std::chrono::time_point<std::chrono::high_resolution_clock> &start);
void end_c(std::chrono::time_point<std::chrono::high_resolution_clock> &end);

#endif //UNTITLED_STUDENTAS_H
