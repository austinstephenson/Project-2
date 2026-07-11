
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
            run.load();


        }
        else if(command == "2") {

            run.addPro();
        }

        else if (command == "3") {
            run.sID();
        }
        else if (command == "4") {

            run.updatePro();
        }

        else if (command == "5") {

            run.removePro();

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
