//Assingment problem statement 2 

#include <iostream>
using namespace std;

class Employee {
    string ID;
    string name;
    string designation;
    string department;
    int rating;
    double salary;

    public:
        Employee();
        Employee(string,string,string,string, double);
        void display();
        void conductAppraisal();
        
        //getters:
        string getID(){        return ID; }
        string getName(){   return name; }
        string getDesig(){   return designation; }
        string getDept(){   return department; }
        int getRating(){    return rating; }
        double getSalary(){ return salary; }

        //setters:
        void setDesig(string desig) {   designation = desig; }
        void setDepartment(string dept){department = dept; }
        void setSalary(double sal) {    salary = sal; }
        void setRating(int rat) {       rating = rat; }
     
};

Employee :: Employee(){
    ID="";
    name="";
    designation="";
    department="";
    salary=0;
}

Employee :: Employee(string i,string n, string desig,
                        string dept, double sal){
    ID=i;
    name=n;
    designation=desig;
    department=dept;
    salary=sal;
}

void Employee ::display() {
    cout << "Employee ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Designation: " << designation << endl;
    cout << "Department: " << department << endl;
    cout << "Salary: " << salary << endl;
}

void Employee :: conductAppraisal() {
    double incrementPercentage;
    switch (rating) {
        case 1: incrementPercentage = 0.05; break;
        case 2: incrementPercentage = 0.10; break;
        case 3: incrementPercentage = 0.15; break;
        case 4: incrementPercentage = 0.20; break;
        case 5: incrementPercentage = 0.25; break;
        default: incrementPercentage = 0.0; break;
    }
    salary += salary * incrementPercentage;
}

class EmployeeManagementSystem {
    static const int max = 100;
    Employee emp[max];
    int size=-1;

    public:
        EmployeeManagementSystem(){
        }
        // Add Employee
        void addEmployee() {
            string id, name, desig, dept;
            double salary;
            cout << "Enter Employee ID: "; 
            cin >> id;
            cout << "Enter Name: ";
            cin>> name;
            cout << "Enter Designation: ";
            cin>>desig;
            cout << "Enter Department: ";
            cin>>desig;
            cout << "Enter Salary: ";
            cin >> salary;
            
            size++;
            emp[size]= Employee (id,name,desig,dept,salary);
            cout << "Employee added successfully!" << endl;
        }

        // Display Employee Details
        void displayEmployeeDetails() {
            if (size==-1) {
                cout << "No employees found." << endl;
                return;
            }
            cout << "Employee Details:" << endl<<endl;
            for (int i=0;i<=size; i++) {
                emp[i].display();
                cout << endl;
            }
        }

        // Update Employee Details
        void updateEmployeeDetails() {
            string id;
            int found = 0;
            cout << "Enter Employee ID to update details: ";
            cin >> id;

            for (int i = 0; i <=size; i++){
                if(emp[i].getID() == id){
                    found=1;
                    string desig, dept;
                    double salary;
                    cout << "Enter New Designation: ";
                    cin >> desig;
                    cout << "Enter New Department: ";
                    cin >>dept;
                    cout << "Enter New Salary: ";
                    cin >> salary;

                    emp[i].setDesig(desig);
                    emp[i].setDepartment(dept);
                    emp[i].setSalary(salary);
                    cout << "Employee details updated successfully!"
                         << endl;
                } 
            }
            if(found == 0){
                cout << "Employee with ID " << id << " not found." 
                     << endl;
            }
        }

        // Search Employee
        void searchEmployee() {
            string key;
            int found = 0;
            cout << "Enter Employee ID or Name to search: ";
            cin>>key;
            for (int i = 0; i <=size; i++){
                if(emp[i].getID() == key || emp[i].getName()== key){
                    emp[i].display();
                    found = 1;
                }
            }
            if(found == 0){
                cout << "Employee not found." << endl;
            }          
        }

        // Conduct Appraisal for all employees
        // Conduct Appraisal for all employees
        void conductAppraisal() {
            if (size==-1) {
                cout << "No employees found." << endl;
                return;
            }
            for (int i = 0; i <=size; i++){
                int rating;
                cout << "Enter Rating for Employee " 
                     << emp[i].getID() << ": ";
                cin >> rating;
                emp[i].setRating(rating);
                emp[i].conductAppraisal();
            }
        cout << "Appraisal conducted successfully!" 
             << endl;    
        }
};

int main() {
    EmployeeManagementSystem empSystem;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employee Details\n";
        cout << "3. Update Employee Details\n";
        cout << "4. Search Employee\n";
        cout << "5. Conduct Appraisal\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                empSystem.addEmployee();
                break;
            case 2:
                empSystem.displayEmployeeDetails();
                break;
            case 3:
                empSystem.updateEmployeeDetails();
                break;
            case 4:
                empSystem.searchEmployee();
                break;
            case 5:
                empSystem.conductAppraisal();
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." 
                     << endl;
        }
    } while (choice != 6);

    return 0;
}