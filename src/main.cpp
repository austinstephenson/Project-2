
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
