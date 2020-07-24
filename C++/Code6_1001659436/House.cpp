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

#include "House.h"

House::House(std::string house, std::map<int, std::string> candies):houseName{house},CandyRankingMap{candies}
{

};

House::~House()
{
	std::cout << "HOUSE" << std::endl;
};