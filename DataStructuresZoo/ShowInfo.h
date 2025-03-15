#pragma once
#include <string>
struct ShowInfo
{
	//Show Info (start time, end time, activity, location, popularity level)
	int startingHour; //military time
	int endingHour; //military time
	std::string location; 
	int popularityLevel; //from 1-5

};

