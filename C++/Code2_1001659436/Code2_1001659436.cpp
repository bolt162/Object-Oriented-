//Kartikey Sharma
//1001659436
#include <iostream>
#include <string>
#include "SnackMachine.h"
using namespace std;

int menu(int& choice)
{
    cout << "\nPlease choose from the following options\n\n" << endl;
    cout << "0. Walk away\n1. Buy a Snack\n2. Restock Machine\n3. Add Change\n4. Display Machine Info\nChoice : ";
    cin >> choice;
    return choice;
}
int main()
{
    SnackMachine MySnackMachine = {"CSE 1325 Snack Machine", 50, 500, 100};
    int status;
    bool decision;
    int choice;
    string diff;
    int pay;
    string total;
    int snacks;
    int amount;
    string mon;
    cout << MySnackMachine.getMachineName() << endl;
    do
    {
        int flag = 1;
        choice = menu(choice);
        while(flag == 1)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(50, '\n');
                cout << "\nInput must be numeric, Please reenter " ;
                cin >>choice;
            }
            else
            {
                flag = 0;
            }
        }
        switch (choice)
        {
            case 0:
            {
                cout << "\n\nAre you sure you are'nt really HUNGRY and need a snack?" <<endl;
                break;
            }
            case 1:
            {
                mon = MySnackMachine.getSnackPrice();
                cout << "\nA snack costs " << mon;
                flag = 1;
                while(flag == 1)
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(50, '\n');
                        cout << "\nInput must be numeric, Please reenter " ;
                        cin >>snacks;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
                cout << "\n\nInsert Payment ";
                cin >> pay;
                flag = 1;
                while(flag == 1)
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(50, '\n');
                        cout << "\nInput must be numeric, Please reenter " ;
                        cin >>pay;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
                decision = MySnackMachine.buyASnack(pay, diff, status);
                if(decision == true)
                {
                    if(status == suffpay)
                    {
                        cout << "\n\nHere's your snack. Thank you for exact payment" << endl;
                    }
                    else if(status == changegiven)
                    {
                        cout << "\nHere's your snacks and your change of " << diff << endl;
                    }
                }
                else
                {
                    if(status == nochange)
                    {
                        cout << "\n\nThis snack Dispencer does not have enough change and cannot accept your payment." << endl;
                    }
                    else if(status == insuffpay)
                    {
                        cout << "\n\nInsufficient payment....returning your payment" << endl;
                    }
                }
                break;
            }
            case 2:
            {
                cout << "\nHow much product are you adding to the machine? ";
                cin >> amount;
                if(MySnackMachine.incrementInventory(amount) == true)
                {
                    cout << "\nYour inventory has been updated\n" << endl;
                    cout << "Your inventory level is now " << MySnackMachine.getInventoryLevel() << endl;
                }
                else
                {
                    cout << "You have exceeded your machine's max capacity" << endl;
                }
                break;
            }
            case 3:
            {
                cout << "\nHow much change are you adding to the machine? ";
                cin >> amount;
                if(MySnackMachine.incrementChangeLevel(amount) == true)
                {
                    cout << "\nYour change has been updated\n" << endl;
                    cout << "Your change level is now " << MySnackMachine.getChangeLevel() << endl;
                }
                else
                {
                    cout << "You have exceeded your machine's max change capacity" << endl;
                }
                break;
            }
            case 4:
            {
                cout << "\n\nCurrent Inventory Level " << MySnackMachine.getInventoryLevel();
                cout << "\n\nMax Inventory Level " << MySnackMachine.getMaxInventoryCapacity();
                string clevel = MySnackMachine.getChangeLevel();
                cout << "\n\nCurrent Change Level " << MySnackMachine.getChangeLevel();
                cout << "\n\nMax Change Level " << MySnackMachine.getMaxChangeCapacity();
                cout << "\n\nCost of a snack " << MySnackMachine.getSnackPrice() << endl;
                break;
            }
            default:
                cout << "\n\nYou must enter a value between 0-4\n" << endl;
        }
    }
    while(choice != 0);
    return 0;
}
