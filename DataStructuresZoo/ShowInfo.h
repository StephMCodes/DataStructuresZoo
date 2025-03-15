#pragma once
#include <string>
struct ShowInfo
{
protected://Show Info (start time, end time, activity, location, popularity level)
	int startingHour; //military time
	int endingHour; //military time
	std::string showTitle;
	std::string showLocation; 
	int popularityLevel; //from 1-5

public:

	ShowInfo(int startingHour, int endingHour, const std::string& showTitle, const std::string& showLocation, int popularityLevel)
		: startingHour(startingHour), endingHour(endingHour), showTitle(showTitle), showLocation(showLocation), popularityLevel(popularityLevel)
	{
	}
};

