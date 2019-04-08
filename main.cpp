#include "headers/main_header.h"
#include "headers/studentas.h"

int main() {

    std::vector<Studentas> stud;
    std::vector<Studentas> vargsiukaii;

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;

    int ilgVar = 0;
    int ilgPav = 0;
    static const int N = 100;

    start_c(start);
    fileGenerate(N);
    end_c(end);
    std::chrono::duration<double> time1 = end-start;
    cout << "Failo generavimas uztruko " << time1.count() << "sec"  << endl;
    failoSkaitymas(stud,ilgVar,ilgPav,N);
    start_c(start);
    vargsiukaii = vargsiukai(stud);
    end_c(end);
    std::chrono::duration<double> time2 = end-start;
    cout << "Vector rusiavimas uztruko " << time2.count() << "sec" << endl;
    start_c(start);
    isvedimas(stud,vargsiukaii,ilgVar,ilgPav);
    end_c(end);
    std::chrono::duration<double> time3 = end-start;
    cout << "Vector isvedimas uztruko " << time3.count() << "sec" << endl;
    stud.resize(1);

    return 0;
}