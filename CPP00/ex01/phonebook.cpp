#include <iostream>
#include <iomanip>

std::string toUpper(const std::string& str) {
	std::string upperStr = str;
	for (char *p = &upperStr[0]; *p; ++p)
		*p = std::toupper(*p);
	return upperStr;
}

int ftAtoi(const std::string& str, int& err) {
	int res = 0, sign = 1;
	size_t i = 0;
	while (i < str.length() && str[i] >= 9 && str[i] <= 32)
		i++;
	if (i < str.length() && (str[i] == '-' || str[i] == '+')) {
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		err++;
	while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return sign * res;
}

int utf8len(const std::string& str) {
	size_t i = 0;
	int cCount = 0;
	while (i < str.size()) {
		if ((str[i] & 0x80) == 0x00)
			i += 1;
		else if ((str[i] & 0xE0) == 0xC0)
			i += 2;
		else if ((str[i] & 0xF0) == 0xE0)
			i += 3;
		else if ((str[i] & 0xF8) == 0xF0)
			i += 4;
		else
			i++;
		cCount++;
	}
	return cCount;
}

size_t utf8ByteIndex(const std::string& str, int cPos) {
	size_t i = 0;
	int cCount = 0;
	while (i < str.size() && cCount < cPos) {
		if ((str[i] & 0x80) == 0x00)
			i += 1;
		else if ((str[i] & 0xE0) == 0xC0)
			i += 2;
		else if ((str[i] & 0xF0) == 0xE0)
			i += 3;
		else if ((str[i] & 0xF8) == 0xF0)
			i += 4;
		else
			i++;
		cCount++;
	}
	return i;
}

std::string utf8substr(const std::string& str, int start, int length) {
	size_t byteStart = utf8ByteIndex(str, start);
	size_t byteEnd = utf8ByteIndex(str, start + length);
	return str.substr(byteStart, byteEnd - byteStart);
}

std::string getInfo(std::string& str) {
	int info_len = utf8len(str);
	if (info_len > 10)
		return utf8substr(str, 0, 9) + ".";
	return std::string(10 - info_len, ' ') + str;
};

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
			std::string firstName = getInfo(contacts[i].firstName);
			std::string lastName = getInfo(contacts[i].lastName);
			std::string nickname = getInfo(contacts[i].nickname);
			std::cout << std::setw(10) << std::right << i << " | "
				<< std::setw(10) << std::right << firstName << " | "
				<< std::setw(10) << std::right << lastName << " | "
				<< std::setw(10) << std::right << nickname << " | " << std::endl;
		}
		std::cout << "Enter index to display contact info: ";
		std::string input;
		std::getline(std::cin, input);
		int err = 0;
		int index = ftAtoi(input, err);
		if (index < 0 || index >= contactCount || err > 0) {
			std::cerr << "Invalid index." << std::endl;
			return;
		}
		contacts[index].showContact();
	}
};

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
		else std::cerr << "Err: Invalid command!" << std::endl;
	}
	return 0;
}
