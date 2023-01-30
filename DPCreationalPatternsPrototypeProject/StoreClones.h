#pragma once
#include <map>
#include "Unit.h"
class StoreClones
{
	std::map<UnitType, Prototype*> clones;
public:
	
	Prototype* GetClone(UnitType type)
	{
		auto it = clones.find(type);
		if (it != clones.end())
			return it->second;

		Factory* factory = nullptr;
		switch (type)
		{
		case UnitType::Infantry:
			factory = new InfantryFactory();
			break;
		case UnitType::Archer:
			factory = new ArcherFactory();
			break;
		case UnitType::Cavalry:
			factory = new CavalryFactory();
			break;
		default:
			break;
		}

		auto unitClone = (Prototype*)factory->CreateUnit();
		auto data = std::make_pair(type, unitClone);

		clones.insert(data);

		return unitClone;
	}
	
};
