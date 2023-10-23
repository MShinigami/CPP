#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outputFile("input.txt", ios::out);

    if (outputFile.is_open()) {
        int numbers[] = {0, 5, 4, 8, 6, 4, 5, 1, 2, 0, 4, 6, 4};
        for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
            outputFile << numbers[i] << " ";
        }

        outputFile.close();
        cout << "File 'input.txt' created with the provided input values." << endl;
    } else {
        cerr << "Error opening the file." << endl;
    }

    return 0;
}
