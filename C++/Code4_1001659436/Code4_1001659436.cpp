/******************************
*		Kartikey Sharma		  *
*			1001659436		  *
******************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <map>

#include "House.h"
#include "TrickOrTreater.h"

using namespace std;

void get_command_line_params(int argc, char *argv[], string& input, string& output, string& one_more)
{
    if(argc!=4)
    {
        throw invalid_argument("Missing command line parameters – - Usage : input^filename output^filename");
    }
    input = argv[1];
    output = argv[2];
    one_more = argv[3];
}

int main(int argc, char *argv[])
{
    srand(time(0));
	string housefilename;
	string housefileline;
	string totsfilename;
	string totsfileline;
	string candyfilename;
	string candyfileline;
	string line;
	string value;
	int key;
	int count= 0;
	try
	{
		get_command_line_params(argc, argv, totsfilename, housefilename, candyfilename);
	}
	catch(invalid_argument& message)
	{
		cout << "An error occurred: " << message.what() << endl;
		exit(0);
	}

	ifstream candyfile (candyfilename, ios::in);
	map <int, string> candies;
	vector<House*> house;
	ostringstream loh;
	vector<TrickOrTreater>TOTs;
	if(candyfile.is_open())
	{
		while(getline(candyfile,candyfileline))
		{
			char * cstr = new char [candyfileline.length()+1];
  			strcpy (cstr, candyfileline.c_str());

  			// cstr now contains a c-string copy of str
  			char * p = strtok (cstr,"|");
  			while (p!=0)
  			{	
  				count++;
  				if(count %2 == 0)
  				{
  					key = stoi(p);
  					candies[key] = value;
  				}
  				else
  				{
  					value = p;
  				}
    			p = strtok(NULL," ");
  			}

  			delete[] cstr;
		}
	}
	else
	{
		cout << "Unable to open the candyfile" << endl;
	}

	ifstream housefile(housefilename, ios::in);
	int i = 0;
	House* temp;
	if(housefile.is_open())
    {
        while(getline(housefile, housefileline))
        {	
        	loh << housefileline;
        	int size = housefileline.size();
        	for(i = 0; i <=(11-size); i++)
    		{
    			loh << " ";
    		}
        	temp = new House(housefileline, candies);
    		house.push_back(temp);
        }
    }
    else
    {
    	cout << "Unable to open the housefile" << endl;
    }

    ifstream totsfile(totsfilename, ios::in);

    if(totsfile.is_open())
    {
    	while(getline(totsfile, totsfileline))
    	{

    	    TOTs.push_back(TrickOrTreater{totsfileline,house});

    	}
    }
    else
    {
    	cout << "Unable to open the totsfile" << endl;
    }

    for(auto &m : TOTs)
    {
    	m.startThread();
    }

    i = 0;
    while (TrickOrTreater::ImDone != TOTs.size() )
	{
		for(int i = 0; i < 80; i++)
		{
			cout << "\n";
		}
		cout << "           ";
		cout << loh.str();
		cout << "\n";
		for (auto &m : TOTs)
		{
			cout << m.getPath() << m.getName() << endl;
		}
		this_thread::sleep_for(chrono::milliseconds(5));
	}

    for(auto &m :TOTs)
    {
    	cout << m << endl;
    }
    for(auto &it : TOTs)
    {
    	it.joinThread();
    }
    delete temp;
    housefile.close();
    totsfile.close();
    candyfile.close();
	return 0;

}
