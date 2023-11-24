#include <iostream>
#include <fstream>

class CentralPolygonalNumber {
private:
    int* mp_iNumbers; 
    int m_nMax;       
    
public:
    CentralPolygonalNumber() : mp_iNumbers(nullptr), m_nMax(0) {}

    CentralPolygonalNumber(int nMax) : mp_iNumbers(nullptr), m_nMax(nMax) {
        mp_iNumbers = new int[m_nMax + 1];

        for (int i = 0; i <= m_nMax; ++i) {
            mp_iNumbers[i] = (i * (i + 1)) / 2 + 1;
        }
    }

    ~CentralPolygonalNumber() {
        delete[] mp_iNumbers;
        std::cout << "Destructor called." << std::endl;
    }

    void displaySequence() const {
        for (int i = 0; i <= m_nMax; ++i) {
            std::cout << mp_iNumbers[i] << " ";
        }
        std::cout << std::endl;
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream outputFile(filename);

        for (int i = 0; i <= m_nMax; ++i) {
            outputFile << "N: " << i << ", max num pieces: " << mp_iNumbers[i] << " " << std::endl;
        }

        outputFile.close();
    }
};

int main() {
    CentralPolygonalNumber sequence(10);

    sequence.displaySequence();

    sequence.saveToFile("sequence.txt");

    return 0;
}