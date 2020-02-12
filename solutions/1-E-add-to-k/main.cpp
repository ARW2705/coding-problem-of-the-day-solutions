#include <iostream>
#include <unordered_set>
#include <vector>

bool hasSum(std::vector<int>& list, int target) {
  // create a hash set to store previous values for fast lookup
  std::unordered_set<int> previousVals;

  for (std::vector<int>::iterator it = list.begin(); it != list.end(); ++it) {
    // find the complement of each item and search for it in the previousVals set
    int toFind = target - *it;
    if (previousVals.count(toFind) > 0) {
      // if the complement was previously encountered, success
      return true;
    } else {
      // otherwise insert the complement and continue
      previousVals.insert(*it);
    }
  }
  return false;
}

int main () {
  std::vector<int> sampleArr {10, 15, 3, 7};
  int sampleTarget1 = 17;
  int sampleTarget2 = 19;

  std::cout
    << "Given [10, 15, 3, 7], hasSum(17) --> "
    << std::boolalpha
    << hasSum(sampleArr, sampleTarget1)
    << "\n\n";

  std::cout
    << "Given [10, 15, 3, 7], hasSum(19) --> "
    << std::boolalpha
    << hasSum(sampleArr, sampleTarget2)
    << "\n\n";

  return 0;
}
