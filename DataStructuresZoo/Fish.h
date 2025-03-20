#pragma once
#include "Animals.h"
using namespace std;

enum class WaterType
{
	FreshWater,
	SaltWater
};

class Fish : public Animal
{
private:
	WaterType waterType;
public:
	//Constructor
	Fish(const string& speciesName, Habitat habitat, const string& diet, WaterType waterType);

	//SETTERS
	void SetDiet(const string& diet) override;
	void SetHabitat(Habitat habitat) override;
	void SetSpeciesName(const string& speciesName) override;
	void SetWaterType(WaterType waterType);

	//GETTER
	string GetWaterType() const { return WaterTypeString(waterType); }

	//Funtion to change enum to string!
	static string WaterTypeString(WaterType waterType);
};