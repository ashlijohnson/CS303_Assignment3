#include <iostream>
using namespace std;
#include "function.h"

int main() {

  vector<int> vec = {1, 3, 5, 3, 9, 3, 7};
  int target = 3;

  // Start searching from the last index
  int lastIndex = recursiveLinearSearch(vec, target, vec.size() - 1);

  if (lastIndex != -1) {
      cout << "Last occurrence of " << target << " is at index " << lastIndex << endl;
  } else {
      cout << "Target " << target << " not found in the vector" << endl;
  }

    return 0;
}
