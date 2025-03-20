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

Fish::Fish(const string& speciesName, Habitat habitat, const string& diet, WaterType waterType)
{
	SetSpeciesName(speciesName);
	SetDiet(diet);
	SetHabitat(habitat);
	SetWaterType(waterType);	
}

void Fish::SetSpeciesName(const string& speciesName)
{
	this->speciesName = speciesName;
}
void Fish::SetHabitat(Habitat habitat)
{
	this->habitat = habitat;
}
void Fish::SetDiet(const string& dite)
{
	this->diet = diet;
}
void Fish::SetWaterType(WaterType waterType)
{
	this->waterType = waterType;
}