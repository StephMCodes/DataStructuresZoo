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
#include <algorithm> 

using namespace std;

//Changes the Habitat input into a usable string
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
//This just changes the string to the Habitat for the LoadFromFiles()
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
		string speciesType, speciesName, habitatStr, dietStr, feedingTimes, canFly_IsFlyingMammal_WaterType, predatorsStr;
		bool canFly = false, isFlyingMammal = false;
		Habitat habitat;
		Animal* newAnimal = nullptr;

		//Checks each line and divides the variables by the ',' comma
		getline(ss, speciesType, ',');
		getline(ss, speciesName, ',');
		getline(ss, habitatStr, ',');
		getline(ss, dietStr, ',');
		getline(ss, feedingTimes, ';');
		getline(ss, canFly_IsFlyingMammal_WaterType, ',');

		//Read the rest of the line
		getline(ss, predatorsStr);

		//Changes habitatStr to the acutal Habitat
		habitat = StringHabitat(habitatStr);

		//This takes the if statement of each type of animal (switch case can't be used with string in C++
		if (speciesType == "Mammal")
		{
			//Checks if it can fly!
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
			//Adds new Animal
			newAnimal = new Mammal(speciesName, habitat, dietStr, feedingTimes, isFlyingMammal, canFly, predatorsStr);
		}
		else if (speciesType == "Bird")
		{
			//Checks if the bird can fly and assigns its bool
			canFly = (canFly_IsFlyingMammal_WaterType == "Yes");
			newAnimal = new Bird(speciesName, habitat, dietStr, feedingTimes, canFly, predatorsStr);
		}
		else if (speciesType == "Fish")
		{
			//Gets watertype of fish
			WaterType waterType = (canFly_IsFlyingMammal_WaterType == "FreshWater") ? WaterType::FreshWater : WaterType::SaltWater;
			newAnimal = new Fish(speciesName, habitat, dietStr, feedingTimes, waterType, predatorsStr);
		}
		else
		{
			cout << "Invalid Species Type: " << speciesType << endl;
		}

		//Adds animal to the appropriate Vector list based off Habitat
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
	string speciesName, diet, predators, feedingTimes;
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
	int feedingAmount;
	int feedingChoice;

	//User input
	cout << "Enter the Species Name of the animal: ";
	std::getline(std::cin, speciesName);
	//getline is better because it doesnt stop at white spaces and ignores enter key
	//cin.ignore();

	cout << "Enter the Diet of the animal: ";
	std::getline(std::cin, diet);
	//cin.ignore();

	cout << "How many feeding times does this animal have?: ";
	cin >> feedingAmount;
	std::cin.ignore(INT_MAX, '\n');

	//This determines if there are multiple feeding times as some animals do get fed more then once!
	for (int i = 0; i < feedingAmount; i++)
	{
		//While loop makes sure the user will enter a valid input
		while (true)
		{
			cout << "Please Select the " << (i + 1) << " feeding time for the animal : \n";
			cout << "(1)Morning, (2)Afternoon, (3)Evening -- Please enter the number of the feeding time.\n";
			cin >> feedingChoice;
			std::cin.ignore(INT_MAX, '\n');

			switch (feedingChoice)
			{
			case 1:
				feedingTimes += "Morning";
				break;
			case 2:
				feedingTimes += "Afternoon";
				break;
			case 3:
				feedingTimes += "Evening";
				break;
			default:
				cout << "You did not make a proper selection!\n";
				continue;
			}
			//Makes sure that there is a comma between the times, and not one at the end!
			if (i >= 0 && i < feedingAmount - 1)
			{
				feedingTimes += ",";
			}
			break;
		}
	}

	//Makes sure input is correct before applying
	while (true)
	{
		//User Input for habitat
		cout << "Enter the habitat of the animal (0:Jungle, 1:Desert, 2:Forest, 3:Arctic, 4:Aquatic): ";
		cin >> habitatChoice;
		std::cin.ignore(INT_MAX, '\n');

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
			continue; // Exit the function if the choice is invalid
		}
		break;
	}

	//While loop for valid input
	while (true)
	{
		cout << "Which Type of Animal? (0:Mammal, 1:Bird, 2:Fish): ";
		cin >> speciesChoice;
		std::cin.ignore(INT_MAX, '\n');

		char choice;
		//Switch statement to add the animal to the correct habitat!
		switch (speciesChoice)
		{
		case 0: //Mammals
			//This will include all extra details for Mammals
			cout << "Is this a flying mammal? (Y: yes, N: no): ";
			cin >> choice;
			std::cin.ignore(INT_MAX, '\n');

			while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
			{
				cout << "Invalid choice! Please enter 'Y' for yes, or 'N' for no: ";
				cin >> choice;
				std::cin.ignore(INT_MAX, '\n');
			}
			isFlyingMammal = (choice == 'Y' || choice == 'y');

			if (isFlyingMammal)
			{
				canFly = true;
			}

			predators = PredatorsQuestion(predators);
			newAnimal = new Mammal(speciesName, habitat, diet, feedingTimes, isFlyingMammal, canFly, predators);
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
			default:
				cout << "Invalid habitat selection!" << endl;
				delete newAnimal; // Clean up memory if habitat is invalid  
				break;
			}
			break;

		case 1: //Birds
			cout << "Can this animal fly? (Y:yes, N:no): ";
			cin >> choice;
			std::cin.ignore(INT_MAX, '\n');

			while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
			{
				cout << "Invalid choice! Please enter 'Y' for yes, or 'N' for no: ";
				cin >> choice;
				std::cin.ignore(INT_MAX, '\n');
			}
			canFly = (choice == 'Y' || choice == 'y');

			predators = PredatorsQuestion(predators);
			newAnimal = new Bird(speciesName, habitat, diet, feedingTimes, canFly, predators);
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
			default:
				cout << "Invalid habitat selection!" << endl;
				delete newAnimal; // Clean up memory if habitat is invalid  
				break;
			}
			break;

		case 2: //Fish
			cout << "Enter the Water Type of the fish (0:Freshwater, 1:Saltwater): ";
			cin >> waterTypeChoice;
			std::cin.ignore(INT_MAX, '\n');

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
				continue; // Exit the function if the choice is invalid
			}
			predators = PredatorsQuestion(predators);
			newAnimal = new Fish(speciesName, habitat, diet, feedingTimes, waterType, predators);
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
			default:
				cout << "Invalid habitat selection!" << endl;
				delete newAnimal; // Clean up memory if habitat is invalid  
				break;
			}
			break;

		default:
			cout << "Invalid species choice!" << endl;
			continue;
		}

		if (newAnimal != nullptr)
		{
			cout << speciesName << " was added to the " << newAnimal->GetHabitat() << " habitat!" << endl;
			break;
		}
		return;
	}
}
string PredatorsQuestion(string predators)
{
	//This determines how many predators and their names!
	int count;
	string predatorName = "";

	cout << "How many predators?: ";
	cin >> count;
	std::cin.ignore(INT_MAX, '\n');

	if (count == 0)
	{
		predators += "No predators!";
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			cout << "Enter Predator " << i + 1 << ": ";
			//cin >> predatorName;
			getline(std::cin, predatorName);
			predators += predatorName;
			if (i < count - 1) // Add a comma if it's not the last predator
			{
				predators += ", ";
			}
		}
	}
	return predators;
}
void SearchTheBiome(vector<Animal*>& animals, const string& biomeName, const string& keyword)
{
	// Convert the keyword to lowercase
	string lowerKeyword = keyword;
    transform(lowerKeyword.begin(), lowerKeyword.end(), lowerKeyword.begin(), ::tolower);   
	/*   
    The `begin()` and `end()` iterators define the range of the string to be transformed.  
    The first `lowerKeyword.begin()` specifies the start of the range, and the second `lowerKeyword.begin()` specifies where the transformed characters will be stored (in-place transformation).  
    The `::tolower` function is applied to each character in the range, converting uppercase letters to their lowercase equivalents.  
    This ensures that the keyword comparison is case-insensitive when searching for matches in the animal data.  
    */

	//This searches the specific Biome
	cout << "\nSearching " << biomeName << " Biome...\n";
	bool found = false;

	for (const auto& animal : animals) // Iterates through the list of animals in the specified biome  
	{
		if (animal == nullptr) continue; // Skips all null ptrs

		// Creates strings to convert to lowercase next
		string lowerSpeciesName = animal->GetSpeciesName();
		string lowerHabitat = animal->GetHabitat();
		string lowerDiet = animal->GetDiet();
		string lowerFeedingTime = animal->GetFeedingTime();
		string lowerPredators = animal->GetPredators();

		//Convert to lowercase
		transform(lowerSpeciesName.begin(), lowerSpeciesName.end(), lowerSpeciesName.begin(), ::tolower);
		transform(lowerHabitat.begin(), lowerHabitat.end(), lowerHabitat.begin(), ::tolower);
		transform(lowerDiet.begin(), lowerDiet.end(), lowerDiet.begin(), ::tolower);
		transform(lowerFeedingTime.begin(), lowerFeedingTime.end(), lowerFeedingTime.begin(), ::tolower);
		transform(lowerPredators.begin(), lowerPredators.end(), lowerPredators.begin(), ::tolower);

		//If found print info
		if (lowerSpeciesName.find(lowerKeyword) != string::npos ||
			lowerHabitat.find(lowerKeyword) != string::npos ||
			lowerDiet.find(lowerKeyword) != string::npos ||
			lowerFeedingTime.find(lowerKeyword) != string::npos ||
			lowerPredators.find(lowerKeyword) != string::npos)
		{
			found = true;
			cout << "\n ---- Animals Found ----\n";
			cout << "Species Names: " << animal->GetSpeciesName() << endl;
			cout << "Habitat: " << animal->GetHabitat() << endl;
			cout << "Diet: " << animal->GetDiet() << endl;
			cout << "Feeding Times: " << animal->GetFeedingTime() << endl;
			cout << "Predators: " << animal->GetPredators() << endl;

			if (IFly* flyingAnimal = dynamic_cast<IFly*>(animal))
			{
				cout << "Can Fly: " << (flyingAnimal->CanFly() ? "Yes" : "No") << endl;
			}
			if (Fish* fish = dynamic_cast<Fish*>(animal))
			{
				cout << "Water Type: " << fish->GetWaterType() << endl;
			}
		}
	}
	//If not found print not found
	if (!found)
	{
		cout << "\nNo animals found in the " << biomeName << " biome matching the keyword: " << keyword << endl;
	}
}
void SearchAnimalsThroughKeyword(const string& keyword, vector<Animal*>& jungleAnimals, vector<Animal*>& desertAnimals, vector<Animal*>& forestAnimals, vector<Animal*>& arcticAnimals, vector<Animal*>& aquaticAnimals)
{
	while (true)
	{
		int choice;
		cout << "Which Biome would you like to search through?(0:Jungle, 1:Desert, 2:Forest, 3:Arctic, 4:Aquatic, 5:All of them):";
		cin >> choice;
		std::cin.ignore(INT_MAX, '\n');

		switch (choice)
		{
		case 0:
			SearchTheBiome(jungleAnimals, "Jungle", keyword); 
			break;
		case 1: 
			SearchTheBiome(desertAnimals, "Desert", keyword); 
			break;
		case 2:
			SearchTheBiome(forestAnimals, "Forest", keyword); 
			break;
		case 3:
			SearchTheBiome(arcticAnimals, "Arctic", keyword); 
			break;
		case 4:
			SearchTheBiome(aquaticAnimals, "Aquatic", keyword); 
			break;
		case 5:
			SearchTheBiome(jungleAnimals, "Jungle", keyword);
			SearchTheBiome(desertAnimals, "Desert", keyword);
			SearchTheBiome(forestAnimals, "Forest", keyword);
			SearchTheBiome(arcticAnimals, "Arctic", keyword);
			SearchTheBiome(aquaticAnimals, "Aquatic", keyword);
			break;
		default:
			cout << "Please enter a valid input!";
			continue;
		}
		break;
	}
}
void DisplayAllAnimals(vector<Animal*>& jungleAnimals, vector<Animal*>& desertAnimals, vector<Animal*>& forestAnimals, vector<Animal*>& arcticAnimals, vector<Animal*>& aquaticAnimals)
{
	//Lambda function to display animals in a biome
	auto displayAnimals = [](const vector<Animal*>& animals, const string& biomeName)
		{
			cout << '\n';
			cout << biomeName << " Biome:\n" << endl;
			cout << "--------------\n" << endl;
			for (const auto& animal : animals)
			{
				if (animal == nullptr) continue; //Does a check to see if the pointer is null!
				cout << '\n';
				cout << "Species Name: " << animal->GetSpeciesName() << endl;
				cout << "Habitat: " << animal->GetHabitat() << endl;
				cout << "Diet: " << animal->GetDiet() << endl;
				cout << "Feeding Time: " << animal->GetFeedingTime() << endl;
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

		};

	displayAnimals(jungleAnimals, "Jungle");
	displayAnimals(desertAnimals, "Desert");
	displayAnimals(forestAnimals, "Forest");
	displayAnimals(arcticAnimals, "Arctic");
	displayAnimals(aquaticAnimals, "Aquatic");
}

