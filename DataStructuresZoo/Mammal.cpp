#include "Mammal.h"
#include "IFly.h"
#include "Animals.h"

Mammal::Mammal(const string& speciesName, Habitat habitat, const string& diet, bool isFlyingMammal, bool canFly, const string& predators)
{
	SetSpeciesName(speciesName);
	SetHabitat(habitat);
	SetDiet(diet);
	SetPredators(predators);
	this->isFlyingMammal = isFlyingMammal;
	this->canFly = isFlyingMammal ? canFly : false; //Makes sure that mammals assigns canFly properly!
}

//SETTERS
void Mammal::SetDiet(const string& diet)
{
	this->diet = diet;
}
void Mammal::SetSpeciesName(const string& speciesName)
{
	this->speciesName = speciesName;
}
void Mammal::SetHabitat(Habitat habitat)
{
	this->habitat = habitat;
}
void Mammal::SetCanFly(bool canFly)
{
	this->canFly = isFlyingMammal ? canFly : false;
}
void Mammal::SetPredators(const string& predators)
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
bool Mammal::CanFly() const { return canFly; }
