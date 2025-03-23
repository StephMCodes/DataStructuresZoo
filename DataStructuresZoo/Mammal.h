#pragma once

#include <string>
#include "Animals.h"
#include "IFly.h"
using namespace std;

class Mammal : public Animal, public IFly
{
private:
	bool canFly;
	bool isFlyingMammal;
	

public:
	//Constructor
	Mammal(const string& speciesName, Habitat habitat, const string& diet, bool isFlyingMammal = false, bool canFly = false, const string& predators = "");

	//SETTERS
	void SetSpeciesName(const string& speciesName) override;
	void SetHabitat(Habitat habitat) override;
	void SetDiet(const string& diet) override;
	void SetPredators(const string& predators) override;
	void SetCanFly(bool canFly) override;

	//GETTERS
	bool CanFly() const override;
};
