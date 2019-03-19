# VU objektinio programavimo antra užduotis

Užduoties reikalavimus galite pamatyti [čia](https://github.com/objprog/paskaitos2019/wiki/2-oji-u%C5%BEduotis).
## [V0.1](https://github.com/rokas28/VUobjprog2/releases/tag/v0.1) (2019-02-17)
### Pridėta:
- Pirminė programos verisja.
-	`CMakeLists.txt` - Programos paleidimo failas.
- `main.cpp` failas. Kodas parašytas naudojantis vektoriais.
- `main_arr.cpp` failas. Kodas parašytas naudojantis dinaminiu masyvu.
- `.gitignore` failas.
- `README.md` failas.
- Galimybė įvesti studentų duomenis ranka, arba juos generuoti atsitiktine tvarka.

Šioje versijoje yra nemažai bug'ų, kurie bus sutvarkyti kitose versijose.

## [V0.2](https://github.com/rokas28/VUobjprog2/releases/tag/v0.2) (2019-02-20)

### Pridėta:
- `./build/students.txt` failas, tekstiniem studentų įvesties duomenim.
- Galiybė nuskaityti duomenis iš pateikto duomenų failo.
- Sutvarkytas studentų duomenų išvedimo rūšiavimas ir lygiavimas.

### Koreguota:
- main.cpp failas.
- Sutvarkyti v0.1 versijos bug'ai vedant neteisingus duomenis ranka.

## [v0.3](https://github.com/rokas28/VUobjprog2/releases/tag/v0.3) (2019-02-23)

### Pridėta:
- main.cpp pridėtas `try catch` blokas, tikrinantis ar yra aptinkamas duomenų failas. Jei jo nėra, duomenys tuomet įvedinėjami ranka.

### Koreguota:
- main.cpp failas suskaidomas į: `main.cpp`,`main_header.h`,`struct_header.h`,`functions.cpp`.

## [v0.4](https://github.com/rokas28/VUobjprog2/releases/tag/v0.4) (2019-03-03)

### Pridėta:
- Studentų atsitiktinis generavimas į duomenų failą.
- Studentų rušiavimas į skirtingas kategorijas (skirstoma pagal galtuinį balą skaičiuojamą su pažymių vidurkiais).
- `./build/galvociai.txt` - studentai kurių balas yra 5 ir daugiau.
- `./build/vargsiukai.txt` - studentai kurių balas yra iki 5.
- Programos spartos matavimas naudojant `std::chrono`.

### Koreguota:
- functions.cpp failas. 

Programos veikimo sparta yra labai lėta, dėl tam tikrų klaidų kodo parašyme.

### [v0.4.1](https://github.com/rokas28/VUobjprog2/releases/tag/v0.4.1) (2019-03-04)

### Koreguota:
- Sutvarkya programos veikimo sparta ir optimizuotas jos veikimo laikas.

**Programos veikimo greičio (spartos) analizė**  

Kiekvienas studentas turi po 6 namų darbus.  
10 studentų:
```
Generavimas užtruko 0.0401591sec  
Skaitymas ir rušiavimas užtruko 0.0900437sec  
Išvedimas užtruko 0.175006sec  
```
100 studentų:  
```
Generavimas užtruko 0.0551987sec  
Skaitymas ir rušiavimas užtruko 0.00936983sec  
Išvedimas užtruko 0.0198203sec.  
```
1000 studentų:  
```
Generavimas užtruko 0.199804sec  
Skaitymas ir rušiavimas užtruko 0.07426sec  
Išvedimas užtruko 0.0388713sec  
```
10000 studentų:  
```
Generavimas užtruko 0.833397sec  
Skaitymas ir rušiavimas užtruko 1.05593sec  
Išvedimas užtruko 0.410506sec  
```
100000 studentų:  
```
Generavimas užtruko 6.51713sec  
Skaitymas ir rušiavimas užtruko 10.1496sec  
Išvedimas užtruko 3.3808sec  
```
1000000 studentų:  
```
Generavimas užtruko 66.9845sec  
Skaitymas ir rušiavimas užtruko 109.726sec  
Išvedimas užtruko 33.6921sec  
```
## [v0.5](https://github.com/rokas28/VUobjprog2/releases/tag/v0.5) (2019-03-10)

### Pridėta:
- `./functions/deque_functions.cpp` - funkcijos skirtos deque tipui.  
- `./functions/list_functions.cpp` - funkcijos skirtos list tipui.

### Koreguota:
- Iš`./functions/functions.cpp` perkeltos į `./functions/iostream_input_functions.cpp` funkcijos, skirtos įvesdinėti studentų duomenis ranka į ekraną.

Yra skaičiuojamas programos laikas, naudojant skirtingus duomenų konteinerius.

**Konteinerių testavimas:**

100 stdentų:  
```
Vector skaitymas ir rušiavimas užtruko 0.0172545sec
Vector išvedimas užtruko 0.0180264sec

List skaitymas ir rušiavimas užtruko 0.00458568sec
List išvedimas užtruko 0.2569425sec

Deque skaitymas ir rušiavimas užtruko 0.00625848sec
Deque išvedimas užtruko 0.0064563sec
```
1000 stdentų:  
```
Vector skaitymas ir rušiavimas užtruko 0.0601525sec
Vector išvedimas užtruko 0.0356498sec

List skaitymas ir rušiavimas užtruko 0.0676589sec
List išvedimas užtruko 0.0513542ec

Deque skaitymas ir rušiavimas užtruko 0.07856954sec
Deque išvedimas užtruko 0.0286541sec
```
10000 stdentų:  
```
Vector skaitymas ir rušiavimas užtruko 0.868945sec
Vector išvedimas užtruko 0.3862145sec

List skaitymas ir rušiavimas užtruko 0.501058sec
List išvedimas užtruko 0.2254125sec

Deque skaitymas ir rušiavimas užtruko 0.575698sec
Deque išvedimas užtruko 0.207854sec
```
100000 stdentų:  
```
Vector skaitymas ir rušiavimas užtruko 5.23413sec
Vector išvedimas užtruko 1.65535sec

List skaitymas ir rušiavimas užtruko 4.918sec
List išvedimas užtruko 1.81334sec

Deque skaitymas ir rušiavimas užtruko 5.32219sec
Deque išvedimas užtruko 1.76306sec
```

## [v1.0](https://github.com/rokas28/VUobjprog2/releases/tag/v1.0) (2019-03-18)

### Pridėta:
-

### Koreguota:
- 
