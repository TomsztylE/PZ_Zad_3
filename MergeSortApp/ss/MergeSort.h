/**
 * @file MergeSort.h
 * @brief Implementacja szablonowej klasy realizujacej algorytm sortowania przez scalanie (MergeSort).
 */

#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <cstddef>

/**
 * @class MergeSort
 * @brief Szablon klasy implementujacy algorytm sortowania przez scalanie.
 * @tparam T Typ danych przechowywanych w tablicy (np. int, long int, double, float).
 */
template <typename T>
class MergeSort {
private:
    /**
     * @brief Funkcja pomocnicza scalajaca dwie posortowane podtablice.
     * @param arr Wektor danych do posortowania.
     * @param left Indeks poczatkowy lewej podtablicy.
     * @param mid Indeks srodkowy dzielacy podtablice.
     * @param right Indeks koncowy prawej podtablicy.
     */
    void merge(std::vector<T>& arr, size_t left, size_t mid, size_t right) {
        size_t n1 = mid - left + 1;
        size_t n2 = right - mid;

        // Tymczasowe tablice dla lewej i prawej czesci
        std::vector<T> leftArr(n1);
        std::vector<T> rightArr(n2);

        for (size_t i = 0; i < n1; ++i)
            leftArr[i] = arr[left + i];
        for (size_t j = 0; j < n2; ++j)
            rightArr[j] = arr[mid + 1 + j];

        size_t i = 0;    // Indeks pierwszej podtablicy
        size_t j = 0;    // Indeks drugiej podtablicy
        size_t k = left; // Indeks scalonej tablicy

        // Scalanie tablic tymczasowych z powrotem do arr
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                ++i;
            } else {
                arr[k] = rightArr[j];
                ++j;
            }
            ++k;
        }

        // Kopiowanie pozostalych elementow z leftArr, jesli istnieja
        while (i < n1) {
            arr[k] = leftArr[i];
            ++i;
            ++k;
        }

        // Kopiowanie pozostalych elementow z rightArr, jesli istnieja
        while (j < n2) {
            arr[k] = rightArr[j];
            ++j;
            ++k;
        }
    }

    /**
     * @brief Rekurencyjna funkcja dzielaca tablice na mniejsze podtablice.
     * @param arr Wektor danych do posortowania.
     * @param left Indeks poczatkowy.
     * @param right Indeks koncowy.
     */
    void mergeSortRecursive(std::vector<T>& arr, size_t left, size_t right) {
        if (left >= right) {
            return;
        }
        size_t mid = left + (right - left) / 2;
        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

public:
    /**
     * @brief Glowna metoda publiczna uruchamiajaca sortowanie.
     * @param arr Referencja do wektora, ktory ma zostac posortowany rosnaco.
     */
    void sort(std::vector<T>& arr) {
        if (arr.size() <= 1) {
            return; // Pusta lub 1-elementowa tablica jest juz posortowana
        }
        mergeSortRecursive(arr, 0, arr.size() - 1);
    }
};

#endif // MERGESORT_H