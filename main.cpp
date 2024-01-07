#include "header.h"

int main() {
	//create catalog of library items
	vector<libraryItem*> catalog {
		new book("Catcher in the Rye", 101, "J.D. Salinger"),
		new book("Harry Potter", 102, "J.K. Rowling"),
		new book("Game of Thrones", 103, "G.R.R. Martin"),
		new dvd("Inception", 201, "Christopher Nolan"),
		new dvd("Jaws", 202, "Stepehn Spielberg"),
		new magazine("National Geographic", 301, 255),
	};

	//create members in the library
	member member1("John Doe", 001);
	member member2("Jane Smith", 002);

	//displaying catalog info
	cout << "Displaying items in catalog: \n" << endl;
	for (size_t i = 0; i < catalog.size(); i++) {
		catalog[i]->displayInfo();
	}
	
	//member borrowing book
	member1.borrowItem(*catalog[0]);
	member1.borrowItem(*catalog[3]);
	member2.borrowItem(*catalog[0]);
	member2.borrowItem(*catalog[4]);

	//displaying member information
	member1.displayMemberInfo();
	member2.displayMemberInfo();

	//displaying catalog info
	cout << "\nDisplaying items in catalog: " << endl;
	for (size_t i = 0; i < catalog.size(); i++) {
		catalog[i]->displayInfo();
	}

	//member returning book
	member1.returnItem(*catalog[0]);

	member1.displayMemberInfo();
	member2.borrowItem(*catalog[0]);

	//displaying catalog info
	cout << "\nDisplaying items in catalog: " << endl;
	for (size_t i = 0; i < catalog.size(); i++) {
		catalog[i]->displayInfo();
	}




	for (const auto& item : catalog) {
		delete item;
	}

	return 0;
}