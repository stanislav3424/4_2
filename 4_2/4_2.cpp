#include <fstream>
#include <iostream>
#include <string>

class Contain
{
  public:
    std::string city{};
    std::string street{};
    std::string house{};
    std::string apartment{};
};

bool read(int& sum, Contain*& containArr)
{
    std::ifstream inputFile("in.txt");

    if (!inputFile)
    {
        return false;
    }

    inputFile >> sum;
    containArr = new Contain[sum];

    for (int index{}; index < sum; ++index)
    {
        inputFile >> containArr[index].city;
        inputFile >> containArr[index].street;
        inputFile >> containArr[index].house;
        inputFile >> containArr[index].apartment;
    }

    inputFile.close();
    return true;
}

bool write(int& sum, Contain*& containArr)
{
    std::ofstream outputFile("out.txt");

    if (!outputFile)
    {
        return false;
    }

    outputFile << sum << std::endl;
    for (int index{}; index < sum; ++index)
    {
        outputFile << containArr[index].city << ", ";
        outputFile << containArr[index].street << ", ";
        outputFile << containArr[index].house << ", ";
        outputFile << containArr[index].apartment;
        outputFile << std::endl;
    }

    outputFile.close();
    return true;
}

void sort(Contain* containArr, int& sum)
{
    for (int time{}; time < sum; ++time)
    {
        for (int index{}; index + 1 < sum; ++index)
        {
            if (containArr[index].city > containArr[index + 1].city)
            {
                Contain local;
                local = containArr[index];
                containArr[index] = containArr[index + 1];
                containArr[index + 1] = local;
            }
        }
    }
}

int main()
{
    int sum = 0;
    Contain* containArr = nullptr;

    if (!read(sum, containArr))
    {
        return 1;
    }

    sort(containArr, sum);

    if (!write(sum, containArr))
    {
        return 2;
        delete[] containArr;
    }

    delete[] containArr;
    return 0;
}