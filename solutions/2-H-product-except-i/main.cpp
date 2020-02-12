#include <iostream>
#include <vector>

/* Follow up challenge not completed */

void printVector(std::vector<int>& source) {
  std::cout << "[";
  for (int i=0; i < source.size(); ++i) {
    std::cout << source[i];
    if (i < source.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]";
}

int getTotalProduct(std::vector<int>& source) {
  int total = 1;
  for (auto it = source.begin(); it != source.end(); ++it) {
    total *= *it;
  }
  return total;
}

void productsExceptIndex(std::vector<int>& source, std::vector<int>& dest) {
  // get the total product of all elements
  int totalProduct = getTotalProduct(source);
  for (int i=0; i < source.size(); ++i) {
    // assign each index with the total produce divided by its value
    dest[i] = totalProduct / source[i];
  }
}

int main() {
  std::vector<int> source1 = {1, 2, 3, 4, 5};
  std::vector<int> source2 = {3, 2, 1};

  std::vector<int> dest1(5);
  std::vector<int> dest2(3);

  productsExceptIndex(source1, dest1);
  productsExceptIndex(source2, dest2);

  std::cout << "For array [1, 2, 3, 4, 5]: ";
  printVector(dest1);

  std::cout << "\n";

  std::cout << "For array [3, 2, 1]: ";
  printVector(dest2);

  std::cout << std::endl;

  return 0;
}
