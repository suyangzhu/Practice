#include "TruckFactory.h"
#include <iostream>

using namespace std;

int main() {
  TruckFactory::RegisterTruck("Ford", FordTruck::Create);
  TruckFactory::RegisterTruck("Chevy", ChevyTruck::Create); 
  Truck* truck = TruckFactory::CreateTruck("Ford");
  Truck* truck2 = TruckFactory::CreateTruck("Chevy");
  truck->Make();
  truck2->Make();
  delete truck;
  delete truck2;
  return 0;
}
