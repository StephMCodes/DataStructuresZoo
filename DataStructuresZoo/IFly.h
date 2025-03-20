#pragma once

class IFly
{
public:
	virtual bool CanFly() const = 0;
	virtual void SetCanFly(bool canFly) = 0;
};
