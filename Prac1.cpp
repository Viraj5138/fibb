


// 1.FIBONACCI


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




// 2.Merge SORTT



// #include <iostream>
// #include <string>
// using namespace std;

// struct Student
// {
//     string name;
//     int marks;
// };

// void merge(Student arr[], int left, int mid, int right)
// {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     Student L[50], R[50];

//     for (int i = 0; i < n1; i++)
//     {
//         L[i] = arr[left + i];
//     }

//     for (int j = 0; j < n2; j++)
//     {
//         R[j] = arr[mid + 1 + j];
//     }

//     int i = 0, j = 0, k = left;

//     while (i < n1 && j < n2)
//     {
//         if (L[i].marks <= R[j].marks)
//         {
//             arr[k] = L[i];
//             i++;
//         }
//         else
//         {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     while (i < n1)
//     {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     while (j < n2)
//     {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

// void mergeSort(Student arr[], int left, int right)
// {
//     if (left < right)
//     {
//         int mid = (left + right) / 2;

//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);

//         merge(arr, left, mid, right);
//     }
// }

// void display(Student arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i].name << " - " << arr[i].marks << endl;
//     }
// }

// int main()
// {
//     Student students[6] = {
//         {"Rahul", 78},
//         {"Aman", 45},
//         {"Sneha", 92},
//         {"Priya", 67},
//         {"Karan", 55},
//         {"Neha", 81}
//     };

//     int n = 6;

//     cout << "Unsorted Student Records:\n";
//     display(students, n);

//     mergeSort(students, 0, n - 1);

//     cout << "\nSorted Student Records (by Total Marks):\n";
//     display(students, n);

//     return 0;
// }
// ************************************************************************************************************





// 3.N QUEENSS




// #include <iostream>
// using namespace std;

// int board[10][10];
// int n = 4;

// bool safe(int row, int col)
// {
//     for (int i = 0; i < row; i++)
//     {
//         if (board[i][col] == 1)
//         {
//             return false;
//         }
//     }

//     int i = row;
//     int j = col;

//     while (i >= 0 && j >= 0)
//     {
//         if (board[i][j] == 1)
//         {
//             return false;
//         }
//         i--;
//         j--;
//     }

//     i = row;
//     j = col;

//     while (i >= 0 && j < n)
//     {
//         if (board[i][j] == 1)
//         {
//             return false;
//         }
//         i--;
//         j++;
//     }

//     return true;
// }

// bool solve(int row)
// {
//     if (row == n)
//     {
//         return true;
//     }

//     for (int col = 0; col < n; col++)
//     {
//         if (safe(row, col))
//         {
//             board[row][col] = 1;

//             if (solve(row + 1))
//             {
//                 return true;
//             }

//             board[row][col] = 0;
//         }
//     }

//     return false;
// }

// void display()
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (board[i][j] == 1)
//             {
//                 cout << "Q ";
//             }
//             else
//             {
//                 cout << ". ";
//             }
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     if (solve(0))
//     {
//         cout << "Solution for " << n << "-Queens Problem:\n\n";
//         display();
//     }
//     else
//     {
//         cout << "No Solution Found";
//     }

//     return 0;
// }
// *****************************************************************************************************




// 4.BST 




// #include <iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node* left;
//     Node* right;
// };

// Node* createNode(int value)
// {
//     Node* temp = new Node();
//     temp->data = value;
//     temp->left = NULL;
//     temp->right = NULL;
//     return temp;
// }

// Node* insert(Node* root, int value)
// {
//     if (root == NULL)
//     {
//         return createNode(value);
//     }

//     if (value < root->data)
//     {
//         root->left = insert(root->left, value);
//     }
//     else
//     {
//         root->right = insert(root->right, value);
//     }

//     return root;
// }

// bool search(Node* root, int value)
// {
//     if (root == NULL)
//     {
//         return false;
//     }

//     if (root->data == value)
//     {
//         return true;
//     }

//     if (value < root->data)
//     {
//         return search(root->left, value);
//     }

//     return search(root->right, value);
// }

// Node* findMin(Node* root)
// {
//     while (root->left != NULL)
//     {
//         root = root->left;
//     }

