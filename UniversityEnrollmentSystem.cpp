#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;


void student();
void viwestudent();
void course();
void viwecourse();
void withdrawcourse();
void course_roster();
void logout();
string getCurrentDate();
void enrollstudent();
void viwe_withdrawcourse();
void course_roster();
void viwe_course_roster();
void viwe_enrollstudent();

int main()
{
	while (true)
	{
			string correct_password, correct_username, password, username;
			int choice;
			bool logging = false;

			//administrators logging username and password

			correct_password = ("1234");
			correct_username = ("uni");

			//administrators login
			cout << "========================================================================================================================\n\n";
			cout << "\t\t\t\t\t\tUNIVERSITY ENROLLMENT SYSTEM LOGIN\t\t\t\t\t\t\n";
			cout << "========================================================================================================================\n\n\n";
			// Allow up to 3 attempts for user
			for (int attempt = 1; attempt <= 3; attempt++) {
				cout << "You have only  3 Attempt \n";

				cout << "Enter the correct username:" ;
				cin >> username;
				cout << "Enter the correct password:";
				cin >> password;




				if (password == correct_password && username == correct_username)
				{
					cout << "\t\t YOUR LOGING IS SUCCESSFUL \n\n";
					logging = true;

					//if login successful this is the exit

					break;
				}
				else
				{
					cout << "YOUR USERNAME OR PASSWORD IS INCORRECT , TRY AGAIN!";
				}
			}
			//after finished 3 attempts
			if (!logging)
			{
				cout << "\n YOU HAVE EXECEEDED 3 LOGIN ATTEMPTS. ACCESS DENIED\n";


				return 0;
			}

			//MAIN MENU SHOWS ONLY IF LOGIN SUCCESSFUL
			do
			{
				//main menu

				cout << "\t\t_____________________MAIN MENU_______________________\n\n";
				cout << "\t\t 1.Add student\n";
				cout << "\t\t 2.Check student list\n";
				cout << "\t\t 3.Add course\n";
				cout << "\t\t 4.Viwe courses\n";
				cout << "\t\t 5.Enroll in course\n";
				cout << "\t\t 6.Withdraw from course\n";
				cout << "\t\t 7.View course roster\n";
				cout << "\t\t 8. View enrollments\n";
				cout << "\t\t 9. View course withdrawals\n";
				cout << "\t\t 10.Logout\n";
				cout << "\t\t 11.Exit\n\n "<<endl;

				cout << "select your choice (1-9):";
				cin >> choice;

				switch (choice)
				{
				case 1:
				{
					student();
					break;
				}

				case 2:
				{
					viwestudent();
					break;
				}

				case 3:
				{
					course();
					break;
				}

				case 4:
				{
					viwecourse();
					break;

				}
				case 5:
				{
					enrollstudent();
					break;
				}
				case 6:
				{
					withdrawcourse();
					break;
				}
				case 7:
				{
					viwe_course_roster();
					break;
				}
				case 8:
				{
					viwe_enrollstudent();
					break;
				}
				case 9:
				{
					viwe_withdrawcourse();
					break;
				}
				case 10:
				{
					logout();
					logging = false;
					break;
				}
				case 11:
				{
					cout << "HAVE A GOOD DAY , THANK YOU !.....\n";
					break;
				}
				

				default:
					cout << "Invalid choice. Try again!\n";
				}

			} while (logging);
    }
}


struct students
{
	string s_id, s_name, s_course;

};

void student()
{
		ofstream student_info("students.txt", ios::app);

		students details;

		cout << "Enter student ID:";
		cin >> details.s_id;
		student_info << details.s_id << endl;

		cout << "Enter student NAME:";
		cin >> details.s_name;
		student_info << details.s_name << endl;

		cout << "Enter student COURSE:";
		cin >> details.s_course;
		student_info << details.s_course << endl;

		student_info << "--------------------------------------------STUDENT RECORD--------------------------------------------------- \n";
}



void viwestudent()
{
	ifstream file("students.txt");

	cout << endl;
	string line;

	if (file.is_open())
	{


		while (getline(file, line))
		{
			cout << line << endl;
		}

		cout << "The file exported successfully!\n\n";

		file.close();
	}
	else
	{
		cout << " YOUR FILE IS NOT WORKING PROPERLY ....\n";

	}
}

struct courses
{
	string c_code, c_name, c_max;
};


void course()
{
	ofstream course_info("courses.txt",ios::app);

	courses details;

	cout << "Enter Course code:";
	cin >> details.c_code;
	course_info << details.c_code << endl;

	cout << "Enter Course Name:";
	cin >> details.c_name;
	course_info << details.c_name << endl;

	cout << "Enter Course Maximum Capacity:";
	cin >> details.c_max;
	course_info << details.c_max << endl;

}

