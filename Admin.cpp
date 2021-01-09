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
#include<cstring>
#include<vector>
#include <utility>
#include"Admin.h"
#include"Patient.h"
using namespace std;

void Admin::display()
{
	bool opp = true;
	if (sign_in())
	{
		do
		{
			int option;
			system("cls");
			cout << endl;

			cout << "\t\t\t------------------------------------------------------------------\n";
			cout << "\t\t\t\t\t| M A I N - I N T E R F A C E |" << endl;
			cout << "\t\t\t------------------------------------------------------------------\n";
			cout << endl << endl << endl;

			cout << "\t\t\t\t\t--- Please Enter Your Choice ---\n" << endl << endl;
			cout << "\t\t\t\t\t(1)--> ADD A NEW DOCTOR\n";
			cout << "\t\t\t\t\t(2)--> View All DOCTOR\n";
			cout << "\t\t\t\t\t(3)--> Edit  DOCTOR\n"; ////
			cout << "\t\t\t\t\t(4)--> ADD A NEW PATIENT\n";
			cout << "\t\t\t\t\t(5)--> View All PATIENT\n";
			cout << "\t\t\t\t\t(6)--> Edit PATIENT\n";//
			cout << "\t\t\t\t\t(7)--> ADD A NEW APPOINTMENT\n";
			cout << "\t\t\t\t\t(8)--> Assign APPOINTMENT\n";
			cout << "\t\t\t\t\t(9)--> VIEW All APPOINTMENT\n";
			cout << "\t\t\t\t\t(10)--> UPDATE APPOINTMENT\n";
			cout << "\t\t\t\t\t(11)--> View fee \n";
			cout << "\t\t\t\t\t(12)--> EXIT HERE\n" << endl << endl;
			cout << "\t\t\t\t\t        Enter : ";
			cin >> option;
			cout << "------------------------------------------------------------" << endl << endl;
			while (option > 12 || option <= 0)
			{
				cout << "--- Wrong input ---" << endl;
				cout << "--- Input again ---" << endl;
				cin >> option;
			}
			switch (option)
			{
			case 1:
			{
				add_doctor();
				break;
			}
			case 2:
			{
				view_all_doctor();
				break;
			}
			case 3:
			{
				edit_doctor();
				break;
			}
			case 4:
			{
				add_patient();
				break;
			}

			case 5:
			{
				view_all_patient();
				break;
			}
			case 6:
			{
				edit_patient();
				break;
			}
			case 7:
			{
				make_appointment();
				break;
			}
			case 8:
			{
				assign_appointment();
				break;
			}
			case 9:
			{
				view_all_appointment();
				break;
			}
			case 10:
			{
				update_appointment();
				break;
			}
			case 11:
			{
				view_fee();
				break;
			}
			case 12:
			{
				system("cls");
				opp = false;
				break;
			}
			}
		} while (opp);
	}
}
bool Admin::sign_in()
{
	system("cls");
	pair<string, string> log_in_detail;

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
		if (log_in_detail.first == "admin" && log_in_detail.second == "admin")
		{
			return true;
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
		}
	} while (true);
}
/*
patient funtion
*/
void Admin::add_patient()
{
	do {
		int opp, op;
		system("cls");
		cout << endl;
		cout << "\t\t\t\t\t ------------------------------ " << endl;
		cout << "\t\t\t\t\t|                              |" << endl;
		cout << "\t\t\t\t\t|     A D D - P A T I E N T    |" << endl;
		cout << "\t\t\t\t\t|                              |" << endl;
		cout << "\t\t\t\t\t ------------------------------ " << endl;
		cout << endl << endl;

		cout << "\t\t\t\t\tEnter Your First Name :";
		cin >> first_name;
		cout << "\t\t\t\t\tEnter your Last Name :";
		cin >> last_name;
		cout << "\t\t\t\t\tSelect your department :" << endl;
		//department option
		cout << "\t\t\t\t\t1)Dental" << endl;
		cout << "\t\t\t\t\t2)Accident & Emergency " << endl;
		cout << "\t\t\t\t\t3)Orthopedics " << endl;
		cout << "\t\t\t\t\t4)Psychiatry " << endl;
		cout << "\t\t\t\t\t5)Physiotherapy " << endl;
		cout << "\t\t\t\t\tEnter departmetn no. : ";
		cin >> opp;
		while (opp <= 0 || opp > 5)
		{
			cout << "\t\t\t\t\t   Invalid input" << endl;
			cout << "\t\t\t\t\tPlease Enter from 1 to 5 " << endl;
			cout << "\t\t\t\t\tEnter departmetn no. : ";
			cin >> opp;
		}
		department = get_department_name(opp);
		//p-id 
		//ya ma baad ma karon ga
		cout << "\t\t\t\t\tyour patient id is = ";
		p_id = generate_patient_id(opp);
		cout << p_id << endl;
		cout << "\t\t\t\t\tEnter username :";
		cin >> username;
		cout << "\t\t\t\t\tEnter password :";
		cin >> password;
		cout << "\t\t\t\t\tEnter your registration date :";
		cin >> registration_date;
		gender = input_gender();
		contact = input_contact_no();
		cout << "\t\t\t\t\tEnter your Blood group :";
		cin >> blood_group;
		adress = input_adress();
		cout << "\t\t\t\t\tFee :";
		cin >> fee_status;
		cout << "\t\t\t\t\tEnter Your Qualification :";
		cin >> qualification;
		cout << "\t\t\t\t\tEnter your Salary :";
		cin >> salary;

		/*
		writting to file
		*/
		make_username_file("Patient_log_in.txt", username, password, p_id);
		fstream patient_file("Patient.txt", ios::app);
		if (patient_file.is_open())
		{
			patient_file << first_name << endl << last_name << endl << department << endl << p_id << endl
				<< registration_date << endl << gender << endl << contact << endl << blood_group << endl
				<< adress << endl << fee_status << endl << qualification << endl << salary << endl << endl;

		}
		else
		{
			cout << "Unable to open 'Patient.txt' file" << endl;
		}
		cout << "\t\t\t\t\t Enter More Patient ? " << endl;
		cout << "\t\t\t\t\t Yes=1 ; No=0 : ";
		while (!(cin >> op))
		{
			cout << endl;
			cout << "\t\t\t\t\tError! Enter again : ";

			cin.clear();
			cin.ignore(123, '\n');
		}

		if (op == 0)
		{
			system("cls");
			break;
		}
	} while (exit);

}
void Admin::edit_patient()
{
	do {
		int opp;
		string p;
		system("cls");
		cout << endl;
		cout << "\t\t\t\t\t ---------------------------- " << endl;
		cout << "\t\t\t\t\t|                            |" << endl;
		cout << "\t\t\t\t\t|       EDIT - PATIENT       |" << endl;
		cout << "\t\t\t\t\t|                            |" << endl;
		cout << "\t\t\t\t\t ---------------------------- " << endl;
		cout << "\t\t\t\t\tEnter Patient Id :";
		cin >> p;
		ifstream old_patient_file("Patient.txt", ios::app);
		ofstream new_patient_file("New_Patient.txt");
		if (old_patient_file.is_open())
		{
			while (old_patient_file >> first_name >> last_name >>
				department >> p_id >> registration_date >>
				gender >> contact >> blood_group >> adress
				>> fee_status >> qualification >> salary)
			{
				if (p_id == p)
				{
					cout << "\t\t\t\t------------------------------------------------------" << endl << endl;
					cout << "\t\t\t\t\tEnter First Name :";
					cin >> first_name;
					cout << "\t\t\t\t\tEnter Last Name :";
					cin >> last_name;
					contact = input_contact_no();
					adress = input_adress();
					cout << "\t\t\t\t\tFee :";
					cin >> fee_status;

					cout << "\t\t\t\t------------------------------------------------------" << endl << endl;
					new_patient_file << first_name << endl << last_name << endl << department << endl << p_id << endl
						<< registration_date << endl << gender << endl << contact << endl << blood_group << endl
						<< adress << endl << fee_status << endl << qualification << endl << salary << endl << endl;
				}
				else
				{
					new_patient_file << first_name << endl << last_name << endl << department << endl << p_id << endl
						<< registration_date << endl << gender << endl << contact << endl << blood_group << endl
						<< adress << endl << fee_status << endl << qualification << endl << salary << endl << endl;
				}

			}
		}
		old_patient_file.close();
		new_patient_file.close();
		remove("Patient.txt");     //This will delete the old file
		rename("New_Patient.txt", "Patient.txt");


		cout << "\t\t\t\t\t Edit More Patient ? " << endl;
		cout << "\t\t\t\t\t Yes=1 ; No=0 : ";
		cin >> opp;
		while (opp > 1 || opp < 0)
		{
			cout << "\t\t\t\t\t--- Wrong input ---" << endl;
			cout << "\t\t\t\t\t--- Input again ---" << endl;
			cout << "\t\t\t\t\t    Enter : ";
			cin >> opp;
		}
		if (opp == 0)
		{
			system("cls");
			break;
		}
	} while (1);
}
void Admin::view_all_patient()
{
	int opp;
	ifstream patient_file("Patient.txt");
	int sr_no = 0;
	system("cls");
	cout << "\t\t-----------------------------------------------------------------------------" << endl;
	cout << "\t\t|              |                     |                  |                   |" << endl;
	cout << "\t\t|    SR NO.    |    Patient Nname    |    Patient ID    |     DEPARTMENT    |" << endl;
	cout << "\t\t|              |                     |                  |                   |" << endl;
	cout << "\t\t-----------------------------------------------------------------------------" << endl;
	while (patient_file >> first_name >> last_name >>
		department >> p_id >> registration_date >>
		gender >> contact >> blood_group >> adress
		>> fee_status >> qualification >> salary)
	{
		cout << "\t\t\t" << ++sr_no << "." << "\t  " << first_name << " " << last_name << "\t\t  " << p_id << "\t\t" << department << endl;
	}
	patient_file.close();

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

/*
DR.funtion
*/
void Admin::add_doctor()
{
	do {
		int opp;
		system("cls");
		cout << endl;
		cout << "\t\t\t\t\t ------------------------------ " << endl;
		cout << "\t\t\t\t\t|                              |" << endl;
		cout << "\t\t\t\t\t|      A D D - D O C T O R     |" << endl;
		cout << "\t\t\t\t\t|                              |" << endl;
		cout << "\t\t\t\t\t ------------------------------ " << endl;
		cout << endl << endl;
		int op;
		cout << "\t\t\t\t\tEnter your First Name =";
		cin >> first_name;
		cout << "\t\t\t\t\tEnter your Last Name =";
		cin >> last_name;
		cout << endl;
		cout << "\t\t\t\t\t--- Select your Department ---" << endl << endl;
		//department option
		cout << "\t\t\t\t\t1)--> Dental" << endl;
		cout << "\t\t\t\t\t2)--> Accident & Emergency " << endl;
		cout << "\t\t\t\t\t3)--> Orthopedics " << endl;
		cout << "\t\t\t\t\t4)--> Psychiatry " << endl;
		cout << "\t\t\t\t\t5)--> Physiotherapy " << endl;
		cout << "\t\t\t\t\tEnter departmetn no. : ";
		cin >> op;
		while (op <= 0 || op > 5)
		{
			cout << "\t\t\t\t\t   Invalid input" << endl;
			cout << "\t\t\t\t\tPlease Enter from 1 to 5 " << endl;
			cout << "\t\t\t\t\tEnter departmetn no. : ";
			cin >> op;
		}
		department = get_department_name(op);
		cout << endl;
		cout << "\t\t\t\t\tSir/Mam Your Doctor Id = ";
		d_id = generate_doctor_id(op);
		cout << d_id << endl;
		cout << "\t\t\t\t\tEnter Your Username =";
		cin >> username;
		cout << "\t\t\t\t\tEnter Your Password =";
		cin >> password;
		cout << "\t\t\t\t\tEnter Your Registration Date =";
		cin >> registration_date;
		gender = input_gender();
		//taking input for contact number
		contact = input_contact_no();
		cout << "\t\t\t\t\tEnter your Blood Group =";
		cin >> blood_group;
		adress = input_adress();
		cout << "\t\t\t\t\tEnter Your Qualification =";
		cin >> qualification;
		cout << "\t\t\t\t\tEnter Your Salary :";
		cin >> salary;

		cout << endl << endl;

		cout << "\t\t\t------------------------------------------------" << endl;
		cout << "\t\t\t\t\t D A T A - S A V E D" << endl;
		cout << "\t\t\t------------------------------------------------" << endl;
		/*
		writting to file
		*/
		/*
		this code is to write file for useename and password
		*/
		make_username_file("Doctor_log_in.txt", username, password, d_id);
		fstream doctor_file("Doctor.txt", ios::app);

		if (doctor_file.is_open())
		{
			doctor_file << first_name << endl << last_name << endl << department << endl << d_id << endl
				<< username << endl << password << endl << registration_date << endl << gender << endl << contact
				<< endl << blood_group << endl << adress << endl << qualification << endl << salary << endl << endl;
		}
		else
		{
			cout << "Unable to open 'Doctor.txt' file" << endl;
		}


		cout << "\t\t\t\t\t Enter More Doctor ? " << endl;
		cout << "\t\t\t\t\t Yes=1 ; No=0 : ";
		cin >> opp;
		while (opp > 1 || opp < 0)
		{
			cout << "\t\t\t\t\t--- Wrong input ---" << endl;
			cout << "\t\t\t\t\t--- Input again ---" << endl;
			cout << "\t\t\t\t\t    Enter : ";
			cin >> opp;
		}
		if (opp == 0)
		{
			system("cls");
			break;
		}
	} while (1);
}
void Admin::edit_doctor()
{

	do {
		int opp;
		string p;
		system("cls");
		cout << endl;
		cout << "\t\t\t\t\t ---------------------------- " << endl;
		cout << "\t\t\t\t\t|                            |" << endl;
		cout << "\t\t\t\t\t|       EDIT - DOCTOR        |" << endl;
		cout << "\t\t\t\t\t|                            |" << endl;
		cout << "\t\t\t\t\t ---------------------------- " << endl;
		cout << "\t\t\t\t\tEnter doctor Id =";
		cin >> p;
		ifstream old_doctor_file("Doctor.txt", ios::app);
		ofstream new_doctor_file("New_Doctor.txt");
		if (old_doctor_file.is_open())
		{
			while (old_doctor_file >> first_name >> last_name >>
				department >> d_id >> username >> password >> registration_date >>
				gender >> contact >> blood_group >> adress
				>> qualification >> salary)
			{
				if (d_id == p)
				{
					adress = input_adress();
					contact = input_contact_no();
					cout << "\t\t\t\t\tEnter your Qualification :";
					cin >> qualification;
					cout << "\t\t\t\t\tEnter your New Salary :";
					cin >> salary;

					new_doctor_file << first_name << endl << last_name << endl << department << endl << d_id << endl
						<< username << endl << password << endl << registration_date << endl << gender << endl << contact
						<< endl << blood_group << endl << adress << endl << qualification << endl << salary << endl << endl;
				}
				else
				{
					new_doctor_file << first_name << endl << last_name << endl << department << endl << d_id << endl
						<< username << endl << password << endl << registration_date << endl << gender << endl << contact
						<< endl << blood_group << endl << adress << endl << qualification << endl << salary << endl << endl;
				}
			}
		}
		old_doctor_file.close();
		new_doctor_file.close();
		remove("Doctor.txt");     //This will delete the old file
		rename("New_Doctor.txt", "Doctor.txt");
		cout << "\t\t\t\t\t Edit More doctor ? " << endl;
		cout << "\t\t\t\t\t Yes=1 ; No=0 : ";
		cin >> opp;
		while (opp > 1 || opp < 0)
		{
			cout << "\t\t\t\t\t--- Wrong input ---" << endl;
			cout << "\t\t\t\t\t--- Input again ---" << endl;
			cout << "\t\t\t\t\t    Enter : ";
			cin >> opp;
		}
		if (opp == 0)
		{
			system("cls");
			break;
		}
	} while (1);
}
void Admin::view_all_doctor()
{
	int opp, sr_no = 0;
	ifstream doctor_file("Doctor.txt");
	system("cls");
	cout << "\t-----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t|              |                    |              |                     |               |                |" << endl;
	cout << "\t|    SR NO.    |    Doctor Nname    |    gender    |    qualification    |    contact    |    username    |" << endl;
	cout << "\t|              |                    |              |                     |               |                |" << endl;
	cout << "\t-----------------------------------------------------------------------------------------------------------" << endl;
	while (doctor_file >> first_name >> last_name >>
		department >> d_id >> username >> password >> registration_date >>
		gender >> contact >> blood_group >> adress
		>> qualification >> salary)
	{

		//cin.ignore();
		cout << "\t\t" << ++sr_no << "." << "\t    " << first_name << " " << last_name << "\t\t"
			<< gender << "\t\t   " << qualification << "\t\t  " << contact << "\t\t" << username << endl;
	}
	cout << "\n\t-----------------------------------------------------------------------------------------------------------" << endl;

	doctor_file.close();
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



/*
appointment related funtion
*/
void Admin::make_appointment()
{
	string assing_to = "not_assigned";
	do {
		int opp2;
		int opp;
		int option;
		string ap_time;
		system("cls");
		cout << endl;
		cout << "\t\t\t------------------------------------------------------------------\n";
		cout << "\t\t\t\t\t| A D D - A P P O I N T M E N T |" << endl;
		cout << "\t\t\t------------------------------------------------------------------\n";
		cout << endl << endl << endl;

		cout << "\n\t\t\t\t\tSelect your department :" << endl;
		//department option
		cout << "\t\t\t\t\t1)Dental" << endl;
		cout << "\t\t\t\t\t2)Accident & Emergency " << endl;
		cout << "\t\t\t\t\t3)Orthopedics " << endl;
		cout << "\t\t\t\t\t4)Psychiatry " << endl;
		cout << "\t\t\t\t\t5)Physiotherapy " << endl;
		cout << "\t\t\t\t\tEnter departmetn no. : ";
		cin >> opp;
		while (opp <= 0 || opp > 5)
		{
			cout << "\t\t\t\t\t   Invalid input" << endl;
			cout << "\t\t\t\t\tPlease Enter from 1 to 5 " << endl;
			cout << "\t\t\t\t\tEnter departmetn no. : ";
			cin >> opp;
		}
		department = get_department_name(opp);
		cout << "\t\t\t\t\tSelect its Parent Department" << endl;
		cout << "\t\t\t\t\t1)Periodontics" << endl;
		cout << "\t\t\t\t\t2)Orthodontics" << endl;
		cout << "\t\t\t\t\tEnter departmetn no. : ";
		cin >> opp2;
		while (opp2 <= 0 || opp2 > 2)
		{
			cout << "\t\t\t\t\t   Invalid input" << endl;
			cout << "\t\t\t\t\tPlease Enter from 1 to 5 " << endl;
			cout << "\t\t\t\t\tEnter departmetn no. : ";
			cin >> opp2;
		}
		if (opp2 == 1)
		{
			Parent_Department = "Periodontics";
		}
		else if (opp2 == 2)
		{
			Parent_Department = "Orthodontics";
		}
		cout << "\t\t\t\t\tEnter Appointment Time :";
		cin >> ap_time;
		cout << "\t\t\t\t\tPatient ID is = ";
		cin >> p_id;
		ap_id = generate_appointment_id(opp);
		cout << "\t\t\t\t\tYour appointment Status is = " << ap_id << endl;

		cout << "\t\t\t\t\tYour appointment Status is = ";
		ap_status = "unchecked";  //initially it is uncheck
		cout << ap_status << endl;

		/*
		making file
		*/
		fstream appointment_file("Appointment.txt", ios::app);
		if (appointment_file.is_open())
		{
			appointment_file << p_id << endl << ap_id << endl << department << endl
				<< ap_time << endl << Parent_Department << endl << ap_status << endl << assing_to << endl;
		}

		cout << "\t\t\t\t\t want to make more appointment ? " << endl;
		cout << "\t\t\t\t\t Yes=1 ; No=0 : ";
		while (!(cin >> option))
		{
			cout << endl;
			cout << "\t\t\t\t\tError! Enter again : ";

			cin.clear();
			cin.ignore(123, '\n');
		}

		if (option == 0)
		{
			system("cls");
			break;
		}

	} while (exit);
}
void Admin::assign_appointment()
{
	do {
		system("cls");
		vector <pair<int, string>> dr_list, patient_list;
		string* st = new string[2];
		int opp;
		int select[2];
		//string dr_var[13];
		ifstream patient("Patient.txt");
		ifstream dr("Doctor.txt");
		ifstream appointment("Appointment.txt", ios::app);

		int n = 0;
		cout << "\t\t\t\t---------------Available Doctor's--------------" << endl << endl;
		while (dr >> first_name >> last_name >> department >> d_id >> username >> password >>
			registration_date >> gender >> contact >> blood_group >> adress >> qualification >> salary)
		{
			cout << ++n << ") DR. " << first_name << " " << last_name << endl;
			dr_list.push_back(make_pair(n, d_id));
		}
		n = 0;
		cout << "\t\t\t\t---------------Patient list-------------------" << endl;

		cout << "PATIENT NAME\t\t" << "PATIENT ID\t\t" << "DEPARTMENT \t\t" << "Is Doctor assigned\n";
		while (appointment >> p_id >> ap_id >> department >>
			st[0] >> Parent_Department >> ap_status >> st[1])
		{
			cout << ++n << ")" << get_patient_name(p_id) << "\t\t\t" << p_id << "\t\t\t"
				<< department << "\t\t" << st[1] << endl;
			patient_list.push_back(make_pair(n, p_id));
		}
		appointment.close();
		cout << "\t\t\t\t------------------------------------------------------" << endl;
		cout << "\t\t\t\t\tto assign dr. to apatient\n";
		cout << "\t\t\t\t\tselect patietn number : ";
		cin >> select[0];
		cout << "\t\t\t\t\tselect dr. number : ";
		cin >> select[1];
		assign_doctor(patient_list[(select[0] - 1)].second, dr_list[(select[1] - 1)].second);
		patient_list.clear();
		dr_list.clear();
		cout << "\t\t\t\t\t want to make more appointment ? " << endl;
		cout << "\t\t\t\t\t Yes=1 ; No=0 : ";
		while (!(cin >> opp))
		{
			cout << endl;
			cout << "\t\t\t\t\tError! Enter again : ";

			cin.clear();
			cin.ignore(123, '\n');
		}

		if (opp == 0)
		{
			delete[] st;
			system("cls");
			break;
		}
		system("cls");
	} while (exit);
}
void Admin::update_appointment()
{
	do {
		int option, option1, option2;
		cout << "\t\t\t\t\t1)--> Update Appointment Status" << endl;
		cout << "\t\t\t\t\t2)--> Update Appointment Time " << endl;
		cout << "\t\t\t\t\tEnter  option: ";
		cin >> option1;
		while (option1 > 2 || option1 <= 0)
		{
			cout << "\t\t\t\t\t ---Wrong input ---" << endl;
			cout << "\t\t\t\t\t Enter again: ";
			cin >> option;
		}
		cout << "\t\t\t\t\tEnter Appointment ID :";
		cin >> ap_id;
		if (option1 == 1)
		{
			cout << "\t\t\t\t\tSelect New Status" << endl;
			cout << "\t\t\t\t\t1) checked" << endl;
			cout << "\t\t\t\t\t1) Unchecked" << endl;
			cout << "\t\t\t\t\t Enter: ";
			cin >> option;
			while (option > 2 || option <= 0)
			{
				cout << "\t\t\t\t\t ---Wrong input ---" << endl;
				cout << "\t\t\t\t\t Enter again: ";
				cin >> option;
			}
			if (option == 1)
			{
				update_appointment_status(ap_id, "checked");
			}
			else if (option == 2)
			{
				update_appointment_status(ap_id, "Unchecked");
			}
		}
		if (option1 == 2)
		{
			string time;
			cout << "\t\t\t\t\tEnter New Time :";
			cin >> time;
			update_appointment_time(ap_id, time);
		}
		cout << "\t\t\t\t\t Would You Want to update more Appointment ? " << endl;
		cout << "\t\t\t\t\t Yes=1 ; No=0 : ";
		while (!(cin >> option2))
		{
			cout << endl;
			cout << "\t\t\t\t\tError! Enter again : ";

			cin.clear();
			cin.ignore(123, '\n');
		}

		if (option2 == 0)
		{
			system("cls");
			break;
		}

	} while (exit);
}
void Admin::view_all_appointment()
{
	int opp;
	int sr_no = 0;
	string* var = new string[7];

	ifstream appointment_file("Appointment.txt");

	system("cls");
	cout << "\t---------------------------------------------------------------------------------------------------" << endl;
	cout << "\t|            |                  |                |                    |               |            |" << endl;
	cout << "\t|   SR NO.   |   patient Name   |   patient id   |   Appointment Id   |   Doctor Id   |   Status   |" << endl;
	cout << "\t|            |                  |                |                    |               |            |" << endl;
	cout << "\t----------------------------------------------------------------------------------------------------" << endl;

	while (appointment_file >> var[0] >> var[1] >> var[2] >>
		var[3] >> var[4] >> var[5] >> var[6])
	{
		cout << "\t\t" << ++sr_no << ".\t  " << get_patient_name(var[0]) << "  \t\t" << var[0] << "\t\t" << var[1]
			<< "\t\t" << var[6] << "\t\t" << var[5] << endl;
	}
	appointment_file.close();
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
	delete[] var;

}
void Admin::view_fee()
{
	int opp, sr_no = 0;
	ifstream patient_file("Patient.txt");
	system("cls");

	cout << "\t\t-------------------------------------------------------------------------------" << endl;
	cout << "\t\t|              |                    |                      |                  |" << endl;
	cout << "\t\t|    SR NO.    |    Patient Name    |    Appointment ID    |    Fee status    |" << endl;
	cout << "\t\t|              |                    |                      |                  |" << endl;
	cout << "\t\t-------------------------------------------------------------------------------" << endl;
	while (patient_file >> first_name >> last_name >>
		department >> p_id >> registration_date >>
		gender >> contact >> blood_group >> adress
		>> fee_status >> qualification >> salary)
	{

		cout << "\t\t\t" << ++sr_no << ".\t   " << first_name << " " << last_name << "\t\t  " << p_id << "\t\t" << fee_status << endl;
	}
	patient_file.close();

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


/*
protected
*/
string Admin::get_department_name(int a)
{
	if (a == 1)
	{
		return "Dental";
	}
	else if (a == 2)
	{
		return "Accident-Emergency";
	}
	else if (a == 3)
	{
		return"Orthopedics";
	}
	else if (a == 4)
	{
		return"Psychiatry";
	}
	else if (a == 5)
	{
		return"Physiotherapy";
	}
}
string Admin::generate_patient_id(int opp)
{

	int p_no;
	ifstream patient_number_file;
	ofstream new_patient_number_file("New_patient_number.txt");
	string file_name = "patient_number_" + to_string(opp) + ".txt";
	patient_number_file.open(file_name);


	if (patient_number_file.is_open())
	{
		patient_number_file >> p_no;

		new_patient_number_file << (++p_no);
	}
	patient_number_file.close();
	new_patient_number_file.close();

	if (opp == 1)
	{
		remove("patient_number_1.txt");     //This will delete the old file
		rename("New_patient_number.txt", "patient_number_1.txt");
	}
	else if (opp == 2)
	{
		remove("patient_number_2.txt");     //This will delete the old file
		rename("New_patient_number.txt", "patient_number_2.txt");

	}
	else if (opp == 3)
	{
		remove("patient_number_3.txt");     //This will delete the old file
		rename("New_patient_number.txt", "patient_number_3.txt");

	}
	else if (opp == 4)
	{
		remove("patient_number_4.txt");     //This will delete the old file
		rename("New_patient_number.txt", "patient_number_4.txt");

	}
	else if (opp == 5)
	{
		remove("patient_number_5.txt");     //This will delete the old file
		rename("New_patient_number.txt", "patient_number_5.txt");

	}
	return "0" + to_string(opp) + to_string(--p_no);

}
string Admin::generate_doctor_id(int opp)
{
	int d_no;
	ifstream doctor_number_file;
	string file_name = "D-ID_0" + to_string(opp) + ".txt";
	doctor_number_file.open(file_name);
	ofstream new_doctor_number_file("New_D-ID.txt");

	if (doctor_number_file.is_open())
	{
		doctor_number_file >> d_no;

		new_doctor_number_file << (++d_no);
	}
	doctor_number_file.close();
	new_doctor_number_file.close();

	if (opp == 1)
	{
		remove("D-ID_01.txt");     //This will delete the old file
		rename("New_D-ID.txt", "D-ID_01.txt");
	}
	else if (opp == 2)
	{
		remove("D-ID_02.txt");     //This will delete the old file
		rename("New_D-ID.txt", "D-ID_02.txt");

	}
	else if (opp == 3)
	{
		remove("D-ID_03.txt");     //This will delete the old file
		rename("New_D-ID.txt", "D-ID_03.txt");

	}
	else if (opp == 4)
	{
		remove("D-ID_04.txt");     //This will delete the old file
		rename("New_D-ID.txt", "D-ID_04.txt");

	}
	else if (opp == 5)
	{
		remove("D-ID_05.txt");     //This will delete the old file
		rename("New_D-ID.txt", "D-ID_05.txt");

	}
	return "0" + to_string(opp) + to_string(--d_no);
}
string Admin::generate_appointment_id(int opp)
{
	int ap_no;
	ifstream appointment_file;
	string file_name = "AP-ID_0" + to_string(opp) + ".txt";
	appointment_file.open(file_name);
	ofstream new_appointment_file("New_AP-ID.txt");

	if (appointment_file.is_open())
	{
		appointment_file >> ap_no;

		new_appointment_file << (++ap_no);
	}
	appointment_file.close();
	new_appointment_file.close();

	if (opp == 1)
	{
		remove("AP-ID_01.txt");     //This will delete the old file
		rename("New_AP-ID.txt", "AP-ID_01.txt");
	}
	else if (opp == 2)
	{
		remove("AP-ID_02.txt");     //This will delete the old file
		rename("New_AP-ID.txt", "AP-ID_02.txt");

	}
	else if (opp == 3)
	{
		remove("AP-ID_03.txt");     //This will delete the old file
		rename("New_AP-ID.txt", "AP-ID_03.txt");

	}
	else if (opp == 4)
	{
		remove("AP-ID_04.txt");     //This will delete the old file
		rename("New_AP-ID.txt", "AP-ID_04.txt");

	}
	else if (opp == 5)
	{
		remove("AP-ID_05.txt");     //This will delete the old file
		rename("New_AP-ID.txt", "AP-ID_05.txt");

	}
	return "0" + to_string(opp) + to_string(--ap_no);
}
string Admin::get_patient_name(string id)
{
	///ifstream old_file("Appointment.txt", ios::app);
	ifstream patient("Patient.txt", ios::app);
	while (patient >> first_name >> last_name >>
		department >> p_id >> registration_date >>
		gender >> contact >> blood_group >> adress
		>> fee_status >> qualification >> salary)
	{
		if (p_id == id)
		{
			return first_name;
		}
	}
}
string Admin::input_contact_no()
{
	string num;
	do
	{
		cout << "\t\t\t\t\tEnter Your Contact No. : ";
		cin.ignore();
		cin >> num;
		if (num.length() != 11)
		{
			cout << "\t\t\t\t\t   Invalid contact" << endl;
			cout << "\t\t\t\t\tPlease Enter 11 Digits !" << endl;
		}
	} while (num.length() != 11);
	return num;
}
string Admin::input_adress()
{
	string var;
	cout << "\t\t\t\t\tEnter your Address =";
	cin.ignore();
	getline(cin, var);
	for (int i = 0; i < var.length(); ++i)
	{

		if (var[i] == ' ') {

			var[i] = '-';
		}
	}
	return var;
}
string Admin::input_gender()
{
	int option;
	cout << "\t\t\t\t\tSelect your gender" << endl;
	cout << "\t\t\t\t\t1) Male" << endl;
	cout << "\t\t\t\t\t2) Female" << endl;
	cout << "\t\t\t\t\t Enter: ";
	cin >> option;
	while (option > 2 || option <= 0)
	{
		cout << "\t\t\t\t\t ---Wrong input ---" << endl;
		cout << "\t\t\t\t\t Enter again: ";
		cin >> option;
	}
	if (option == 1)
	{
		return "Male";
	}
	else if (option == 2)
	{
		return "Female";
	}
}

void Admin::update_appointment_status(string id, string new_status)
{
	string* var = new string[7];
	ifstream old_file("Appointment.txt", ios::app);
	ofstream new_file("New_Appointment.txt");

	if (old_file.is_open())
	{
		while (old_file >> var[0] >> var[1] >> var[2] >>
			var[3] >> var[4] >> var[5] >> var[6])
		{
			if (var[1] == id)
			{
				new_file << var[0] << endl << var[1] << endl << var[2] << endl
					<< var[3] << endl << var[4] << endl << new_status << endl << var[6] << endl;
			}
			else
			{
				new_file << var[0] << endl << var[1] << endl << var[2] << endl
					<< var[3] << endl << var[4] << endl << var[5] << endl << var[6] << endl;
			}
		}

	}
	delete[] var;
	new_file.close();
	old_file.close();
	remove("Appointment.txt");
	rename("New_Appointment.txt", "Appointment.txt");
}
void Admin::update_appointment_time(string id, string new_time)
{
	string* var = new string[7];
	ifstream old_file("Appointment.txt", ios::app);
	ofstream new_file("New_Appointment.txt");

	if (old_file.is_open())
	{
		while (old_file >> var[0] >> var[1] >> var[2] >>
			var[3] >> var[4] >> var[5] >> var[6])
		{
			if (var[1] == id)
			{
				new_file << var[0] << endl << var[1] << endl << var[2] << endl << new_time
					<< endl << var[4] << endl << var[5] << endl << var[6] << endl;
			}
			else
			{
				new_file << var[0] << endl << var[1] << endl << var[2] << endl
					<< var[3] << endl << var[4] << endl << var[5] << endl << var[6] << endl;
			}
		}

	}
	delete[] var;
	new_file.close();
	old_file.close();
	remove("Appointment.txt");
	rename("New_Appointment.txt", "Appointment.txt");
}
void Admin::assign_doctor(string p_id, string dr_id)
{
	string* var = new string[7];
	ifstream old_file("Appointment.txt", ios::app);
	ofstream new_file("New_Appointment.txt");

	if (old_file.is_open())
	{
		while (old_file >> var[0] >> var[1] >> var[2] >>
			var[3] >> var[4] >> var[5] >> var[6])
		{
			if (var[0] == p_id)
			{
				new_file << var[0] << endl << var[1] << endl << var[2] << endl
					<< var[3] << endl << var[4] << endl << var[5] << endl << dr_id << endl;
			}
			else
			{
				new_file << var[0] << endl << var[1] << endl << var[2] << endl
					<< var[3] << endl << var[4] << endl << var[5] << endl << var[6] << endl;
			}
		}

	}
	delete[] var;
	new_file.close();
	old_file.close();
	remove("Appointment.txt");
	rename("New_Appointment.txt", "Appointment.txt");
}
void Admin::make_username_file(string file_name, string user_name, string password, string id)
{

	fstream file(file_name, ios::app);
	if (file.is_open())
	{
		file << user_name << endl << password << endl << id << endl;
	}
	else
	{
		cout << "Unable to open " << file_name << endl;
	}
}
