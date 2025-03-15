#pragma once
#include <iostream>
#include <string>

struct Ticket
{
protected: //encapsulation
	//Ticket (VIP, family, classic) <- add the price
	std::string type;
	int price;
	//constructor is protected so it is abstract
	Ticket(const std::string& type, int price)
		: type(type), price(price)
	{
	}
	//a simple displaying method
	void DisplayTicketInfo() {
		std::cout << "Ticket Type: " << type << "\nPrice: $" << price << std::endl;
	}
	
};

struct VIPTicket : Ticket
{
	VIPTicket() : Ticket("VIP Ticket", 100) {} // VIP costs $100 for full experience
};

struct FamilyTicket : Ticket
{
	FamilyTicket() : Ticket("Family Ticket", 50) {} // for family group
};

struct StudentElderTicket : Ticket
{
	StudentElderTicket() : Ticket("Student/Elder Discount Ticket", 10) {} // student discount
};

struct BasicTicket : Ticket
{
	BasicTicket() : Ticket("Basic Ticket", 20) {} // simple 20 dollar ticket
};

