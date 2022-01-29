/*
Program Description:
This program made to determine their current BMI status based on their age, height, and weight. User put all the patient's information to one input file and submit it through the console. Then, it will automatically determine each patient's BMI status. 
*/

#include "Patient.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

void printReport(Patient list[], int size, string fileName);
int readData(string fileName, Patient list[]);
void displayWeight(Patient list[], int size, string);
void insertionSort(Patient list[], int size);
void displayOutput(string fileName, string &outFileName);

int main()
{
  Patient patArr[MAX_SIZE];
  string outFileName;
  string fileName;

  cout << "Please enter the input file's name: ";
  getline(cin, fileName);
  cout << endl;

  int arrSize = readData(fileName, patArr);

  insertionSort(patArr, arrSize);

  displayWeight(patArr, arrSize, "Underweight");
  displayWeight(patArr, arrSize, "Overweight");
  displayWeight(patArr, arrSize, "Obese");
  displayWeight(patArr, arrSize, "Normal");

  displayOutput(fileName, outFileName); //display output file name to the command.

  printReport(patArr, arrSize, outFileName); //printout the report to the designated output file.

  return 0;
}

/*~*~*~*~*~*~
This function does the following:
 - receives the given file name,
 - insert "Report" inside of the file name
 - Then, that name is real output file name and it will printed out to the command.
*~*/
void displayOutput(string fileName, string &outFileName)
{
  int index = fileName.find('.');
  outFileName = fileName.insert(index, "Report");
  cout << "Report saved in:  " << outFileName << endl;
}

/*~*~*~*~*~*~
This function does the following:
 - sorts the Patient array in ascending order of it's Age
 - sort by insertion sort.
*~*/
void insertionSort(Patient list[], int size)
{
  for (int i = 1; i < size; i++)
  {
    Patient temp = list[i];
    int cur = i - 1;
    while ((cur >= 0) && temp < list[cur])
    {
      list[cur + 1] = list[cur];
      --cur;
    }
    list[cur + 1] = temp;
  }
}

/*~*~*~*~*~*~
This function does the following:
 - opens the output text file
 - print out the weight status report in clean form
 - after printing out, close the output text file
*~*/
void printReport(Patient list[], int size, string fileName)
{
  ofstream ofile;
  ofile.open(fileName);

  string lines = "==================== === ====== ====== =============";
  ofile << "Weight Status Report" << endl;
  ofile << lines << endl;
  ofile << "Name                 Age Height Weight Status" << endl;
  ofile << lines << endl;
  for (int i = 0; i < size; i++)
  {
    ofile << list[i] << endl;
  }
  ofile << lines << endl;
  ofile << "Number of patients: " << size << endl;

  ofile.close();
}

/*~*~*~*~*~*~
This function does the following:
 - opens the input file
 - validate the input file
 - while input file empty, distribute data to each Patient objects
 - return the Patient object array's size
*~*/
int readData(string fileName, Patient list[])
{
  ifstream ifile;
  ifile.open(fileName);
  if (ifile.fail())
  {
    cout << "Input file: " << fileName << " not found!" << endl;
    exit(EXIT_FAILURE);
  }

  int currAge, currWeight;
  double currHeight;
  string currName;

  int size = 0;

  ifile >> currAge;
  while (!ifile.eof())
  {
    ifile >> currHeight;
    ifile >> currWeight;
    string patient_name;
    getline(ifile, patient_name);
    int index = patient_name.find("  ");
    currName = patient_name.substr(1, index);

    list[size].setAge(currAge);
    list[size].setHeight(currHeight);
    list[size].setWeight(currWeight);
    list[size].setName(currName);

    size++;
    ifile >> currAge;
  }

  ifile.close();
  return size;
}

/*~*~*~*~*~*~
This function does the following:
 - purposedly created to display each bmi information based on each patient's weight status. 
 - it prompts the user every time whether they want to check to see each specific weight status. If the first character of it's answer is y or Y, then it assumes to be answered as yes, and prints out the corresponding reports. Else, it doesn't give any reports. 
 - If there is no report, prints "none".
*~*/
void displayWeight(Patient list[], int size, string status)
{
  string answer;
  cout << "Display \"" << status << "\"[Y/N]? ";

  getline(cin, answer);

  if (answer.at(0) == 'y' || answer.at(0) == 'Y')
  {
    cout << "Showing patients with the \"" << status << "\" status:" << endl;
    bool not_found { true };
    for (int i = 0; i < size; ++i)
    {
      if (list[i].weightStatus() == status)
      {
        const int MAX_NAME_SIZE = 22;
        not_found = false;
        cout << setprecision(2) << fixed << showpoint;
        cout << setw(MAX_NAME_SIZE) << left << list[i].getName() << list[i].getAge() << " years  ";
        cout << list[i].getHeight() << " inches  " << list[i].getWeight() << " pounds " << list[i].weightStatus() << endl;
      }
    }
    if(not_found) 
    {
        cout << "none" << endl;
    } else {
        cout << endl;
    }
  }
}

