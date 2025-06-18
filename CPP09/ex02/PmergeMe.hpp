#pragma once

#include <cstddef>
#include <vector>
#include <string>

class PmergeMe {
private:
    std::vector<int> _input;

	template<typename Container>
	Container generateInsertOrder(size_t count);
	
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
Container PmergeMe::generateInsertOrder(size_t count) {
    Container order;
    if (count <= 1) return order;

    Container jacobsthal;
    jacobsthal.push_back(1);

    // Generate Jacobsthal numbers
    size_t j1 = 1, j2 = 0;
    while (j1 < count) {
        jacobsthal.push_back(j1);
        size_t tmp = j1;
        j1 = j1 + 2 * j2;
        j2 = tmp;
    }

    // Build insertion order based on Jacobsthal indices
    std::vector<bool> used(count, false);
    for (int i = static_cast<int>(jacobsthal.size()) - 1; i >= 0; --i) {
        size_t limit = jacobsthal[i];
        for (size_t j = limit; j > 0; --j) {
            if (j < count && !used[j]) {
                order.push_back(j);
                used[j] = true;
            }
        }
    }

	// Add remaining indices that were not used
    for (size_t i = 1; i < count; ++i) {
        if (!used[i]) {
            order.push_back(i);
        }
    }

    return order;
}

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
    
    for (size_t i = 0; i < arr.size() - 1; i += 2) {
        if (arr[i] > arr[i + 1]) {
            larger.push_back(arr[i]);
            smaller.push_back(arr[i + 1]);
        } else {
            larger.push_back(arr[i + 1]);
            smaller.push_back(arr[i]);
        }
    }
    
    if (arr.size() % 2 == 1) {
		straggler = arr.back();
	}
    // Recursively sort larger elements
    if (larger.size() > 1) {
		larger = fordJohnson(larger);
	}
    // Build result: first smaller + all larger
    Container result;
    if (!smaller.empty()) {
		result.push_back(smaller[0]);
	}
	for (typename Container::iterator it = larger.begin(); it != larger.end(); ++it) {
        result.push_back(*it);
    }
    
    // Insert remaining smaller elements
	Container insertOrder = generateInsertOrder<Container>(smaller.size());
	for (size_t i : insertOrder) {
		binaryInsert(result, smaller[i]);
	}
    if (straggler != -1) {
		binaryInsert(result, straggler);
	}
    return result;
}
