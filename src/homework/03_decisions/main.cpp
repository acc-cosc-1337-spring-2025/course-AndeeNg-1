//write include statements
#include <iostream>
#include "decisions.h"
using std::cout; using std::cin;

int main() 
{
	int choice, grade;

    cout << "MAIN MENU\n";
    cout << "1 - Letter grade using if\n";
    cout << "2 - Letter grade using switch\n";
    cout << "3 - Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1 || choice == 2) {
        cout << "Enter a numerical grade (0-100): ";
        cin >> grade;

        if (grade < 0 || grade > 100) {
            cout << "Error: Grade out of range!\n";
        } else {
            if (choice == 1)
                cout << "Letter grade (if-else): " << get_letter_grade_using_if(grade) << "\n";
            else
                cout << "Letter grade (switch): " << get_letter_grade_using_switch(grade) << "\n";
        }
    } else if (choice == 3) {
        cout << "Exiting program...\n";
    } else {
        cout << "Invalid choice!\n";
    }
	return 0;
}