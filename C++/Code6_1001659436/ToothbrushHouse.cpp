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
#include <ctime>

#include "ToothbrushHouse.h"
#include "House.h"

ToothbrushHouse::ToothbrushHouse(std::string name, std::map<int, std::string> candies):House{name,candies}
{

};

ToothbrushHouse::~ToothbrushHouse()
{
  std::cout << "TOOTHBRUSHHOUSE" << std::endl;
};

std::string ToothbrushHouse::ringDoorbell(std::ostringstream &ostr)
{	
	door.lock();
	ostr << "-";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	door.unlock();
	std::string val = "Toothbrush";
	return val;
}