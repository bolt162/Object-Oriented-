//Kartikey Sharma
//1001659436

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "SnackMachine.h"
#include "SnackLib.h"

using namespace std;
void get_command_line_params(int argc, char *argv[], string& input, string& output)
{
    if(argc!=3)
    {
        throw invalid_argument("Missing command line parameters – - Usage : input^filename output^filename");
    }
    input = argv[1];
    output = argv[2];
}

int menu(int& choice)
{
    cout << "\nPlease choose from the following options\n\n" << endl;
    cout << "0. Walk away\n1. Buy a Snack\n2. Restock Machine\n3. Add Change\n4. Display Machine Info\n5. Update Machine Name\n6. Update Snack Price\n\nChoice : ";
    cin >> choice;
    return choice;
}

int main(int argc, char *argv[])
{
    SnackMachine myMachine;
    vector <SnackMachine> SetOfSnackMachines;
    vector<string> ConstructorValues(4);
    string input;
    string output;
    int fchoice;
    int mach;
    string SnackMachineLine;
    int status;
    bool decision;
    bool dec;
    int choice;
    string diff;
    int pay;
    int tflag;
    string total;
    int snacks;
    int amount;
    string mon;
    string newMachineName;
    int newSnackPrice;
    try
    {
      get_command_line_params(argc, argv, input, output);
    }
    catch(invalid_argument& msg)
    {
      cout << msg.what() << endl;
      exit(0);
    }
    ifstream SnackInputFile{input};
    ofstream SnackOutputFile;
    SnackOutputFile.open(output, ios::out);
    if(SnackInputFile.is_open())
    {
        while(getline(SnackInputFile, SnackMachineLine))
        {
            dec = ParseSnackLine(SnackMachineLine, ConstructorValues);
            if(dec == true)
            {
                SnackMachine temp{ConstructorValues.at(0),stoi(ConstructorValues.at(1)),stoi(ConstructorValues.at(2)),stoi(ConstructorValues.at(3))};
                SetOfSnackMachines.push_back(temp);
            }
        }
    }
    else
    {
        cout << "\nUnable to open the file" << endl;
        exit(0);
    }
    do{
        cout << "\n\nPick a SnackMachine: \n0. Exit" << endl;
        for(mach = 0; mach < SetOfSnackMachines.size(); mach++)
        {
            cout << mach+1 << ". " << SetOfSnackMachines.at(mach).getMachineName() << endl;
        }
        cout << mach+1 << ". Add a new Machine" << endl;
        cout << "\nEnter choice: ";
        cin >> fchoice;
        if(fchoice == 0)
        {
          tflag = 1;
        }
        else if (fchoice == mach+1)
        {
          SetOfSnackMachines.push_back(myMachine);
				  cout << "\nNew machine added"<<endl;
        }
        else
        {
          do
          {
              cout << SetOfSnackMachines.at(fchoice-1).getMachineName() << endl;
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
                    cout << "\n\nAre you sure you are'nt really HUNGRY and need a snack?"   <<endl;
                    break;
                  }
                  case 1:
                  {
                    mon = SetOfSnackMachines[fchoice-1].getSnackPrice();
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
                    decision = SetOfSnackMachines[fchoice-1].buyASnack(pay, diff, status);
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
                    if(SetOfSnackMachines[fchoice-1].incrementInventory(amount) == true)
                    {
                        cout << "\nYour inventory has been updated\n" << endl;
                        cout << "Your inventory level is now " << SetOfSnackMachines[fchoice-1].getInventoryLevel() << endl;
                    }
                    else
                    {
                        cout << "You have exceeded your machine's max capacity" << endl;
                        cout << "\n\nCurrent Inventory Level " << SetOfSnackMachines[fchoice-1].getInventoryLevel();
                    }
                    break;
                  }
                  case 3:
                  {
                      cout << "\nHow much change are you adding to the machine? ";
                      cin >> amount;
                      if(SetOfSnackMachines[fchoice-1].incrementChangeLevel(amount) == true)
                      {
                          cout << "\nYour change has been updated\n" << endl;
                          cout << "Your change level is now " << SetOfSnackMachines[fchoice-1].getChangeLevel() << endl;
                      }
                      else
                      {
                          cout << "You have exceeded your machine's max change capacity" << endl;
                          cout << "\n\nCurrent Change Level " << SetOfSnackMachines[fchoice-1].getChangeLevel();
                      }
                      break;
                    }
                    case 4:
                    {
                        cout << SetOfSnackMachines.at(fchoice-1);
                        break;
                    }
                    case 5:
                    {
                          cin.ignore(10,'\n');
                          cout << "\n\nEnter a new Machine Name: ";
                          getline(cin, newMachineName);
                          SetOfSnackMachines[fchoice-1].setMachineName(newMachineName);
                          cout << "\nMachine Name has been updated" << endl;
                          break;
                    }
                    case 6:
                    {
                          cout << "\n\nEnter new Snack Price: ";
                          cin >> newSnackPrice;
                          SetOfSnackMachines[fchoice-1].setSnackPrice(newSnackPrice);
                          cout << "\nSnack Price has been updated" << endl;
                          break;
                      }
                        default:
                        cout << "\n\nYou must enter a value between 0-4\n" << endl;
                  }
              }while(choice != 0);

          }
        }while(tflag !=1);
        if(tflag ==1)
        {
            for(int i = 0; i < SetOfSnackMachines.size(); i++)
            {
              SnackOutputFile << CreateSnackOutputLine(SetOfSnackMachines.at(i)) << endl;
            }
        }
        SnackInputFile.close();
        SnackOutputFile.close();
        return 0;
}
