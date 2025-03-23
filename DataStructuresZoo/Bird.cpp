#include "IFly.h"
#include "Animals.h"
#include "Bird.h"
using namespace std;

Bird::Bird(const string& speciesName, Habitat habitat, const string& diet, bool canFly, const string& predators)
{
	SetSpeciesName(speciesName);
	SetHabitat(habitat);
	SetDiet(diet);
	SetCanFly(canFly);
	SetPredators(predators);
}

//SETTERS
void Bird::SetDiet(const string& diet)
{
	this->diet = diet;
}
void Bird::SetSpeciesName(const string& speciesName)
{
	this->speciesName = speciesName;
}
void Bird::SetHabitat(Habitat habitat)
{
	this->habitat = habitat;
}
void Bird::SetCanFly(bool canFly)
{
	this->canFly = canFly;
}
void Bird::SetPredators(const string& predators)
{
	if (this->predators.empty())
	{
		this->predators = predators;
	}
	else
	{
		this->predators += ", " + predators;
	}
	
}
