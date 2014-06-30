#include "TruckFactory.h"
#include <iostream>

using namespace std;

int main() {
  TruckFactory::RegisterTruck("Ford", FordTruck::Create);
  Truck* truck = TruckFactory::CreateTruck("Ford");
  truck->Make();
  delete truck;
  return 0;
}
