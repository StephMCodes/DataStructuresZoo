#pragma once
#include <iostream>
#include <string>
#include <queue>

struct Ticket
{
protected: //encapsulation
	//Ticket (VIP, family, classic) <- add the price
	std::string type;
	int price;
public:
    std::string clientName;
protected:
	//constructor is protected so it is abstract
	Ticket(const std::string& type, int price, std::string clientName)
		: type(type), price(price), clientName(clientName)
	{
	}
public: //a simple read-only displaying method that needs to be public so it can be used
	void DisplayTicketInfo() const {
		std::cout << "Ticket Type: " << type << "\nPrice($): " << price << "\nName: " << clientName << std::endl;
	}
	
};

struct VIPTicket : Ticket
{
	VIPTicket() : Ticket("VIP Ticket", 100, "Name") {} // VIP costs $100 for full experience
};

struct FamilyTicket : Ticket
{
	FamilyTicket() : Ticket("Family Ticket", 50, "Name") {} // for family group
};

struct StudentElderTicket : Ticket
{
    StudentElderTicket() : Ticket("Student/Elder Discount Ticket", 10, "Name") {} // student discount
};

struct BasicTicket : Ticket
{
	BasicTicket() : Ticket("Basic Ticket", 20, "Name") {} // simple 20 dollar ticket
};

struct TicketQueue {
private:
    std::queue<Ticket> zooTicketReservations;
    //queues are data FIFO data structures
    //They are generally used for tickets, printing jobs, etc

public:
    //this function is not read-only because we modify the queue
    void EnterZooReservation(const Ticket& ticket) {
        zooTicketReservations.push(ticket); //push adds to queue
        std::cout << "Ticket reservation entered into queue." << std::endl;
    }
    //const aka read-only function
    void DisplayZooReservations() const {
        std::queue<Ticket> tempQueue = zooTicketReservations;
        //make temp queue to run through it and delete whats inside
        //that way all of todays reservations are not deleted
        if (tempQueue.empty()) {
            std::cout << "No zoo ticket reservation currently queued." << std::endl;
            return;
        }
        std::cout << "Current queue of zoo ticket reservations: " << std::endl;
        while (!tempQueue.empty()) {
            tempQueue.front().DisplayTicketInfo();
            std::cout << "----------------------" << std::endl;
            tempQueue.pop(); //remove first member of queue
        }
    }
};

