#ifndef UNTITLED_STUDENTAS_H
#define UNTITLED_STUDENTAS_H

#include "main_header.h"

class Studentas {
private:
    string vardas, pavarde;
    int egzaminas;
    double vidGalutinis;
    std::vector<int > nd;
public:
    Studentas() : vardas(" "), pavarde(" "), egzaminas(0), vidGalutinis(0){ };
    void set_vidGalutinis (double &a) { vidGalutinis = a; };
    double get_vidGalutinis() const { return vidGalutinis; };
    double medGalutinis = 0;
    void set_name(string &a){ vardas = a; };
    void set_lastname (string &a) {pavarde = a; };
    string get_name() const {return vardas; };
    string get_lastname() const {return pavarde; };
    void set_exam (int a);
    int get_exam() {return egzaminas; };
    void set_mark(int a);
    double ndSum(int x);
    double mediana(int x, int y);
    friend bool operator== (const Studentas &a, const Studentas &b) { return a.get_vidGalutinis() == b.get_vidGalutinis(); };
    friend bool operator!= (const Studentas &a, const Studentas &b) { return a.get_vidGalutinis() != b.get_vidGalutinis(); };
    friend std::ostream& operator << (std::ostream &out, const Studentas a) {
        out << std::left <<  std::setw(13+3) << a.get_name() << std::setw(14+3) << a.get_lastname();
        out << std::setw(17) << std::fixed << std::setprecision(2) << a.get_vidGalutinis() << endl;
        return out;
    };
    friend std::istream &operator >> (std::istream & in, Studentas & a) {
        cout << " Iveskite varda ";
        in >> a.vardas;
        cout << endl << "Iveskite pavarde ";
        in >> a.pavarde;
        cout << endl << "Iveskite namu darbu skaiciu ";
        int n;
        in >> n;
        int q;
        int sum = 0;
        for(int u=0;u<n;u++){
            cout << "Iveskite namu darbu pazymi " << endl;
            in >> q;
            if(!in.fail() && q >= 0 && q <= 10){
                if(q!=0) {
                    a.set_mark(q);
                    sum = sum + q;
                }
            }
            else {
                cout << "Netinkamas pazymys, iveskite kita" << endl;
                in.clear();
                in.ignore(256, '\n');
                u--;
                continue;

            }
        }
        while(true){
            int eg = 0;
            cout << "Iveskite egzamino rezultata" << endl;
            in >> eg;
            if( !in.fail() && eg>= 0 && eg <= 10){
                if(eg!=0) {
                    a.egzaminas = eg;
                    break;
                }
            }
            else {
                cout << "Netinkamas pazymys, iveskite kita" << endl;
                in.clear();
                in.ignore(256, '\n');
                continue;
            }
        }
        cout << endl;
        double galutinis;
        galutinis =  0.4 * sum/n + 0.6 * a.get_exam();
        a.set_vidGalutinis(galutinis);
        return in;
    };
    friend bool operator > (const Studentas &a, const Studentas &b) { return a.get_vidGalutinis() > b.get_vidGalutinis(); };
    friend bool operator < (const Studentas &a, const Studentas &b) { return a.get_vidGalutinis() < b.get_vidGalutinis(); };
};

int ndSk(std::ifstream &df);
void fileGenerate(int x);
void failoSkaitymas(std::vector<Studentas> &stud, int &ilgVar, int &ilgPav, int N);
void rusiavimas(std::vector<Studentas>& stud);
bool negavoSkolos(const Studentas& s);
std::vector<Studentas> vargsiukai(std::vector<Studentas>& stud);
void isvedimas( std::vector<Studentas> stud, std::vector<Studentas> vargsiukai, int ilgVar, int ilgPav);
void start_c(std::chrono::time_point<std::chrono::high_resolution_clock> &start);
void end_c(std::chrono::time_point<std::chrono::high_resolution_clock> &end);

#endif //UNTITLED_STUDENTAS_H
