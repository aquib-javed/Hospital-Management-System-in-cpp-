using namespace std;
class Admin
{
public:
	void display();
	bool sign_in();
	//doctor funtions
	void add_doctor();
	void edit_doctor();
	void view_all_doctor();

	//patient funtions
	void add_patient();
	void edit_patient();
	void view_all_patient();
	//appointment funtion 
	void make_appointment();
	void assign_appointment();
	void update_appointment();
	void view_all_appointment();
	void update_appointment_status(string, string);
	void view_fee();
protected:
	string get_department_name(int);
	string generate_patient_id(int);
	string generate_doctor_id(int);
	string generate_appointment_id(int);
	string get_patient_name(string);
	string input_contact_no();
	string input_adress();
	string input_gender();
	void assign_doctor(string, string);
	void make_username_file(string, string, string, string);
	void update_appointment_time(string, string);


private:
	//these variable will be use to store data
	string first_name;
	string last_name;
	string department;
	string d_id; //dr. id
	string p_id; //patient id
	string username;
	string password;
	string registration_date;
	string gender;
	string contact;
	string blood_group;
	string adress;
	string fee_status;
	string qualification;
	string salary;
	string ap_id; //appointment id
	string ap_status;
	string Parent_Department;
};