//     return root;
// }

// Node* deleteNode(Node* root, int value)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }

//     if (value < root->data)
//     {
//         root->left = deleteNode(root->left, value);
//     }
//     else if (value > root->data)
//     {
//         root->right = deleteNode(root->right, value);
//     }
//     else
//     {
//         if (root->left == NULL && root->right == NULL)
//         {
//             delete root;
//             return NULL;
//         }

//         else if (root->left == NULL)
//         {
//             Node* temp = root->right;
//             delete root;
//             return temp;
//         }

//         else if (root->right == NULL)
//         {
//             Node* temp = root->left;
//             delete root;
//             return temp;
//         }

//         Node* temp = findMin(root->right);
//         root->data = temp->data;
//         root->right = deleteNode(root->right, temp->data);
//     }

//     return root;
// }

// int countNodes(Node* root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     return 1 + countNodes(root->left) + countNodes(root->right);
// }

// void inorder(Node* root)
// {
//     if (root != NULL)
//     {
//         inorder(root->left);
//         cout << root->data << " ";
//         inorder(root->right);
//     }
// }

// int main()
// {
//     Node* root = NULL;

//     root = insert(root, 50);
//     root = insert(root, 30);
//     root = insert(root, 70);
//     root = insert(root, 20);
//     root = insert(root, 40);
//     root = insert(root, 60);
//     root = insert(root, 80);

//     int choice, value;

//     do
//     {
//         cout << "\n--- Binary Search Tree ---\n";
//         cout << "1. Insert\n";
//         cout << "2. Delete\n";
//         cout << "3. Search\n";
//         cout << "4. Count Nodes\n";
//         cout << "5. Display Inorder\n";
//         cout << "6. Exit\n";
//         cout << "Enter choice: ";
//         cin >> choice;

//         switch(choice)
//         {
//             case 1:
//                 cout << "Enter value to insert: ";
//                 cin >> value;
//                 root = insert(root, value);
//                 break;

//             case 2:
//                 cout << "Enter value to delete: ";
//                 cin >> value;
//                 root = deleteNode(root, value);
//                 break;

//             case 3:
//                 cout << "Enter value to search: ";
//                 cin >> value;

//                 if (search(root, value))
//                 {
//                     cout << "Element Found";
//                 }
//                 else
//                 {
//                     cout << "Element Not Found";
//                 }

//                 break;

//             case 4:
//                 cout << "Total Nodes: " << countNodes(root);
//                 break;

//             case 5:
//                 cout << "BST Elements: ";
//                 inorder(root);
//                 break;

//             case 6:
//                 cout << "Program Ended";
//                 break;

//             default:
//                 cout << "Invalid Choice";
//         }

//     } while(choice != 6);

//     return 0;
// }
// *****************************************************************************************





// 5.BST FAMily TREE




// #include <iostream>
// #include <string>
// using namespace std;

// struct Node
// {
//     string name;
//     Node* left;
//     Node* right;
// };

// Node* createNode(string name)
// {
//     Node* temp = new Node();
//     temp->name = name;
//     temp->left = NULL;
//     temp->right = NULL;
//     return temp;
// }

// void inorder(Node* root)
// {
//     if (root != NULL)
//     {
//         inorder(root->left);
//         cout << root->name << " ";
//         inorder(root->right);
//     }
// }

// void preorder(Node* root)
// {
//     if (root != NULL)
//     {
//         cout << root->name << " ";
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

// void postorder(Node* root)
// {
//     if (root != NULL)
//     {
//         postorder(root->left);
//         postorder(root->right);
//         cout << root->name << " ";
//     }
// }

// int main()
// {
//     Node* root = createNode("Grandfather");

//     root->left = createNode("Father");
//     root->right = createNode("Uncle");

//     root->left->left = createNode("Me");
//     root->left->right = createNode("Sister");

//     root->right->left = createNode("Cousin1");
//     root->right->right = createNode("Cousin2");

//     int choice;

//     do
//     {
//         cout << "\n--- Family Tree Traversals ---\n";
//         cout << "1. Inorder Traversal\n";
//         cout << "2. Preorder Traversal\n";
//         cout << "3. Postorder Traversal\n";
//         cout << "4. Exit\n";
//         cout << "Enter choice: ";
//         cin >> choice;

