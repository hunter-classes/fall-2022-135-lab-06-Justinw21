#include <iostream>
#include <cctype>
char shiftChar(char c, int rshift)
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

std::string encryptCaesar(std::string plaintext, int rshift)
{
    std::string result = "";
    for(int i = 0; i < plaintext.length(); i++)
    {
        char newChar;
        if(isalpha(plaintext[i]))
        {
            newChar = shiftChar(plaintext[i], rshift);
            result += newChar;
        }
        else
        {
            newChar = plaintext[i];
            result += newChar;
        }
    }
    return result;
}