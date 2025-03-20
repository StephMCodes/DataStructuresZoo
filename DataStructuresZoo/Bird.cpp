#include "IFly.h"
#include "Animals.h"
#include "Bird.h"
using namespace std;

Bird::Bird(const string& speciesName, Habitat habitat, const string& diet, bool canFly)
{
	SetSpeciesName(speciesName);
	SetHabitat(habitat);
	SetDiet(diet);
	SetCanFly(canFly);
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
