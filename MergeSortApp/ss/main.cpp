/**
 * @file main.cpp
 * @brief Glowny plik programu demonstrujacy dzialanie klasy MergeSort dla typow int oraz double.
 */

#include <iostream>
#include <vector>
#include "MergeSort.h"

/**
 * @brief Funkcja pomocnicza do wypisywania zawartosci wektora na ekran.
 * @tparam T Typ elementow w wektorze.
 * @param arr Wektor do wyswietlenia.
 */
template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    // 1. Instancja dla liczb typu int
    MergeSort<int> intSorter;
    std::vector<int> intArray = { 38, 27, 43, 3, 9, 82, 10, -5, 0 };

    std::cout << "Tablica int przed sortowaniem: ";
    printArray(intArray);

    intSorter.sort(intArray);

    std::cout << "Tablica int po sortowaniu:    ";
    printArray(intArray);
    std::cout << "--------------------------------------------------\n";

    // 2. Instancja dla liczb typu double
    MergeSort<double> doubleSorter;
    std::vector<double> doubleArray = { 3.14, -2.71, 0.0, 100.5, 42.42, -99.9, 1.01 };

    std::cout << "Tablica double przed sortowaniem: ";
    printArray(doubleArray);

    doubleSorter.sort(doubleArray);

    std::cout << "Tablica double po sortowaniu:    ";
    printArray(doubleArray);

    return 0;
}