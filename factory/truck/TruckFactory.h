#include "Truck.h"
#include <string>
#include <map>

class TruckFactory {
  public:
  // type define a function which returns a truck object. 
  // This object may be a Ford truck object or Chevy truck
  // object. 
  typedef Truck* (*CreateCallBack) ();
  // Register call back function with specific class name.
  static void RegisterTruck (const std::string& type, CreateCallBack cbf);
  // Unregister call back function. 
  static void UnregisterTruck (const std::string& type);
  // Return the specific created object with the name id.
  static Truck* CreateTruck(const std::string& type);

  private:
  typedef std::map<std::string, CreateCallBack> CallBackMap;
  // The call back function map.
  static CallBackMap mTrucks;
};
