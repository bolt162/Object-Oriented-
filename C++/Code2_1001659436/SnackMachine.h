//Kartikey Sharma
//1001659436
#include <iostream>
#include <string>

enum stat
{
    suffpay,
    changegiven,
    noinventory,
    nochange,
    insuffpay,
    other
};
class SnackMachine
{
    public:
    SnackMachine(std::string name, int cost, int change, int inventory)
    :machineName{name}, SnackPrice{cost}, changeLevel{change}, inventoryLevel{inventory}
    {};
    std::string getMachineName()
        {
            return machineName;
        }
    bool buyASnack(int payment, std::string& change, int& status)
        {
            bool decision;
            if(inventoryLevel < 1)
            {
                status = noinventory;
                decision = false;
                return decision;
            }
            else
            {
                if(payment == SnackPrice)
                {
                    status = suffpay;
                    inventoryLevel = inventoryLevel-1;
                    changeLevel = changeLevel + payment;
                    decision = true;
                }
                else if(payment > SnackPrice)
                {
                    if(payment - SnackPrice > changeLevel)
                    {
                        status = nochange;
                        decision = false;
                    }
                    else
                    {
                        int diff;
                        status = changegiven;
                        decision = true;
                        inventoryLevel = inventoryLevel-1;
                        changeLevel = changeLevel - (payment - SnackPrice);
                        changeLevel = changeLevel + payment;
                        diff = payment - SnackPrice;
                        change = displayMoney(diff);
                    }
                }
                else if(payment < SnackPrice)
                {
                    status = insuffpay;
                    decision = false;
                }
                else
                {
                    status = other;
                    decision = false;
                }
                return decision;
            }
        }
        int getInventoryLevel()
        {
            return inventoryLevel;
        }
        int getMaxInventoryCapacity()
        {
            return maxInventoryCapacity;
        }
        bool incrementInventory(int amountToAdd)
        {
            if(amountToAdd+inventoryLevel>maxInventoryCapacity)
            {
                return false;
            }
            else
            {
                inventoryLevel = amountToAdd + inventoryLevel;
                return true;
            }
        }
        std::string getChangeLevel()
        {
            std::string changel = displayMoney(changeLevel);
            return changel;
        }
        bool incrementChangeLevel(int amountToAdd)
        {
            if(amountToAdd+changeLevel>maxChangeCapacity)
            {
                return false;
            }
            else
            {
                changeLevel = amountToAdd + changeLevel;
                return true;
            }
        }
        std::string getMaxChangeCapacity()
        {
            std::string maxcc = displayMoney(maxChangeCapacity);
            return maxcc;
        }
        std::string getSnackPrice()
        {
            std::string snackp = displayMoney(SnackPrice);
            return snackp;
        }
        std::string displayMoney(int amount)
        {
            std::string dollars{std::to_string(amount / 100)};
            std::string cents{std::to_string(abs(amount % 100))};
            std::string amt = "$" + dollars + "." + (cents.size() == 1 ? "0" : "") + cents;
            return amt;
        }
    private:
        std::string machineName;
        int changeLevel;
        int maxChangeCapacity = 5000;
        int SnackPrice;
        int inventoryLevel;
        int maxInventoryCapacity = 100;
};
