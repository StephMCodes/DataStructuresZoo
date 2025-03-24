#include <iostream>
#include <string>
#include <vector>
#include "IFly.h"
#include "Animals.h"
#include "Mammal.h"
#include "Bird.h"
#include "Fish.h"
#include <fstream>
#include <sstream>

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
//This just changes the strign to the Habitat for the LoadFromFiles()
Habitat StringHabitat(const string& habitatStr) 
{
	if (habitatStr == "Jungle") return Habitat::Jungle;
	if (habitatStr == "Desert") return Habitat::Desert;
	if (habitatStr == "Forest") return Habitat::Forest;
	if (habitatStr == "Arctic") return Habitat::Arctic;
	if (habitatStr == "Aquatic") return Habitat::Aquatic;
	throw invalid_argument("Invalid habitat string:" + habitatStr);
}

//Loads from a file to add animals right away instead of having an empty zoo
//Takes the string for the name of the file, followed by all our vector lists
void LoadFromFiles(const string& filename, vector<Animal*>& jungleAnimals, vector<Animal*>& desertAnimals, vector<Animal*>& forestAnimals, vector<Animal*>& arcticAnimals, vector<Animal*>& aquaticAnimals)
{
	//Checks if the file even exists or opens in the first place
	ifstream file(filename);
	if (!file.is_open())
	{
		cout << "Failed to open the file: " << filename << endl; 
		return;
	}

	//string line for dividing up the lines in the text file
	string line;
	while (getline(file, line))
	{
		//string stream exists in the program to help read string and format the input
		stringstream ss(line);

		//The format of the Animals.txt
		string speciesType, speciesName, habitatStr, dietStr, canFly_IsFlyingMammal_WaterType, predatorsStr;
		bool canFly = false, isFlyingMammal = false;
		Habitat habitat;
		Animal* newAnimal = nullptr;

		//Checks each line and divides the variables by the ',' comma
		getline(ss, speciesType, ',');
		getline(ss, speciesName, ',');
		getline(ss, habitatStr, ',');
		getline(ss, dietStr, ',');
		getline(ss, canFly_IsFlyingMammal_WaterType, ',');
		getline(ss, predatorsStr, ',');

		//Changes habitatStr to the acutal Habitat
		habitat = StringHabitat(habitatStr);

		//This takes the if statement of each type of animal (switch case can't be used with string in C++
		if (speciesType == "Mammal")
		{
			if (canFly_IsFlyingMammal_WaterType == "Yes")
			{
				isFlyingMammal = true;
				canFly = isFlyingMammal;
			}
			else
			{
				isFlyingMammal = false;
				canFly = isFlyingMammal;
			}
			
			newAnimal = new Mammal(speciesName, habitat, dietStr, isFlyingMammal, canFly, predatorsStr);
		}
		else if (speciesType == "Bird")
		{
			canFly = (canFly_IsFlyingMammal_WaterType == "Yes");
			newAnimal = new Bird(speciesName, habitat, dietStr, canFly, predatorsStr);
		}
		else if (speciesType == "Fish")
		{
			WaterType waterType = (canFly_IsFlyingMammal_WaterType == "FreshWater") ? WaterType::FreshWater : WaterType::SaltWater;
		}
		else
		{
			cout << "Invalid Species Type: " << speciesType << endl;
		}

		switch (habitat)
		{
		case Habitat::Jungle:
			jungleAnimals.push_back(newAnimal);
			break;
		case Habitat::Forest:
			forestAnimals.push_back(newAnimal);
			break;
		case Habitat::Desert:
			desertAnimals.push_back(newAnimal);
			break;
		case Habitat::Aquatic:
			aquaticAnimals.push_back(newAnimal);
			break;
		case Habitat::Arctic:
			arcticAnimals.push_back(newAnimal);
			break;

		}
	}

}
//Clears Animals for the dynamically allocated memory
void ClearAnimals(vector<Animal*>& animals)
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
	WaterType waterType;
	Animal* newAnimal = nullptr;

	//User input for the animal
	bool canFly = false;
	bool isFlyingMammal = false;

	//For all switch cases
	int waterTypeChoice;
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
	case 0: //Mammals
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

		predators = PredatorsQuestion(predators);
		newAnimal = new Mammal(speciesName, habitat, diet, isFlyingMammal, canFly, predators);
		jungleAnimals.push_back(newAnimal);
		break;

	case 1: //Birds
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

		predators = PredatorsQuestion(predators);
		newAnimal = new Bird(speciesName, habitat, diet, canFly, predators);
		jungleAnimals.push_back(newAnimal);
		break;

	case 2: //Fish
		cout << "Enter the Water Type of the fish (0:Freshwater, 1:Saltwater): ";
		cin >> waterTypeChoice;
		cin.ignore();

		switch (waterTypeChoice)
		{
		case 0:
			waterType = WaterType::FreshWater;
			break;
		case 1:
			waterType = WaterType::SaltWater;
			break;
		default:
			cout << "Invalid choice!" << endl;
			return; // Exit the function if the choice is invalid
		}
		predators = PredatorsQuestion(predators);
		newAnimal = new Fish(speciesName, habitat, diet, waterType, predators);
		jungleAnimals.push_back(newAnimal);
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
string PredatorsQuestion(string predators)
{
	int count;
	string predatorName = "";

	cout << "How many predators?: ";
	cin >> count;
	cin.ignore();

	for (int i = 0; i < count; i++)
	{
		cout << "Enter Predator " << i + 1 << ": ";
		cin >> predatorName;
		cin.ignore();
		predators += predatorName;
		if (i < count - 1) // Add a comma if it's not the last predator
		{
			predators += ", ";
		}
	}
	return predators;
}

void DisplayAllAnimals(vector<Animal*>& jungleAnimals, vector<Animal*>& desertAnimals, vector<Animal*>& forestAnimals, vector<Animal*>& arcticAnimals, vector<Animal*>& aquaticAnimals)
{
	cout << '\n';
	cout << "Forest Biome:\n" << endl;
	cout << "--------------\n" << endl;
	for (const auto& animal : forestAnimals)
	{
		if (animal == nullptr) continue; //Does a check to see if the pointer is null!
		cout << '\n';
		cout << "Species Name: " << animal->GetSpeciesName() << endl;
		cout << "Habitat: " << animal->GetHabitat() << endl;
		cout << "Diet: " << animal->GetDiet() << endl;
		if (IFly* flyingAnimal = dynamic_cast<IFly*>(animal))
		{
			cout << "Can Fly: " << (flyingAnimal->CanFly() ? "Yes" : "No") << endl;
		}
		else if (Fish* fish = dynamic_cast<Fish*>(animal))
		{
			cout << animal->GetSpeciesName() << " live in " << fish->GetWaterType() << endl;
		}
		cout << "Predators: " << animal->GetPredators() << endl;
	}
}

