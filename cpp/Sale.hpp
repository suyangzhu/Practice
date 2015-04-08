#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

class SalesItem {
	public:
		double avg_price() const {
			price++;
		}
		SalesItem() : isbn(""), unitSold(0), revenue(0.0) {}
	private:
		std::string isbn;
		unsigned unitSold;
		double revenue;
};
