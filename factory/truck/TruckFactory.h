#include "Truck.h"
#include <string>
#include <map>

class TruckFactory {
  public:
  typedef Truck* (*CreateCallBack) ();
  static void RegisterTruck (const std::string& type, CreateCallBack cbf);
  static void UnregisterTruck (const std::string& type);
  static Truck* CreateTruck(const std::string& type);

  private:
  typedef std::map<std::string, CreateCallBack> CallBackMap;
  static CallBackMap mTrucks;
};
