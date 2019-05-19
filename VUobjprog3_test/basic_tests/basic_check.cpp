#include "../../code/headers/main_header.h"
#include "../../code/headers/studentas.h"
#include "../../code/headers/zmogus.h"
#include "../lib/googletest-release-1.8.1/googletest/include/gtest/gtest.h"

TEST(name_check, test_eq) {
    Studentas stud("Vardas", "Pavarde");

    EXPECT_EQ(stud.get_name(), "Vardas");
}

TEST(lastname_check, test_eq) {
    Studentas stud("Vardas", "Pavarde");

    EXPECT_EQ(stud.get_lastname(), "Pavarde");
}

TEST(ndSum_check, test_eq) {
    Studentas stud;
    stud.set_mark(9);
    stud.set_mark(8);
    stud.set_mark(10);
    stud.set_mark(9);
    stud.set_mark(10);

    EXPECT_EQ(stud.ndSum(5), 46);
}

TEST(exam_check, test_eq) {
    Studentas stud;
    stud.set_exam(10);

    EXPECT_EQ(stud.get_exam(), 10);
}