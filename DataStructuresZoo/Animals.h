#pragma once
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

class Animal
{
protected:
	string speciesName;
	Habitat habitat; // No initialization
	string diet;
	string predators;

public:
	virtual ~Animal() = default;//destructor

	//SETTERS
	virtual void SetSpeciesName(const string& speciesName) = 0;
	virtual void SetHabitat(const Habitat habitat) = 0;
	virtual void SetDiet(const string& diet) = 0;
	virtual void SetPredators(const string& predators) = 0;

	//GETTERS
	string GetSpeciesName() const { return speciesName; }
	string GetHabitat() const { return HabitatString(habitat); }
	string GetDiet() const { return diet; }
	string GetPredators() const { return predators; }

	//Function to return the habitat as a string
	static string HabitatString(Habitat habitat);
};

string PredatorsQuestion(string predators);
void AddAnimals(vector<Animal*>& jungleAnimals, vector<Animal*>& desertAnimals, vector<Animal*>& forestAnimals, vector<Animal*>& arcticAnimals, vector<Animal*>& aquaticAnimals);
void DisplayAllAnimals(vector<Animal*>& jungleAnimals, vector<Animal*>& desertAnimals, vector<Animal*>& forestAnimals, vector<Animal*>& arcticAnimals, vector<Animal*>& aquaticAnimals);
