#pragma once
#include <iostream>
#include "Prototype.h"

enum UnitType
{
	Infantry,
	Archer,
	Cavalry
};

// abstract class Product
class Unit : public Prototype
{
protected:
	std::string name;
public:
	std::string& Name() { return name; }
	Unit(std::string name) : name{ name } {}
	virtual std::string ToString()
	{
		return "Unit: " + name;
	}
	virtual ~Unit() {};
};

// abstract interface Factory
class Factory
{
public:
	virtual Unit* CreateUnit() = 0;
	virtual ~Factory() {};
};

// Infantry
class InfantryUnit : public Unit
{
public:
	InfantryUnit() : Unit("Infantry") {}
	Prototype* Clone() override
	{
		return new InfantryUnit(*this);
	}

};


class InfantryFactory : public Factory
{
public:
	Unit* CreateUnit() override
	{
		return new InfantryUnit();
	}
};

// Archer
class ArcherUnit : public Unit
{
public:
	ArcherUnit() : Unit("Archer") {}
	Prototype* Clone() override
	{
		return new ArcherUnit(*this);
	}
};

class ArcherFactory : public Factory
{
public:
	Unit* CreateUnit() override
	{
		return new ArcherUnit();
	}
};

// Cavalry
class CavalryUnit : public Unit
{
public:
	CavalryUnit() : Unit("Cavalry") {}
	Prototype* Clone() override
	{
		return new CavalryUnit(*this);
	}
};

class CavalryFactory : public Factory
{
public:
	Unit* CreateUnit() override
	{
		return new CavalryUnit();
	}
};

