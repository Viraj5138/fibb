// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int fibonacciSearch(const vector<string>& books, const string& target) {
//     int n = books.size();

//     int fibM2 = 0;
//     int fibM1 = 1;
//     int fibM  = 1;

//     while (fibM < n) {
//         fibM2 = fibM1;
//         fibM1 = fibM;
//         fibM  = fibM1 + fibM2;
//     }

//     int offset = -1;

//     while (fibM > 1) {
//         int i = min(offset + fibM2, n - 1);

//         if (books[i] < target) {
//             fibM  = fibM1;
//             fibM1 = fibM2;
//             fibM2 = fibM - fibM1;
//             offset = i;
//         } else if (books[i] > target) {
//             fibM  = fibM2;
//             fibM1 = fibM1 - fibM2;
//             fibM2 = fibM - fibM1;
//         } else {
//             return i;
//         }
//     }

//     if (fibM1 && (offset + 1) < n && books[offset + 1] == target)
//         return offset + 1;

//     return -1;
// }

// int main() {
//     vector<string> library = {
//         "Artificial Intelligence: A Modern Approach",
//         "Clean Code",
//         "Computer Networks",
//         "Computer Organization and Architecture",
//         "Data Structures and Algorithms",
//         "Database Management Systems",
//         "Design and Analysis of Algorithms",
//         "Digital Logic and Computer Design",
//         "Discrete Mathematics",
//         "Introduction to Automata Theory",
//         "Introduction to the Theory of Computation",
//         "Operating System Concepts",
//         "Principles of Compiler Design",
//         "Software Engineering",
//         "The Art of Computer Programming"
//     };

//     string target = "Design and Analysis of Algorithms";

//     cout << "Library Catalog (Alphabetical Order):\n";
//     for (int i = 0; i < (int)library.size(); i++)
//         cout << i << ". " << library[i] << "\n";

//     cout << "\nSearching for: \"" << target << "\"\n\n";

//     int result = fibonacciSearch(library, target);

//     if (result != -1)
//         cout << "Book found at index " << result << ": " << library[result] << "\n";
//     else
//         cout << "Book not found.\n";

//     return 0;
// }
// ***********************************************************************************


// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// struct Student {
//     string name;
//     int rollNo;
//     int marks;
// };

// void merge(vector<Student>& arr, int left, int mid, int right) {
//     vector<Student> leftArr(arr.begin() + left, arr.begin() + mid + 1);
//     vector<Student> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

//     int i = 0, j = 0, k = left;

//     while (i < leftArr.size() && j < rightArr.size()) {
//         if (leftArr[i].marks <= rightArr[j].marks)
//             arr[k++] = leftArr[i++];
//         else
//             arr[k++] = rightArr[j++];
//     }

//     while (i < leftArr.size()) arr[k++] = leftArr[i++];
//     while (j < rightArr.size()) arr[k++] = rightArr[j++];
// }

// void mergeSort(vector<Student>& arr, int left, int right) {
//     if (left >= right) return;

//     int mid = left + (right - left) / 2;

//     mergeSort(arr, left, mid);
//     mergeSort(arr, mid + 1, right);
//     merge(arr, left, mid, right);
// }

// void printRecords(const vector<Student>& arr) {
//     cout << left;
//     cout << "----------------------------------------------\n";
//     cout << "Roll No   Name                  Total Marks\n";
//     cout << "----------------------------------------------\n";
//     for (const Student& s : arr)
//         cout << s.rollNo << "         " << s.name
//              << string(22 - s.name.length(), ' ') << s.marks << "\n";
//     cout << "----------------------------------------------\n";
// }

// int main() {
//     vector<Student> students = {
//         {"Alice",   101, 87},
//         {"Bob",     102, 73},
//         {"Charlie", 103, 95},
//         {"Diana",   104, 60},
//         {"Ethan",   105, 82},
//         {"Fiona",   106, 91},
//         {"George",  107, 68}
//     };

//     cout << "\nStudent Records Before Sorting:\n";
//     printRecords(students);

//     mergeSort(students, 0, students.size() - 1);

//     cout << "\nStudent Records After Sorting (by Total Marks):\n";
//     printRecords(students);

//     return 0;
// }