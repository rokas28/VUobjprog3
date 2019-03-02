#include "main_header.h"
#include "struct_header.h"

int main() {
    std::vector<studentas> stud;
    std::vector<studentas> vargsiukai;

    int ilgVar = 0;
    int ilgPav = 0;
    bool err = false;
    static const int N = 1000;


    auto start = std::chrono::high_resolution_clock::now();
    fileGenerate(N);
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
    if(!err)isvedimas(stud,vargsiukai,ilgVar,ilgPav);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = end-start;
    cout << "Programa uztruko " << time.count() << "sec" << endl;
    return 0;
}