#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // Include the <sstream> header for stringstream
using namespace std;

// Function to convert an integer to a string
string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}


// Function to write data to a file
void writeToFile(const string& filename, const string& data) {
    ofstream file(filename.c_str(), ios::out);
    if (file.is_open()) {
        file << data;
        file.close();
        cout << "Data written to file '" << filename << "' successfully." << endl;
    } else {
        cout << "Unable to open the file '" << filename << "'." << endl;
    }
}

// Function to read data from a file
void readFromFile(const string& filename) {
    ifstream file(filename.c_str(), ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open the file '" << filename << "'." << endl;
    }
}

void writeStudentDataToFile(const string& filename, const string& data) {
    ofstream file(filename.c_str(), ios::app); // Open the file in append mode
    if (file.is_open()) {
        file << data << endl;
        file.close();
        cout << "Student data written to file '" << filename << "' successfully." << endl;
    } else {
        cout << "Unable to open the file '" << filename << "'." << endl;
    }
}

void writeFacultyDataToFile(const string& filename, const string& data) {
    ofstream file(filename.c_str(), ios::app); // Open the file in append mode
    if (file.is_open()) {
        file << data << endl;
        file.close();
        cout << "Faculty data written to file '" << filename << "' successfully." << endl;
    } else {
        cout << "Unable to open the file '" << filename << "'." << endl;
    }
}

struct StudentData {
    string name;
    string registrationNumber;
};

class User {
protected:
    string username;
    string password;
    bool isAdmin;

public:
    User(const string& username, const string& password, bool isAdmin = false)
        : username(username), password(password), isAdmin(isAdmin) {}

    bool authenticate(const string& enteredUsername, const string& enteredPassword) const {
        return (username == enteredUsername && password == enteredPassword);
    }

    bool isAdministrator() const {
        return isAdmin;
    }
};

class Student : public User {
private:
    string name;
    string registrationNumber;

public:
    Student(const string& name, const string& registrationNumber, const string& username, const string& password)
        : User(username, password), name(name), registrationNumber(registrationNumber) {}

    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Registration Number: " << registrationNumber << endl;
    }

    const string& getName() const {
        return name;
    }

    const string& getRegistrationNumber() const {
        return registrationNumber;
    }
    
    void viewCourses() {
	    cout << "Viewing courses for student with registration number: " << registrationNumber << endl;
	
	    ifstream file("courses.txt");
	    if (file.is_open()) {
	        string line;
	        while (getline(file, line)) {
	            // Extract the course title from each line
	            size_t pos = line.find("Course Title: ");
	            if (pos != string::npos) {
	                string courseTitle = line.substr(pos + 14);
	                cout << courseTitle << endl;
	            }
	        }
	        file.close();
	    } else {
	        cout << "Unable to open the courses file." << endl;
	    }
	}
	void viewAttendance() {
	    cout << "Viewing attendance for student with registration number: " << registrationNumber << endl;
	
	    ifstream file("attendance.txt");
	    if (file.is_open()) {
	        string line;
	        bool foundStudent = false;
	        while (getline(file, line)) {
	            // Check if the line contains the student's registration number
	            size_t pos = line.find("Registration Number: ");
	            if (pos != string::npos && line.substr(pos + 21) == registrationNumber) {
	                foundStudent = true;
	                break;
	            }
	        }
	
	        if (foundStudent) {
	            // Display the attendance details for the student
	            cout << "Attendance details:" << endl;
	            while (getline(file, line)) {
	                // Check if the line contains the attendance data for the student
	                size_t pos = line.find("Attendance: ");
	                if (pos != string::npos) {
	                    string attendance = line.substr(pos + 12);
	                    cout << attendance << endl;
	                }
	            }
	        } else {
	            cout << "No attendance record found for the student." << endl;
	        }
	
	        file.close();
	    } else {
	        cout << "Unable to open the attendance file." << endl;
	    }
	}
	void viewGrade() {
	    cout << "Viewing grades for student with registration number: " << registrationNumber << endl;
	
	    ifstream file("grades.txt");
	    if (file.is_open()) {
	        string line;
	        bool foundStudent = false;
	        while (getline(file, line)) {
	            // Check if the line contains the student's registration number
	            size_t pos = line.find("Registration Number: ");
	            if (pos != string::npos && line.substr(pos + 21) == registrationNumber) {
	                foundStudent = true;
	                break;
	            }
	        }
	
	        if (foundStudent) {
	            // Display the grade details for the student
	            cout << "Grade details:" << endl;
	            while (getline(file, line)) {
	                // Check if the line contains the grade data for the student
	                size_t pos = line.find("Grade: ");
	                if (pos != string::npos) {
	                    string grade = line.substr(pos + 7);
	                    cout << grade << endl;
	                }
	            }
	        } else {
	            cout << "No grade record found for the student." << endl;
	        }
	
	        file.close();
	    } else {
	        cout << "Unable to open the grades file." << endl;
	    }
	}
	void viewFee() {
	    cout << "Viewing fee details for student with registration number: " << registrationNumber << endl;
	
	    ifstream file("fees.txt");
	    if (file.is_open()) {
	        string line;
	        bool foundStudent = false;
	        while (getline(file, line)) {
	            // Check if the line contains the student's registration number
	            size_t pos = line.find("Registration Number: ");
	            if (pos != string::npos && line.substr(pos + 21) == registrationNumber) {
	                foundStudent = true;
	                break;
	            }
	        }
	
	        if (foundStudent) {
	            // Display the fee details for the student
	            cout << "Fee details:" << endl;
	            while (getline(file, line)) {
	                // Check if the line contains the fee data for the student
	                size_t pos = line.find("Fee: ");
	                if (pos != string::npos) {
	                    string fee = line.substr(pos + 5);
	                    cout << fee << endl;
	                }
	            }
	        } else {
	            cout << "No fee record found for the student." << endl;
	        }
	
	        file.close();
	    } else {
	        cout << "Unable to open the fees file." << endl;
	    }
	}
};

