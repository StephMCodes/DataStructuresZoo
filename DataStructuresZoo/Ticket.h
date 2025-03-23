#pragma once
#include <iostream>
#include <string>
#include <queue>

#include <list>
#include <memory>



struct Ticket
{
protected: //encapsulation
	//Ticket (VIP, family, basic)
	std::string type;
	int price;
	std::string clientName; //TO FIX AT SOME POINT (REFERENCES ANIMALS)

	//constructor is protected so it is abstract
	Ticket(const std::string& type, int price, std::string clientName)
		: type(type), price(price), clientName(clientName)
	{
	}

public:
	virtual ~Ticket() = default; // destructor

	//SETTER
	void SetClientName(const std::string& name) {
		clientName = name;
	}

	//display method
	//a simple read-only displaying method that needs to be public so it can be used
	void DisplayTicketInfo() const {
		std::cout << "Ticket Type: " << type << "\nPrice($): " << price << "\nName: " << clientName << std::endl;
	}

};

struct VIPTicket : Ticket
{
	VIPTicket() : Ticket("VIP Ticket", 100, "") {} // VIP costs $100 for full experience
};

struct FamilyTicket : Ticket
{
	FamilyTicket() : Ticket("Family Ticket", 50, "") {} // for family group
};

struct StudentElderTicket : Ticket
{
	StudentElderTicket() : Ticket("Student/Elder Discount Ticket", 10, "") {} // student discount
};

struct BasicTicket : Ticket
{
	BasicTicket() : Ticket("Basic Ticket", 20, "") {} // simple 20 dollar ticket
};

struct TicketList {
private:
	std::list<std::unique_ptr<Ticket>> zooTicketReservations;
	//we use smart pointers to have simpler memory management

	//this is where all clients are stored, there is a list for the ones in each biome
	//that are visiting the show and one for all clients

public:
	// Add a new reservation to the list (memory managed with unique_ptr)
	void EnterZooReservation(std::unique_ptr<Ticket> ticket) {
		zooTicketReservations.push_back(std::move(ticket)); // Transfer ptr to the list
		std::cout << "Ticket reservation entered into the list." << std::endl;
	}

	// Display reservations without modifying the list
	void DisplayZooReservations() const {
		if (zooTicketReservations.empty()) {
			std::cout << "No one's at the zoo right now." << std::endl;
			return;
		}

		std::cout << "Current list of zoo ticket holders: " << std::endl;
		for (const auto& ticket : zooTicketReservations) {
			ticket->DisplayTicketInfo();
			std::cout << "----------------------" << std::endl;
		}
	}

	// Clean up all reservations
	void ClearReservations() {
		if (zooTicketReservations.empty()) {
			std::cout << "No reservations to clear." << std::endl;
			return;
		}

		std::cout << "Processing and clearing all reservations..." << std::endl;
		zooTicketReservations.clear(); // Automatically cleans up memory via unique_ptr
		std::cout << "All zoo reservations cleared." << std::endl;
	}

	void AddTicket()
	{
		//user input for ticket
		int choice;
		std::string name;

		//null ptr
		std::unique_ptr<Ticket> ticket = nullptr;

		std::cout << "What kind of ticket are you creating?\n";
		std::cout << "------------------------\n";
		std::cout << "0: VIP Ticket\n";
		std::cout << "1: Family Ticket\n";
		std::cout << "2: Student/Elder Discount Ticket\n";
		std::cout << "3: Basic Ticket\n";
		std::cout << "------------------------\n";
		//loop asking until we break out with a correct answer
		while (true) {
			std::cin >> choice;
			std::cin.ignore();
			//check ignore

			// take input and validate
			while (!std::cin.good() || choice < 0 || choice > 3) {

				//clear console error flag. needs the overloads
				std::cin.clear();
				//clear console. needs the overloads
				std::cin.ignore(INT_MAX, '\n');

				std::cout << "Invalid input. Please enter a number between 0 and 3.\n";
				std::cin >> choice;
			}
			//input is valid!
			break;
		}

		switch (choice) {
		case 0:
			std::cout << "Creating VIP ticket.\n";
			ticket = std::make_unique<VIPTicket>();
			break;
		case 1:
			std::cout << "Creating family ticket.\n";
			ticket = std::make_unique<FamilyTicket>();
			break;
		case 2:
			std::cout << "Creating student/elder discount ticket.\n";
			ticket = std::make_unique<StudentElderTicket>();
			break;
		case 3:
			std::cout << "Creating basic ticket.\n";
			ticket = std::make_unique<BasicTicket>();
			break;
		default:
			std::cout << "Enter a number from 0 to 3." << std::endl;
			return;
		}

		std::cout << "Enter client name: ";
		std::getline(std::cin, name);

		ticket->SetClientName(name);
		EnterZooReservation(std::move(ticket));
	}
};

//improve ticket queue to avoid splicing by using unique ptrs here too
struct TicketQueue {
private:
	std::queue<Ticket> zooTicketQueue;
	//queues are data FIFO data structures
	//They are generally used for tickets, printing jobs, etc
	//WHEN TO USE THE QUEUE:
	//we use the queue for lining up people to see animal shows
	//They wait in line first come first serve until they can go become part of the list of
	//people in the show

public:
	//this function is not read-only because we modify the queue
	void EnterZooQueue(const Ticket& ticket) {
		zooTicketQueue.push(ticket); //push adds to queue
		std::cout << "Visitor entered into show queue." << std::endl;
	}
	//const aka read-only function
	void DisplayZooQueue() const {
		std::queue<Ticket> tempQueue = zooTicketQueue;
		//make temp queue to run through it and delete whats inside
		//that way all of todays reservations are not deleted
		if (tempQueue.empty()) {
			std::cout << "No visitors currently queued for the show." << std::endl;
			return;
		}
		std::cout << "Current waiting line for the show: " << std::endl;
		while (!tempQueue.empty()) {
			tempQueue.front().DisplayTicketInfo();
			std::cout << "----------------------" << std::endl;
			tempQueue.pop(); //remove first member of queue
		}
	}
};




