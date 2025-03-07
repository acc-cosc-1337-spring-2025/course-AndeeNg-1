#include <iostream>
#include <string>
#include "func.h"

using namespace std;

int main() 
{
	int choice;
    string dna;

    do {
        cout << "\nMenu:\n";
        cout << "1 - Get GC Content\n";
        cout << "2 - Get DNA Complement\n";
        cout << "3 - Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            cout << "Enter DNA string: ";
            cin >> dna;

            // Input validation: Ensure only valid DNA characters
            bool valid = true;
            for (char nucleotide : dna) {
                if (nucleotide != 'A' && nucleotide != 'T' && nucleotide != 'C' && nucleotide != 'G') {
                    valid = false;
                    break;
                }
            }

            if (!valid) {
                cout << "Invalid DNA string! Please enter only A, T, C, and G.\n";
                continue;
            }

            if (choice == 1) {
                cout << "GC Content: " << (get_gc_content(dna) * 100) << "%\n";  // Convert to percentage
            } else if (choice == 2) {
                cout << "DNA Complement: " << get_dna_complement(dna) << "\n";
            }
        } else if (choice != 3) {
            cout << "Invalid choice! Please enter 1, 2, or 3.\n";
        }

    } while (choice != 3);

    cout << "Goodbye and thank you!\n";
	return 0;
}