class Faculty : public User {
private:
    string name;

public:
    Faculty(const string& name, const string& username, const string& password)
        : User(username, password), name(name) {}

    void displayInfo() const {
        cout << "Name: " << name << endl;
    }
    
    void markAttendance() {
	    string registrationNumber, attendanceStatus;
	
	    cout << "Enter registration number: ";
	    getline(cin, registrationNumber);
	
	    cout << "Enter attendance status (Present/Absent): ";
	    getline(cin, attendanceStatus);
	
	    // Create a string with the attendance details
	    string attendanceDetails = "Registration Number: " + registrationNumber + "\n";
	    attendanceDetails += "Attendance: " + attendanceStatus + "\n";
	
	    ofstream file("attendance.txt", ios::app);
	    if (file.is_open()) {
	        file << attendanceDetails << endl;
	        cout << "Attendance marked successfully." << endl;
	        file.close();
	    } else {
	        cout << "Unable to open the attendance file." << endl;
	    }
	}
	
	void submitFee() {
    string registrationNumber, fee;

    cout << "Enter registration number: ";
    getline(cin, registrationNumber);

    cout << "Enter fee: ";
    getline(cin, fee);

    // Create a string with the fee details
    string feeDetails = "Registration Number: " + registrationNumber + "\n";
    feeDetails += "Fee: " + fee + "\n";

    ofstream file("fees.txt", ios::app);
    if (file.is_open()) {
        file << feeDetails << endl;
        cout << "Fee submitted successfully." << endl;
        file.close();
    } else {
        cout << "Unable to open the fees file." << endl;
    }
}
    
	
    void createAssessment() {
        string assessmentTitle;
        string assessmentDescription;

        cout << "Enter assessment title: ";
        cin.ignore(); // Ignore the newline character from previous input
        getline(cin, assessmentTitle);

        cout << "Enter assessment description: ";
        getline(cin, assessmentDescription);

        string assessmentData = "Title: " + assessmentTitle + "\nDescription: " + assessmentDescription;

        // Write the assessment data to the assessments file
        writeFacultyDataToFile("assessments.txt", assessmentData);
    }

    void viewAttendance() {
        // Read and display attendance data from the file
        readFromFile("attendance.txt");
    }

    void viewAssessments() {
        // Read and display assessment data from the file
        readFromFile("assessments.txt");
    }

    const string& getName() const {
        return name;
    }
};


class Admin : public User {
public:
    Admin(const string& username, const string& password)
        : User(username, password, true) {}

    void registerStudent() {
        string name;
        string registrationNumber;
        string username;
        string password;

        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter student registration number: ";
        cin >> registrationNumber;

        cout << "Enter student username: ";
        cin >> username;

        cout << "Enter student password: ";
        cin >> password;

        Student student(name, registrationNumber, username, password);

        string studentData = "Name: " + name + "\nRegistration Number: " + registrationNumber + "\nUsername: " + username + "\nPassword: " + password;

        // Write the student data to the student file
        writeStudentDataToFile("students.txt", studentData);
    }

    void registerFaculty() {
        string name;
        string username;
        string password;

        cout << "Enter faculty name: ";
        cin >> name;

        cout << "Enter faculty username: ";
        cin >> username;

        cout << "Enter faculty password: ";
        cin >> password;

        Faculty faculty(name, username, password);

        string facultyData = "Name: " + name + "\nUsername: " + username + "\nPassword: " + password;

        // Write the faculty data to the faculty file
        writeFacultyDataToFile("faculty.txt", facultyData);
    }
    
    void enrollStudentInCourse() {
        string registrationNumber;
        string courseTitle;

        cout << "Enter student registration number: ";
        cin >> registrationNumber;

        cout << "Enter course title: ";
        cin.ignore(); // Ignore the newline character from previous input
        getline(cin, courseTitle);

        string enrollmentData = "Student Registration Number: " + registrationNumber + "\nCourse Title: " + courseTitle;

        // Write the enrollment data to the enrollments file
        writeStudentDataToFile("enrollments.txt", enrollmentData);
    }

