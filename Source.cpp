/*
Hospital managment system
Developed by:
M.Aquib Javed	19F-0175
Fazal Qadeer   19F-0101
*/
#include<iostream>
#include<Windows.h>
#include<fstream>
#include<string>
#include<vector>
#include <utility>
#include"Admin.h"
#include"Doctor.h"
#include"Patient.h"
using namespace std;
void loading()
{
	cout << "\n\n";
	cout << "\t\t\t\t\t\t" << "   | Loading |\n" << "\t\t";

	for (int i = 0; i < 75; i++)
	{

		cout << "|";
		system("color 9");
		Sleep(15);

	}
	cout << endl;
	system("color 7");
	system("cls");

}
int main()
{
	Admin admin;
	Doctor doctor;
	Patient patient;
	cout << endl;
	cout << "\t\t\t\t | H O S P I T A L - M A N A G E M E N T - S Y S T E M |\n\n";
	cout << "\t\t\t\t\t\t | W E L C O M E | \n\n";
	cout << "\t\t\t\t\t\t | ---- BY ----  |\n" << endl;
	cout << "\t\t\t\t\t  Fazal Qadeer   &" << "  M.Aquib Javed" << endl;
	cout << "\t\t\t\t\t     19F-0101   " << "       19F-0175" << endl;
	loading();
	int option;
	do
	{
		cout << "\n\n\n";
		cout << "\t\t\t\t\t --------------------------" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|     Choose One Option    |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|   1. Login as Admin      |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|   2. Login as Doctor     |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|   3. Login as Patient    |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|   4. Exit                |" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|--------------------------|" << endl;
		cout << "\t\t\t\t\t|                          |" << endl;
		cout << "\t\t\t\t\t|  Enter : ";
		cin >> option;
		while (option > 4 || option <= 0)
		{
			try {
				cin.clear();
				cin.ignore();
				throw option;

			}
			catch (...)
			{
				cout << "\t\t\t\t\t--- Wrong input ---" << endl;
				cout << "\t\t\t\t\t--- Input again ---" << endl;
				cout << "\t\t\t\t\t|  Enter : ";
				cin >> option;
			}
		}
		system("cls");
		switch (option)
		{
		case 1:
		{
			admin.display();
			break;
		}
		case 2:
		{
			doctor.display();
			break;
		}
		case 3:
		{
			patient.display();
			break;
		}
		case 4:
		{
			exit(0);
			break;
		}
		}

	} while (exit);
	system("pause");
	return 0;
}
