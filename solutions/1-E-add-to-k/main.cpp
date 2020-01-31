#include <iostream>
#include <unordered_set>
#include <vector>

bool hasSum(std::vector<int>& list, int target) {
  std::unordered_set<int> previousVals;
  for (std::vector<int>::iterator it = list.begin(); it != list.end(); ++it) {
    int toFind = target - *it;
    if (previousVals.count(toFind) > 0) {
      return true;
    } else {
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