    void assignCourse() {
	    string facultyName, courseTitle, semester;
	    int creditHours;
	
	    cout << "Enter faculty name: ";
	    getline(cin, facultyName);
	
	    cout << "Enter course title: ";
	    getline(cin, courseTitle);
	
	    cout << "Enter semester: ";
	    getline(cin, semester);
	
	    cout << "Enter credit hours: ";
	    cin >> creditHours;
	    cin.ignore(); // Ignore the newline character after reading the credit hours
	
	    // Create a string with the course details
	    string courseDetails = "Faculty Name: " + facultyName + "\n";
	    courseDetails += "Course Title: " + courseTitle + "\n";
	    courseDetails += "Semester: " + semester + "\n";
	    courseDetails += "Credit Hours: " + intToString(creditHours) + "\n";
	
	    ofstream file("courses.txt", ios::app);
	    if (file.is_open()) {
	        file << courseDetails << endl;
	        cout << "Course added successfully." << endl;
	        file.close();
	    } else {
	        cout << "Unable to open the courses file." << endl;
	}
}
};

int main() {
    string enteredUsername;
    string enteredPassword;

    // Asking the credentials for the authentication purpose
    cout << "Please log in by providing your username and password!" << endl;

    cout << "Enter username: ";
    cin >> enteredUsername;

    cout << "Enter password: ";
    cin >> enteredPassword;

    bool isAuthenticated = false;
    bool isAdmin = false;
    bool isFaculty = false;
    bool isStudent = false;

    Admin admin("admin_username", "admin_password"); // Create an instance of Admin class
    Student student("student_name", "student_registration_number", "student_username", "student_password"); // Create an instance of Student class
    Faculty faculty("faculty_name", "faculty_username", "faculty_password"); // Create an instance of Faculty class

    if (admin.authenticate(enteredUsername, enteredPassword)) {
        isAuthenticated = true;
        isAdmin = true;
        cout << "Authentication successful. You are logged in as an admin." << endl;
    } else if (student.authenticate(enteredUsername, enteredPassword)) {
        isAuthenticated = true;
        isStudent = true;
        cout << "Authentication successful. You are logged in as a student." << endl;
    } else if (faculty.authenticate(enteredUsername, enteredPassword)) {
        isAuthenticated = true;
        isFaculty = true;
        cout << "Authentication successful. You are logged in as a faculty member." << endl;
    } else {
        cout << "Authentication failed. Exiting..." << endl;
        return 0;
    }

    if (isAuthenticated) {
        while (true) {
            if (isAdmin) {
                int choice;
                cout << "Choose from the menu below:" << endl;
                cout << "Press 1 to register a student." << endl;
                cout << "Press 2 to register a faculty member." << endl;
                cout << "Press 3 to assign a course to a faculty member." << endl;
                cout << "Press 4 to enroll a student in a course." << endl;
                cout << "Press 0 to exit." << endl; // Added option to exit
                cout << "Enter your choice: ";
                cin >> choice;
            
                if (choice == 0) {
                    cout << "Exiting..." << endl;
                    break; // Exit the loop
                }
            
                // Handle admin menu options
                switch (choice) {
                    case 1:
                        admin.registerStudent();
                        break;
                    case 2:
                        admin.registerFaculty();
                        break;
                    case 3:
                        admin.assignCourse();
                        break;
                    case 4:
                        admin.enrollStudentInCourse(); // Call the new function to enroll a student in a course
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                }
            } else if (isFaculty) {
                int choice;
                cout << "Choose from the menu below:" << endl;
                cout << "Press 1 to mark attendance." << endl;
                cout << "Press 2 to view attendance." << endl;
                cout << "Press 3 to create an assessment." << endl;
                cout << "Press 4 to view an assessment." << endl;
                cout << "Press 0 to exit." << endl; // Added option to exit
                cout << "Enter your choice: ";
                cin >> choice;
            
                if (choice == 0) {
                    cout << "Exiting..." << endl;
                    break; // Exit the loop
                }
            
                // Handle faculty menu options
                switch (choice) {
                    case 1: {
                        faculty.markAttendance();
                        break;
                    }
                    case 2: {
                        faculty.viewAttendance();
                        break;
                    }
                    case 3: {
                        faculty.createAssessment();
                        break;
                    }
                    case 4: {
                        faculty.viewAssessments();
                        break;
                    }
                    default:
                        cout << "Invalid choice." << endl;
                }
            } else if (isStudent) {
                int choice;
                cout << "Choose from the menu below:" << endl;
                cout << "Press 1 to view course schedule." << endl;
                cout << "Press 2 to view grades." << endl;
                cout << "Press 0 to exit." << endl; // Added option to exit
                cout << "Enter your choice: ";
                cin >> choice;
            
                if (choice == 0) {
                    cout << "Exiting..." << endl;
                    break; // Exit the loop
                }
            
                // Handle student menu options
                switch (choice) {
		            case 1:
		                // View courses
		                student.viewCourses();
		                break;
		            case 2:
		                // View attendance
		                student.viewAttendance();
		                break;
		            case 3:
		                // View grades
		                student.viewGrade();
		                break;
		            case 4:
		                // View fees
		                student.viewFee();
		                break;
		            default:
		                cout << "Invalid choice." << endl;
		        }
            }
        }
    }

    return 0;
}