//         switch(choice)
//         {
//             case 1:
//                 cout << "Inorder Traversal:\n";
//                 inorder(root);
//                 break;

//             case 2:
//                 cout << "\nPreorder Traversal:\n";
//                 preorder(root);
//                 break;

//             case 3:
//                 cout << "\nPostorder Traversal:\n";
//                 postorder(root);
//                 break;

//             case 4:
//                 cout << "\nProgram Ended";
//                 break;

//             default:
//                 cout << "\nInvalid Choice";
//         }

//         cout << endl;

//     } while(choice != 4);

//     return 0;
// }

// ***********************************************************************************************************





// 6.MSP Kruskals Algorithm




// #include <iostream>
// using namespace std;

// struct Edge
// {
//     int u;
//     int v;
//     int cost;
// };

// int parent[10];

// int find(int x)
// {
//     while (parent[x] != x)
//     {
//         x = parent[x];
//     }

//     return x;
// }

// void unionSet(int a, int b)
// {
//     int p1 = find(a);
//     int p2 = find(b);

//     parent[p1] = p2;
// }

// void sortEdges(Edge edges[], int e)
// {
//     for (int i = 0; i < e - 1; i++)
//     {
//         for (int j = 0; j < e - i - 1; j++)
//         {
//             if (edges[j].cost > edges[j + 1].cost)
//             {
//                 Edge temp = edges[j];
//                 edges[j] = edges[j + 1];
//                 edges[j + 1] = temp;
//             }
//         }
//     }
// }

// int main()
// {
//     int vertices = 5;
//     int edgesCount = 7;

//     Edge edges[7] = {
//         {0, 1, 2},
//         {0, 3, 6},
//         {1, 2, 3},
//         {1, 3, 8},
//         {1, 4, 5},
//         {2, 4, 7},
//         {3, 4, 9}
//     };

//     for (int i = 0; i < vertices; i++)
//     {
//         parent[i] = i;
//     }

//     sortEdges(edges, edgesCount);

//     int totalCost = 0;

//     cout << "Minimum Spanning Tree:\n";

//     for (int i = 0; i < edgesCount; i++)
//     {
//         int u = edges[i].u;
//         int v = edges[i].v;

//         if (find(u) != find(v))
//         {
//             cout << "Village " << u << " - Village " << v;
//             cout << " : Cost = " << edges[i].cost << endl;

//             totalCost += edges[i].cost;

//             unionSet(u, v);
//         }
//     }

//     cout << "\nMinimum Total Cost = " << totalCost;

//     return 0;
// }
// ******************************************************************************************************





// 7.HASH TABLE EMPLOYEEEEE




// #include <iostream>
// #include <string>
// using namespace std;

// struct Employee
// {
//     int id;
//     string name;
//     float salary;
//     Employee* next;
// };

// Employee* table[10];

// int hashFunction(int id)
// {
//     return id % 10;
// }

// void insertEmployee(int id, string name, float salary)
// {
//     int index = hashFunction(id);

//     Employee* newEmployee = new Employee();
//     newEmployee->id = id;
//     newEmployee->name = name;
//     newEmployee->salary = salary;
//     newEmployee->next = NULL;

//     if (table[index] == NULL)
//     {
//         table[index] = newEmployee;
//     }
//     else
//     {
//         Employee* temp = table[index];

//         while (temp->next != NULL)
//         {
//             temp = temp->next;
//         }

//         temp->next = newEmployee;
//     }

//     cout << "Employee Inserted\n";
// }

// void searchEmployee(int id)
// {
//     int index = hashFunction(id);

//     Employee* temp = table[index];

//     while (temp != NULL)
//     {
//         if (temp->id == id)
//         {
//             cout << "\nEmployee Found\n";
//             cout << "ID: " << temp->id << endl;
//             cout << "Name: " << temp->name << endl;
//             cout << "Salary: " << temp->salary << endl;
//             return;
//         }

//         temp = temp->next;
//     }

//     cout << "Employee Not Found\n";
// }

// void deleteEmployee(int id)
// {
//     int index = hashFunction(id);

