using namespace std;
class Patient
{
public:
	void display();
protected:

	bool sign_in();
	void view_fee();
	void view_appointment_Status();
	string get_doctor_name(string);
private:
	string id;
};