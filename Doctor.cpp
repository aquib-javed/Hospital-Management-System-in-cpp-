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
#include"Doctor.h"
#include"Admin.h"
using namespace std;
/*
Doctor class funtions
*/

bool Doctor::sign_in()
{
	string* var = new string[3];
	pair<string, string> login_detail;
	ifstream log_in_file("Doctor_log_in.txt");
	system("cls");
	cout << "\t\t\t\t\t -------------------------" << endl;
	cout << "\t\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t\t|          LOGIN          |" << endl;
	cout << "\t\t\t\t\t|                         |" << endl;
	cout << "\t\t\t\t\t ------------------------- " << endl;
	cout << "\t\t\t\t\t  enter user name :";
	cin >> login_detail.first;
	cout << "\t\t\t\t\t  enter password  :";
	cin >> login_detail.second;
	cout << "\t\t\t\t\t  <--------------------->" << endl;
	do
	{
		if (log_in_file.is_open())
		{
			while (log_in_file >> var[0] >> var[1] >> var[2])
			{
				if (login_detail.first == var[0] && login_detail.second == var[1])
				{
					d_id = var[2];
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
			cin >> login_detail.first;
			cout << "\t\t\t\t\tenter password  again:";
			cin >> login_detail.second;
			log_in_file.open("Doctor_log_in.txt");
		}
	} while (true);

}
void Doctor::display()
{
	bool opp = true;
	if (sign_in())
	{
		do {
			int option;
			system("cls");

			cout << "\n\n\n";
			cout << "\t\t\t\t\t --------------------------" << endl;
			cout << "\t\t\t\t\t|                          |" << endl;
			cout << "\t\t\t\t\t|     Choose One Option    |" << endl;
			cout << "\t\t\t\t\t|                          |" << endl;
			cout << "\t\t\t\t\t|--------------------------|" << endl;
			cout << "\t\t\t\t\t|                          |" << endl;
			cout << "\t\t\t\t\t|   1. View Appointments   |" << endl;
			cout << "\t\t\t\t\t|                          |" << endl;
			cout << "\t\t\t\t\t|   2. Update Appointment  |" << endl;
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
				Doctor_appointment();
				break;
			}
			case 2:
			{
				update_appointment();
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
void Doctor::Doctor_appointment()
{
	ifstream appointment("Appointment.txt");
	string* var = new string[7];
	int no = 0;
	system("cls");
	cout << "\t\t------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|         |                  |                          |                           |" << endl;
	cout << "\t\t|  SR NO. | Appointment ID   |    Appointment time      |      Appointment status   |" << endl;
	cout << "\t\t|         |                  |                          |                           |" << endl;
	cout << "\t\t-------------------------------------------------------------------------------------" << endl;
	while (appointment >> var[0] >> var[1] >> var[2] >>
		var[3] >> var[4] >> var[5] >> var[6])
	{
		if (var[6] == d_id)
		{
			cout << "\t\t    " << ++no << ".\t\t" << var[1] << "\t\t\t" << var[3] << "\t\t\t" << var[5] << endl;
		}
	}
	delete var;
	int opp;
	cout << "\t\t\t\t\tPress 1 to go back to menu : ";
	cin >> opp;
	while (opp != 1)
	{
		cout << "\t\t\t\t\t--- Wrong input ---" << endl;
		cout << "\t\t\t\t\t--- Input again ---" << endl;
		cout << "\t\t\t\t\t    Enter : ";
		cin >> opp;
	}
}
void Doctor::update_appointment()
{
	vector < pair<int, string>> patient;
	string* var = new string[7];
	int patient_no;
	int n = 0;
	ifstream appointment("Appointment.txt");
	system("cls");
	cout << "\t\t------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|         |                   |                          |                          |" << endl;
	cout << "\t\t|  SR NO. | Appointment ID    |   Appointment time       |     Appointment status   |" << endl;
	cout << "\t\t|         |                   |                          |                          |" << endl;
	cout << "\t\t-------------------------------------------------------------------------------------" << endl;
	//cout << "\t\t\tAppointment ID\t\t" << "Appointment time \t\t" << "Appointment status\n";
	while (appointment >> var[0] >> var[1] >> var[2] >>
		var[3] >> var[4] >> var[5] >> var[6])
	{
		if (var[6] == d_id)
		{
			cout << "\t\t    " << ++n << ".\t\t" << var[1] << "\t\t\t" << var[3] << "\t\t\t\t" << var[5] << endl;
			patient.push_back(make_pair(n, var[1]));
		}
	}
	appointment.close();
	cout << "\t\t\t\t\tEnter patient no. to change status to checked: ";
	cin >> patient_no;
	string c = "checked";
	Admin* a = new Admin[1];
	a->update_appointment_status(patient[patient_no - 1].second, c);

	cout << "\t\t\t\t------------------------------------------------------" << endl;
	delete var;
	int opp;
	cout << "\t\t\t\t\tPress 1 to go back to menu : ";
	cin >> opp;
	while (opp != 1)
	{
		cout << "\t\t\t\t\t--- Wrong input ---" << endl;
		cout << "\t\t\t\t\t--- Input again ---" << endl;
		cout << "\t\t\t\t\t    Enter : ";
		cin >> opp;
	}
}

