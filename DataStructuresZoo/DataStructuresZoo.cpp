
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
	string filename = "C:\\Users\\Chpcu\\OneDrive\\Desktop\\W2025\\Advanced Data Structures\\DataStructuresZoo\\DataStructuresZoo\\Animals.txt";
	//Animal Vectors to keep track of the animals + add them dynamically
	vector<Animal*> jungleAnimals;
	vector<Animal*> desertAnimals;
	vector<Animal*> forestAnimals;
	vector<Animal*> arcticAnimals;
	vector<Animal*> aquaticAnimals;

	TicketList allClients;

	int menuChoice;

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


   //this is for the zoo

	//loop asking until we break out with a correct answer
	while (true) {
		cout << "Welcome to the Zoo!\n";

		cout << "------------------------\n";
		cout << "0: Enter a new client's ticket\n";
		cout << "1: Display list of all tickets\n";
		cout << "2: Enter a new animal into the zoo\n";
		cout << "3: Display all current animals\n";
		cout << "4: Exit the application\n";
		cout << "------------------------\n";

		cout << "Enter your option:\n";
		std::cin >> menuChoice;
		std::cin.ignore();
		//check ignore

		// take input and validate
		//validation may need editing in future
		while (!std::cin.good() || menuChoice < 0 || menuChoice > 4) {

			//clear console error flag. needs the overloads
			std::cin.clear();
			//clear console. needs the overloads
			std::cin.ignore(INT_MAX, '\n');

			std::cout << "Invalid input. Please enter a number between 0 and 3.\n";
			std::cin >> menuChoice;
			std::cin.ignore();
		}
		//input is valid!


		switch (menuChoice) {
		case 0:
			//enter new client
			allClients.AddTicket();
			break;
		case 1:
			//display tickets
			allClients.DisplayZooReservations();
			break;
		case 2:
			//Add an animal
			AddAnimals(jungleAnimals, desertAnimals, forestAnimals, arcticAnimals, aquaticAnimals);
			break;
		case 3:
			//display
			DisplayAllAnimals(jungleAnimals, desertAnimals, forestAnimals, arcticAnimals, aquaticAnimals);
			break;
		case 4:
			// close
			std::cout << "Goodbye! Closing the zoo...\n";
			return 0;
		default:
			std::cout << "Enter a number from 0 to 3." << std::endl;
		}
		//loop menu
	}

	//ticket creation test
	//allClients.AddTicket();
	//use the animals Test
	LoadFromFiles(filename, jungleAnimals, desertAnimals, forestAnimals, arcticAnimals, aquaticAnimals);
	//AddAnimals(jungleAnimals, desertAnimals, forestAnimals, arcticAnimals, aquaticAnimals);
	DisplayAllAnimals(jungleAnimals, desertAnimals, forestAnimals, arcticAnimals, aquaticAnimals);
	
	return 0;
	
}



//unique_ptr<VIPTicket> vipTicket = make_unique<VIPTicket>();
//vipTicket->SetClientName("Ellen Rivers");
////(*vipTicket).SetClientName("Ellen Rivers"); other option via dereferencing
////-> is shorthand for (*vipTicket) its an operator to help with dereferencng inside a pointer
//allClients.EnterZooReservation(move(vipTicket));

//unique_ptr<FamilyTicket> familyTicket = make_unique<FamilyTicket>();
//familyTicket->SetClientName("Brennan Berkley");
//allClients.EnterZooReservation(move(familyTicket));

//unique_ptr<StudentElderTicket> studentTicket = make_unique<StudentElderTicket>();
//studentTicket->SetClientName("Melissa Adams");
//allClients.EnterZooReservation(move(studentTicket));

//unique_ptr<BasicTicket> basicTicket = make_unique<BasicTicket>();
//basicTicket->SetClientName("John Doe");
//allClients.EnterZooReservation(move(basicTicket));


