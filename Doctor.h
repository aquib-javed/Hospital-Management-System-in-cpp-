using namespace std;
class Doctor
{
public:
	void display();
protected:
	bool sign_in();
	void Doctor_appointment();
	void update_appointment();
private:
	string d_id;
};