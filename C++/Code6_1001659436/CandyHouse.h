
//Kartikey Sharma 1001659436
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <thread>

#include "House.h"


#ifndef _CANDYHOUSE_H
#define _CANDYHOUSE_H

class CandyHouse : public House
{

	public:

		CandyHouse(std::string, std::map<int, std::string>);
		virtual ~CandyHouse();
		std::string ringDoorbell(std::ostringstream &);

};

#endif

