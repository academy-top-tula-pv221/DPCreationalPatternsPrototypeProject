#include <iostream>
#include <vector>
#include <chrono>

#include "StoreClones.h"


using namespace std;

void PrototypeExample()
{
	class Army
	{
		string title;
		vector<InfantryUnit*> infantries;
		vector<ArcherUnit*> archers;
		vector<CavalryUnit*> cavalries;

	public:
		
		Army(string title, int iCount, int aCount, int cCount)
			: title{ title }
		{
			Factory* factory;
			factory = new InfantryFactory();
			for (int i = 0; i < iCount; i++)
				infantries.push_back((InfantryUnit*)factory->CreateUnit());
			delete factory;

			factory = new ArcherFactory();
			for (int i = 0; i < aCount; i++)
				archers.push_back((ArcherUnit*)factory->CreateUnit());
			delete factory;

			factory = new CavalryFactory();
			for (int i = 0; i < cCount; i++)
				cavalries.push_back((CavalryUnit*)factory->CreateUnit());
			delete factory;
		}
		
		
		Army(int iCount, int aCount, int cCount, string title)
		{
			StoreClones store;
			for (int i = 0; i < iCount; i++)
				infantries.push_back((InfantryUnit*)store.GetClone(UnitType::Infantry));
			for (int i = 0; i < aCount; i++)
				archers.push_back((ArcherUnit*)store.GetClone(UnitType::Archer));
			for (int i = 0; i < cCount; i++)
				cavalries.push_back((CavalryUnit*)store.GetClone(UnitType::Cavalry));
		}
		
		~Army()
		{
			/*for (int i = 0; i < infantries.size(); i++)
				delete infantries[i];
			for (int i = 0; i < archers.size(); i++)
				delete archers[i];
			for (int i = 0; i < cavalries.size(); i++)
				delete cavalries[i];*/
			infantries.clear();
			archers.clear();
			cavalries.clear();

		}

		void PrintConsole()
		{
			cout << "Army: " << title << "\n";
			for (int i = 0; i < infantries.size(); i++)
				cout << "\t" << infantries[i]->ToString() << "\n";
			for (int i = 0; i < archers.size(); i++)
				cout << "\t" << archers[i]->ToString() << "\n";
			for (int i = 0; i < cavalries.size(); i++)
				cout << "\t" << cavalries[i]->ToString() << "\n";
		}
	};

	const auto start1 = std::chrono::steady_clock::now();
	Army army1("army1", 1000, 1000, 1000);
	//army1.PrintConsole();
	const auto end1 = std::chrono::steady_clock::now();
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << "\n";

	
	const auto start2 = std::chrono::steady_clock::now();
	Army army2(1000, 1000, 1000, "army2");
	//army2.PrintConsole();
	const auto end2 = std::chrono::steady_clock::now();
	cout << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << "\n";

}

int main()
{
	srand(time(nullptr));

	PrototypeExample();
}
