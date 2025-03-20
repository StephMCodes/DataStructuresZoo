#include <iostream>
#include <string>
#include <vector>
#include "IFly.h"
#include "Animals.h"
#include "Mammal.h"
using namespace std;

string Animal::HabitatString(Habitat habitat)
{
	switch (habitat)
	{
	case Habitat::Jungle:
		return "Jungle";
	case Habitat::Desert:
		return "Desert";
	case Habitat::Forest:
		return "Forest";
	case Habitat::Arctic:
		return "Arctic";
	case Habitat::Aquatic:
		return "Aquatic";
	default:
		return "Selection Invalid!";
	}
};

//Derived class for the Birds
class Bird : public Animal, public IFly
{
private:
	bool canFly;
public:
	Bird(const string& speciesName, Habitat habitat, const string& diet, bool canFly)
	{
		SetSpeciesName(speciesName);
		SetHabitat(habitat);
		SetDiet(diet);
		SetCanFly(canFly);
	}

	//SETTERS
	void SetDiet(const string& diet) override
	{
		this->diet = diet;
	}
	void SetSpeciesName(const string& speciesName) override
	{
		this->speciesName = speciesName;
	}
	void SetHabitat(Habitat habitat) override
	{
		this->habitat = habitat;
	}
	void SetCanFly(bool canFly) override
	{
		this->canFly = canFly;
	}
	bool CanFly() const override { return canFly; }


};

//Derived class for Fish
//class Fish : public Animal
//{
//private:
//	string predators;
//
//public:
//	Fish(const string& speciesName, Habitat habitat, const string& diet, const string& predators)
//	{
//		SetSpeciesName(speciesName);
//		SetHabitat(habitat);
//		SetDiet(diet);
//		SetPredators(predators);
//	}
//
//	//SETTERS
//	void SetSpeciesName(const string& speciesName) override
//	{
//		this->speciesName = speciesName;
//	}
//	void SetDiet(const string& diet)override
//	{
//		this->diet = diet;
//	}
//	void SetHabitat(Habitat habitat)override
//	{
//		this->habitat = habitat;
//	}
//	string SetPredators(const string& predators)
//	{
//		int amount;
//		string predatorsString = "";
//		vector<string> Predators;
//
//		cout << "How many predators would you like to add to this list? ";
//		cin >> amount;
//
//		for (int i = 0; i < amount; i++)
//		{
//			string predator;
//			cout << "Enter name of predator " << i + 1 << ": ";
//			cin >> predator;
//			Predators.push_back(predator);
//		}
//
//		for (const auto& predator : Predators)
//		{
//			predatorsString += predator + ", ";
//		}
//
//		if (!predatorsString.empty())
//		{
//			predatorsString.pop_back(); // Remove the last comma
//			predatorsString.pop_back(); // Remove the space after the last comma
//			predatorsString += ".";
//		}
//
//		return predatorsString;
//	}
//	string GetPredators() { return predators; }
//};

//Clears Animals for the dynamically allocated memory
static void ClearAnimals(vector<Animal*>& animals)
{
	for (Animal* animal : animals)
	{
		delete animal;
	}
	animals.clear();
};

//Function to add animals to the zoo -- Can be called in the DataStructuresZoo.cpp file
void AddAnimals(vector<Animal*>& jungleAnimals, vector<Animal*>& desertAnimals, vector<Animal*>& forestAnimals, vector<Animal*>& arcticAnimals, vector<Animal*>& aquaticAnimals)
{
	//Variables for the animal
	string speciesName, diet, predators;
	Habitat habitat;
	Animal* newAnimal = nullptr;

	//User input for the animal
	bool canFly = false;
	bool isFlyingMammal = false;
	int habitatChoice;
	int speciesChoice;

	//User input
	cout << "Enter the speciesName of the animal: ";
	cin >> speciesName;
	cin.ignore();

	cout << "Enter the diet of the animal: ";
	cin >> diet;
	cin.ignore();

	cout << "Enter the habitat of the animal (0:Jungle, 1:Desert, 2:Forest, 3:Arctic, 4:Aquatic): ";
	cin >> habitatChoice;
	cin.ignore();

	switch (habitatChoice)
	{
	case 0:
		habitat = Habitat::Jungle;
		break;
	case 1:
		habitat = Habitat::Desert;
		break;
	case 2:
		habitat = Habitat::Forest;
		break;
	case 3:
		habitat = Habitat::Arctic;
		break;
	case 4:
		habitat = Habitat::Aquatic;
		break;
	default:
		cout << "Invalid choice!" << endl;
		return; // Exit the function if the choice is invalid
	}

	cout << "Which Type of Animal? (0:Mammal, 1:Bird, 2:Fish): ";
	cin >> speciesChoice;
	cin.ignore();

	char choice; 

	//Switch statement to add the animal to the correct habitat -- Will be updated with more derived classes!
	switch (speciesChoice)
	{
	case 0:
		

		cout << "Is this a flying mammal? (Y: yes, N: no): ";
		cin >> choice;
		cin.ignore();

		while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
		{
			cout << "Invalid choice! Please enter 'Y' for yes, or 'N' for no: ";
			cin >> choice;
			cin.ignore();
		}
		isFlyingMammal = (choice == 'Y' || choice == 'y');

		if (isFlyingMammal)
		{
			canFly = true;
		}
		newAnimal = new Mammal(speciesName, habitat, diet, isFlyingMammal, canFly);
		jungleAnimals.push_back(newAnimal);
		break;
	case 1:
		

		cout << "Can this animal fly? (Y:yes, N:no): ";
		cin >> choice;
		cin.ignore();

		while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
		{
			cout << "Invalid choice! Please enter 'Y' for yes, or 'N' for no: ";
			cin >> choice;
			cin.ignore();
		}
		canFly = (choice == 'Y' || choice == 'y');
		newAnimal = new Bird(speciesName, habitat, diet, canFly);
		jungleAnimals.push_back(newAnimal);
		break;
	case 2:
		//newAnimal = new Fish(speciesName, habitat, diet, predators);
		//jungleAnimals.push_back(newAnimal);
		break;
	default:
		cout << "Invalid species choice!" << endl;
		break;
	}

	if (newAnimal != nullptr)
	{
		cout << speciesName << " was added to the " << newAnimal->GetHabitat() << " habitat!" << endl;
	}

	//THIS NEEDS TO BE DONE WHEN THE CONSOLE CLOSES!
	//Clear the memory for all -- just to be safe!
	//ClearAnimals(jungleAnimals);
	//ClearAnimals(desertAnimals);
	//ClearAnimals(forestAnimals);
	//ClearAnimals(arcticAnimals);
	//ClearAnimals(aquaticAnimals);
}

void DisplayAllAnimals(vector<Animal*>& jungleAnimals, vector<Animal*>& desertAnimals, vector<Animal*>& forestAnimals, vector<Animal*>& arcticAnimals, vector<Animal*>& aquaticAnimals)
{

	cout << "Jungle Biome:\n" << endl;
	cout << "--------------\n" << endl;
	for (const auto& animal : jungleAnimals)
	{
		cout << "Species Name: " << animal->GetSpeciesName() << endl;
		cout << "Habitat: " << animal->GetHabitat() << endl;
		cout << "Diet: " << animal->GetDiet() << endl;
		if (IFly* flyingAnimal = dynamic_cast<IFly*>(animal))
		{
			cout << "Can Fly: " << (flyingAnimal->CanFly() ? "Yes" : "No") << endl;
		}
		
	}
}

