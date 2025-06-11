#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>

bool PmergeMe::isValid(const std::string& str) {
    if (str.empty() || str[0] == '-') return false;
    size_t start = (str[0] == '+') ? 1 : 0;
    if (start == str.length()) return false;
    
    for (size_t i = start; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) return false;
    }
    
    try {
        long num = std::stol(str);
        return num > 0 && num <= 2147483647;
    } catch (...) {
        return false;
    }
}

void PmergeMe::binaryInsertVec(std::vector<int>& arr, int val) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < val) left = mid + 1;
        else right = mid;
    }
    arr.insert(arr.begin() + left, val);
}

void PmergeMe::binaryInsertDeq(std::deque<int>& arr, int val) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < val) left = mid + 1;
        else right = mid;
    }
    arr.insert(arr.begin() + left, val);
}

std::vector<int> PmergeMe::fordJohnsonVec(std::vector<int> arr) {
    if (arr.size() <= 1) return arr;
    
    std::vector<int> larger, smaller;
    int straggler = -1;
    
    // Pair and compare
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        if (arr[i] > arr[i + 1]) {
            larger.push_back(arr[i]);
            smaller.push_back(arr[i + 1]);
        } else {
            larger.push_back(arr[i + 1]);
            smaller.push_back(arr[i]);
        }
    }
    
    if (arr.size() % 2 == 1) straggler = arr.back();
    
    // Recursively sort larger elements
    if (larger.size() > 1) larger = fordJohnsonVec(larger);
    
    // Build result: first smaller + all larger
    std::vector<int> result;
    if (!smaller.empty()) result.push_back(smaller[0]);
    for (int val : larger) result.push_back(val);
    
    // Insert remaining smaller elements
    for (size_t i = 1; i < smaller.size(); ++i) {
        binaryInsertVec(result, smaller[i]);
    }
    
    if (straggler != -1) binaryInsertVec(result, straggler);
    
    return result;
}

std::deque<int> PmergeMe::fordJohnsonDeq(std::deque<int> arr) {
    if (arr.size() <= 1) return arr;
    
    std::deque<int> larger, smaller;
    int straggler = -1;
    
    // Pair and compare
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        if (arr[i] > arr[i + 1]) {
            larger.push_back(arr[i]);
            smaller.push_back(arr[i + 1]);
        } else {
            larger.push_back(arr[i + 1]);
            smaller.push_back(arr[i]);
        }
    }
    
    if (arr.size() % 2 == 1) straggler = arr.back();
    
    // Recursively sort larger elements
    if (larger.size() > 1) larger = fordJohnsonDeq(larger);
    
    // Build result: first smaller + all larger
    std::deque<int> result;
    if (!smaller.empty()) result.push_back(smaller[0]);
    for (int val : larger) result.push_back(val);
    
    // Insert remaining smaller elements
    for (size_t i = 1; i < smaller.size(); ++i) {
        binaryInsertDeq(result, smaller[i]);
    }
    
    if (straggler != -1) binaryInsertDeq(result, straggler);
    
    return result;
}

void PmergeMe::run(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return;
    }
    
    // Parse input
    for (int i = 1; i < argc; ++i) {
        if (!isValid(argv[i])) {
            std::cerr << "Error" << std::endl;
            return;
        }
        int num = std::stoi(argv[i]);
        _vec.push_back(num);
        _deq.push_back(num);
    }
    
    // Display before
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        if (i > 0) std::cout << " ";
        std::cout << _vec[i];
        if (i >= 4 && _vec.size() > 5) {
            std::cout << " [...]";
            break;
        }
    }
    std::cout << std::endl;
    
    // Sort and time vector
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> sortedVec = fordJohnsonVec(_vec);
    auto end = std::chrono::high_resolution_clock::now();
    double vecTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    // Sort and time deque
    start = std::chrono::high_resolution_clock::now();
    std::deque<int> sortedDeq = fordJohnsonDeq(_deq);
    end = std::chrono::high_resolution_clock::now();
    double deqTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    // Display after
    std::cout << "After: ";
    for (size_t i = 0; i < sortedVec.size(); ++i) {
        if (i > 0) std::cout << " ";
        std::cout << sortedVec[i];
        if (i >= 4 && sortedVec.size() > 5) {
            std::cout << " [...]";
            break;
        }
    }
    std::cout << std::endl;
    
    // Display timing
    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) 
              << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque : " << std::fixed << std::setprecision(5) 
              << deqTime << " us" << std::endl;
}