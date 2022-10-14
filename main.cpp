#include <iostream>
#include "caesar.h"
#include "decrypt.h"
#include "vigenere.h"

int main()
{
  std::cout << encryptCaesar("Dog and Cat", 5) << "\n";
  std::cout << encryptVigenere("Hello, World!", "cake") << "\n";
  std::cout << decryptCaesar("Rovvy, Gybvn!", 10) << "\n";
  std::cout << decryptVigenere("Jevpq, Wyvnd!", "cake") << "\n";
  return 0;
}
