#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<char> charToString(std::string input)
{
    std::vector<char> result(input.length());
    std::copy(input.begin(), input.end(), result.begin());
    return result;
}

int findBadge(std::vector<char> backPackOne, std::vector<char> backpackTwo, std::vector<char> backpackThree)
{

    int score = 0;
    for (int i = 65; i <= 90; i++)
    {
        if (std::find(backPackOne.begin(), backPackOne.end(), i) != backPackOne.end())
        {
            if (std::find(backpackTwo.begin(), backpackTwo.end(), i) != backpackTwo.end())
            {
                if (std::find(backpackThree.begin(), backpackThree.end(), i) != backpackThree.end())
                {
                    score += (i - 38);
                    return score;
                }
            }
        }
    }
    for (int i = 97; i <= 122; i++)
    {
        if (std::find(backPackOne.begin(), backPackOne.end(), i) != backPackOne.end())
        {
            if (std::find(backpackTwo.begin(), backpackTwo.end(), i) != backpackTwo.end())
            {
                if (std::find(backpackThree.begin(), backpackThree.end(), i) != backpackThree.end())
                {
                    score += (i - 96);
                    return score;
                }
            }
        }
    }
}

int main()
{
    std::fstream inputFile;
    std::string backpackInput;

    std::vector<char> elfOne;
    std::vector<char> elfTwo;
    std::vector<char> elfThree;

    int sum = 0;

    inputFile.open("input.txt");
    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            std::getline(inputFile, backpackInput);
            elfOne = charToString(backpackInput);
            std::getline(inputFile, backpackInput);
            elfTwo = charToString(backpackInput);
            std::getline(inputFile, backpackInput);
            elfThree = charToString(backpackInput);
            sum += findBadge(elfOne, elfTwo, elfThree);
        }
    }
    inputFile.close();
    std::cout << "The total is " << sum << "\n";
}
