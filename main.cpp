#include "main_header.h"
#include "struct_header.h"

int main() {
    std::vector<studentas> stud;
    std::vector<studentas> vargsiukai;

    int ilgVar = 0;
    int ilgPav = 0;
    bool err = false;
    static const int N = 1000;


    auto start1 = std::chrono::high_resolution_clock::now();
    fileGenerate(N);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time1 = end1-start1;
    cout << "Generavimas uztruko " << time1.count() << "sec" << endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    try {
        failoSkaitymas(stud,ilgVar,ilgPav,N);
    } catch (const char* error) {
        std::cerr << error << endl;
        if(error) err = true;
        generate(stud,ilgVar,ilgPav);
        skirstymas(stud,vargsiukai,N);
        isvedimas(stud,vargsiukai,ilgVar,ilgPav);
    }
    skirstymas(stud,vargsiukai,N);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time2 = end2-start2;
    cout << "Rusiavimas uztruko " << time2.count() << "sec" << endl;
    auto start3 = std::chrono::high_resolution_clock::now();
    if(!err)isvedimas(stud,vargsiukai,ilgVar,ilgPav);
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time3 = end3-start3;
    cout << "Isvedimas uztruko " << time3.count() << "sec" << endl;
    return 0;
}