#include <iostream>
#include <string>
#include <fstream>
 
using namespace std;

bool login()
{
	string username, password, un, pw;
	cout << "Enter Username: ";
	cin >> username;
	cout << "Enter Passsword: ";
	cin >> password;

	ifstream read(username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

int main()
{
	int menuchoice;
		
	cout << "cmp307 project by Ross Paterson" << endl << endl;

	
	cout << "Menu:" << endl;
	cout << "1. Register: \n2. Login: " <<endl; 
	cin >> menuchoice;
	if (menuchoice == 1)
	{
		string username, password;
		cout << "select a username :";
			cin >> username;
		cout << "select a password :";
			cin >> password;

		ofstream file;
		file.open(username + ".txt");

		file << username << endl << password; 
		file.close();

		main();
	}
	else if (menuchoice == 2)
	{
		bool status = login();

		if (!status)
		{
			cout << "Login incorrect" << endl;
			system("PAUSE");
			return 0;
		}
		else
		{
			cout << "Logged in successfully" << endl << endl;
			cout << "Menu:" << endl;
			cout << "1. Load asset database: \n2. Quit: " <<endl;
			cin >> menuchoice;
			if (menuchoice == 1)
			{
				cout << "loading database..."<<endl;
			}
			else if (menuchoice == 2)
			{
				system("PAUSE");
				return 0;
			}
		}	
	}
}
