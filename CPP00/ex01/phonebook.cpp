#include <iostream>
#include <iomanip>

class Contact {
public:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	void getContact() {
		std::cout << "Enter first name: ";
		std::getline(std::cin, firstName);
		std::cout << "Enter last name: ";
		std::getline(std::cin, lastName);
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nickname);
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phoneNumber);
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, darkestSecret);
	}

	void showContact() {
		std::cout << "First Name: " << firstName << std::endl;
		std::cout << "Last Name: " << lastName << std::endl;
		std::cout << "Nickname: " << nickname << std::endl;
		std::cout << "Phone Number: " << phoneNumber << std::endl;
		std::cout << "Darkest Secret: " << darkestSecret << std::endl;
	}
};

class PhoneBook {
private:
	Contact contacts[8];
	int contactCount;

public:
	PhoneBook() : contactCount(0) {}

	void addContact() {
		if (contactCount < 8) contacts[contactCount++].getContact();
		else {
			for (int i = 0; i < 7; i++) contacts[i] = contacts[i + 1];
			contacts[7].getContact();
		}
	}

	void searchContact() {
		if (contactCount == 0) {
			std::cout << "No contacts found." << std::endl;
			return;
		}
		std::cout << std::setw(10) << std::right << "Index" << " | "
			<< std::setw(10) << std::right << "First Name" << " | "
			<< std::setw(10) << std::right << "Last Name" << " | "
			<< std::setw(10) << std::right << "Nickname" << " | " << std::endl;
		for (int i = 0; i < contactCount; i++) {
			std::string firstName = contacts[i].firstName;
			std::string lastName = contacts[i].lastName;
			std::string nickname = contacts[i].nickname;
			if (firstName.length() > 10) firstName = firstName.substr(0, 9) + ".";
			if (lastName.length() > 10) lastName = lastName.substr(0, 9) + ".";
			if (nickname.length() > 10) nickname = nickname.substr(0, 9) + ".";
			std::cout << std::setw(10) << std::right << i << " | "
				<< std::setw(10) << std::right << firstName << " | "
				<< std::setw(10) << std::right << lastName << " | "
				<< std::setw(10) << std::right << nickname << " | " << std::endl;
		}
		std::cout << "Enter index to display contact info: ";
		std::string input;
		std::getline(std::cin, input);
		int index = std::stoi(input);
		if (index < 0 || index >= contactCount) {
			std::cout << "Invalid index." << std::endl;
			return;
		}
		contacts[index].showContact();
	}
};

std::string toUpper(const std::string& str) {
	std::string upperStr = str;
	for (char *p = &upperStr[0]; *p; ++p)
		*p = std::toupper(*p);
	return upperStr;
}

int main() {
	PhoneBook phoneBook;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::string command;
		std::getline(std::cin, command);
		command = toUpper(command);
		if (command == "ADD") phoneBook.addContact();
		else if (command == "SEARCH") phoneBook.searchContact();
		else if (command == "EXIT") break;
		else std::cout << "Err: Invalid command!" << std::endl;
	}
	return 0;
}
