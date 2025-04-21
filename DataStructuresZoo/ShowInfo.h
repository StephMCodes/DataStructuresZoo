#pragma once
#include <string>
#include <queue>
#include <list>
#include <iostream>
#include "Ticket.h"
#include "Animals.h" 

using namespace std;

struct ShowInfo
{
protected://Show Info (start time, end time, activity, location, popularity level)
	int startingHour; //military time
	int endingHour; //military time
	std::string showTitle;
	std::string showLocation;
	int popularityLevel; //from 1-5
	//queue<Ticket> zooShowReservations; //the people in line
	//list of people in show


	//queue<Ticket*> showQueue;    // who’s waiting
	//list<Ticket*> watchingList;  // who’s inside

public:

	ShowInfo(int startingHour, int endingHour, const std::string& showTitle, const std::string& showLocation, int popularityLevel)
		: startingHour(startingHour), endingHour(endingHour), showTitle(showTitle), showLocation(showLocation), popularityLevel(popularityLevel)
	{
	}

	////get the title of the show
	//string GetShowTitle() const
	//{
	//	return showTitle;
	//}

	////adds to wait queue
	//void QueuePerson(Ticket* ticket)
	//{
	//	showQueue.push(ticket);
	//	cout << ticket->GetClientName() << " queued for " << showTitle << "\n";
	//}

	////move proritzed person from waiting to watch
	//void ProcessNextViewer()
	//{
	//	if (showQueue.empty())
	//	{
	//		cout << "No one's waiting for " << showTitle << "\n";
	//		return;
	//	}

	//	Ticket* next = showQueue.front();
	//	showQueue.pop();
	//	watchingList.push_back(next);

	//	cout << next->GetClientName() << " has entered the show: " << showTitle << "\n";

	//}

	////list of all peeps watching
	//void ShowAudienceList() const
	//{
	//	if (watchingList.empty())
	//	{
	//		cout << "No one's watching " << showTitle << "\n";
	//		return;
	//	}

	//	cout << "Audience in " << showTitle << ":\n";
	//	for (Ticket* viewer : watchingList)
	//	{
	//		viewer->DisplayTicketInfo();
	//	}
	//}

	////show ends & clears everyone 
	//void EndShow()
	//{
	//	int count = watchingList.size();
	//	watchingList.clear();
	//	cout << "Show \"" << showTitle << "\" ended — "<< count << " audience member(s) cleared.\n";
	//}
};

