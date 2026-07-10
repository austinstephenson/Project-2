
#include <iostream>
#include <string>
#include <sstream>
#include "UIface.h"

using namespace std;


int main() {

    UIface run;
    run.running=true;


    cout << endl;
    cout << "Welcome To the Senior Fall-Risk Predictor!" << endl;
    string line;


    while (run.running) {
        //Main menu
        run.runMenu();


        //option selection
        if (!getline(cin, line)) {
            break;
        }
        istringstream inStream(line);
        string command;
        inStream >> command;

        if (line == "1") {
            //Load Patient data function
            cout << "Loading Patient data..."<< endl;

            run.load();

            cout <<"Load Successful" <<endl;

        }
        else if(command == "2") {

            //USE SIMILAR METHOD FOR IMPLEMENTING NEW RECORD
            // string name;
            // string ufid;
            //
            // getline(inStream, name, '"');
            // getline(inStream, name, '"');
            //
            // inStream >> ufid;
            // //tree.insert(name, ufid);
            run.addPro();
            cout << "Record inserted!" <<endl;
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
            run.sID();
            cout << "Patient found!" << endl;
        }
        else if (command == "4") {

            run.updatePro();
            cout << "Patient record updated!" << endl;
            //Update information
        }

        else if (command == "5") {
            //Similar to Patient Remove
            // string ufid;
            // inStream >> ufid;
            // tree.remove(ufid);
            run.removePro();
            cout << "Patient removed successfully!" << endl;
        }



        else if (command == "6") {
            //Show top x highest-rated patients
            int x = 0;
            cout << "Showing top " << x << " highest at risk patients:" << endl;

            run.topX();
        }

        else if (command == "7") {
            //Save data to file
            run.saveToFile();
            cout << "Patient data saved to file!" << endl;
        }
        else if (command == "8") {

            cout << "Exiting..." << endl;
            run.exitOP();
            break;
        }

        else {
            cout << "UNKNOWN COMMAND: TRY AGAIN" << endl;
        }

    }
    cout << "Thank you for using the Senior Fall-Risk Predictor!" << endl ;
    return 0;
}
