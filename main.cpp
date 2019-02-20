#include "main_header.h"
#include "struct_header.h"

int main() {
    std::vector<studentas> stud;
    int ilgVar = 0;
    int ilgPav = 0;
    bool err = false;

    try {
        failoSkaitymas(stud,ilgVar,ilgPav);
    } catch (const char* error) {
        std::cerr << error << endl;
        if(error) err = true;
        generate(stud,ilgVar,ilgPav);
        isvedimas(stud,ilgVar,ilgPav);
    }
    if(!err)isvedimas(stud,ilgVar,ilgPav);

    return 0;
}