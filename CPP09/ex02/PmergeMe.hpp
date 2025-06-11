#pragma once
#include <vector>
#include <deque>
#include <string>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;
    
    std::vector<int> fordJohnsonVec(std::vector<int> arr);
    std::deque<int> fordJohnsonDeq(std::deque<int> arr);
    void binaryInsertVec(std::vector<int>& arr, int val);
    void binaryInsertDeq(std::deque<int>& arr, int val);
    bool isValid(const std::string& str);

public:
    void run(int argc, char **argv);
};
