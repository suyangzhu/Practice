#include "TruckFactory.h"

TruckFactory::CallBackMap TruckFactory::mTrucks;

void TruckFactory::RegisterTruck(const std::string& type,
                            CreateCallBack cbf) {
  mTrucks[type] = cbf;
}

void TruckFactory::UnregisterTruck(const std::string& type) {
  mTrucks.erase(type);
}

Truck* TruckFactory::CreateTruck(const std::string& type) {
  CallBackMap::iterator it = mTrucks.find(type);
  if (it != mTrucks.end()) 
    return (it->second)();
   return NULL;
}
