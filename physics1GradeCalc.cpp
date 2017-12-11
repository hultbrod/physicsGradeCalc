//Program outputs your final physics grade

#include <iostream>
#include <stdio.h>
using namespace std;

//4 quizes at 10% final at 20%
double method1(double q[], double test);
//3 quizes at 10% final at 30%
double method2(double q[], double test);
//2 quizes at 10% final at 40%
double method3(double q[], double test);
//bubblesort, sorts quizs highest to lowest
void bubbleSort(double arr[], int n);

int main()
{
	double q[4], lab, homework, tophat, m[3], temp, goal;
	char again;
	bool found;
	cout << "Welcome to the final Physics Grade Calculator! The program allow you to see"
		 << endl << "what you need to get your goal final grade. (Cushman's grading)" << endl << endl;
	do
	{	 
		cout << "Enter your percentage on lab reports and participation: ";
		cin >> lab;
		cout << "Enter your percentage on homework and pre-class questions: ";
		cin >> homework;
		cout << "Enter your percentage on TopHat questions: ";
		cin >> tophat;
		cout << "Enter in each of your quiz percentages seperated by a space: ";
		cin >> q[0] >> q[1] >> q[2] >> q[3];
		do
		{
			cout << "Enter your goal final grade: ";
			cin >> goal;
			bubbleSort(q, 4);
			
			found = false;
			double i = 0;
			do
			{
				temp = (lab * .2) + (homework * .12) + (tophat * .08);
				m[0] = temp + method1(q, i);
				m[1] = temp + method2(q, i);
				m[2] = temp + method3(q, i);
				
				bubbleSort(m, 3);
				if(m[2] >= goal)
					found = true;	
				i += .01;
			}
			while(found == false);
			cout << endl << "In order to get a grade of " << goal << "% in "
				 << "the class you will need to get a " << i << "% " 
				 << "on the" << "final.";
		cout << endl << "Would you like to try a different final goal? (Enter 'Y' or 'N'): ";
		cin >> again;
		cout << endl;
		}
		while ((again == 'y') || (again == 'Y'));
		cout << "Would you like to try again with different scores? (Enter 'Y' or 'N'): ";
		cin >> again;
		cout << endl;
		cin.ignore(1);
	}
	while ((again == 'y') || (again == 'Y'));
	
	
	return 0;
}

void bubbleSort(double arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)    
	{
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
       {
			if (arr[j] > arr[j+1])
			{
				double temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

double method1(double q[], double test)
{
	double temp;
	temp = (q[0] * .1) + (q[1] * .1) + (q[2] * .1) + (q[3] * .1) + (test * .2);
	return temp;
}

double method2(double q[], double test)
{
	double temp;
	temp = (q[1] * .1) + (q[2] * .1) + (q[3] * .1) + (test * .3);
	return temp;
}

double method3(double q[], double test)
{
	double temp;
	temp = (q[2] * .1) + (q[3] * .1) + (test * .4);
	return temp;
}
