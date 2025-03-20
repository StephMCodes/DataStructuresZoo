#include "Mammal.h"
#include "IFly.h"
#include "Animals.h"

Mammal::Mammal(const string& speciesName, Habitat habitat, const string& diet, bool isFlyingMammal, bool canFly)
{
	SetSpeciesName(speciesName);
	SetHabitat(habitat);
	SetDiet(diet);
	this->isFlyingMammal = isFlyingMammal;
	if (isFlyingMammal)
	{
		SetCanFly(canFly);
	}
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
	if (isFlyingMammal)
	{
		this->canFly = canFly;
	}
}
bool Mammal::CanFly() const { return canFly; }
