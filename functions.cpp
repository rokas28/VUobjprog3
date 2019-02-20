//
// Created by HP on 2019-02-20.
//

#include "main_header.h"
#include "struct_header.h"

double mediana(std::vector<studentas> stud, int x, int y){
    double med;
    sort(stud[y].nd.begin(), stud[y].nd.end());
    if (y % 2 == 0)
    {
        med =  (stud[y].nd[x / 2 - 1] + stud[y].nd[x / 2]) / 2.0;
    }
    else
    {
        med = stud[y].nd[x / 2];
    }
    return med;
}

bool netinkamasPav(const string a){
    for (char i : a) {
        if (!(( i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))) return false;
    }
    return true;
}

void ndGen(std::vector<studentas>& stud, int x, int y){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> random(1, 10);
    int a;
    for(int j = 0; j < x; j++){
        a=random(gen);
        stud[y].nd.push_back(a);
    }
}

void egGen(std::vector<studentas>& stud, int y){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> random(1, 10);
    stud[y].egzaminas = random(gen);
}

double ndSum(std::vector<studentas> stud, int x, int y){
    double sum=0;
    for(int z = 0; z < x ; z++) {
        sum +=  stud[y].nd[z];
    }
    return sum;
}

void galutinis(std::vector<studentas>& stud, int x, int y){
    stud[y].vidGalutinis =  0.4 * ndSum(stud,x,y)/x + 0.6 * stud[y].egzaminas;
    stud[y].medGalutinis =  0.4 * mediana(stud,x,y) + 0.6 * stud[y].egzaminas;
}

void varTikrinimas(std::vector<studentas>& stud, int y){
    cout << "Iveskite studento varda " << endl;
    cin >> stud[y].vardas;
    while(!netinkamasPav(stud[y].vardas)) {
        cout << "Netinkamas vardas, iveskite kita ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> stud[y].vardas;
    }
}

void pavTikrinimas(std::vector<studentas>& stud, int y){
    cout << "Iveskite studento pavarde" << endl;
    cin >> stud[y].pavarde;
    while(!netinkamasPav(stud[y].pavarde)) {
        cout << "Netinkama pavarde, iveskite kita ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> stud[y].pavarde;
    }
}

void fTikrinimas(int &f){
    while (f!=0 && f!=1){
        cout << "Ivestas neteisingas simbolis, pasirinkite dar karta " << endl;
        cin >> f;
    }
}

void egzIvedimas(std::vector<studentas>& stud, int y, int f){
    if (f==1){
        while(true){
            int eg = 0;
            cout << "Iveskite egzamino rezultata" << endl;
            cin >> eg;
            if( !cin.fail() && eg>= 0 && eg <= 10){
                if(eg!=0) {
                    stud[y].egzaminas = eg;
                    break;
                }
            }
            else {
                cout << "Netinkamas pazymys, iveskite kita" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                continue;
            }
        }
    }
    else if(f==0){
        egGen(stud,y);
    }
}

void ndIvedimas(std::vector<studentas>& stud, int y, int f){
    int k=0;
    int q=1;
    if (f==1){
        cout << "Iveskite namu darbu rezultatus, kai visi namu darbu rezultataibus suvesti, spauskite 0" << endl;
        while(q!=0){
            cout << "Iveskite namu darbu pazymi " << endl;
            cin >> q;
            if(!cin.fail() && q >= 0 && q <= 10){
                if(q!=0) {
                    stud[y].nd.push_back(q);
                    k++;
                }
            }
            else {
                cout << "Netinkamas pazymys, iveskite kita" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                q=1;
                continue;

            }
        }

        galutinis(stud,k,y);
    }
    else if(f==0){
        cout << "Iveskite kiek namu darbu pazymiu norite sugeneruoti" << endl;
        int n;
        cin >> n;
        ndGen(stud,n,y);
        galutinis(stud,n,y);
    }
}

