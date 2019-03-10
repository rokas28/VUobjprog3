#include "headers/main_header.h"
#include "headers/struct_header.h"
#include "headers/list_header.h"
#include "headers/deque_header.h"

int main() {

    std::vector<studentas> stud;
    std::vector<studentas> vargsiukai;
    std::list<studentas> studl;
    std::list<studentas> vargsiukail;
    std::deque<studentas> studd;
    std::deque<studentas> vargsiukaid;

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;

    int ilgVar = 0;
    int ilgPav = 0;
    bool err = false;
    static const int N = 100000;

    start_c(start);
    fileGenerate(N);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time1 = end1-start;
    cout << "Failo generavimas uztruko " << time1.count() << "sec" << endl << endl;
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
    cout << "Vector rusiavimas uztruko " << time2.count() << "sec" << endl;
    auto start3 = std::chrono::high_resolution_clock::now();
    if(!err)isvedimas(stud,vargsiukai,ilgVar,ilgPav);
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time3 = end3-start3;
    cout << "Vector isvedimas uztruko " << time3.count() << "sec" << endl << endl;
    stud.resize(1);

    auto startl2 = std::chrono::high_resolution_clock::now();
    failoSkaitymas(studl,ilgVar,ilgPav);
    skirstymas(studl,vargsiukail);
    auto endl2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timel2 = endl2-startl2;
    cout << "List rusiavimas uztruko " << timel2.count() << "sec" << endl;
    auto startl3 = std::chrono::high_resolution_clock::now();
    if(!err)isvedimas(studl,vargsiukail,ilgVar,ilgPav);
    auto endl3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timel3 = endl3-startl3;
    cout << "List isvedimas uztruko " << timel3.count() << "sec" << endl << endl;
    studl.resize(1);

    auto startd2 = std::chrono::high_resolution_clock::now();
    failoSkaitymas(studd,ilgVar,ilgPav);
    skirstymas(studd,vargsiukaid,N);
    auto endd2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timed2 = endd2-startd2;
    cout << "Deque rusiavimas uztruko " << timed2.count() << "sec" << endl;
    auto startd3 = std::chrono::high_resolution_clock::now();
    if(!err)isvedimas(studd,vargsiukaid,ilgVar,ilgPav);
    auto endd3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timed3 = endd3-startd3;
    cout << "Deque isvedimas uztruko " << timed3.count() << "sec" << endl;
    studd.resize(1);

    return 0;
}