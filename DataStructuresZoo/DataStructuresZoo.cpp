
#include <iostream>
#include <string>
#include "ShowInfo.h"
#include "Ticket.h"
#include "Animals.cpp"
#include <vector>
using namespace std;

int main()
{
	//Animal Vectors to keep track of the animals + add them dynamically
	vector<Animal*> jungleAnimals;
	vector<Animal*> desertAnimals;
	vector<Animal*> forestAnimals;
	vector<Animal*> arcticAnimals;
	vector<Animal*> aquaticAnimals;


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

	//use the animals Test
	AddAnimals(jungleAnimals, desertAnimals, forestAnimals, arcticAnimals, aquaticAnimals);
	
	
	
}


