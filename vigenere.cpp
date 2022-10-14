#include <iostream>
#include <cctype>
char shiftCharacter(char c, int rshift)
{
    if(int(c) <= 90){
        int ascii = (((int(c) - 65) + rshift) % 26) + 65; 
        char result = (char)ascii;
        return result;
    }
    else
    {
       int ascii = (((int(c) - 97) + rshift) % 26) + 97; 
        char result = (char)ascii;
        return result; 
    }
}

std::string encryptVigenere(std::string plaintext, std::string keyword)
{
    std::string result = "";
    int b = 0;
    for(int i = 0; i < plaintext.length(); i++)
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
        if(isalpha(plaintext[i]))
        {
            newChar = shiftCharacter(plaintext[i], shift);
            result += newChar;
            b++;

        }
        else
        {
            newChar = plaintext[i];
            result += newChar;
        }
    }
    return result;
}
