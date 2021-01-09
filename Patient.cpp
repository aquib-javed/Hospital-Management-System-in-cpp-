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
#include"Patient.h"
using namespace std;
/*
patient class funtions
*/
bool Patient::sign_in()
{
	system("cls");
	string* var = new string[3];
	pair<string, string> log_in_detail;
	ifstream log_in_file("Patient_log_in.txt");

	cout << "\t\t\t\t\t -------------------------" << endl;
	cout << "\t\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t\t|          LOGIN          |" << endl;
	cout << "\t\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t\t ------------------------- " << endl;
	cout << "\t\t\t\t\t  Enter user name :";
	cin >> log_in_detail.first;
	cout << "\t\t\t\t\t  Enter password  :";
	cin >> log_in_detail.second;
	cout << "\t\t\t\t\t  <--------------------->" << endl;


	do
	{
		if (log_in_file.is_open())
		{
			while (log_in_file >> var[0] >> var[1] >> var[2])
			{
				if (log_in_detail.first == var[0] && log_in_detail.second == var[1])
				{
					id = var[2];
					return true;
				}
			}
			log_in_file.close();
		}
		else
		{
			cout << "\t\t\t\t\t -------------------------" << endl;
			cout << "\t\t\t\t\t|                         |" << endl;
			cout << "\t\t\t\t\t|       Input Valid       |" << endl;
			cout << "\t\t\t\t\t|  Username or Password   |" << endl;
			cout << "\t\t\t\t\t|                         |" << endl;
			cout << "\t\t\t\t\t -------------------------" << endl;
			cout << "\t\t\t\t\tenter user name again:";
			cin >> log_in_detail.first;
			cout << "\t\t\t\t\tenter password  again:";
			cin >> log_in_detail.second;
			log_in_file.open("Patient_log_in.txt");
		}
	} while (true);

}
void Patient::display()
{
	bool opp = true;
	if (sign_in())
	{
		do
		{
			int option;
			system("cls");
			cout << "\n\n\n";
			cout << "\t\t\t\t\t --------------------------" << endl;
			cout << "\t\t\t\t\t|                          |" << endl;
			cout << "\t\t\t\t\t|     Choose One Option    |" << endl;
			cout << "\t\t\t\t\t|                          |" << endl;
			cout << "\t\t\t\t\t|--------------------------|" << endl;
			cout << "\t\t\t\t\t|                          |" << endl;
			cout << "\t\t\t\t\t|   1. Appointment Status  |" << endl;
			cout << "\t\t\t\t\t|                          |" << endl;
			cout << "\t\t\t\t\t|   2. View Fee            |" << endl;
			cout << "\t\t\t\t\t|                          |" << endl;
			cout << "\t\t\t\t\t|   3. EXIT                |" << endl;
			cout << "\t\t\t\t\t|                          |" << endl;
			cout << "\t\t\t\t\t|--------------------------|" << endl;
			cout << "\t\t\t\t\t|                          |" << endl;
			cout << "\t\t\t\t\t|  Enter : ";
			cin >> option;
			cout << "\t\t\t---------------------------------------------------------------------" << endl << endl;
			while (option > 3 || option <= 0)
			{
				cout << "\t\t\t\t\t--- Wrong input ---" << endl;
				cout << "\t\t\t\t\t--- Input again ---" << endl;
				cout << "\t\t\t\t\t    Enter : ";
				cin >> option;
			}
			system("cls");
			switch (option)
			{
			case 1:
			{
				view_appointment_Status();
				break;
			}
			case 2:
			{
				cout << endl;
				view_fee();
				break;
			}
			case 3:
			{

				opp = false;
				break;
			}
			}
		} while (opp);


	}
}
void Patient::view_fee()
{
	///
	int opp;
	string var[12];
	ifstream patient_file("Patient.txt");
	system("cls");
	cout << "\t\t\t\t-----------------------------------------------------" << endl;
	cout << "\t\t\t\t|                    |                  |           |" << endl;
	cout << "\t\t\t\t|    PATIENT NAME    |    PATIENT ID    |    FEE    |" << endl;
	cout << "\t\t\t\t|                    |                  |           |" << endl;
	cout << "\t\t\t\t-----------------------------------------------------" << endl;
	while (patient_file >> var[0] >> var[1] >>
		var[2] >> var[3] >> var[4] >>
		var[5] >> var[6] >> var[7] >> var[8]
		>> var[9] >> var[10] >> var[11])
	{
		if (var[3] == id)
		{
			cout << "\t\t\t\t|\t" << var[0] << " " << var[1] << "  |\t  " << var[3] << "\t|  " << var[9] << "    |" << endl;
			cout << "\t\t\t\t|---------------------------------------------------|" << endl;

		}
	}
	delete var;
	cout << "\t\t\t\t\tPress 1 to go back to menu : ";
	cin >> opp;
	while (opp != 1)
	{
		cout << "\t\t\t\t\t--- Wrong input ---" << endl;
		cout << "\t\t\t\t\t--- Input again ---" << endl;
		cout << "\t\t\t\t\t    Enter : ";
		cin >> opp;
	}
	system("cls");

}
void Patient::view_appointment_Status()
{
	int opp;
	string* var = new string[7];
	ifstream appointment_file("Appointment.txt");
	//cout << "Appointment ID\t\t" << "Appointment time \t\t" << "Appointment status\n";
	system("cls");
	cout << "\t\t|----------------------------------------------------------------------------------------------|" << endl;
	cout << "\t\t|                      |                        |                          |                   |" << endl;
	cout << "\t\t|    Appointment ID    |    Appointment time    |    Appointment status    |    Doctor Name    |" << endl;
	cout << "\t\t|                      |                        |                          |                   |" << endl;
	cout << "\t\t|----------------------------------------------------------------------------------------------|" << endl;

	while (appointment_file >> var[0] >> var[1] >> var[2] >>
		var[3] >> var[4] >> var[5] >> var[6])
	{
		if (var[0] == id)
		{
			cout << "\t\t|\t" << var[1] << "\t\t|\t" << var[3] << "\t\t|\t" << var[5] << " \t|\t" << get_doctor_name(var[6]) << "\t|" << endl;
			cout << "\t\t|----------------------------------------------------------------------------------------------|" << endl;
		}
	}
	appointment_file.close();
	delete var;
	cout << endl << endl;
	cout << "\t\t\t\t\tPress 1 to go back to menu : ";
	cin >> opp;
	while (opp != 1)
	{
		cout << "\t\t\t\t\t--- Wrong input ---" << endl;
		cout << "\t\t\t\t\t--- Input again ---" << endl;
		cout << "\t\t\t\t\t    Enter : ";
		cin >> opp;
	}
	system("cls");
}
string Patient::get_doctor_name(string d_id)
{
	string* var = new string[13];
	ifstream doctor_file("Doctor.txt");
	while (doctor_file >> var[0] >> var[1] >>
		var[2] >> var[3] >> var[4] >> var[5] >> var[6] >>
		var[7] >> var[8] >> var[9] >> var[10]
		>> var[11] >> var[12])
	{
		if (var[3] == d_id)
		{
			return "DR. " + var[0];
		}
	}
	doctor_file.close();

}

