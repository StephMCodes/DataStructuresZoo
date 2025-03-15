// DataStructuresZoo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "ShowInfo.h"
#include "Ticket.h"

int main()
{
	//use queue of purchased tickets
	VIPTicket vip;
	vip.clientName = "Ellen Rivers";
	FamilyTicket family;
	family.clientName = "Brennan Berkley";
	StudentElderTicket student;
	student.clientName = "Melissa Adams";
	BasicTicket basic;
	basic.clientName = "John Doe";
	TicketQueue queue;
	queue.EnterZooReservation(vip);
	queue.EnterZooReservation(family);
	queue.EnterZooReservation(student);
	queue.EnterZooReservation(basic);
	queue.DisplayZooReservations();

   //this is for the zoo
	std::cout << "Welcome to the Zoo!\n";

	
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
