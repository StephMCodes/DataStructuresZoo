
#include <iostream>
#include "limits.h"
#include <string>
#include <vector>
#include <map>
#include "ShowInfo.h"
#include "Ticket.h"
#include "Animals.h"
#include "Mammal.h"
#include "IFly.h"


using namespace std;

// Function to wait for a key press
static void WaitForKeyPress()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Press Enter to continue...";
	std::cin.get();
}

int main()
{
	//relative file path
	string filename = "./Animals.txt";
	string keyword;
	//Animal Vectors to keep track of the animals + add them dynamically
	vector<Animal*> jungleAnimals;
	vector<Animal*> desertAnimals;
	vector<Animal*> forestAnimals;
	vector<Animal*> arcticAnimals;
	vector<Animal*> aquaticAnimals;

	//map shows 1 per biome
	/*map<Habitat, vector<ShowInfo>> biomeShows; 
	
	{
		ShowInfo jungleShow(10, 12, "Sassy Birdies", "Jungle Dome", 4);
		biomeShows[Habitat::Jungle].push_back(jungleShow);

		ShowInfo desertShow(11, 13, "Hi-enas Delight", "Desert Arena", 3);
		biomeShows[Habitat::Desert].push_back(desertShow);

		ShowInfo forestShow(12, 14, "Lion King Who", "Forest Clearing", 5);
		biomeShows[Habitat::Forest].push_back(forestShow);

		ShowInfo arcticShow(13, 15, "Penguin Stampede", "Arctic Circle", 4);
		biomeShows[Habitat::Arctic].push_back(arcticShow);

		ShowInfo aquaticShow(14, 16, "Eerie Dolphin Sways", "Aquatic Arena", 5);
		biomeShows[Habitat::Aquatic].push_back(aquaticShow);
	}*/


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

	LoadFromFiles(filename, jungleAnimals, desertAnimals, forestAnimals, arcticAnimals, aquaticAnimals); 
	//loop asking until we break out with a correct answer
	while (true) {
		cout << "\nWelcome to the Zoo!\n";

		cout << "------------------------\n";
		cout << "0: Enter a new client's ticket\n";
		cout << "1: Display list of all tickets\n";
		cout << "2: Enter a new animal into the zoo\n";
		cout << "3: Display all current animals\n";
		cout << "4: Search animals using keyword\n";
		cout << "5: Exit the application\n";
		cout << "------------------------\n";

		cout << "Enter your option:\n";
		std::cin >> menuChoice;
		//we dont want the user to send further input with white spaces and other strings
		
		std::cin.ignore(INT_MAX, '\n');
		//std::cin.ignore();
		//check ignore

		// take input and validate
		//validation may need editing in future
		while (!std::cin.good() || menuChoice < 0 || menuChoice > 5) {

			//clear console error flag. needs the overloads
			std::cin.clear();
			//clear console. needs the overloads
			//std::cin.ignore(INT_MAX, '\n');

			std::cout << "Invalid input. Please enter a number between 0 and 5.\n";
			std::cin >> menuChoice;
			std::cin.ignore(INT_MAX, '\n');
		}
		//input is valid!


		switch (menuChoice) {
		case 0:
			//enter new client
			allClients.AddTicket();
			//allClients.AddTicket(biomeShows);//failed attempt
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
			WaitForKeyPress();
			break;
		case 4:
			std::cout << "Please enter your keyword search: \n";
			std::getline(cin, keyword);
			SearchAnimalsThroughKeyword(keyword, jungleAnimals, desertAnimals, forestAnimals, arcticAnimals, aquaticAnimals);
			WaitForKeyPress();
			break;
		case 5:
			// close
			ClearAnimals(jungleAnimals);
			ClearAnimals(desertAnimals);
			ClearAnimals(forestAnimals);
			ClearAnimals(arcticAnimals);
			ClearAnimals(aquaticAnimals);
			std::cout << "Goodbye! Closing the zoo...\n";
			return 0;
		default:
			std::cout << "Enter a number from 0 to 5." << std::endl;
		}
		//loop menu
	}

	//ticket creation test
	//allClients.AddTicket();
	//use the animals Test
	
	//AddAnimals(jungleAnimals, desertAnimals, forestAnimals, arcticAnimals, aquaticAnimals);
	//DisplayAllAnimals(jungleAnimals, desertAnimals, forestAnimals, arcticAnimals, aquaticAnimals);
	
	return 0;
	
}





