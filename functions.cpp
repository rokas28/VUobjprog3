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
    };

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

    void stringTikrinimas (std::ifstream &df, string a, bool &fail, int eil){
        if(!netinkamasPav(std::move(a))) {
            df.clear();
            df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            fail = true;
            cout << "Ivestas netinkamas vardas arba pavarde " << eil << " eiluteje. Del to studento duomenys nebuvo nuskaityti. " << endl;
        }
    }

    void nd(std::ifstream &df,std::vector<studentas> &stud, int x, int y, bool &fail, int eil){
        int q=0;
        for(int j = 0; j < x; j++){
            df >> q;
            if(!df.fail() && q > 0 && q <= 10){
                stud[y].nd.emplace_back(q);
            }
            else {
                df.clear();
                df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                fail = true;
                cout << "Ivestas netinkamas namu darbu pazymys " << eil << " eiluteje. Del to studento duomenys nebuvo nuskaityti." << endl;
                break;
            }
        }
    }

    void egz(std::ifstream &df,std::vector<studentas> &stud, int y, bool &fail, int eil){
        int q=0;
        df >> q;
        if(!df.fail() && q > 0 && q <= 10){
            stud[y].egzaminas = q;
        }
        else {
            df.clear();
            df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            fail = true;
            cout << "Ivestas netinkamas egzamino pazymys " << eil << " eiluteje. Del to studento duomenys nebuvo nuskaityti." << endl;
        }

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

    void failoSkaitymas(std::vector<studentas> &stud, int &ilgVar, int &ilgPav, int N){
        std::ifstream df (data);
        if (!df) throw "Duomenu failas nerastas";
        stud.reserve(N);
        int i=0;
        int eil=0;
        int n = ndSk(df);
        stud.emplace_back(studentas());
        while(true) {

            if (df.eof() == 1) break;
            eil++;
            df >> stud[i].vardas >> stud[i].pavarde;
            if (stud[i].vardas.length() > ilgVar) ilgVar = stud[i].vardas.length();
            if (stud[i].pavarde.length() > ilgPav) ilgPav = stud[i].pavarde.length();
            int q;
            int sum=0;
            for(int u=0;u<6;u++){
                df >> q;
                stud[i].nd.emplace_back(q);
                sum = sum + q;
            }
            df >> stud[i].egzaminas;
            stud[i].vidGalutinis =  0.4 * sum/n + 0.6 * stud[i].egzaminas;
            if (df.eof() == 1) break;
            i++;
            stud.emplace_back(studentas());
        }

        df.seekg(0);
        df.clear();
        stud.shrink_to_fit();
    };

/*void rikiavimas(std::vector<studentas>& stud) {
    sort(stud.begin(), stud.end(), [](const studentas &lhs, const studentas &rhs) {
        if (lhs.vardas != rhs.vardas) {
            return lhs.vardas < rhs.vardas;
        } else {
            return lhs.pavarde < rhs.pavarde;
        }
    });
};*/

    void rusiavimas(std::vector<studentas>& stud) {
        sort(stud.begin(), stud.end(), [](const studentas &lhs, const studentas &rhs) {
            return ( lhs.vidGalutinis > rhs.vidGalutinis );
        });
    };

    void skirstymas(std::vector<studentas>& stud, std::vector<studentas>& vargsiukai, int x){
        rusiavimas(stud);
        int i = x;
        int k =0;
        while(stud[i].vidGalutinis < 5){
            k++;
            i--;
        }
        std::move(stud.end()-k, stud.end(),std::back_inserter(vargsiukai));
        stud.erase (stud.end()-k, stud.end());
    }

    void isvedimas( std::vector<studentas> stud, std::vector<studentas> vargsiukai, int ilgVar, int ilgPav){
        //rikiavimas(stud);
        std::ofstream gs ("galvociai.txt");
        std::ofstream bs ("vargsiukai.txt");

        gs << std::left << std::setw(ilgVar + 3) << "vardas";
        gs << std::setw(ilgPav + 3) << "Pavarde" << std::setw(10) << "Galutiis(vid.)   "  << endl;
        for(int w=0;w<(ilgVar+ilgPav+6+14);w++) gs << "-";gs <<endl;
        for (auto &i : stud) {
            gs << std::left <<  std::setw(ilgVar+3) << i.vardas << std::setw(ilgPav+3) << i.pavarde;
            gs << std::setw(17) << std::fixed << std::setprecision(2) << i.vidGalutinis << endl;
        }
        gs.close();
        bs << std::left << std::setw(ilgVar + 3) << "vardas";
        bs << std::setw(ilgPav + 3) << "Pavarde" << std::setw(10) << "Galutiis(vid.)   " << endl;
        for(int w=0;w<(ilgVar+ilgPav+6+14);w++) bs << "-";bs <<endl;
        for (auto &i : vargsiukai) {
            bs << std::left <<  std::setw(ilgVar+3) << i.vardas << std::setw(ilgPav+3) << i.pavarde;
            bs << std::setw(17) << std::fixed << std::setprecision(2) << i.vidGalutinis << endl;
        }
    bs.close();
};