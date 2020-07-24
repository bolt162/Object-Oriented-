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

#include "TrickOrTreater.h"
#include "House.h"

int TrickOrTreater::ImDone = 0;

std::ostream& operator<<(std::ostream& info, TrickOrTreater& laststep)
{
     

    info << laststep.name << "'s - ";
	for(auto it = laststep.Bucket.cbegin(); it != laststep.Bucket.cend(); ++it)
	{
   	 	info << it->second << " "<< it->first << ", ";
	}
    return info;

}

TrickOrTreater::TrickOrTreater(std::string tots, std::vector<House*> house):name{tots},ListOfHouses{house}
{
	
};

void TrickOrTreater::GoTrickOrTreating()
{
	for (auto& m: ListOfHouses) 
	{
  		int speed = rand() % 500 + 1;
  		Walk(speed);
  		std::string candy = m->ringDoorbell(path);
  		Bucket[candy]++;
	}
	TrickOrTreater::ImDone++;
}
void TrickOrTreater::Walk(int speed)
{
	int i;
	for(i = 0; i <11;i++)
	{
		path << ".";
		std::this_thread::sleep_for(std::chrono::milliseconds(speed));
	}
}
std::string TrickOrTreater::getPath()
{
	return path.str();
}
std::string TrickOrTreater::getName()
{
	return name;
}
void TrickOrTreater::startThread()
{

	TOTThreadPtr = new std::thread(&TrickOrTreater::GoTrickOrTreating, this);

}
void TrickOrTreater::joinThread()
{

	this->TOTThreadPtr->join();
	delete this->TOTThreadPtr; 

}
