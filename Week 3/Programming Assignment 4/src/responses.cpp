#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  if(r.buses.empty()) {
	  os << "No stop" << endl;
  } else {
	  for(const string& bus : r.buses) {
		  cout << bus << " ";
	  }
	  os << endl;
  }
  return os;
}


ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  if(r.stops.empty()) {
	  os << "No bus" << endl;
  } else {
	  for(const auto& item : r.stops) {
		  os << "Stop " << item.first << ":";
		  if(item.second.size() == 1) {
			  os << " no interchange" << endl;
		  } else {
			  for(const string& other_bus : item.second) {
				  if(other_bus != r.bus) {
					  os << " " << other_bus;
				  }
			  }
			  os << endl;
		  }
	  }
  }
  return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.buses_to_stops.empty()) {
	  os << "No buses" << endl;
	} else {
	  for (const auto& bus_item : r.buses_to_stops) {
		os << "Bus " << bus_item.first << ": ";
		for (const string& stop : bus_item.second) {
		  os << stop << " ";
		}
		os << endl;
	  }
	}
	return os;
}

