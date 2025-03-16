#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Enumeration for the habitat of the animals
enum class Habitat
{
	Jungle,
	Desert,
	Forest,
	Arctic,
	Aquatic
};

//Abstract class for the animals
class Animal 
{
protected:
	string name;
	Habitat habitat; // No initialization
	string diet;

public:
	virtual ~Animal() = default; //destructor

	//SETTERS
	virtual void SetName(const string& name) = 0;
	virtual void SetHabitat(const Habitat habitat) = 0;
	virtual void SetDiet(const string& diet) = 0;

	//GETTERS
	string GetName() const { return name; }
	string GetHabitat() const { return HabitatString(habitat); }
	string GetDiet() const { return diet; }

	//Function to return the habitat as a string
	string HabitatString(Habitat habitat) const
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
};

//Derived class for the Mammals
class Mammal : public Animal
{
public:
	//Constructor
	Mammal(const string& name, Habitat habitat, const string& diet)
	{
		SetName(name);
		SetHabitat(habitat);
		SetDiet(diet);
	}

	//SETTERS
	void SetDiet(const string& diet) override
	{
		this->diet = diet;
	}
	void SetName(const string& name) override
	{
		this->name = name;
	}
	void SetHabitat(Habitat habitat) override
	{
		this->habitat = habitat;
	}
};

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
static void AddAnimals(vector<Animal*>& jungleAnimals, vector<Animal*>& desertAnimals, vector<Animal*>& forestAnimals, vector<Animal*>& arcticAnimals, vector<Animal*>& aquaticAnimals)
{
	//Variables for the animal
	string name, diet;
	Habitat habitat;
	Animal* newAnimal = nullptr;
	
	//User input for the animal
	int habitatChoice;
	int speciesChoice;

	//User input
	cout << "Enter the name of the animal: ";
	cin >> name;
	cout << "Enter the diet of the animal: ";
	cin >> diet;
	cout << "Enter the habitat of the animal (0:Jungle, 1:Desert, 2:Forest, 3:Arctic, 4:Aquatic): ";
	cin >> habitatChoice;

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

	cout << "Which Species? (0:Mammal, 1:Bird, 2:Fish): ";
	cin >> speciesChoice;

	//Switch statement to add the animal to the correct habitat -- Will be updated with more derived classes!
	switch (speciesChoice)
	{
	case 0:
		newAnimal = new Mammal(name, habitat, diet);
		jungleAnimals.push_back(newAnimal);
		break;
	case 1:
		//newAnimal = new Bird(name, habitat, diet);
		//jungleAnimals.push_back(newAnimal);
		break;
	case 2:
		//newAnimal = new Fish(name, habitat, diet);
		//jungleAnimals.push_back(newAnimal);
		break;
	default:
		cout << "Invalid species choice!" << endl;
		break;
	}

	if (newAnimal != nullptr)
	{
		cout << name << " was added to the " << newAnimal->GetHabitat() << " habitat!" << endl;
	}
	
	//Clear the memory for all -- just to be safe!
	ClearAnimals(jungleAnimals);
	ClearAnimals(desertAnimals);
	ClearAnimals(forestAnimals);
	ClearAnimals(arcticAnimals);
	ClearAnimals(aquaticAnimals);
};

