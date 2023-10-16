#include <iostream>
#include <iomanip>
int main() {
    int n;
    double pi = 0.0;

    std::cout << "Enter the number of terms to approximate pi: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        double term = 1.0 / (2 * i + 1);

        if (i % 2 == 1) {
            pi -= term;
        } else {
            pi += term;
        }
    }

    pi *= 4; // Multiply by 4 to get a closer approximation of π

    std::cout << "Approximation of pi after " << n << " terms: " << std::setprecision(15)<< pi << std::endl;

  std::cout << "PI (approx): " << pi << "; n: " << std::setw(7) << n << std::endl;
  std::cout << "PI (actual): " << "3.141592653589793" << std::endl;
    std::cout << "Number of base 2 mantissa digits of double precision floating point value: ";

    std::cout << "Next representable number from 3.141592653589793: ";

    return 0;
}