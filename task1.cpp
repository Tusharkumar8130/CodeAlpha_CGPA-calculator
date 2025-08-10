#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<string> courseNames(numCourses);
    vector<double> grades(numCourses);
    vector<int> creditHours(numCourses);

    double totalCredits = 0, totalGradePoints = 0;

    // Taking course details as input
    for (int i = 0; i < numCourses; i++) {
        cout << "\nEnter name of course " << i + 1 << ": ";
        cin >> courseNames[i];
        cout << "Enter grade (on 10-point scale) for " << courseNames[i] << ": ";
        cin >> grades[i];
        cout << "Enter credit hours for " << courseNames[i] << ": ";
        cin >> creditHours[i];

        totalCredits += creditHours[i];
        totalGradePoints += grades[i] * creditHours[i];
    }

    // Calculate GPA for semester
    double GPA = totalGradePoints / totalCredits;

    // Display results
    cout << "\n--- Semester Report ---\n";
    cout << left << setw(15) << "Course" << setw(10) << "Grade" << "Credits\n";
    for (int i = 0; i < numCourses; i++) {
        cout << left << setw(15) << courseNames[i]
             << setw(10) << grades[i]
             << creditHours[i] << "\n";
    }

    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nGPA (Semester): " << fixed << setprecision(2) << GPA;

    // Assuming this is the only semester (so CGPA = GPA)
    cout << "\nCGPA (Overall): " << fixed << setprecision(2) << GPA << "\n";

    return 0;
}
