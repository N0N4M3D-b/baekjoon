#include <iostream>

bool CheckValid(std::string longLine, std::string shortLine, int longIndex)
{
    int shortIndex = 0;

    for (; longIndex < longLine.length(); longIndex++)
    {
        if (shortLine[shortIndex] == '2' && longLine[longIndex] == '2')
            return false;

        shortIndex++;
    }

    return true;
}

int GetMinValue(std::string line1, std::string line2)
{
    int minValue = 300;
    int tmp;
    bool check = false;

    for (int idx = 0; idx < line1.length(); idx++)
    {
        if (CheckValid(line1, line2, idx))
        {
            if ((line1.length() - idx) < line2.length())
            {
                tmp = line1.length() + (line2.length() - (line1.length() - idx));
                if (tmp < minValue)
                    minValue = tmp;
            }
            else
            {
                tmp = line1.length();
                if (tmp < minValue)
                    minValue = tmp;
            }

            check = true;
        }
    }

    if (!check)
        minValue = line1.length() + line2.length();

    return minValue;
}

int main()
{
    bool check = false;

    std::string line1;
    std::string line2;

    int tmpValue;

    std::cin >> line1 >> line2;

    int minValue = GetMinValue(line1, line2);
    tmpValue = GetMinValue(line2, line1);
    if (minValue > tmpValue)
        minValue = tmpValue;
    
    std::cout << minValue << std::endl;

    return 0;
}
