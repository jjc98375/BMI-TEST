/*
  Implementation file for the Patient class.
*/

#include "Patient.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

/*******
mutator function that sets the name. 
*/
void Patient::setName(string initName)
{
    name = initName;
}

/*******
mutator function that sets the height. 
*/
void Patient::setHeight(double initHeight)
{
    height = initHeight;
}

/*******
mutator function that sets the weight. 
*/
void Patient::setWeight(int initWeight)
{
    weight = initWeight;
}

/*******
mutator function that sets the age. 
*/
void Patient::setAge(int initAge)
{
    age = initAge;
}

/*******
accesor function that gets the name and return it. 
*/
string Patient::getName() const
{
    return name;
}

/*******
accesor function that gets the height and return it. 
*/
double Patient::getHeight() const
{
    return height;
}

/*******
accesor function that gets the weight and return it. 
*/
int Patient::getWeight() const
{
    return weight;
}

/*******
accesor function that gets the age and return it. 
*/
int Patient::getAge() const
{
    return age;
}

/*******
 This is the default constructor; it sets everything to 0 or "".
 */
Patient::Patient()
{
    name = "";
    age = 0;
    height = 0;
    weight = 0;
}

/*******
This is an overloaded constructor.
 It sets the variables according to the parameters.
*/
Patient::Patient(string initName, int initAge, double initHeight, int initWeight)
{
    name = initName;
    age = initAge;
    height = initHeight;
    weight = initWeight;
}

/*******
This function displays the member variables
 in a neat format.
*/
void Patient::display() const
{
    cout << setw(15) << right << "Name: ";
    cout << left << getName() << endl;
    cout << setw(15) << right << "Age: ";
    cout << left << getAge() << endl;
    cout << setw(15) << right << "Height: ";
    cout << left << getHeight() << " inches" << endl;
    cout << setw(15) << right << "Weight: ";
    cout << left << getWeight() << " pounds" << endl;
    cout << setw(15) << right << "Weight Status: ";
    cout << left << weightStatus() << endl;
}

/*******
This function is an operator function overloads <. It compares the age of this Patient with the parameter object's age. It returns if this age is smaller than given object's age, else it returns false. 
*/
bool Patient::operator<(const Patient &obj)
{
    bool status = false;
    if (age < obj.age)
    {
        status = true;
    }
    return status;
}

/*******
This function is an operator function that overloads << with output stream. 
When the user use cout << object << endl;, this will allow it to print out all the object's field data.
*/
ostream &operator<<(ostream &ostrm, const Patient &obj)
{
    const int MAX_NAME_SIZE = 20;

    ostrm << setw(MAX_NAME_SIZE) << left << obj.getName();
    ostrm << right << "  " << obj.getAge();
    ostrm << "   " << obj.getHeight();
    ostrm << "    " << obj.getWeight();
    ostrm << "   " << obj.weightStatus();
    ostrm << endl;

    return ostrm;
}

/*******
This function calculates the BMI using the following formula:
 BMI = (weight in pounds * 703) / (height in inches)^2
 Then, it returns a string reflecting the weight status according to the BMI:
 <18.5 = underweight
 18.5 - 24.9 = normal
 25 - 29.9 = overweight
 >=30 = obese
 */
string Patient::weightStatus() const
{
    double bmi;
    string stat = "";

    if (height > 0)
    {
        bmi = (weight * 703) / (pow(height, 2));

        if (bmi >= 30)
        {
            stat = "Obese";
        }
        else if (bmi >= 25)
        {
            stat = "Overweight";
        }
        else if (bmi >= 18.5)
        {
            stat = "Normal";
        }
        else if (bmi > 0)
        {
            stat = "Underweight";
        }
    }

    return stat;
}
