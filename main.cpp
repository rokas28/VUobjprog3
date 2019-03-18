#include "headers/main_header.h"
#include "headers/struct_header.h"
#include "headers/list_header.h"
#include "headers/deque_header.h"

int main() {

    std::vector<studentas> stud;
    std::vector<studentas> vargsiukai;
    std::vector<studentas> galvociai;
    std::list<studentas> studl;
    std::list<studentas> vargsiukail;
    std::list<studentas> galvociail;
    std::deque<studentas> studd;
    std::deque<studentas> vargsiukaid;
    std::deque<studentas> galvociaid;

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;

    int ilgVar = 0;
    int ilgPav = 0;
    static const int N = 100;

    start_c(start);
    fileGenerate(N);
    end_c(end);
    std::chrono::duration<double> time1 = end-start;
    cout << "Failo generavimas uztruko " << time1.count() << "sec" << endl << endl;
    start_c(start);
    failoSkaitymas(stud,ilgVar,ilgPav,N);
    skirstymas(stud,vargsiukai,N);
    end_c(end);
    std::chrono::duration<double> time2 = end-start;
    cout << "Vector skaitymas ir rusiavimas uztruko(2 strategija) " << time2.count() << "sec" << endl;
    start_c(start);
    isvedimas(stud,vargsiukai,ilgVar,ilgPav);
    end_c(end);
    std::chrono::duration<double> time3 = end-start;
    cout << "Vector isvedimas uztruko(2 strategija) " << time3.count() << "sec" << endl << endl;
    stud.resize(1);
    vargsiukai.resize(1);

    start_c(start);
    failoSkaitymas(studl,ilgVar,ilgPav);
    skirstymas(studl,vargsiukail);
    end_c(end);
    std::chrono::duration<double> timel2 = end-start;
    cout << "List skaitymas ir rusiavimas uztruko(2 strategija) " << timel2.count() << "sec" << endl;
    start_c(start);
    isvedimas(studl,vargsiukail,ilgVar,ilgPav);
    end_c(end);
    std::chrono::duration<double> timel3 = end-start;
    cout << "List isvedimas uztruko(2 strategija) " << timel3.count() << "sec" << endl << endl;
    studl.resize(1);
    vargsiukail.resize(1);

    start_c(start);
    failoSkaitymas(studd,ilgVar,ilgPav);
    skirstymas(studd,vargsiukaid,N);
    end_c(end);
    std::chrono::duration<double> timed2 = end-start;
    cout << "Deque skaitymas ir rusiavimas uztruko(2 strategija) " << timed2.count() << "sec" << endl;
    start_c(start);
    isvedimas(studd,vargsiukaid,ilgVar,ilgPav);
    end_c(end);
    std::chrono::duration<double> timed3 = end-start;
    cout << "Deque isvedimas uztruko(2 strategija) " << timed3.count() << "sec" << endl << endl;
    studd.resize(1);
    vargsiukaid.resize(1);

    start_c(start);
    failoSkaitymas(stud,ilgVar,ilgPav,N);
    skirstymas2(stud,vargsiukai,galvociai,N);
    end_c(end);
    std::chrono::duration<double> time22 = end-start;
    cout << "Vector skaitymas ir rusiavimas uztruko(1 strategija) " << time22.count() << "sec" << endl;
    start_c(start);
    isvedimas(galvociai,vargsiukai,ilgVar,ilgPav);
    end_c(end);
    std::chrono::duration<double> time33 = end-start;
    cout << "Vector isvedimas uztruko(1 strategija) " << time33.count() << "sec" << endl << endl;
    stud.resize(1);

    start_c(start);
    failoSkaitymas(studl,ilgVar,ilgPav);
    skirstymas2(studl,vargsiukail,galvociail);
    end_c(end);
    std::chrono::duration<double> timel22 = end-start;
    cout << "List skaitymas ir rusiavimas uztruko(1 strategija) " << timel22.count() << "sec" << endl;
    start_c(start);
    isvedimas(galvociail,vargsiukail,ilgVar,ilgPav);
    end_c(end);
    std::chrono::duration<double> timel33 = end-start;
    cout << "List isvedimas uztruko " << timel33.count() << "sec" << endl << endl;
    studl.resize(1);

    start_c(start);
    failoSkaitymas(studd,ilgVar,ilgPav);
    skirstymas2(studd,vargsiukaid,galvociaid,N);
    end_c(end);
    std::chrono::duration<double> timed22 = end-start;
    cout << "Deque skaitymas ir rusiavimas uztruko(1 strategija) " << timed22.count() << "sec" << endl;
    start_c(start);
    isvedimas(galvociaid,vargsiukaid,ilgVar,ilgPav);
    end_c(end);
    std::chrono::duration<double> timed33 = end-start;
    cout << "Deque isvedimas uztruko(1 strategija) " << timed33.count() << "sec" << endl;
    studd.resize(1);

    return 0;
}