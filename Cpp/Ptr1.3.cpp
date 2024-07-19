#include <iostream>
#include <string>
using namespace std;

class Room {
    int roll;
    string name;
    int mark;

public:
    Room() {
        roll = 0;
        name = "\0";
        mark = 0;
    }

    Room(int r, string n, int m) {
        roll = r;
        name = n;
        mark = m;
    }

    void show() {
        cout << roll << ") " << name << " -> " << mark << endl;
    }

    int getMark() const {
        return mark;
    }

    string getName() const {
        return name;
    }
};

double calculateAverage(Room Arr[], int size) {
    double totalMarks = 0;

    for (int i = 0; i < size; i++) {
        totalMarks += Arr[i].getMark();
    }

    return (size > 0) ? totalMarks / size : 0;
}

string findTopper(Room Arr[], int size) {
    if (size <= 0) {
        return "No students to find the topper.";
    }

    int maxMark = Arr[0].getMark();
    string topperName = Arr[0].getName();

    for (int i = 1; i < size; i++) {
        if (Arr[i].getMark() > maxMark) {
            maxMark = Arr[i].getMark();
            topperName = Arr[i].getName();
        }
    }

    return topperName;
}

int main() {
    cout << "Hello World" << endl;

    cout << "Enter the number of Students: ";
    int n;
    cin >> n;

    Room Arr[n];

    for (int i = 0; i < n; i++) {
        int roll;
        string name;
        int mark;

        cout << "Enter Roll, Name, and Marks for Student " << i + 1 << ": ";
        cin >> roll >> name >> mark;

        Arr[i] = Room(roll, name, mark);
    }

    // Display student details
    cout << "\nStudent Details:\n";
    for (int i = 0; i < n; i++) {
        Arr[i].show();
    }

    // Calculate and display average marks
    double average = calculateAverage(Arr, n);
    cout << "\nAverage Marks: " << average << endl;

    // Find and display the name of the topper
    string topper = findTopper(Arr, n);
    cout << "Topper: " << topper << endl;

    return 0;
}