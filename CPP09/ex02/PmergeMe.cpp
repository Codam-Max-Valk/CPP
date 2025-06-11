#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <algorithm>

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
        _input.push_back(std::stoi(argv[i]));
    }
    
    // Display before
    std::cout << "Before: ";
    for (size_t i = 0; i < _input.size(); ++i) {
        if (i > 0) std::cout << " ";
        std::cout << _input[i];
        if (i >= 4 && _input.size() > 5) {
            std::cout << " [...]";
            break;
        }
    }
    std::cout << std::endl;
    
    // Create containers from input
    std::vector<int> vec(_input.begin(), _input.end());
    std::deque<int> deq(_input.begin(), _input.end());
    
    // Sort and time vector
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> sortedVec = fordJohnson(vec);
    auto end = std::chrono::high_resolution_clock::now();
    double vecTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    // Sort and time deque
    start = std::chrono::high_resolution_clock::now();
    std::deque<int> sortedDeq = fordJohnson(deq);
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
    std::cout << "Time to process a range of " << _input.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) 
              << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _input.size() 
              << " elements with std::deque : " << std::fixed << std::setprecision(5) 
              << deqTime << " us" << std::endl;
}