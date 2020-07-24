
//Kartikey Sharma 1001659436
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <mutex>
#include <thread>

#include "House.h"


#ifndef _TTHOUSE_H
#define _TTHOUSE_H



class ToothbrushHouse : public House
{

	public:

		ToothbrushHouse(std::string, std::map<int, std::string>);
		virtual ~ToothbrushHouse();
		std::string ringDoorbell(std::ostringstream &);

};

#endif
