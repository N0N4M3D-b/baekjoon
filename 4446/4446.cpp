#include <iostream>
#include <string>
#include <cctype>

int GetIndex(const std::string type, int index)
{
    if (type.size() == 20)
    {
        index += 10;
        index %= 20;
    }
    else
    {
        index += 3;
        index %= 6;
    }

    return index;
}

int main()
{
    const std::string consonant = "bkxznhdcwgpvjqtsrlmf";
    const std::string vowel = "aiyeou";
    int charIndex;

    std::string inputString;

    while (std::getline(std::cin, inputString))
    {
        for (char c : inputString)
        {
            if (c >= 97 && c <= 122)
            {
                if (consonant.find(c) != std::string::npos)
                {
                    charIndex = GetIndex(consonant, consonant.find(c));
                    std::cout << consonant[charIndex];
                }
                else
                {
                    charIndex = GetIndex(vowel, vowel.find(c));
                    std::cout << vowel[charIndex];
                }
            }
            else if (c >= 65 && c <= 90)
            {
                c = tolower(c);
                
                if (consonant.find(c) != std::string::npos)
                {
                    charIndex = GetIndex(consonant, consonant.find(c));
                    std::cout << char(toupper(consonant[charIndex]));
                }
                else
                {
                    charIndex = GetIndex(vowel, vowel.find(c));
                    std::cout << char(toupper(vowel[charIndex]));
                }
            }
            else if (c >= 32 && c <=126)
            {
                std::cout << c;
            }
            else
            {
                std::cout << "ERROR" << std::endl;

                return 1;
            }
        }

        std::cout << std::endl;
    }

    return 0;
}
