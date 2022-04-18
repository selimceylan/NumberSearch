#include <iostream>
#include <string>
#include "SelimCeylan.hpp"
#include "INumberSearch.h"
//#define SDL_MAIN_HANDLED

using namespace std;

int main() {



	SelimCeylan::NumberSearch* a = new SelimCeylan::NumberSearch();
	std::string sonuc;


	//INumberSearch b();
	a->SetTargetNumber(320);
	a->SetInputNumbers("2 3 7 10 25 50");
	sonuc = a->GetSolution();
	cout << sonuc << endl;

	//a().SetTargetNumber(20);
	//a().SetInputNumbers("15 20 25");
	//cout << a().GetSolution() << endl;




	return 0;
}