#include <iostream>

void ascii()
{
    std::string input;
    std::getline(std::cin, input);
    for(int i = 0; i < input.length(); i++)
    {
        char letter = input[i];
        std::cout << letter << " " << (int)letter << "\n"; 
    }
}

int main()
{
    ascii();
    return 0;
}