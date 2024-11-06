#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;

void menu();
class ManageMenu
{
protected:
    string userName;

public:
    ManageMenu()
    {
        system("color 0A"); //changing terminal color
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t Enter Your Name to Continue as an Admin : ";
        cin >> userName;
        system("CLS");
        menu();
    }
    ~ManageMenu() {}
};

// creating classes
class Customers
{
public:
    string name, gender, address;
    int age, mobileNo;
    static int cusId;
    char all[999];

    void getDetails()
    {
        ofstream out("old-customers.txt", ios::app);
        {
            cout << "Enter Customer Id : ";
            cin >> cusId;
            cout << "Enter Name : ";
            cin >> name;
            cout << "Enter Age : ";
            cin >> age;
            cout << "Enter MobileNo. : ";
            cin >> mobileNo;
            cout << "Enter Address : ";
            cin >> address;
            cout << "Enter Gender. : ";
            cin >> gender;
        }

        out << "\nCustomer Id : " << cusId << "\nName : " << name << "\nAge : " << age << "\nGender : " << gender << "\nMobile No. : " << mobileNo << "\nAddress : " << address << endl;

        out.close();
        cout << "\nSAVED \nNote : We save your details for future purpose\n"
             << endl;
    }

    void showDetails()
    {
        ifstream in("old-customers.txt");
        {
            if (!in)
            {
                cout << "File Error" << endl;
            }
            while (!(in.eof()))
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }
    }
};

class Cabs
{
public:
    int cabChoice;
    int kilometer;
    float cabCost;
    static float lastCabCost;

