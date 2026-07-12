How to Use the Senior Fall-Risk Predictor...

Load a CSV file using option 1 or manually insert records following the prompts with option 2.
WARNING: USE ABSOLUTE FILE PATH WHEN LOADING CSV FILES!!!

If manually inserting, inserting a non-unique ID will reprompt the user for a new one.

Use the search patient ID (option 3) to display individual patient records. Make sure you know the ID of your patient. This will show 2 execution times: one for a Hash Table and another for a Max Heap. However the patient ID is only displayed once because they store the same information and would be kind of redundant.

Update existing patient data using option 4. You will be unable to change ID, names, or sex. Additionally, you can only change the fall count by increments of 1.

Remove individual patients using their ID with Option 5. Once again this will display 2 execution times: one for each structure.

Use option 6 to show the top x highest-risk patients, where 'x' is a value that will be prompted. This will show execution times for both data structures as well as both results (Ex Top '3' will result in 6 total displayed records). The results should match and represent the top 'x' patients from highest to lowest calculated Risk Score. This is the only implemented way to show multiple Records simultaneously (without looking at the CSV files) and to not use individual IDs. 

Use option 7 to save changes to a CSV file of your choice
ONCE AGAIN: USE ABSOLUTE FILE PATH

CSV File use recommendations:
patients.csv is a default record that contains 100k records of randomly generated people. This is good for comparing performance for the SEARCH, REMOVE, and TOP X functions.
patients1.csv is blank besides the header. This is good if you want to save changes from patients without overwriting the original CSV or if you want to easily find and manipulate manually inserted data.

Option 8 ends the program.


