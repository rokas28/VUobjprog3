#include "../headers/studentas.h"

void Studentas::set_exam (int a){
    egzaminas = a;
}

void Studentas::set_mark(int a){
    nd.emplace_back(a);
}

double Studentas::ndSum(int x){
    double sum=0;
    for(int z = 0; z < x ; z++) {
        sum +=  nd[z];
    }
    return sum;
}

double Studentas::mediana(int x, int y){
    double med;
    sort(nd.begin(), nd.end());
    if (y % 2 == 0)
    {
        med =  (nd[x / 2 - 1] + nd[x / 2]) / 2.0;
    }
    else
    {
        med = nd[x / 2];
    }
    return med;
}

int ndSk(std::ifstream &df){
    size_t n=0;
    string str = "ND";
    string p_eil;
    getline(df,p_eil);
    string::size_type pos = 0;
    while((pos=p_eil.find(str,pos)) != string::npos){
        n++;
        pos+=str.size();
    }
    return n;
}

void fileGenerate(int x) {
    std::ofstream gf(data);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> random(1, 10);
    int a;
    int b;
    gf << std::left << std::setw(14) << "Vardas" << std::setw(15) << "Pavarde" <<  "ND1 ND2 ND3 ND4 ND5 ND6 Egzaminas" << endl;
    for (int i = 1; i <= x; i++) {
        gf <<  "Vardas" << std::setw(8) << i << "Pavarde" << std::setw(8) <<  i;
        for (int j = 0; j < 6; j++) {
            a = random(gen);
            gf << std::setw(4) << a ;
        }
        b = random(gen);
        gf << b << endl;
    }
    gf.close();
}

void failoSkaitymas(std::vector<Studentas> &stud, int &ilgVar, int &ilgPav, int N){
    std::ifstream df (data);
    if (!df) throw "Duomenu failas nerastas";
    stud.reserve(N);
    int i=0;
    int eil=0;
    int n = ndSk(df);
    stud.emplace_back(Studentas());
    string name, lastname;
    int exam;
    while(true) {
        if (df.eof() == 1) break;
        eil++;
        df >> name >> lastname;
        stud[i].set_name(name);
        stud[i].set_lastname(lastname);
        if (stud[i].get_name().length() > ilgVar) ilgVar = stud[i].get_name().length();
        if (stud[i].get_lastname().length() > ilgPav) ilgPav = stud[i].get_lastname().length();
        int q;
        int sum=0;
        for(int u=0;u<6;u++){
            df >> q;
            stud[i].set_mark(q);
            sum = sum + q;
        }
        df >> exam;
        stud[i].set_exam(exam);
        stud[i].vidGalutinis =  0.4 * sum/n + 0.6 * stud[i].get_exam();
        if (df.eof() == 1) break;
        i++;
        stud.emplace_back(Studentas());
    }

    df.seekg(0);
    df.clear();
    stud.shrink_to_fit();
}

void rusiavimas(std::vector<Studentas>& stud) {
    sort(stud.begin(), stud.end(), [](const Studentas &lhs, const Studentas &rhs) {
        return (lhs.vidGalutinis > rhs.vidGalutinis);
    });
}


bool negavoSkolos(const Studentas& s){
    return s.vidGalutinis > 5;
}

std::vector<Studentas> vargsiukai(std::vector<Studentas>& stud) {
    std::vector<Studentas>::iterator it =
            stable_partition(stud.begin(), stud.end(), negavoSkolos);
    std::vector<Studentas> minksti(it, stud.end());
    stud.erase(it, stud.end());
    return minksti;
}

void isvedimas( std::vector<Studentas> stud, std::vector<Studentas> vargsiukai, int ilgVar, int ilgPav){
    rusiavimas(stud);
    rusiavimas(vargsiukai);
    std::ofstream gs ("galvociai.txt");
    std::ofstream bs ("vargsiukai.txt");

    gs << std::left << std::setw(ilgVar + 3) << "vardas";
    gs << std::setw(ilgPav + 3) << "Pavarde" << std::setw(10) << "Galutiis(vid.)   "  << endl;
    for(int w=0;w<(ilgVar+ilgPav+6+14);w++) gs << "-";gs <<endl;
    for (auto &i : stud) {
        gs << std::left <<  std::setw(ilgVar+3) << i.get_name() << std::setw(ilgPav+3) << i.get_lastname();
        gs << std::setw(17) << std::fixed << std::setprecision(2) << i.vidGalutinis << endl;
    }
    gs.close();
    bs << std::left << std::setw(ilgVar + 3) << "vardas";
    bs << std::setw(ilgPav + 3) << "Pavarde" << std::setw(10) << "Galutiis(vid.)   " << endl;
    for(int w=0;w<(ilgVar+ilgPav+6+14);w++) bs << "-";bs <<endl;
    for (auto &i : vargsiukai) {
        bs << std::left <<  std::setw(ilgVar+3) << i.get_name() << std::setw(ilgPav+3) << i.get_lastname();
        bs << std::setw(17) << std::fixed << std::setprecision(2) << i.vidGalutinis << endl;
    }
    bs.close();
}

void start_c(std::chrono::time_point<std::chrono::high_resolution_clock> &start) {
    start = std::chrono::high_resolution_clock::now();
}

void end_c(std::chrono::time_point<std::chrono::high_resolution_clock> &end) {
    end = std::chrono::high_resolution_clock::now();
}