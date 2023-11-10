#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Item
{
    string name, DOP, SN;
    int quan;
    double cost;
};
vector<Item> rec;

void get_data()
{
    Item item;
    cout << "_________________________________________________" << endl;
    cout << "Enter the Name of the product: ";
    cin >> item.name;
    cout << "Enter the Serial Number for " << item.name << ": ";
    cin >> item.SN;
    cout << "Enter the date of packaging of " << item.name << ": ";
    cin >> item.DOP;
    cout << "Enter quantity of " << item.name << ": ";
    cin >> item.quan;
    cout << "Enter Cost Per Unit of " << item.name << ": ";
    cin >> item.cost;
    cout << "_________________________________________________" << endl;
    rec.push_back(item);
}

void display_data()
{
    cout << "The List of Items Available" << endl;
    cout << "___________________________" << endl;
    for (const Item &item : rec)
    {
        cout << item.name << endl;
        cout << "Serial Number: " << item.SN << endl;
        cout << "Date of Packaging: " << item.DOP << endl;
        cout << "Quantity: " << item.quan << endl;
        cout << "Cost Per Unit: Rs." << item.cost << endl;
    }
    cout << "\n_________________________" << endl;
}

void sorting()
{
    sort(rec.begin(), rec.end(), [](const Item &a, const Item &b) { return a.name < b.name; });
}

void searching(const string &query)
{
    bool found = false;

    for (const Item &item : rec)
    {
        if (item.name == query)
        {
            cout << "Item Found:" << endl;
            cout << "Name: " << item.name << endl;
            cout << "Serial Number: " << item.SN << endl;
            cout << "Date of Packaging: " << item.DOP << endl;
            cout << "Quantity: " << item.quan << endl;
            cout << "Cost Per Unit: Rs." << item.cost << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "Item not found." << endl;
    }
}

void save_to_file(const string &filename)
{
    ofstream outputFile;
    outputFile.open(filename);

    if (!outputFile.is_open())
    {
        cout << "Error: Unable to open the file for writing." << endl;
        return;
    }

    for (const Item &item : rec)
    {
        outputFile << "Name: " << item.name << endl;
        outputFile << "Serial Number: " << item.SN << endl;
        outputFile << "Date of Packaging: " << item.DOP << endl;
        outputFile << "Quantity: " << item.quan << endl;
        outputFile << "Cost Per Unit: Rs." << item.cost << endl;
        outputFile << "_________________________" << endl;
    }

    outputFile.close();
    cout << "Item data saved to " << filename << endl;
}

int main()
{
    string searchQuery;
    int num_items;
    string filename; // Moved the declaration here

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Display Items" << endl;
        cout << "3. Search Item" << endl;
        cout << "4. Sort Items" << endl;
        cout << "5. Save to File" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the number of Items - ";
            cin >> num_items;
            for (int i = 0; i < num_items; i++)
            {
                get_data();
            }
            break;
        case 2:
            display_data();
            break;
        case 3:
            cout << "Enter the name of the item you want to search for: ";
            cin >> searchQuery;
            searching(searchQuery);
            break;
        case 4:
            sorting();
            display_data();
            break;
        case 5:
            cout << "Enter the filename to save: ";
            cin >> filename;
            save_to_file(filename);
            break;
        case 6:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
