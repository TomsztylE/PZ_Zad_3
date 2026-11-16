#include "pch.h"
#include "../MergeSortApp/MergeSort.h"
#include <vector>
#include <algorithm>
#include <random>

// 1. Zachowuje tablice niezmieniona, gdy jest juz posortowana rosnaco
TEST(MergeSortTests, AlreadySortedArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };
    std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7 };
    
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 2. Potrafi posortowac tablice posortowana w odwrotnej kolejnosci
TEST(MergeSortTests, ReverseSortedArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 9, 7, 5, 3, 1, 0 };
    std::vector<int> expected = { 0, 1, 3, 5, 7, 9 };
    
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 3. Poprawnie sortuje losowa tablice liczb
TEST(MergeSortTests, RandomArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 42, 12, 89, 3, 56, 21, 7 };
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());
    
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 4. Poprawnie sortuje tablice tylko z liczbami ujemnymi
TEST(MergeSortTests, OnlyNegativeNumbers) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -5, -100, -1, -42, -12 };
    std::vector<int> expected = { -100, -42, -12, -5, -1 };
    
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 5. Poprawnie sortuje tablice z liczbami ujemnymi i dodatnimi
TEST(MergeSortTests, NegativeAndPositiveNumbers) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -10, 5, 0, -3, 8, 12, -1 };
    std::vector<int> expected = { -10, -3, -1, 0, 5, 8, 12 };
    
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 6. Obsluguje pusta tablice bez rzucania wyjatkiem
TEST(MergeSortTests, EmptyArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = {};
    
    EXPECT_NO_THROW(sorter.sort(arr));
    EXPECT_TRUE(arr.empty());
}

// 7. Nie zmienia tablicy, ktora zawiera tylko jeden element
TEST(MergeSortTests, SingleElementArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 42 };
    std::vector<int> expected = { 42 };
    
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 8. Poprawnie sortuje tablice z duplikatami liczb
TEST(MergeSortTests, ArrayWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 5, 2, 8, 2, 5, 5, 1 };
    std::vector<int> expected = { 1, 2, 2, 5, 5, 5, 8 };
    
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 9. Poprawnie sortuje tablice ujemna z duplikatami
TEST(MergeSortTests, NegativeArrayWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -3, -10, -3, -1, -10, -5 };
    std::vector<int> expected = { -10, -10, -5, -3, -3, -1 };
    
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 10. Poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortTests, MixedNumbersWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 4, -2, 0, 4, -2, 7, 0, -5 };
    std::vector<int> expected = { -5, -2, -2, 0, 0, 4, 4, 7 };
    
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 11. Poprawnie sortuje tablice zawierajaca tylko dwa elementy w kolejnosci rosnacej
TEST(MergeSortTests, TwoElementsSorted) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 10, 20 };
    std::vector<int> expected = { 10, 20 };
    
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 12. Poprawnie sortuje duza tablice zawierajaca ponad 100 elementow
TEST(MergeSortTests, LargeArrayOver100Elements) {
    MergeSort<int> sorter;
    std::vector<int> arr(150);
    for (int i = 0; i < 150; ++i) {
        arr[i] = 150 - i; // Wypelnienie malejaco
    }
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 13. Poprawnie sortuje duza tablice (>100 elementow) z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortTests, LargeMixedArrayWithDuplicates) {
    MergeSort<double> sorter; // Test dodatkowo na typie double
    std::vector<double> arr;
    std::mt19937 gen(42); // Stale ziarno dla powtarzalnosci testow
    std::uniform_real_distribution<> dis(-50.0, 50.0);

    for (int i = 0; i < 120; ++i) {
        arr.push_back(std::round(dis(gen) * 10.0) / 10.0);
    }
    // Dodanie celowych duplikatow
    arr.push_back(-25.5);
    arr.push_back(-25.5);
    arr.push_back(10.0);
    arr.push_back(10.0);

    std::vector<double> expected = arr;
    std::sort(expected.begin(), expected.end());

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}