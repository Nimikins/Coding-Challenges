#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string splitElf(std::string input, std::string half)
{
    std::string result;
    if (half == "TOP")
    {
        result = input.substr(0, input.length() / 2);
    }
    else
    {
        result = input.substr(input.length() / 2);
    }
    return result;
}

std::vector<char> charToString(std::string input)
{
    std::vector<char> result(input.length());
    std::copy(input.begin(), input.end(), result.begin());
    return result;
}

int findDuplicate(std::vector<char> inputOne, std::vector<char> inputTwo)
{

    int score = 0;
    for (int i = 65; i <= 90; i++)
    {
        if (std::find(inputOne.begin(), inputOne.end(), i) != inputOne.end())
        {
            if (std::find(inputTwo.begin(), inputTwo.end(), i) != inputTwo.end())
            {
                score += (i - 38);
            }
        }
    }
    for (int i = 97; i <= 122; i++)
    {
        if (std::find(inputOne.begin(), inputOne.end(), i) != inputOne.end())
        {
            if (std::find(inputTwo.begin(), inputTwo.end(), i) != inputTwo.end())
            {
                score += (i - 96);
            }
        }
    }
    return score;
}

int main()
{
    std::fstream inputFile;
    std::string backpackInput;
    std::string partOne;
    std::string partTwo;

    std::vector<char> compartmentOne;
    std::vector<char> compartmentTwo;

    int sum = 0;

    inputFile.open("input.txt");
    if (inputFile.is_open())
    {
        while (std::getline(inputFile, backpackInput))
        {
            partOne = splitElf(backpackInput, "TOP");
            partTwo = splitElf(backpackInput, "BOTTOM");
            compartmentOne = charToString(partOne);
            compartmentTwo = charToString(partTwo);
            sum += findDuplicate(compartmentOne, compartmentTwo);
        }
    }
    inputFile.close();
    std::cout << "The total is " << sum << "\n";
}
