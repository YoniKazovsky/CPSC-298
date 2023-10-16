#include <iostream>
#include <iomanip>
int main() {
    int n;
    double pi = 0.0;

    std::cout << "Enter the number of terms to approximate pi: ";
    std::cin >> n;
    pi = 0.0;
  
      for (int j = 2; j <= n; j *= 2) {
      pi = 0.0;
    
      for (int i = 0; i < n; i++) {
          double term = 1.0 / (2 * i + 1);
    
          if (i % 2 == 1) {
              pi -= term;
          } else {
              pi += term;
          }
          std::cout << "PI: " << std::setprecision(15)<< pi << " n: " << j <<std::endl;
      }
      }
      
    pi *= 4; // Multiply by 4 to get a closer approximation of π

    return 0;
}