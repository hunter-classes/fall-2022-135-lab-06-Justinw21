#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

TEST_CASE("B"){
    CHECK(shiftChar('a',1) == 'b');
    CHECK(shiftChar('a', 5) == 'f');
    CHECK(shiftChar('d', 4) == 'h');

    CHECK(shiftChar('I', 1) == 'J');
    CHECK(shiftChar('A', 5) == 'F');
    CHECK(shiftChar('T', 4) == 'X');

    CHECK(encryptCaesar("This is it!", 5) == "Ymnx nx ny!");
    CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
    CHECK(encryptCaesar("The Teacher Walked Into The Classroom", 5) == "Ymj Yjfhmjw Bfqpji Nsyt Ymj Hqfxxwttr");
    CHECK(encryptCaesar("asioduoiauoruqwueqcjsojdioa*&^%", 10) == "kcsyneyskeybeageoamtcytnsyk*&^%");
}

TEST_CASE("C")
{
    CHECK(encryptVigenere("The Valorant Player Died of dehydration", "jsodieri") == "Czs Yipfzjfh Stepma Vwhl sw lnzmgzekqxf");
    CHECK(encryptVigenere("poasjfdoiaJOIGowehioIOJGOIJ", "ietoiuwet") == "xstgrzzsbiNHWOisiaqsBCRAKMC");
    CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
}

TEST_CASE("D")
{
    CHECK(shiftCharLeft('z',2) == 'x');
    CHECK(shiftCharLeft('A',1) == 'Z');
    CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
    CHECK(decryptCaesar("Ymj Yjfhmjw Bfqpji Nsyt Ymj Hqfxxwttr", 5) == "The Teacher Walked Into The Classroom");
    CHECK(decryptCaesar("kcsyneyskeybeageoamtcytnsyk*&^%", 10) == "asioduoiauoruqwueqcjsojdioa*&^%");
    CHECK(decryptVigenere("Czs Yipfzjfh Stepma Vwhl sw lnzmgzekqxf","jsodieri") == "The Valorant Player Died of dehydration");
    CHECK(decryptVigenere("xstgrzzsbiNHWOisiaqsBCRAKMC", "ietoiuwet") == "poasjfdoiaJOIGowehioIOJGOIJ");
    CHECK(decryptVigenere("Jevpq, Wyvnd!","cake") == "Hello, World!");
}