void viwecourse()
{

	ifstream file("courses.txt");

	cout << endl;
	string line;

	if (file.is_open())
	{


		while (getline(file, line))
		{
			cout << line << endl;
		}

		cout << "The file expored successfully!\n\n";

		file.close();
	}
	else
	{
		cout << " YOUR FILE IS NOT WORKING PROPERLY ....\n";

	}
}


string getCurrentDate()
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now); // Safe version of localtime()

	ostringstream oss;
	oss << put_time(&ltm, "%Y-%m-%d");
	return oss.str();
}


struct enroll
{
	string s_name , c_name,date;
};



void enrollstudent()
{
	

	ofstream enroll_info("enrollment.txt", ios::app);

	enroll  details;

	cout << "Enter Student name:";
	cin >> details.s_name;
	enroll_info << details.s_name << endl;

	cout << "Enter Course Name:";
	cin >> details.c_name;
	enroll_info << details.c_name << endl;

	details.date = getCurrentDate();
	if (enroll_info.is_open())
	{

		enroll_info << details.s_name << "|" << details.c_name << "|" << details.date << endl;
		enroll_info.close();
		cout << "\n___enrollment recorded successfully on __\n\n" << details.date << endl;
	}
	else
	{
		cout << "FILE COULD NOT OPEN TO SAVE ENROLLMENT INFO.\n";
	}
	
}


void viwe_enrollstudent()
{

	ifstream file("enrollment.txt");

	cout << endl;
	string line;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			cout << line << endl;
		}

		cout << "\n___enrollment recorded successfully on __\n\n" << endl;
		file.close();
	}
	else
	{
		cout << "FILE COULD NOT OPEN TO SAVE ENROLLMENT INFO.\n";
	}

}


struct withdraw 
{
	string s_name, c_name, date  ;
};


void withdrawcourse()
{

	ofstream withdraw_info("withdrawcourse.txt", ios::app);

	enroll  details;

	cout << "Enter Student name:";
	cin >> details.s_name;
	withdraw_info << details.s_name << endl;

	cout << "Enter Course Name:";
	cin >> details.c_name;
	withdraw_info << details.c_name << endl;

	details.date = getCurrentDate();
	if (withdraw_info.is_open())
	{

		withdraw_info << details.s_name << "|" << details.c_name << "|" << details.date << endl;
		withdraw_info.close();
		cout << "\n___withdrawal recorded successfully on __\n\n" << details.date << endl;
	}
	else
	{
		cout << "FILE COULD NOT OPEN TO SAVE WITHDRAWAL INFO.\n";
	}
}

void viwe_withdrawcourse()
{

	ifstream file("withdrawcourse.txt");

	cout << endl;
	string line;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			cout << line << endl;
		}

		cout << "\n______withdrawal recorded successfully on ____\n\n" << endl;
		file.close();
	}
	else
	{
		cout << "FILE COULD NOT OPEN TO SAVE  WITHDRAWAL INFO.\n";
	}

}

struct rosters 
{
	string s_name, id_num, enrollment_date, email;

};

void course_roster()
{
	ofstream rosters_info ("course_roster.txt", ios::app);

	rosters details;

	cout << "Enter Student name:";
	cin >> details.s_name;
	

	cout << "Enter Id Number:";
	cin >> details.id_num;
	

	cout << "Enter Your Email:";
	cin >> details.email;
	

	details.enrollment_date = getCurrentDate();

	if (rosters_info.is_open())
	{

		rosters_info<< details.s_name << "|" << details.id_num << "|" << details.enrollment_date << endl;
		rosters_info.close();
		cout << "\n__Course roster entry recorded successfully on: __\n\n" << details.enrollment_date << endl;
	}
	else
	{
		cout << "FILE COULD NOT OPEN TO SAVE COURSE ROSTER INFO \n";
	}
}

void viwe_course_roster()
{
	ifstream file("course_roster.txt");

	cout << endl;
	string line;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			cout << line << endl;
		}

		cout << "\n___course roster recorded successfully on __\n\n" << endl;
		file.close();
	}
	else
	{
		cout << "FILE COULD NOT OPEN TO SAVE COURSE ROSTER INFO.\n";
	}

}

void logout()
{
	cout << "======================================================================================\n\n";
	cout << "\t\t\tYOU HAVE BEEN LOGGED OUT SUCCESSFULLY.\t\t\t\n";
	
	cout << "======================================================================================\n\n"<<endl;
	cout << endl;
	cout << endl;

} 
	
