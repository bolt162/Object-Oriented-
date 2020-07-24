//Kartikey Sharma
//1001659436
#include <iostream>
#include <string>
#define price 60
using namespace std;
enum stat
{
    true1,
    true2,
    false1,
    false2,
    false3,
    false4
};
string displayMoney(int amount)
{
    string dollars{to_string(amount / 100)};
    string cents{to_string(abs(amount % 100))};
    string amt = "$" + dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
    return amt;
}
bool buypencils(int& inventory, int& change, int pencils, int& pay, stat& status)
{
    bool decision;
    if(inventory < pencils)
    {
        status = false1;
        decision = false;
        return decision;
    }
    else{
        if(pay == pencils*price)
        {
            status = true1;
            inventory = inventory-pencils;
            change = change + pay;
            decision = true;
        }
        else if(pay > pencils*price)
        {
            if(pay - pencils*price >change)
            {
                status = false2;
                decision = false;
            }
            else
            {
                status = true2;
                decision = true;
                inventory = inventory-pencils;
                change = change - (pay - pencils*price);
                change = change + pay;
            }
        }
        else if(pay < pencils*price)
        {
            status = false3;
            decision = false;
        }
        else
        {
            status = false4;
            decision = false;
        }
        return decision;
    }
}
int menu(int& choice)
{
    cout << "\nPlease choose from the following options\n\n" << endl;
    cout << "0. No pencil for me today\n1. Purchase pencils\n2. Check inventory level\n3. Check change level\n\nChoice : ";
    cin >> choice;
    return choice;
}
int main()
{
    stat status;
    bool decision;
    int choice;
    string diff;
    int pay;
    string total;
    int pencils;
    int inventory = 100;
    int change = 500;
    string mon;
    cout << "Welcome to my Pencil Machine" << endl;
    do
    {
        int flag = 1;
        choice = menu(choice);
        while(flag == 1){
            if(cin.fail()){
                cin.clear();
                cin.ignore(50, '\n');
                cout << "\nInput must be numeric, Please reenter " ;
                cin >>choice;
            }
            else{
                flag = 0;
            }
        }
        switch (choice)
        {
            case 0:
                break;
                
            case 1:
                mon = displayMoney(price);
                if( inventory == 0)
                {
                    cout << "There is no pencil left in the inventory" << endl;
                    break;
                }
                cout << "\nA pencil costs " << mon;
                cout << "\n\nHow many pencils would you like to purchase? ";
                cin >> pencils;
                flag = 1;
                while(flag == 1){
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(50, '\n');
                        cout << "\nInput must be numeric, Please reenter " ;
                        cin >>pencils;
                    }
                    else{
                        flag = 0;
                    }
                }
                if(pencils <=0)
                {
                    cout << "\nYou must purchase atleast one pencil"<< endl;
                    break;
                }
                if(inventory < pencils)
                {
                    cout << "\nThe machine does not have that many pencils - buy " << inventory << " or fewer." <<  endl;
                    break;
                }
                else
                {
                    total = displayMoney(pencils*price);
                    cout << "\nYour total is " << total;
                    cout << "\n\nEnter your Payment (in cents) ";
                    cin >> pay;
                    flag = 1;
                    while(flag == 1){
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(50, '\n');
                            cout << "\nInput must be numeric, Please reenter " ;
                            cin >>pay;
                        }
                        else{
                            flag = 0;
                        }
                    }
                    decision = buypencils(inventory, change, pencils, pay, status);
                    if(decision == 1)
                    {
                        if(status == 0)
                        {
                            cout << "\n\nHere's your pencils. Thank you for exact payment" << endl;
                        }
                        else
                        {
                            diff = displayMoney(pay-price*pencils);
                            cout << "\nHere's your pencils and your change of " << diff << endl;
                        }
                    }
                    else
                    {
                        if(status == 3)
                        {
                            cout << "\n\nThis pencil Dispencer does not have enough change and cannot accept your payment." << endl;
                        }
                        else if(status == 4)
                        {
                            cout << "\n\nInsufficient amount. No pencils for you." << endl;
                        }
                    }
                    break;
                }
            case 2:
                cout << "\nThe current inventory level is " << inventory << endl;
                break;
            
            case 3:
                cout << "\nThe current change level is " << change << endl;
                break;
                
            default:
                cout << "Invalid menu option" << endl;
        }
    }
    while(choice != 0);
    return 0;
}

