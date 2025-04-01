#include "Fish.h"
#include "Animals.h"

using namespace std;

string Fish::WaterTypeString(WaterType waterType)
{
	switch (waterType)
	{
	case WaterType::FreshWater:
		return "Freshwater";
	case WaterType::SaltWater:
		return "Saltwater";
	default:
		return "Selection Invalid!";
	}
}

Fish::Fish(const string& speciesName, Habitat habitat, const string& diet, WaterType waterType, const string& predators)
{
	SetSpeciesName(speciesName);
	SetDiet(diet);
	SetHabitat(habitat);
	SetWaterType(waterType);	
	SetPredators(predators);
}

void Fish::SetSpeciesName(const string& speciesName)
{
	this->speciesName = speciesName;
}
void Fish::SetHabitat(Habitat habitat)
{
	this->habitat = habitat;
}
void Fish::SetDiet(const string& diet)
{
	this->diet = diet;
}
void Fish::SetWaterType(WaterType waterType)
{
	this->waterType = waterType;
}
void Fish::SetPredators(const string& predators)
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