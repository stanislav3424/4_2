#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

struct Contain
{
    std::string a{};
    std::string b{};
    std::string c{};
    std::string d{};
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

    for (int index = 0; index < sum; ++index)
    {
        inputFile >> containArr[index].a;
        inputFile >> containArr[index].b;
        inputFile >> containArr[index].c;
        inputFile >> containArr[index].d;
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
    for (int index = 0; index < sum; ++index)
    {
        outputFile << containArr[index].a << ", ";
        outputFile << containArr[index].b << ", ";
        outputFile << containArr[index].c << ", ";
        outputFile << containArr[index].d;
        outputFile << std::endl;
    }

    outputFile.close();
    return true;
}

void sort(Contain* containArr, int sum)
{
    std::sort(containArr, containArr + sum,
              [](const Contain& local_a, const Contain& local_b) { return local_a.a < local_b.a; });
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
    }

    delete[] containArr;
    return 0;
}