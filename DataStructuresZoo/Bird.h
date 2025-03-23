#pragma once
#include "Animals.h"
#include "IFly.h"
using namespace std;

class Bird : public Animal, public IFly
{
private:
	bool canFly;
public:
	Bird(const string& speciesName, Habitat habitat, const string& diet, bool canFly, const string& predators = "");

	void SetDiet(const string& diet) override;
	void SetSpeciesName(const string& speciesName) override;
	void SetHabitat(Habitat habitat) override;
	void SetPredators(const string& predators) override;
	void SetCanFly(bool canFly) override;


	bool CanFly() const override { return canFly; }
};