void generate( std::vector<studentas>& stud, int &ilgVar, int &ilgPav ){
    int i = 0;
    int st = 0;
    stud.reserve(1000);
    while(true){
        cout << "Jei norite prideti studenta spauskite 1" << endl;
        cin >> st;
        if (st==1){
            stud.emplace_back(studentas());
            int f;
            varTikrinimas(stud,i);
            pavTikrinimas(stud,i);
            if(stud[i].vardas.length()>ilgVar) ilgVar = stud[i].vardas.length();
            if(stud[i].pavarde.length()>ilgPav) ilgPav = stud[i].pavarde.length();
            cout << "Jei norite ivseti studento egzamino pazymi ranka, spauskite 1, jei norite ji atsitiktinai sugeneruoti, spauskite 0" << endl;
            cin >> f;
            fTikrinimas(f);
            egzIvedimas(stud,i,f);
            cout << "Jei norite ivseti studento namu darbu pazymius ranka, spauskite 1, jei norite juos atsitiktinai sugeneruoti, spauskite 0" << endl;
            cin >>f;
            fTikrinimas(f);
            ndIvedimas(stud,i,f);
            i++;
        }
        else break;
    }
    stud.shrink_to_fit();
}

void stringTikrinimas (std::ifstream &df, string a, bool &fail){
    if(!netinkamasPav(std::move(a))) {
        df.clear();
        df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        fail = true;
    }
}

void skTikrinimas(std::ifstream &df, bool &fail){
    if(df.fail()){
        df.clear();
        df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        fail = true;
    }
}

void nd(std::ifstream &df,std::vector<studentas> &stud, int x, int y, bool &fail){
    int q=0;
    for(int j = 0; j < x; j++){
        df >> q;
        if(!df.fail() && q > 0 && q <= 10){
            stud[y].nd.push_back(q);
        }
        else {
            df.clear();
            df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            fail = true;
            break;
        }
    }
}

void egz(std::ifstream &df,std::vector<studentas> &stud, int y, bool &fail){
    int q=0;
    df >> q;
    if(!df.fail() && q > 0 && q <= 10){
        stud[y].egzaminas = q;
    }
    else {
        df.clear();
        df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        fail = true;
    }
}

void failoSkaitymas(std::vector<studentas> &stud, int &ilgVar, int &ilgPav){
    std::ifstream df (data);
    if (!df) throw "Duomenu failas nerastas";
    stud.reserve(1000);
    int i=0;
    int sk=0;
    stud.emplace_back(studentas());
    while(true){
        bool fail = false;
        if(df.eof()==1) break;

        df >> stud[i].vardas;
        stringTikrinimas(df, stud[i].vardas,fail);
        if(fail)continue;

        df >> stud[i].pavarde;
        stringTikrinimas(df, stud[i].pavarde,fail);
        if(fail)continue;

        df >> sk;
        skTikrinimas(df,fail);
        if(fail)continue;

        if(stud[i].vardas.length()>ilgVar) ilgVar = stud[i].vardas.length();
        if(stud[i].pavarde.length()>ilgPav) ilgPav = stud[i].pavarde.length();

        nd(df,stud,sk,i,fail);
        if(fail)continue;

        egz(df,stud,i,fail);
        if(fail)continue;

        galutinis(stud,sk,i);
        i++;
        if(df.eof()==1) break;
        stud.emplace_back(studentas());
    }
    stud.shrink_to_fit();
}

void rikiavimas(std::vector<studentas>& stud) {
    sort(stud.begin(), stud.end(), [](const studentas &lhs, const studentas &rhs) {
        if (lhs.vardas != rhs.vardas) {
            return lhs.vardas < rhs.vardas;
        } else {
            return lhs.pavarde < rhs.pavarde;
        }
    });
}

void isvedimas( std::vector<studentas> stud, int ilgVar, int ilgPav){
    rikiavimas(stud);
    cout << std::left << std::setw(ilgVar + 3) << "vardas";
    cout << std::setw(ilgPav + 3) << "Pavarde" << std::setw(10) << "Galutiis(vid.)   " << std::setw(10) << "Galutiis(med.)" << endl;
    for(int w=0;w<(ilgVar+ilgPav+6+31);w++) cout << "-";cout <<endl;
    for (auto &i : stud) {
        cout << std::left <<  std::setw(ilgVar+3) << i.vardas << std::setw(ilgPav+3) << i.pavarde
             << std::setw(17) << std::fixed << std::setprecision(2) << i.vidGalutinis
             << std::setw(10) << std::fixed << std::setprecision(2) << i.medGalutinis << endl;
    }
}