//     Employee* temp = table[index];
//     Employee* prev = NULL;

//     while (temp != NULL)
//     {
//         if (temp->id == id)
//         {
//             if (prev == NULL)
//             {
//                 table[index] = temp->next;
//             }
//             else
//             {
//                 prev->next = temp->next;
//             }

//             delete temp;
//             cout << "Employee Deleted\n";
//             return;
//         }

//         prev = temp;
//         temp = temp->next;
//     }

//     cout << "Employee Not Found\n";
// }

// void display()
// {
//     cout << "\nHash Table:\n";

//     for (int i = 0; i < 10; i++)
//     {
//         cout << i << " : ";

//         Employee* temp = table[i];

//         while (temp != NULL)
//         {
//             cout << "[" << temp->id << ", " << temp->name << "] -> ";
//             temp = temp->next;
//         }

//         cout << "NULL\n";
//     }
// }

// int main()
// {
//     for (int i = 0; i < 10; i++)
//     {
//         table[i] = NULL;
//     }

//     insertEmployee(101, "Rahul", 45000);
//     insertEmployee(112, "Sneha", 52000);
//     insertEmployee(123, "Aman", 47000);
//     insertEmployee(134, "Priya", 50000);

//     int choice;
//     int id;
//     string name;
//     float salary;

//     do
//     {
//         cout << "\n--- Hash Table Menu ---\n";
//         cout << "1. Insert Employee\n";
//         cout << "2. Search Employee\n";
//         cout << "3. Delete Employee\n";
//         cout << "4. Display Hash Table\n";
//         cout << "5. Exit\n";
//         cout << "Enter choice: ";
//         cin >> choice;

//         switch(choice)
//         {
//             case 1:
//                 cout << "Enter ID: ";
//                 cin >> id;

//                 cout << "Enter Name: ";
//                 cin >> name;

//                 cout << "Enter Salary: ";
//                 cin >> salary;

//                 insertEmployee(id, name, salary);
//                 break;

//             case 2:
//                 cout << "Enter Employee ID to Search: ";
//                 cin >> id;

//                 searchEmployee(id);
//                 break;

//             case 3:
//                 cout << "Enter Employee ID to Delete: ";
//                 cin >> id;

//                 deleteEmployee(id);
//                 break;

//             case 4:
//                 display();
//                 break;

//             case 5:
//                 cout << "Program Ended";
//                 break;

//             default:
//                 cout << "Invalid Choice";
//         }

//     } while(choice != 5);

//     return 0;
// }

// ************************************************************************************************




// 8.AVL


// #include <iostream>
// #include <string>
// using namespace std;

// struct Node
// {
//     string name;
//     int score;
//     Node* left;
//     Node* right;
//     int height;
// };

// int getHeight(Node* root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     return root->height;
// }

// int maxValue(int a, int b)
// {
//     if (a > b)
//     {
//         return a;
//     }

//     return b;
// }

// Node* createNode(string name, int score)
// {
//     Node* temp = new Node();

//     temp->name = name;
//     temp->score = score;
//     temp->left = NULL;
//     temp->right = NULL;
//     temp->height = 1;

//     return temp;
// }

// Node* rightRotate(Node* y)
// {
//     Node* x = y->left;
//     Node* t2 = x->right;

//     x->right = y;
//     y->left = t2;

//     y->height = maxValue(getHeight(y->left), getHeight(y->right)) + 1;
//     x->height = maxValue(getHeight(x->left), getHeight(x->right)) + 1;

//     return x;
// }

// Node* leftRotate(Node* x)
// {
//     Node* y = x->right;
//     Node* t2 = y->left;

//     y->left = x;
//     x->right = t2;

//     x->height = maxValue(getHeight(x->left), getHeight(x->right)) + 1;
//     y->height = maxValue(getHeight(y->left), getHeight(y->right)) + 1;

//     return y;
// }

// int getBalance(Node* root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     return getHeight(root->left) - getHeight(root->right);
// }

// Node* insert(Node* root, string name, int score)
// {
//     if (root == NULL)
//     {
//         return createNode(name, score);
//     }

