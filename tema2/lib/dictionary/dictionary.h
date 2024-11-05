#include <stdint.h>
#include <avr/pgmspace.h>

// furat de la regele https://github.com/oreoezi si adaugat cateva replici
const char str0[] PROGMEM = "piticule cine esti ma"; 
const char str1[] PROGMEM = "zero munca"; 
const char str2[] PROGMEM = "alta gasca in alta traista"; 
const char str3[] PROGMEM = "switch switch router";  
const char str4[] PROGMEM = "domnu student";
const char str5[] PROGMEM = "ai lacune mari";
const char str6[] PROGMEM = "sterge tot";
const char str7[] PROGMEM = "pasul doi incomplet";
const char str8[] PROGMEM = "nu treci mai departe";
const char str9[] PROGMEM = "pentru ca da";
const char str10[] PROGMEM = "colegul meu";
const char str11[] PROGMEM = "nu ai fost la curs";
const char str12[] PROGMEM = "nu merge asa";
const char str13[] PROGMEM = "din aproape in aproape";
const char str14[] PROGMEM = "de la stanga la dreapta";
const char str15[] PROGMEM = "de la simplu la compus";
const char str16[] PROGMEM = "de la mic la mare";
const char str17[] PROGMEM = "cine nu are parola";
const char str18[] PROGMEM = "nu urmariti informatia";
const char str19[] PROGMEM = "se intoarce in zero";
const char str20[] PROGMEM = "armin van buuren";
const char str21[] PROGMEM = "layer zero nota zero";
const char str22[] PROGMEM = "inchideti monitoarele";
const char str23[] PROGMEM = "cand vreodata";
const char str24[] PROGMEM = "in momentul de fata";
const char str25[] PROGMEM = "reguli simple";
const char str26[] PROGMEM = "noi gandim in modele";
const char str27[] PROGMEM = "ia-o din zero";
const char str28[] PROGMEM = "rautare protocoale aipiuri";
const char str29[] PROGMEM = "lucruri marunte";
const char str30[] PROGMEM = "inchideti echipamentele";
const char str31[] PROGMEM = "nu salvati nimic";
const char str32[] PROGMEM = "resetati aplicatia";
const char str33[] PROGMEM = "echipament inseamna unitate + monitor";
const char str34[] PROGMEM = "ne vedem data viitoare la laborator";
const char str35[] PROGMEM = "ma suna managerul";
const char str36[] PROGMEM = "eu nu sunt aici";
const char str37[] PROGMEM = "nu exista help";
const char str38[] PROGMEM = "help-ul dauneaza grav notei finale";
const char str39[] PROGMEM = "va pierdeti atentia foarte usor";
const char str40[] PROGMEM = "cum spune rusu";
const char str41[] PROGMEM = "time is money";
const char str42[] PROGMEM = "ce inseamna RSA?";
const char str43[] PROGMEM = "restanta puisor";
const char str44[] PROGMEM = "astazi facem un pas mai departe";
const char str45[] PROGMEM = "un pas mare pentru voi";
const char str46[] PROGMEM = "un pas mic pentru omenire";
const char str47[] PROGMEM = "am un default gateway pentru tine";
const char str48[] PROGMEM = "defolt ghetoi";
const char str49[] PROGMEM = "nu sariti peste fire";
const char str50[] PROGMEM = "toate cele bune copii";
const char str51[] PROGMEM = "si voua copii";
const char str52[] PROGMEM = "ati folosit gipitiul";
const char str53[] PROGMEM = "tu stii ce inseamna USO";
const char str54[] PROGMEM = "ce o fi ala folder";
const char str55[] PROGMEM = "ce o fi aia partitie";
const char str56[] PROGMEM = "ti-am zis eu sa intri acolo";
const char str57[] PROGMEM = "te joci acasa";
const char str58[] PROGMEM = "am spus castraveti";
const char str59[] PROGMEM = "rong copilu";
const char str60[] PROGMEM = "ce cablu foloseste conexiunea wireless";
const char str61[] PROGMEM = "nu sariti peste fire";

const char *const dictionary[] PROGMEM = {
    str0, str1, str2, str3, str4, str5, str6, str7,
    str8, str9, str10, str11, str12, str13, str14, str15,
    str16, str17, str18, str19, str20, str21, str22, str23,
    str24, str25, str26, str27, str28, str29, str30, str31,
    str32, str33, str34, str35, str36, str37, str38, str39,
    str40, str41, str42, str43, str44, str45, str46, str47,
    str48, str49, str50, str51, str52, str53, str54, str55,
    str56, str57, str58, str59, str60, str61
};

const uint8_t dictionaryLen = sizeof(dictionary) / sizeof(dictionary[0]);
const char dif1[] PROGMEM = "Easy";
const char dif2[] PROGMEM = "Medium";
const char dif3[] PROGMEM = "Hard mode on!";

const char *const difficultyMessages[] PROGMEM = {dif1, dif2, dif3};