

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
    int step   = 0;  

    cout << "\n  [Fibonacci Search Trace]\n";
    cout << "  n = " << n << " | Starting Fibonacci: Fm=" << fibM
         << ", Fm1=" << fibM1 << ", Fm2=" << fibM2 << "\n\n";

    
    while (fibM > 1) {
        
        int i = min(offset + fibM2, n - 1);
        step++;

        cout << "  Step " << step << " | Comparing index " << i
             << " -> \"" << books[i] << "\"";

        if (books[i] < target) {
            
            cout << "  →  TARGET is AHEAD\n";
            fibM  = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        } else if (books[i] > target) {
        
            cout << "  →  TARGET is BEHIND\n";
            fibM  = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        } else {
            // Found!
            cout << "  →  ✓ MATCH FOUND!\n";
            return i;
        }
    }

    
    if (fibM1 && (offset + 1) < n) {
        int i = offset + 1;
        step++;
        cout << "  Step " << step << " | Final check at index " << i
             << " -> \"" << books[i] << "\"";

        if (books[i] == target) {
            cout << "  →   MATCH FOUND!\n";
            return i;
        } else {
            cout << "  →  No match.\n";
        }
    }

    return -1; // Not found
}

// ─────────────────────────────────────────────────────────────
//  Main
// ─────────────────────────────────────────────────────────────
int main() {
    
    vector<string> library = {
        "Artificial Intelligence: A Modern Approach",
        "Clean Code",
        "Computer Networks",
        "Computer Organization and Architecture",
        "Data Structures and Algorithms",
        "Database Management Systems",
        "Design and Analysis of Algorithms",     // ← TARGET (index 6)
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

    // ── Display the library catalog ──────────────────────────
   
    cout << "║       COLLEGE LIBRARY - FIBONACCI BOOK SEARCH   ║\n";
   

    cout << "  Library Catalog (Sorted Alphabetically):\n";
    cout << "  ─────────────────────────────────────────\n";
    for (int i = 0; i < (int)library.size(); i++) {
        cout << "  [" << i << "] " << library[i] << "\n";
    }

    cout << "\n  Searching for: \"" << target << "\"\n";
    cout << "  ─────────────────────────────────────────";

    
    int result = fibonacciSearch(library, target);

    
    cout << "\n  ─────────────────────────────────────────\n";
    if (result != -1) {
        cout << "\n  ✅ Book FOUND at rack index: " << result << "\n";
        cout << "     Title: \"" << library[result] << "\"\n";
    } else {
        cout << "\n  ❌ Book NOT found in the library.\n";
    }

    cout << "\n  Algorithm  : Fibonacci Search\n";
    cout << "  Time Complexity  : O(log n)\n";
    cout << "  Space Complexity : O(1)\n\n";

    return 0;
}