//     if (score < root->score)
//     {
//         root->left = insert(root->left, name, score);
//     }
//     else if (score > root->score)
//     {
//         root->right = insert(root->right, name, score);
//     }
//     else
//     {
//         return root;
//     }

//     root->height = 1 + maxValue(getHeight(root->left), getHeight(root->right));

//     int balance = getBalance(root);

//     if (balance > 1 && score < root->left->score)
//     {
//         return rightRotate(root);
//     }

//     if (balance < -1 && score > root->right->score)
//     {
//         return leftRotate(root);
//     }

//     if (balance > 1 && score > root->left->score)
//     {
//         root->left = leftRotate(root->left);
//         return rightRotate(root);
//     }

//     if (balance < -1 && score < root->right->score)
//     {
//         root->right = rightRotate(root->right);
//         return leftRotate(root);
//     }

//     return root;
// }

// Node* minValue(Node* root)
// {
//     Node* current = root;

//     while (current->left != NULL)
//     {
//         current = current->left;
//     }

//     return current;
// }

// Node* deleteNode(Node* root, int score)
// {
//     if (root == NULL)
//     {
//         return root;
//     }

//     if (score < root->score)
//     {
//         root->left = deleteNode(root->left, score);
//     }

//     else if (score > root->score)
//     {
//         root->right = deleteNode(root->right, score);
//     }

//     else
//     {
//         if (root->left == NULL || root->right == NULL)
//         {
//             Node* temp;

//             if (root->left != NULL)
//             {
//                 temp = root->left;
//             }
//             else
//             {
//                 temp = root->right;
//             }

//             if (temp == NULL)
//             {
//                 temp = root;
//                 root = NULL;
//             }
//             else
//             {
//                 *root = *temp;
//             }

//             delete temp;
//         }

//         else
//         {
//             Node* temp = minValue(root->right);

//             root->score = temp->score;
//             root->name = temp->name;

//             root->right = deleteNode(root->right, temp->score);
//         }
//     }

//     if (root == NULL)
//     {
//         return root;
//     }

//     root->height = 1 + maxValue(getHeight(root->left), getHeight(root->right));

//     int balance = getBalance(root);

//     if (balance > 1 && getBalance(root->left) >= 0)
//     {
//         return rightRotate(root);
//     }

//     if (balance > 1 && getBalance(root->left) < 0)
//     {
//         root->left = leftRotate(root->left);
//         return rightRotate(root);
//     }

//     if (balance < -1 && getBalance(root->right) <= 0)
//     {
//         return leftRotate(root);
//     }

//     if (balance < -1 && getBalance(root->right) > 0)
//     {
//         root->right = rightRotate(root->right);
//         return leftRotate(root);
//     }

//     return root;
// }

// void display(Node* root)
// {
//     if (root != NULL)
//     {
//         display(root->right);

//         cout << root->name << " - Score: " << root->score << endl;

//         display(root->left);
//     }
// }

// int main()
// {
//     Node* root = NULL;

//     root = insert(root, "Rahul", 300);
//     root = insert(root, "Aman", 450);
//     root = insert(root, "Sneha", 250);
//     root = insert(root, "Priya", 500);

//     int choice;
//     string name;
//     int score;

//     do
//     {
//         cout << "\n--- Gaming Leaderboard ---\n";
//         cout << "1. Insert Player Score\n";
//         cout << "2. Delete Player Score\n";
//         cout << "3. Display Leaderboard\n";
//         cout << "4. Exit\n";
//         cout << "Enter choice: ";
//         cin >> choice;

//         switch(choice)
//         {
//             case 1:
//                 cout << "Enter Player Name: ";
//                 cin >> name;

//                 cout << "Enter Score: ";
//                 cin >> score;

//                 root = insert(root, name, score);
//                 break;

//             case 2:
//                 cout << "Enter Score to Delete: ";
//                 cin >> score;

//                 root = deleteNode(root, score);
//                 break;

//             case 3:
//                 cout << "\nLeaderboard:\n";
//                 display(root);
//                 break;

//             case 4:
//                 cout << "Program Ended";
//                 break;

//             default:
//                 cout << "Invalid Choice";
//         }

//     } while(choice != 4);

//     return 0;
// }