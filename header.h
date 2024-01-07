#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//base class
class libraryItem {
private:
	string title;
	int id;
	bool checkedOut;

public:
	//constructor
	libraryItem(string t, int i) : title(t), id(i), checkedOut(false) {} //member initialization list

	//defining getters and setters
	string getTitle() const {
		return title;
	}

	int getId() const {
		return id;
	}

	bool checkedOutStatus() const {
		return checkedOut;
	}

	void checkOut() {
		checkedOut = true;
	}

	void checkIn() {
		checkedOut = false;
	}

	virtual void displayInfo() const {
		cout << "Item ID: " << id << "\nTitle: " << title
			<< "\nAvailability: " << (checkedOut ? "Unavailable" : "Available") << endl;
	}

	//destructor
	virtual ~libraryItem(){}
		
};

//derived class
class book : public libraryItem {
private:
	string author;

public: 
	//constructor
	book(string t, int i, string a) : libraryItem(t,i), author(a) {}

	string getAuthor() const {
		return author;
	}

	void displayInfo() const override {
		libraryItem::displayInfo();
		cout << "Author: " << author << endl <<endl;
	}

	//destructor
	virtual ~book(){}
};

//derived class
class dvd : public libraryItem {
private:
	string director;

public:
	dvd(string t, int i, string d) : libraryItem(t,i), director(d) {}
	
	string getDirector() const {
		return director;
	}

	void displayInfo() const override {
		libraryItem::displayInfo();
		cout << "Director: " << director << endl <<endl;
	}
};

//derived class
class magazine : public libraryItem {
private:
	int issueNumber;
	
public:
	magazine(string t, int i, int n) : libraryItem(t,i), issueNumber(n) {}
	
	int getIssueNumber() const {
		return issueNumber;
	}

	void displayInfo() const override {
		libraryItem::displayInfo();
		cout << "Issue Number: " << issueNumber << endl << endl;
	}
};

class audiobook : public libraryItem {
private:
	string narrator;
public:
	audiobook(string t, int i, string n) : libraryItem(t,i), narrator(n) {}

	string  getNarrator() const {
		return narrator;
	}

	void displayInfo() const override {
		libraryItem::displayInfo();
		cout << "Narrator: " << narrator << endl << endl;
	}
};

//class for members of the library
class member {
private:
	string name;
	int memberId;
	vector<libraryItem*> borrowedItems;

public: 
	member(string n, int i) : name(n), memberId(i) {}

	string getName() const {
		return name;
	}

	int getMemberId() const {
		return memberId;
	}

	vector<libraryItem*> getBorrowedItems() const {
		return borrowedItems;
	}

	void borrowItem(libraryItem& item) {
		if (item.checkedOutStatus() == false) {
			item.checkOut();
			borrowedItems.push_back(&item);
			cout << name << " borrowed the item: " << item.getTitle() << endl;
		}
		else {
			cout << item.getTitle() << " is unavailable" << endl;
		}
	}

	void returnItem(libraryItem& item) {
		for (size_t i = 0; i < borrowedItems.size(); i++) {
			if (borrowedItems[i] == &item) {
				item.checkIn();
				borrowedItems.erase(borrowedItems.begin() + i);
				cout << name << " returned the item: " << item.getTitle() << endl;
				break;
			}
			else {
				cout << item.getTitle() << " cannot be returned" << endl;
			}
		}
	}

	void displayMemberInfo() const {
		cout << "\nMember ID: " << memberId << "\nMember name: " << name << "\nBorrowed items: " << endl;
		for (size_t i = 0; i < borrowedItems.size(); i++) {
			cout << borrowedItems[i]->getTitle() << endl;
		}
	}
};