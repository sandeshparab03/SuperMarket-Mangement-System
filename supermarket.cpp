#include <iostream>
#include <fstream>  //It is directive in C++ is used to include the file stream library, which provides functionalities to perform input and output operations on files.
#include <string>

using namespace std;

class Shopping {  //Class
private:
    int pcode;   // Data Members
    float price;
    float dis;
    string pname; //productname

public:
    void menu();     // Functions
    void administrator();
    void buyer();
    void add();
    void edit();
    void removeProduct();  // Renamed from remove() to avoid conflict
    void list();
    void receipt();
};

void Shopping::menu() {  // Function Number 1
    int choice;
    string email, password;

    while (true) {
        cout << "\t\t\t\t______________________________________\n";
        cout << "\t\t\t\t          Supermarket Main Menu       \n";
        cout << "\t\t\t\t______________________________________\n";
        cout << "\t\t\t\t|  1) Administrator   |\n";
        cout << "\t\t\t\t|  2) Buyer           |\n";
        cout << "\t\t\t\t|  3) Exit            |\n";
        cout << "\n\t\t\t Please select: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\t\t\t Please Login \n";
                cout << "\t\t\t Enter Email:   \n";
                cin >> email;
                cout << "\t\t\t Password:       \n";
                cin >> password;

                if (email == "sandeshparab2026@gmail.com" && password == "Sohan@123") {
                    administrator();
                } else {
                    cout << "Invalid email/password\n";
                }
                break;

            case 2:
                buyer();
                break;

            case 3:
                cout << "Exiting the program...\n";
                return;  // Exit the menu and terminate the program

            default:
                cout << "Please select from the given options\n";
        }
    }
}

void Shopping::administrator() {  // Function Number 2
    int choice;

    while (true) {
        cout << "\n\n\t\t\t Administrator menu";
        cout << "\n\t\t\t| 1) Add the product |";
        cout << "\n\t\t\t| 2) Modify the product |";
        cout << "\n\t\t\t| 3) Delete the product |";
        cout << "\n\t\t\t| 4) Back to main menu |";
        cout << "\n\n\t Please enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add();
                break;

            case 2:
                edit();
                break;

            case 3:
                removeProduct();
                break;

            case 4:
                cout << "Returning to the main menu...\n";
                return;  // Exit the administrator menu and return to main menu

            default:
                cout << "Invalid choice!\n";
        }
    }
}

void Shopping::buyer() {
    int choice;

    while (true) {
        cout << "\n\t\t\t  Buyer \n";
        cout << "\t\t\t1) Buy product \n";
        cout << "\t\t\t2) Go back \n";
        cout << "\t\t\t Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                receipt();
                break;

            case 2:
                cout << "Returning to the main menu...\n";
                return;  // Exit the buyer menu and return to main menu

            default:
                cout << "Invalid choice\n";
        }
    }
}

void Shopping::add() {
    fstream data;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t Product code of the product: ";
    cin >> pcode;
    cout << "\n\n\t Name of the product: ";
    cin >> pname;
    cout << "\n\n\t Price of the product: ";
    cin >> price;
    cout << "\n\n\t Discount on product: ";
    cin >> dis;

    data.open("database.txt", ios::in); //ios::in will open the file in reading mode
    if (data) {
        while (data >> c >> n >> p >> d) {
            if (c == pcode) {
                token++;
                break;
            }
        }
        data.close();
    }

    if (token == 0) {
        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
        cout << "\n\n\t\t Record inserted!\n";
    } else {
        cout << "\n\n\t\t Product code already exists!\n";
    }
}

void Shopping::edit() {
    fstream data, data1;
    int pkey, c;
    float p, d;
    string n;
    bool found = false;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\nFile doesn't exist!\n";
        return;
    }

    data1.open("database1.txt", ios::out); //opening file in write mode
    while (data >> pcode >> pname >> price >> dis) {
        if (pkey == pcode) {
            cout << "\n\t\t New product code: ";
            cin >> c;
            cout << "\n\t\t Name of the product: ";
            cin >> n;
            cout << "\n\t\t Price: ";
            cin >> p;
            cout << "\n\t\t Discount: ";
            cin >> d;
            data1 << c << " " << n << " " << p << " " << d << "\n";
            found = true;
        } else {
            data1 << pcode << " " << pname << " " << price << " " << dis << "\n";
        }
    }

    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt", "database.txt");

    if (found) {
        cout << "\n\n\t\t Record edited!\n";
    } else {
        cout << "\n\n\t\t Record not found!\n";
    }
}

void Shopping::removeProduct() {
    fstream data, data1;
    int pkey;
    bool found = false;

    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "File doesn't exist!\n";
        return;
    }

    data1.open("database1.txt", ios::out);
    while (data >> pcode >> pname >> price >> dis) {
        if (pcode == pkey) {
            cout << "\n\n\t Product deleted successfully!\n";
            found = true;
        } else {
            data1 << pcode << " " << pname << " " << price << " " << dis << "\n";
        }
    }

    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt", "database.txt");

    if (!found) {
        cout << "\n\n\t Record not found!\n";
    }
}

void Shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\nFile doesn't exist!\n";
        return;
    }

    cout << "\n\n|___________________________________________________________\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "|___________________________________________________________\n";
    while (data >> pcode >> pname >> price >> dis) {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
    }
    data.close();
}

void Shopping::receipt() {
    fstream data;
    int arrc[100], arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float discountedAmount = 0;
    float total = 0;

    cout << "\n\n\t\t\t Receipt ";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n Empty database";
        return;
    }

    list(); // Display the product list

    cout << "\n____________________________\n";
    cout << "\n|   Please place the order   |";
    cout << "\n|____________________________|\n";

    do {
        cout << "\n\n Product Code: ";
        cin >> arrc[c];
        cout << "\n Product Quantity: ";
        cin >> arrq[c];

        bool duplicate = false;
        for (int i = 0; i < c; i++) {
            if (arrc[c] == arrc[i]) {
                cout << "\n\n Duplicate Product Code. Please try again!";
                duplicate = true;
                break;
            }
        }

        if (!duplicate) {
            c++;
        }

        cout << "\n\n Want to buy another product? Press y for yes and n for no: ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\n\n\t\t\t__________RECEIPT______________\n";
    cout << "\nProduct Num.\tProduct Name\tQuantity\tPrice\tAmount\tAmount with discount\n";

    data.clear(); // Clear EOF flag if set
    data.seekg(0); // Reset file read position to the beginning

    for (int i = 0; i < c; i++) {
        bool productFound = false;

        // Reset file read position to the beginning for each product search
        data.clear();
        data.seekg(0);

        while (data >> pcode >> pname >> price >> dis) {
            if (pcode == arrc[i]) {
                amount = price * arrq[i];
                discountedAmount = amount - (amount * dis / 100);
                total += discountedAmount;

                cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price
                     << "\t" << amount << "\t\t" << discountedAmount;

                productFound = true;
                break;
            }
        }

        if (!productFound) {
            cout << "\nProduct with code " << arrc[i] << " not found in the database.";
        }
    }

    data.close();

    cout << "\n\n----------------------------------------";
    cout << "\n Total Amount: " << total;
    cout << "\n----------------------------------------\n";
}

int main() {
    Shopping s;
    s.menu();
    return 0;
}