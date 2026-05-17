#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int fibonacciSearch(const vector<string>& books, const string& target) {
    int n = books.size();

    int fibM2 = 0;
    int fibM1 = 1;
    int fibM  = 1;

    while (fibM < n) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM  = fibM1 + fibM2;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibM2, n - 1);

        if (books[i] < target) {
            fibM  = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        } else if (books[i] > target) {
            fibM  = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        } else {
            return i;
        }
    }

    if (fibM1 && (offset + 1) < n && books[offset + 1] == target)
        return offset + 1;

    return -1;
}

int main() {
    vector<string> library = {
        "Artificial Intelligence: A Modern Approach",
        "Clean Code",
        "Computer Networks",
        "Computer Organization and Architecture",
        "Data Structures and Algorithms",
        "Database Management Systems",
        "Design and Analysis of Algorithms",
        "Digital Logic and Computer Design",
        "Discrete Mathematics",
        "Introduction to Automata Theory",
        "Introduction to the Theory of Computation",
        "Operating System Concepts",
        "Principles of Compiler Design",
        "Software Engineering",
        "The Art of Computer Programming"
    };

    string target = "Design and Analysis of Algorithms";

    cout << "Library Catalog (Alphabetical Order):\n";
    for (int i = 0; i < (int)library.size(); i++)
        cout << i << ". " << library[i] << "\n";

    cout << "\nSearching for: \"" << target << "\"\n\n";

    int result = fibonacciSearch(library, target);

    if (result != -1)
        cout << "Book found at index " << result << ": " << library[result] << "\n";
    else
        cout << "Book not found.\n";

    return 0;
}
