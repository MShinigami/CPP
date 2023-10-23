#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    ofstream outputFile("output.txt");

    if (!outputFile.is_open())
    {
        cerr << "Failed to open the output file." << endl;
        return 1;
    }

    string dataToWrite = "File created Successfully";
    outputFile << dataToWrite << endl;
    outputFile.close();

    ifstream inputFile("output.txt");

    if (!inputFile.is_open())
    {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }

    string dataRead;
    getline(inputFile, dataRead);

    if (!inputFile.eof())
    {
        cout << "Data read from the file: " << dataRead << endl;
    }
    else
    {
        cerr << "Failed to read from the input file." << endl;
        return 1;
    }

    inputFile.close();

    return 0;
}
