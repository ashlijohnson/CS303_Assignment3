#include "function.h"

// Recursive function to find the last occurrence of target in the vector
int recursiveLinearSearch(const vector<int>& vec, int target, int index) {

    if (index == -1) {
        return -1;
    }
    if (vec[index] == target) {
        return index; 
    }
    return recursiveLinearSearch(vec, target, index - 1);
}
