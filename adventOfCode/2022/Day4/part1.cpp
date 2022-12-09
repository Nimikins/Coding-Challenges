#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int findOverlapp(int lowA, int highA, int lowB, int highB)
{
    if (lowA <= lowB && highA >= highB || lowB <= lowA && highB >= highA)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int splitOverlapp(std::string input)
{

    std::string assignmentOne = input.substr(0, input.find(","));
    std::string assignmentTwo = input.substr(input.find(",") + 1);

    int minA = stoi(assignmentOne.substr(0, assignmentOne.find("-")));
    int maxA = stoi(assignmentOne.substr(assignmentOne.find("-") + 1));
    int minB = stoi(assignmentTwo.substr(0, assignmentTwo.find("-")));
    int maxB = stoi(assignmentTwo.substr(assignmentTwo.find("-") + 1));

    if (findOverlapp(minA, maxA, minB, maxB))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    std::fstream inputFile;
    std::string assignments;

    int sum = 0;

    inputFile.open("input.txt");
    if (inputFile.is_open())
    {
        while (std::getline(inputFile, assignments))
        {
            sum += splitOverlapp(assignments);
        }
    }
    inputFile.close();
    std::cout << "The total is " << sum << "\n";
}
