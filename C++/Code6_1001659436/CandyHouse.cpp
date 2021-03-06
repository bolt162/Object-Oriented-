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

#include "CandyHouse.h"
#include "House.h"

CandyHouse::CandyHouse(std::string name, std::map<int, std::string>candies):House{name,candies}
{

};

CandyHouse::~CandyHouse()
{
  std::cout << "CANDYHOUSE" << std::endl;
};

std::string CandyHouse::ringDoorbell(std::ostringstream &ostr)
{
	door.lock();
	ostr << "+";
	std::this_thread::sleep_for(std::chrono::seconds(3));
    int random = rand() % CandyRankingMap.size() + 1;
	door.unlock();
	std::string val = CandyRankingMap[random];
	return val;
}

