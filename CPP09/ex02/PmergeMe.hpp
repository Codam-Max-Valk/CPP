#pragma once

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
private:
    std::vector<int> _input;
    
    template<typename Container>
    Container fordJohnson(Container arr);
    
    template<typename Container>
    void binaryInsert(Container& arr, int val);
    
    bool isValid(const std::string& str);

public:
	PmergeMe() = default;
	~PmergeMe() = default;
	PmergeMe(const PmergeMe &cpy) = default;
	PmergeMe &operator=(const PmergeMe &cpy) = default;

    void run(int argc, char **argv);
};


template<typename Container>
void PmergeMe::binaryInsert(Container& arr, int val) {
    typename Container::iterator pos = std::lower_bound(arr.begin(), arr.end(), val);
    arr.insert(pos, val);
}

template<typename Container>
Container PmergeMe::fordJohnson(Container arr) {
    if (arr.size() <= 1) return arr;
    
    Container larger, smaller;
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
    if (larger.size() > 1) larger = fordJohnson(larger);
    
    // Build result: first smaller + all larger
    Container result;
    if (!smaller.empty()) result.push_back(smaller[0]);
    for (typename Container::iterator it = larger.begin(); it != larger.end(); ++it) {
        result.push_back(*it);
    }
    
    // Insert remaining smaller elements
    for (size_t i = 1; i < smaller.size(); ++i) {
        binaryInsert(result, smaller[i]);
    }
    
    if (straggler != -1) binaryInsert(result, straggler);
    
    return result;
}
