// Author Michael Velazco 
// on 11/10/2021
//
// In this program it shall take two gpio n and states.
// this will put the first state n for the gpio , following
// find out the 2nd state and pull it out.
// As instructions config gpio pins in a build file.
//

#include<iostream>
#include<sstream>
#include<fstream>
#include<string>

using namespace std;

#define PATH "/sys/class/gpio" // path defined for gpio dir.

int main(int argc, char* argv[]) // entering n of agruments
{
	if(argc != 4) {
		cout << "State gpio_number for control_GPIO" << endl;
		cout << "State the gpio number to run" << endl;
		cout << "State  hi or low" << endl;
		return 3;
	}
	cout <<" Comencing program: control_GPIO." << endl << endl;

	int gpion1 = atoi(argv[1]);
	string state(argv[2]);
	int gpion2 = atoi(argv[3]);

	string outpin; // this will decide if high or low 

	if(state == "hi"){
		outpin= "1";
	}
	else if(state == "low"){
		outpin = "0";
	}
 
	// print out the fill paths
	ostringstream p1; 
	p1 << PATH << "/gpio" << gpion1 << "/val";
	string fpath1 = string(p1.str());
	cout << "f path 1: " << fpath1 << endl;
	
	ostringstream p2;
	p2 << PATH << "/gpio" << gpion2 << "/val";
	string fpath2 = string(p2.str());
	cout << "f path 2: " << fpath2 << endl << endl;
	
	//opening first gpio value and writing it.
	ofstream fp1;
	fp1.open(fpath1.c_str());
	fp1 << outpin;
	fp1.close();

	// opening the 2nd value file and read valin. 
	ifstream fp2;
	fp2.open(fpath2.c_str());
	string valin;
	getline(fp2,valin);
	fp2.close();

	cout << endl << "Value of gpio" << gpion2 << "is" << valin << "." << endl << endl;

	cout << " Terminate program." << endl;

}




