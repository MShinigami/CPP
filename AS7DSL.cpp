#include <iostream>
#include <string>

using namespace std;

struct Node 
{
    int prn;
    string name;
    Node* next;
};

class Division 
{
private:
    Node* head;

public:
    Division() 
    {
        head = nullptr;
    }

    void addMember(int prn, string name) 
    {
        Node* newNode = new Node;
        newNode->prn = prn;
        newNode->name = name;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } 
        else 
        {
            Node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayMembers() 
    {
        Node* temp = head;

        while (temp != nullptr) 
        {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    void SortMembers() 
    {
        if (head == nullptr || head->next == nullptr) 
        {
            return;
        }

        bool swapped;
        Node* temp;
        Node* last = nullptr;

        do {
            swapped = false;
            temp = head;

            while (temp->next != last) 
            {
                if (temp->prn > temp->next->prn) 
                {
                    swap(temp->prn, temp->next->prn);
                    swap(temp->name, temp->next->name);
                    swapped = true;
                }
                temp = temp->next;
            }

            last = temp;
        } while (swapped);
    }

    void ReverseOrder() 
    {
        RORecursive(head);
    }

    Node* getHead() 
    {
        return head;
    }

private:
    void RORecursive(Node* current) 
    {
        if (current == nullptr)
        {
            return;
        }

        RORecursive(current->next);
        cout << "PRN: " << current->prn << ", Name: " << current->name << endl;
    }
};

class MergedDivision 
{
private:
    Node* head;

public:
    MergedDivision() 
    {
        head = nullptr;
    }

    void NewDivision(Division& division1, Division& division2)
    {
        Node* temp1 = division1.getHead();
        Node* temp2 = division2.getHead();

        while (temp1 != nullptr && temp2 != nullptr) 
        {
            if (temp1->prn < temp2->prn) 
            {
                addMember(temp1->prn, temp1->name);
                temp1 = temp1->next;
            } 
            else 
            {
                addMember(temp2->prn, temp2->name);
                temp2 = temp2->next;
            }
        }

        while (temp1 != nullptr) 
        {
            addMember(temp1->prn, temp1->name);
            temp1 = temp1->next;
        }

        while (temp2 != nullptr) 
        {
            addMember(temp2->prn, temp2->name);
            temp2 = temp2->next;
        }
    }

    void displayMembers() 
    {
        Node* temp = head;

        while (temp != nullptr) 
        {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

private:
    void addMember(int prn, string name) 
    {
        Node* newNode = new Node;
        newNode->prn = prn;
        newNode->name = name;
        newNode->next = nullptr;

        if (head == nullptr) 
        {
            head = newNode;
        } 
        else 
        {
            Node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
};

class Club 
{
private:
    Division division1;
    Division division2;
    MergedDivision mergedDivision;

public:
    void Div1Details() 
    {
        char choice;
        int prn;
        string name;

        do 
        {
            cout << "\nOptions for Division 1:\n";
            cout << "1) Add President\n";
            cout << "2) Add Secretary\n";
            cout << "3) Add Members\n";
            cout << "4) Display Members\n";
            cout << "5) Sort Members by PRN\n";
            cout << "6) Display Members in Reverse Order\n";
            cout << "7) Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) 
            {
                case '1':
                    cout << "Enter PRN and Name of Division 1 President: ";
                    cin >> prn >> name;
                    division1.addMember(prn, name);
                    break;

                case '2':
                    cout << "Enter PRN and Name of Division 1 Secretary: ";
                    cin >> prn >> name;
                    division1.addMember(prn, name);
                    break;

                case '3':
                    cout << "Enter PRN and Name to add a member to Division 1: ";
                    cin >> prn >> name;
                    division1.addMember(prn, name);
                    break;

                case '4':
                    cout << "Division 1 Members:\n";
                    division1.displayMembers();
                    break;

                case '5':
                    division1.SortMembers();
                    cout << "Division 1 Members sorted by PRN.\n";
                    break;

                case '6':
                    cout << "Division 1 Members in Reverse Order:\n";
                    division1.ReverseOrder();
                    break;

                case '7':
                    cout << "Exiting Division 1 menu.\n";
                    break;

                default:
                    cout << "Invalid choice. Try again.\n";
            }

            if (choice != '7') 
            {
                cout << "\nDo you wish to select a Division? (Y/N): ";
                cin >> choice;
            }

        } while (choice != '7');
    }

    void Div2Details() 
    {
        char choice;
        int prn;
        string name;

        do 
        {
            cout << "\nOptions for Division 2:\n";
            cout << "1) Add President\n";
            cout << "2) Add Secretary\n";
            cout << "3) Add Members\n";
            cout << "4) Display Members\n";
            cout << "5) Sort Members by PRN\n";
            cout << "6) Display Members in Reverse Order\n";
            cout << "7) Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) 
            {
                case '1':
                    cout << "Enter PRN and Name of Division 2 President: ";
                    cin >> prn >> name;
                    division2.addMember(prn, name);
                    break;

                case '2':
                    cout << "Enter PRN and Name of Division 2 Secretary: ";
                    cin >> prn >> name;
                    division2.addMember(prn, name);
                    break;

                case '3':
                    cout << "Enter PRN and Name to add a member to Division 2: ";
                    cin >> prn >> name;
                    division2.addMember(prn, name);
                    break;

                case '4':
                    cout << "Division 2 Members:\n";
                    division2.displayMembers();
                    break;

                case '5':
                    division2.SortMembers();
                    cout << "Division 2 Members sorted by PRN.\n";
                    break;

                case '6':
                    cout << "Division 2 Members in Reverse Order:\n";
                    division2.ReverseOrder();
                    break;

                case '7':
                    cout << "Exiting Division 2 menu.\n";
                    break;

                default:
                    cout << "Invalid choice. Try again.\n";
            }

            if (choice != '7') 
            {
                cout << "\nDo you wish to select a Division? (Y/N): ";
                cin >> choice;
            }

        } while (choice != '7');
    }

    void NDDisplay() 
    {
        division1.SortMembers();
        division2.SortMembers();

        mergedDivision.NewDivision(division1, division2);

        cout << "Merged and Sorted Division Members:\n";
        mergedDivision.displayMembers();
    }
};

int main() 
{
    Club club;

    char choice;

    do 
    {
        cout << "\nDo you wish to select a Division? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') 
        {
            cout << "\nOptions:\n";
            cout << "a) Enter the details of Division 1\n";
            cout << "b) Enter the details of Division 2\n";
            cout << "c) Merge and Display Sorted Divisions\n";
            cout << "x) Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) 
            {
                case 'a':
                    club.Div1Details();
                    break;

                case 'b':
                    club.Div2Details();
                    break;

                case 'c':
                    club.NDDisplay();
                    break;

                case 'x':
                    cout << "\nThank You\n";
                    break;

                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } 
        else if (choice != 'N' && choice != 'n') 
        {
            cout << "Invalid choice. Please enter 'Y' or 'N'.\n";
        }

    } 
    while (choice != 'x');
    return 0;
}