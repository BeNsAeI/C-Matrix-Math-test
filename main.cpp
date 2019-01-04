#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#define R0 3
#define C0 3
#define R1 3
#define C1 3
#define R2 2
#define C2 2
std::vector<int> Z0 = {0, 0, 0,
                       0, 0, 0, 
                       0, 0, 0};
std::vector<int> I0 = {1, 0, 0,
                       0, 1, 0, 
                       0, 0, 1};
std::vector<int> M1 = {1, 2, 3,
                       4, 5, 6, 
                       7, 8, 9};
std::vector<int> M2 = {1, 2,
                       3, 4};

void printMatrix(std::vector<int> m, int col)
{
    int cc = 1;
    for (std::vector<int>::iterator it = m.begin() ; it != m.end(); it++)
    {
        printf("%d",*it);
        if (cc % col == 0)
            printf("\n");
        else
            printf(", ");
        cc++;
    }
}
template <class T>
std::vector<T> add(std::vector<T> a, std::vector<T> b)
{
    std::vector<T> result = {};
    std::vector<int>::iterator itA = a.begin();
    std::vector<int>::iterator itB = b.begin();
    if (a.size() != b.size())
        printf("err!\n");
    while (itA != a.end() && itB != b.end() && a.size() == b.size())
    {
        result.push_back(*itA + *itB);
        itA++;
        itB++;
    }
    return result;
}
template <class T>
std::vector<T> sub(std::vector<T> a, std::vector<T> b)
{
    std::vector<T> result = {};
    std::vector<int>::iterator itA = a.begin();
    std::vector<int>::iterator itB = b.begin();
    if (a.size() != b.size())
        printf("err!\n");
    while (itA != a.end() && itB != b.end() && a.size() == b.size())
    {
        result.push_back(*itA - *itB);
        itA++;
        itB++;
    }
    return result;
}
template <class T>
std::vector<T> mult(T a, std::vector<T> b)
{
    std::vector<T> result = {};
    for(std::vector<int>::iterator it = b.begin(); it != b.end(); it++)
        result.push_back(a * (*it));
    return result;
}
template <class T>
std::vector<T> mult(std::vector<T> a, std::vector<T> b)
{
    std::vector<T> result = {};
    return result;
}
int main()
{
    std::cout << "Testing..." << std::endl;
    std::cout << "Z0:" << std::endl;
    printMatrix(Z0,C0);
    std::cout << "I0:" << std::endl;
    printMatrix(I0,C0);
    std::cout << "M1:" << std::endl;
    printMatrix(M1,C1);
    std::cout << "M2:" << std::endl;
    printMatrix(M2,C2);
    std::cout << "Z0 + Z0:" << std::endl;
    printMatrix(add<int>(Z0,Z0), C0);
    std::cout << "I0 + I0:" << std::endl;
    printMatrix(add<int>(I0,I0), C0);
    std::cout << "Z0 + M1:" << std::endl;
    printMatrix(add<int>(Z0,M1), C0);
    std::cout << "I0 + M1:" << std::endl;
    printMatrix(add<int>(I0,M1), C0);
    std::cout << "M1 + M1:" << std::endl;
    printMatrix(add<int>(M1,M1), C1);
    std::cout << "M2 + M2:" << std::endl;
    printMatrix(add<int>(M2,M2), C2);
    std::cout << "M1 + M2:" << std::endl;
    printMatrix(add<int>(M1,M2), C1);
    std::cout << "5 * I0:" << std::endl;
    printMatrix(mult<int>(5,I0), C0);
    std::cout << "7 * Z0:" << std::endl;
    printMatrix(mult<int>(7,Z0), C0);
    std::cout << "3 * M1:" << std::endl;
    printMatrix(mult<int>(3,M1), C1);
    std::cout << "2 * M2:" << std::endl;
    printMatrix(mult<int>(2,M2), C2);
    std::cout << "M1 * M1:" << std::endl;
    printMatrix(mult<int>(M1,M1), C1);
    std::cout << "M2 * M2:" << std::endl;
    printMatrix(mult<int>(M2,M2), C2);
    std::cout << "M1 * M2:" << std::endl;
    printMatrix(mult<int>(M1,M2), C2);
    return 0;
}
