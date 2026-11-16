/**
 * @file MergeSort.h
 * @brief Implementacja szablonowej klasy realizującej algorytm sortowania przez scalanie (MergeSort).
 */

#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <cstddef>

 /**
  * @class MergeSort
  * @brief Szablon klasy implementujący algorytm sortowania przez scalanie.
  * @tparam T Typ danych przechowywanych w tablicy (np. int, long int, double, float).
  */
template <typename T>
class MergeSort {
private:
    /**
     * @brief Funkcja pomocnicza scalająca dwie posortowane podtablice.
     * @param arr Wektor danych do posortowania.
     * @param left Indeks początkowy lewej podtablicy.
     * @param mid Indeks środkowy dzielący podtablice.
     * @param right Indeks końcowy prawej podtablicy.
     */
    void merge(std::vector<T>& arr, size_t left, size_t mid, size_t right) {
        size_t n1 = mid - left + 1;
        size_t n2 = right - mid;

        // Tymczasowe tablice dla lewej i prawej części
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
            }
            else {
                arr[k] = rightArr[j];
                ++j;
            }
            ++k;
        }

        // Kopiowanie pozostałych elementów z leftArr, jeśli istnieją
        while (i < n1) {
            arr[k] = leftArr[i];
            ++i;
            ++k;
        }

        // Kopiowanie pozostałych elementów z rightArr, jeśli istnieją
        while (j < n2) {
            arr[k] = rightArr[j];
            ++j;
            ++k;
        }
    }

    /**
     * @brief Rekurencyjna funkcja dzieląca tablicę na mniejsze podtablice.
     * @param arr Wektor danych do posortowania.
     * @param left Indeks początkowy.
     * @param right Indeks końcowy.
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
     * @brief Główna metoda publiczna uruchamiająca sortowanie.
     * @param arr Referencja do wektora, który ma zostać posortowany rosnąco.
     */
    void sort(std::vector<T>& arr) {
        if (arr.size() <= 1) {
            return; // Pusta lub 1-elementowa tablica jest już posortowana
        }
        mergeSortRecursive(arr, 0, arr.size() - 1);
    }
};

#endif // MERGESORT_H