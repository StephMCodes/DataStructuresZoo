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
	Fish(const string& speciesName, Habitat habitat, const string& diet, string feedingTimes, WaterType waterType, const string& predators = "");

	//SETTERS
	void SetDiet(const string& diet) override;
	void SetHabitat(Habitat habitat) override;
	void SetSpeciesName(const string& speciesName) override;
	void SetPredators(const string& predators) override;
	void SetWaterType(WaterType waterType);
	void SetFeedingTime(const string& feedingTimes) override;

	//GETTER
	string GetWaterType() const { return WaterTypeString(waterType); }

	//Funtion to change enum to string!
	static string WaterTypeString(WaterType waterType);
};