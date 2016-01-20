#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <vector>

template<typename T>
void PrintVector(std::vector<T> v)
{
    int l = v.size();
    for(int i = 0;i < l;i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void PrintMatrix(std::vector<std::vector<T>> m)
{
    int r = m.size();
    for(int i = 0;i < r;i++)
    {
        PrintVector(m[i]);
    }
}

#endif
