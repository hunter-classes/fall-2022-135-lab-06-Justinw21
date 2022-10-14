#include <iostream>
#include <cctype>
char shiftCharLeft(char c, int lshift)
{
    char result;
    if(int(c) <= 90)
    {
        if((int(c) - 65) - lshift < 0)
        {
            int increment = abs(((int(c) - 65) - lshift) % 26);
            int ascii = 91 - increment;
            result = char(ascii);
        }
        else
        {
            int ascii = (((int(c) - 65) - lshift) % 26) + 65; 
            result = (char)ascii;
        }
    }
    if(int(c) >= 97)
    {
        if((int(c) - 97) - lshift < 0)
        {
            int increment = abs(((int(c) - 97) - lshift) % 26);
            int ascii = 123 - increment;
            result = char(ascii);
        } 
        else
        {
            int ascii = (((int(c) - 97) - lshift) % 26) + 97; 
            result = (char)ascii;
        }
    }
    return result;
}

std::string decryptCaesar(std::string ciphertext, int rshift)
{
    std::string result = "";
    for(int i = 0; i < ciphertext.length(); i++)
    {
        char newChar;
        if(isalpha(ciphertext[i]))
        {
            newChar = shiftCharLeft(ciphertext[i], rshift);
            result += newChar;
        }
        else
        {
            newChar = ciphertext[i];
            result += newChar;
        }
    }
    return result;
}

std::string decryptVigenere(std::string ciphertext, std::string keyword)
{
    std::string result = "";
    int b = 0;
    for(int i = 0; i < ciphertext.length(); i++)
    {
        char newChar;
        int shift;
        char shiftChar;
        if(b % keyword.length() == 0)
        {
            b = 0;
        }
        shiftChar = keyword[b];
        shift = int(shiftChar) - 97;
        if(isalpha(ciphertext[i]))
        {
            newChar = shiftCharLeft(ciphertext[i], shift);
            result += newChar;
            b++;

        }
        else
        {
            newChar = ciphertext[i];
            result += newChar;
        }
    }
    return result;
}