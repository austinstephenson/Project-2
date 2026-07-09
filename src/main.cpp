
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int main() {
    string line;
    while (true) {
        //Main menu
        cout << endl;
        cout << "Welcome To the Senior Fall-Risk Predictor!" << endl << endl;
        cout << "Please select an option:" << endl << endl;
        cout << "1. Load patient data from file" << endl;
        cout << "2. Add new patient record" << endl;
        cout << "3. Search patient by ID" << endl;
        cout << "4. Update patient information" << endl;
        cout << "5. Remove patient record" << endl;
        cout << "6. Show top x highest-risk patients" << endl;
        cout << "7. Save data to file" << endl;
        cout << "8. Exit" << endl << endl;


        //option selection
        if (!getline(cin, line)) {
            break;
        }

        if (line == "1") {
            //Load Patient data function

        }

        istringstream inStream(line);
        string command;
        inStream >> command;

        if (command == "2") {

            //USE SIMILAR METHOD FOR IMPLEMENTING NEW RECORD
            // string name;
            // string ufid;
            //
            // getline(inStream, name, '"');
            // getline(inStream, name, '"');
            //
            // inStream >> ufid;
            // //tree.insert(name, ufid);
        }

        else if (command == "3") {
            //Similar to ID Search
            // string arg;
            //
            // inStream >> ws;
            //
            // if (inStream.peek() == '"') {
            //     getline(inStream, arg, '"');
            //     getline(inStream, arg, '"');
            // } else {
            //     inStream >> arg;
            // }

            // tree.search(arg);
        }
        else if (command == "4") {
            cout << "Update patient record" << endl;
            //Update information
        }

        else if (command == "5") {
            //Similar to Patient Remove
            // string ufid;
            // inStream >> ufid;
            // tree.remove(ufid);
        }



        else if (command == "6") {
            //Show top x highest-rated patients
        }

        else if (command == "7") {
            //Save data to file
        }
        else if (command == "8") {
            break;
        }


        else {
            cout << "UNKNOWN COMMAND: TRY AGAIN" << endl;
        }



    }
    return 0;
}


//     int numCommands = 0;
//     if (!(cin >> numCommands)) {
//         return 0;
//     }
//
//
//     //EATS NEWLINE
//     string dummy;
//     getline(cin, dummy);
//
//     for (int i = 0; i < numCommands; ++i) {
//         string line;
//         if (!getline(cin, line)) break;
//
//         istringstream inStream(line);
//         string command;
//         inStream >> command;
//
//
//         //PARSING FOR ARGUMENTS FOUND NEAR END OF PROJECT BREAKDOWN VIDEO
//         if (command == "insert") {
//             string name;
//             string ufid;
//
//             getline(inStream, name, '"');
//             getline(inStream, name, '"');
//
//             inStream >> ufid;
//             tree.insert(name, ufid);
//
//         }
//         else if (command == "remove") {
//             string ufid;
//             inStream >> ufid;
//             tree.remove(ufid);
//         }
//
//
//
//         //SHOULD WORK FOR BOTH ID AND NAME
//
//         // source for peek logic      https://cplusplus.com/reference/istream/istream/peek/
//         else if (command == "search") {
//             string arg;
//
//             inStream >>ws;
//
//
//             //IF NAME
//             if (inStream.peek() == '"') {
//                 getline(inStream, arg, '"');
//                 getline(inStream, arg, '"');
//
//                 //IF ID
//             } else {
//                 inStream >> arg;
//             }
//             tree.search(arg);
//         }
//
//         else if (command == "printLevelCount") {
//
//             tree.printLevelCount();
//
//         }
//
//
//         else if (command == "printInorder") {
//             tree.printInorder();
//
//         }
//         else if (command == "printPreorder") {
//             tree.printPreorder();
//
//         }
//         else if (command == "printPostorder") {
//             tree.printPostorder();
//
//         }
//
//         else if (command == "removeInorder") {
//             int n;
//             inStream >> n;
//             tree.removeInorder(n);
//
//         }
//     }
//
//     return 0;
//