
#include <iostream>
#include <string>
#include "ShowInfo.h"
#include "Ticket.h"
#include "Animals.h"
#include "Mammal.h"
#include "IFly.h"
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
	/*VIPTicket vip;
	vip.SetClientName("Ellen Rivers");
	FamilyTicket family;
	family.SetClientName("Brennan Berkley");
	StudentElderTicket student;
	student.SetClientName("Melissa Adams");
	BasicTicket basic;
	basic.SetClientName("John Doe");*/

	TicketList allClients;

	//how it works
	//POINTERS
	//unique pointers handle the memory management for you
	//we use the make_unique function of std to allocate a spot in memory and return a pointer
	//this makes the object AND the pointer, saving us an extra line of code
	
	//NAMING CLIENT
	//we set the name with a method instead of hardcoding it so the user can enter the name they want
	//we use the arrow to access the attribute name
	
	//ENTERING CLIENT
	//we then add the pointer of the item to the list with std::move
	//this turns the pointer into a nullptr since it goes out of scope into the method
	//avoiding double deletion

	unique_ptr<VIPTicket> vipTicket = make_unique<VIPTicket>();
	vipTicket->SetClientName("Ellen Rivers");
	//(*vipTicket).SetClientName("Ellen Rivers"); other option via dereferencing
	//-> is shorthand for (*vipTicket) its an operator to help with dereferencng inside a pointer
	allClients.EnterZooReservation(move(vipTicket));

	unique_ptr<FamilyTicket> familyTicket = make_unique<FamilyTicket>();
	familyTicket->SetClientName("Brennan Berkley");
	allClients.EnterZooReservation(move(familyTicket));

	unique_ptr<StudentElderTicket> studentTicket = make_unique<StudentElderTicket>();
	studentTicket->SetClientName("Melissa Adams");
	allClients.EnterZooReservation(move(studentTicket));

	unique_ptr<BasicTicket> basicTicket = make_unique<BasicTicket>();
	basicTicket->SetClientName("John Doe");
	allClients.EnterZooReservation(move(basicTicket));

	allClients.DisplayZooReservations();

   //this is for the zoo
	cout << "Welcome to the Zoo!\n";

	//use the animals Test
	AddAnimals(jungleAnimals, desertAnimals, forestAnimals, arcticAnimals, aquaticAnimals);
	DisplayAllAnimals(jungleAnimals, desertAnimals, forestAnimals, arcticAnimals, aquaticAnimals);
	
	return 0;
	
}


