//add include statements
#include "func.h"

//add function code here
double get_gc_content(const std::string& dna) {
    if (dna.empty()) return 0.0;  // Handle empty string case

    int gc_count = 0;
    for (char nucleotide : dna) {
        if (nucleotide == 'G' || nucleotide == 'C') {
            gc_count++;
        }
    }
    return static_cast<double>(gc_count) / dna.length();
}

std::string reverse_string(const std::string& dna) {
    std::string reversed;
    reversed.reserve(dna.length());  // Optimize memory allocation

    for (int i = dna.length() - 1; i >= 0; --i) {
        reversed += dna[i];
    }
    return reversed;
}

std::string get_dna_complement(const std::string& dna) {
    std::string reversed = reverse_string(dna);

    for (char& nucleotide : reversed) {
        switch (nucleotide) {
            case 'A': nucleotide = 'T'; break;
            case 'T': nucleotide = 'A'; break;
            case 'C': nucleotide = 'G'; break;
            case 'G': nucleotide = 'C'; break;
        }
    }
    return reversed;
}