    void cabDetails()
    {
        cout << "We collaborates with fastest, safest and smartest cab service around the city" << endl;
        cout << "\n------------ABC Cabs Services------------\n"
             << endl;
        cout << "1. Rent a Standard Cab - Rs. 15 per 1KM" << endl;
        cout << "2. Rent a Luxury Cab - Rs. 25 per 1KM" << endl;

        cout << "\nTo calculate the cost for your journey : " << endl;
        cout << "Which kind of cab you need : ";
        cin >> cabChoice;

        cout << "Enter Kilometers you have : ";
        cin >> kilometer;

        int hireCab;

        if (cabChoice == 1)
        {
            cabCost = kilometer * 15;
            cout << "\nYour tour cost " << cabCost << " rupees for a Standard Cab" << endl;
            cout << "Press 1 to hire cab or" << endl;
            cout << "Press 2 to select another cab :";
            cin >> hireCab;

            system("CLS");

            if (hireCab == 1)
            {
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired a Standard cab" << endl;
                cout << "Goto Menu and take the Receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();
            }
            else
            {
                cout << "Invalid Inputs! Redirecting to previous menu \n Please Wait!" << endl;
                Sleep(2000);
                system("CLS");
                cabDetails();
            }
        }
        else if (cabChoice == 2)
        {
            cabCost = kilometer * 25;
            cout << "\nYour tour cost " << cabCost << " rupees for a Luxury Cab" << endl;
            cout << "Press 1 to hire cab or" << endl;
            cout << "Press 2 to select another cab :";
            cin >> hireCab;

            system("CLS");

            if (hireCab == 1)
            {
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired a Luxury cab" << endl;
                cout << "Goto Menu and take the Receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();
            }
            else
            {
                cout << "Invalid Inputs! Redirecting to previous menu \n Please Wait!" << endl;
                Sleep(2000);
                system("CLS");
                cabDetails();
            }
        }
        else
        {
            cout << "Invalid Inputs! Redirecting to Main menu \n Please Wait!" << endl;
            Sleep(2000);
            system("CLS");
            menu();
        }
        cout << "\nPress 1 to redirect Main Menu : ";
        cin >> hireCab;
        system("CLS");
        if (hireCab == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
};

class Booking
{
public:
    int choiceHotel;
    int packChoice;
    static float hotelCost;

    void hotels()
    {
        string hotel1No[] = {"Avendra", "LuxuryChoice", "Elephenta"};
        for (int a = 0; a < 3; a++)
        {
            cout << a + 1 << ". " << hotel1No[a] << endl;
        }
        cout << "\nCurrently we Colleborated with above Hotels!!" << endl;

        cout << "Press any key to back or \nEnter hotel number you want to book: ";
        cin >> choiceHotel;

        system("CLS");

        if (choiceHotel == 1)
        {
            cout << "----------WELCOME TO HOTEL AVENDRA----------\n"
                 << endl;
            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;
            cout << "Packages offered by Avendra: \n"
                 << endl;
            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for : Rs. 5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium at : Rs.10000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tLive a Luxury at Avendra : Rs.15000.00" << endl;

            cout << "\nPress another key to back or \nEnter package number you want to book : ";
            cin >> packChoice;

            if (packChoice == 1)
            {
                hotelCost = 5000.00;
                cout << "\nYou have successfully booked Standard Pack at Avendra" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice == 2)
            {
                hotelCost = 10000.00;
                cout << "\nYou have successfully booked Premium Pack at Avendra" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice == 3)
            {
                hotelCost = 15000.00;
                cout << "\nYou have successfully booked Luxury Pack at Avendra" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Inalid Input! Redirecting to previous Menu \nPlease Wait!" << endl;
                Sleep(2000);
                system("CLS");
                hotels();
            }

            int gotoMenu;
            cout << "\nPress 1 to redirect to main menu : ";
            cin >> gotoMenu;
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else if (choiceHotel == 2)
        {
            cout << "----------WELCOME TO HOTEL LuxuryChoice----------\n"
                 << endl;
            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;
            cout << "Packages offered by LuxuryChoice: \n"
                 << endl;
            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for : Rs. 5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium at : Rs.10000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tLive a Luxury at LuxuryChoice : Rs.15000.00" << endl;

            cout << "\nPress another key to back or \nEnter package number you want to book : ";
            cin >> packChoice;

            if (packChoice == 1)
            {
                hotelCost = 5000.00;
                cout << "\nYou have successfully booked Standard Pack at LuxuryChoice" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice == 2)
            {
                hotelCost = 10000.00;
                cout << "\nYou have successfully booked Premium Pack at LuxuryChoice" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice == 3)
            {
                hotelCost = 15000.00;
                cout << "\nYou have successfully booked Luxury Pack at LuxuryChoice" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Inalid Input! Redirecting to previous Menu \nPlease Wait!" << endl;
                Sleep(2000);
                system("CLS");
                hotels();
            }

            int gotoMenu;
            cout << "\nPress 1 to redirect to main menu : ";
            cin >> gotoMenu;
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else if (choiceHotel == 3)
        {
            cout << "----------WELCOME TO HOTEL Elephenta----------\n"
                 << endl;
            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;
            cout << "Packages offered by Elephenta: \n"
                 << endl;
            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for : Rs. 5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium at : Rs.10000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tLive a Luxury at Elephenta : Rs.15000.00" << endl;

            cout << "\nPress another key to back or \nEnter package number you want to book : ";
            cin >> packChoice;

            if (packChoice = 1)
            {
                hotelCost = 5000.00;
                cout << "\nYou have successfully booked Standard Pack at Elephenta" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice == 2)
            {
                hotelCost = 10000.00;
                cout << "\nYou have successfully booked Premium Pack at Elephenta" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice == 3)
            {
                hotelCost = 15000.00;
                cout << "\nYou have successfully booked Luxury Pack at Elephenta" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Inalid Input! Redirecting to previous Menu \nPlease Wait!" << endl;
                Sleep(2000);
                system("CLS");
                hotels();
            }

            int gotoMenu;
            cout << "\nPress 1 to redirect to main menu : ";
            cin >> gotoMenu;
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            cout << "Invalid Input! Redirecting to previous menu \nPlease wait" << endl;
            Sleep(2000);
            system("CLS");
            menu();
        }
    }
};

float Cabs::lastCabCost;
float Booking::hotelCost;
int Customers::cusId;

class Charges : public Booking, Cabs, Customers
{
public:
    void printBill()
    {
        ofstream outf("receipt.txt");
        {
            outf << "----------ABC Travel Agency----------" << endl;
            outf << "--------------Receipt----------------" << endl;
            outf << "_____________________________________" << endl;

            outf << "Customer ID: " << Customers::cusId << endl
                 << endl;
            outf << "Description\t\t Total" << endl;
            outf << "Hotel cost:\t\t" << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "Travel (cab) cost:\t" << fixed << setprecision(2) << Cabs::lastCabCost << endl;
            outf << "_____________________________________" << endl;
            outf << "Total Charge: \t\t" << fixed << setprecision(2) << Booking::hotelCost + Cabs::lastCabCost << endl;
            outf << "_____________________________________" << endl;
            outf << "----------------THANK YOU------------" << endl;
        }

        outf.close();
    }

    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if (!inf)
            {
                cout << "File Opening Error!!" << endl;
            }
            while (!(inf.eof()))
            {
                inf.getline(all, 999);
                cout << all << endl;
            }
            inf.close();
        }
    }
};

void menu()
{
    int mainChoice;
    int inChoice;
    int gotoMenu;

    cout << "\t\t     *ABC Travels*       \n"
         << endl;
    cout << "\t---------------MAIN MENU----------------" << endl;
    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tBookings Management -> 3\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 4\t|" << endl;
    cout << "\t|\tExit                -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Your Choice: ";
    cin >> mainChoice;
    system("CLS");

    Customers a2;
    Cabs a3;
    Booking a4;
    Charges a5;

    if (mainChoice == 1)
    {
        cout << "----------Customers----------\n"
             << endl;
        cout << "1. Enter New Customer" << endl;
        cout << "2. See Old Customer" << endl;

        cout << "\nEnter Choice : ";
        cin >> inChoice;
        system("CLS");
        if (inChoice == 1)
        {
            a2.getDetails();
        }
        else if (inChoice == 2)
        {
            a2.showDetails();
        }
        else
        {
            cout << "Invalid Input! Redirecting to previous menu \nPlease wait" << endl;
            Sleep(2000);
            system("CLS");
            menu();
        }
        cout << "\nPress 1 to redirect Main menu : " << endl;
        cin >> gotoMenu;
        system("CLS");
        if (gotoMenu == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
    else if (mainChoice == 2)
    {
        a3.cabDetails();
    }
    else if (mainChoice == 3)
    {
        cout << "---->Book a luxury Hotel using the system <---" << endl;
        a4.hotels();
    }
    else if (mainChoice == 4)
    {
        cout << "---> Get your receipt <---" << endl;
        a5.printBill();
        cout << "Your receipt is already printed you can get it from file path\n"
             << endl;
        cout << "to display your receipt on the screen, Enter 1: or Enter another key to back in main menu : ";

        cin >> gotoMenu;
        if (gotoMenu == 1)
        {
            system("CLS");
            a5.showBill();
            cout << "\nPress 1 to redirect main menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            system("CLS");
            menu();
        }
    }
    else if (mainChoice == 5)
    {
        cout << "----GOOD BYE----" << endl;
        Sleep(6969);
        system("CLS");
        menu();
    }
    else
    {
        cout << "Invalid Input! Redirecting to previous menu \nPlease wait" << endl;
        Sleep(2000);
        system("CLS");
        menu();
    }
}

int main()
{
    ManageMenu startObj;

    return 0;
}
