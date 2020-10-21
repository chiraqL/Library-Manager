#include <iostream>
#include <iomanip>
#include <string>

void loginCheck(std::string user_name, std::string password) {
	if (user_name == "admin" && password == "pass") {
		system("cls");
		std::cout << "User is Logged in.";
	}
	else {
		system("cls");
		std::cout << "Wrong login credentials.";
	}

}

void loginScreen() {
	std::string user_name, password;
	std::cout << "Username: ";
	std::getline(std::cin, user_name);
	std::cout << "Password: ";
	std::getline(std::cin, password);

	loginCheck(user_name, password);
}


int main() {
	loginScreen();
	return 0;
}