#include <iostream>
#include <conio.h>


const int MAX_PASSWORD_LEN = 32;


struct user_data
{
	std::string name;
	std::string password;
};


inline bool is_valid_char(char &c)
{
	return c >= 33 && c <= 126;
}


const std::string get_user_password()
{
	char password[MAX_PASSWORD_LEN] ;
	char temp;

	for (int i = 0;;)
	{

		temp = getch();

		// TODO: validate password length
		if (temp == '\b' && i >= 1)
		{
			std::cout << "\b \b";
			--i;
		}
		else if (temp == '\r')
		{
			password[i] = '\0';
			break;
		}
		else if (i <= MAX_PASSWORD_LEN && is_valid_char(temp)){
			password[i] = temp;
			++i;
			std::cout << "*";
		}
	}
	std::string str_password(password);
	return str_password;
}


const user_data get_user_data()
{
	user_data ud;
	// TODO: Validate username length
	std::cout << "Username: ";
	std::cin >> ud.name;

	std::cout << "Password: ";
	ud.password = get_user_password();
	std::cout << std::endl;
	return ud;
}


int main()
{
	user_data ud = get_user_data();
	std::cout << ud.name << std::endl;
	std::cout << ud.password << std::endl;
	return 0;
}
