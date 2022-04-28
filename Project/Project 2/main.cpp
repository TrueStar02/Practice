#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <typeinfo>
#include "RPNCauc.h"
using namespace std;
char menu(void);					  //Show main menu,can judge whether the option is valid until the valid option is given
char waremenu(void);				  //Show warehouse menu,can judge whether the option is valid until the valid option is given
void Star(void);					  //Print 60 stars
bool confirm(void);					  //Confirm your change.Enter y to confirm and other to cancel
double GetNum(void);				  //Get a number.If the input isn't valid,it will repeat until the input is valid
Poly GetPoly(ST<string, Poly> &s);	  //Get a polynomial.If the input isn't valid,it will repeat until the input is valid
void Add(ST<string, Poly> &s);		  //Add two polynomials
void Minus(ST<string, Poly> &s);	  //Minus two polynomials
void Multiply(ST<string, Poly> &s);	  //Multiply two polynomials
void Derivative(ST<string, Poly> &s); //Get the derivative of one polynomial
void Integral(ST<string, Poly> &s);	  //Get the integral of one polynomial
void Value(ST<string, Poly> &s);	  //Get the value of a polynomial for a certain x
void Calculate(ST<string, Poly> &s);  //Using stored polynomials to calculate
void Warehouse(ST<string, Poly> &s);  //Managing the stored polynomial
void Readme(void);					  //Some details
void InsPoly(ST<string, Poly> &s);	  //Insert a new polynomial
void DelPoly(ST<string, Poly> &s);	  //Delete a polynomial
void SrcPoly(ST<string, Poly> &s);	  //Search a polynomial
void ChgPoly(ST<string, Poly> &s);	  //Change a polynomial
void PrintAll(ST<string, Poly> &s);	  //Print all polynomials
void ReadPoly(ST<string, Poly> &s);	  //Read polynomials from a file
void WritePoly(ST<string, Poly> &s);  //Write polynomials to a file
int main()
{
	ST<string, Poly> wh; //Warehouse
	char ch;
	while ((ch = menu()) != 'q') //Using the main menu
	{
		switch (ch) //Using the right function according to the choice
		{
		case 'a':
			Add(wh);
			break;
		case 'b':
			Minus(wh);
			break;
		case 'c':
			Multiply(wh);
			break;
		case 'd':
			Derivative(wh);
			break;
		case 'e':
			Integral(wh);
			break;
		case 'f':
			Value(wh);
			break;
		case 'g':
			Calculate(wh);
			break;
		case 'h':
			Warehouse(wh);
			break;
		case 'i':
			Readme();
			break;
		default: //Debug option
			cout << "Loading~\n";
		}
	}
	cout << "Bye~\n";
	return 0;
}
char menu(void)
{
	char v;
	Star();
	cout << "Polynomial Calculator\n";
	cout << "Choose a function:\n";
	cout << "A-Add two polynomials\n";
	cout << "B-Minus two polynomials\n";
	cout << "C-Multiply two polynomials\n";
	cout << "D-Get the derivative of one polynomial\n";
	cout << "E-Get the integral of one polynomial\n";
	cout << "F-Get the value of a polynomial for a certain x\n";
	cout << "G-Using stored polynomials to calculate\n";
	cout << "H-Managing the stored polynomial\n";
	cout << "I-Readme:)\n";
	cout << "Q-Quit\n";
	cout << "Your choice:";
	while ((v = tolower(cin.get())) && strchr("abcdefghiq", v) == NULL) //If the choice is illegal
	{
		cin.ignore(999, '\n');	   //Clear the input line
		cout << "Enter A~H or Q:"; //Remind the user,then get choice again
	}
	cin.ignore(999, '\n'); //Clear the input line
	return v;			   //Return thr choice
}
char waremenu(void)
{
	char v;
	Star();
	cout << "Polynomial Warehouse\n";
	cout << "Choose a function:\n";
	cout << "A-Insert a new polynomial\n";
	cout << "B-Delete a polynomial\n";
	cout << "C-Search a polynomial\n";
	cout << "D-Change a polynomial\n";
	cout << "E-Print all polynomials\n";
	cout << "F-Read polynomials from a file\n";
	cout << "G-Write polynomials to a file\n";
	cout << "Q-Back to the main menu\n";
	cout << "Your choice:";
	while ((v = tolower(cin.get())) && strchr("abcdefgq", v) == NULL) //If the choice is illegal
	{
		cin.ignore(999, '\n');	   //Clear the input line
		cout << "Enter A~H or Q:"; //Remind the user,then get choice again
	}
	cin.ignore(999, '\n'); //Clear the input line
	return v;			   //Return thr choice
}
void Star(void)
{
	int x;
	for (x = 1; x <= 60; x++)
		cout << "*";
	cout << endl;
}
bool confirm(void)
{
	cin.ignore(999, '\n');
	char ch = tolower(cin.get()); //Get the choice
	cin.ignore(999, '\n');
	if (ch == 'y') //Confirm
		return 1;
	return 0; //Otherwise,cancel
}
double GetNum(void)
{
	double num;
	cin >> num;
	while (cin.fail()) //If you enter an invalid input
	{
		cin.clear();			   //Clear the istream object
		cin.ignore(999, '\n');	   //Clear the input line
		cout << "Enter a number:"; //Remind the user to enter a number
		cin >> num;				   //Get the number again
	}
	cin.ignore(999, '\n'); //Clear the input line
	return num;			   //Return the valid input
}
Poly GetPoly(ST<string, Poly> &s)
{	
	Poly poly;
	int x;
	bool flag = 1, use = 0; //Labels
	string t, name = "";
	while (flag) //If it is the first time or the input is invalid
	{	
		poly.clear();
		cout << "Enter polynomial:"; //Remind the user to input
		cin >> t;
		name = "";
		try
		{
			for (x = 0; x < t.length(); x++)
			{
				if (t[x] == '=') //Input as p=(2,3)(4,2)
				{
					poly = Poly(t.substr(x + 1, t.length() - x - 1)); //Transform the string to the polynomial
					if (name != "")									  //Means that you want to srore it
					{
						if (!s.insert(name, poly)) //Failed insertion means conflict name
							throw used_name();	   //So throw an exception
					}
					flag = 0; //Successfully get the valid input
					break;
				}
				else if (t[x] == '(') //Input as (4,3)(3,2)
				{
					poly = Poly(t.substr(x, t.length() - x)); //Transform the string to the polynomial
					flag = 0;								  //Successfully get the valid input
					break;
				}
				else
					name += t[x];
			}
			if (t[t.length() - 1] != ')' && poly.empty()) //Using stored polynomial
				if (s.contains(name))					  //If the polynomial is in the warehouse
				{
					cout << "Using polynomial " << name << endl; //Remind the user
					poly = s[name];								 //Get the polynomial
					use = 1;									 //Means that we are using stored polynomial
					flag = 0;									 //Successfully get the valid input
				}
				else //If the polynomial is in the warehouse
					cout << "No polynomial " << name << " in the warehouse!\n";
		}
		catch (logic_error &le) //Catch exceptions
		{
			cout << le.what() << endl; //Print the error
			flag = 1;				   //Fasiled to get the valid input
			cin.ignore(999, '\n');	   //Clear the input line
		}
	}
	cout << "Polymonial:" << poly << endl;			//Print the polynomial
	if (name != "" && !use)							//If we store a new polynomial
		cout << "It was saved to " << name << endl; //Remind the user
	cin.ignore(999, '\n');							//Clear the input line
	return poly;									//Return the result
}
void Add(ST<string, Poly> &s)
{
	Star();
	cout << "Function:Add\n";
	string name;
	cout << "Polymonial 1:\n";
	Poly poly1 = GetPoly(s); //Get polynomial1
	cout << "Polymonial 2:\n";
	Poly poly2 = GetPoly(s);				   //Get polynomial2
	Poly result = poly1 + poly2;			   //Calculate
	cout << "Result:" << result << endl;	   //Print the result
	cout << "Want to store the polynomial?\n"; //Ask the user whether to store
	cout << "Enter the name to store or 0 to exit:";
	cin >> name;
	while (name != "0" && s.contains(name)) //If the name is used
	{
		cout << "The name is used!Enter the name:"; //Ask the user to change a name
		cin >> name;
	}
	if (name != "0") //If the name is valid
	{
		s.insert(name, result);								//Insert the polynomial
		cout << "The result was saved to " << name << endl; //Remind the user
	}
	cin.ignore(999, '\n');
	cout << "Press enter to the main menu"; //Back to the main menu
	cin.ignore(999, '\n');
}
void Minus(ST<string, Poly> &s)
{
	Star();
	cout << "Function:Subtract\n";
	string t, name;
	cout << "Polymonial 1:\n";
	Poly poly1 = GetPoly(s); //Get polynomial1
	cout << "Polymonial 2:\n";
	Poly poly2 = GetPoly(s);				   //Get polynomial2
	Poly result = poly1 - poly2;			   //Calculate
	cout << "Result:" << result << endl;	   //Print the result
	cout << "Want to store the polynomial?\n"; //Ask the user whether to store
	cout << "Enter the name to store or 0 to exit:";
	cin >> name;
	while (name != "0" && s.contains(name)) //If the name is used
	{
		cout << "The name is used!Enter the name:"; //Ask the user to change a name
		cin >> name;
	}
	if (name != "0") //If the name is valid
	{
		s.insert(name, result);								//Insert the polynomial
		cout << "The result was saved to " << name << endl; //Remind the user
	}
	cin.ignore(999, '\n');
	cout << "Press enter to the main menu"; //Back to the main menu
	cin.ignore(999, '\n');
}
void Multiply(ST<string, Poly> &s)
{
	Star();
	cout << "Function:Subtract\n";
	string t, name;
	cout << "Polymonial 1:\n";
	Poly poly1 = GetPoly(s); //Get polynomial1
	cout << "Polymonial 2:\n";
	Poly poly2 = GetPoly(s);				   //Get polynomial2
	Poly result = poly1 * poly2;			   //Calculate
	cout << "Result:" << result << endl;	   //Print the result
	cout << "Want to store the polynomial?\n"; //Ask the user whether to store
	cout << "Enter the name to store or 0 to exit:";
	cin >> name;
	while (name != "0" && s.contains(name)) //If the name is used
	{
		cout << "The name is used!Enter the name:"; //Ask the user to change a name
		cin >> name;
	}
	if (name != "0") //If the name is valid
	{
		s.insert(name, result);								//Insert the polynomial
		cout << "The result was saved to " << name << endl; //Remind the user
	}
	cin.ignore(999, '\n');
	cout << "Press enter to the main menu"; //Back to the main menu
	cin.ignore(999, '\n');
}
void Derivative(ST<string, Poly> &s)
{
	Star();
	cout << "Function:Derivative\n";
	string t, name;
	Poly poly1 = GetPoly(s);				   //Get polynomial
	Poly result = poly1.diff();				   //Calculate
	cout << "Result:" << result << endl;	   //Print the result
	cout << "Want to store the polynomial?\n"; //Ask the user whether to store
	cout << "Enter the name to store or 0 to exit:";
	cin >> name;
	while (name != "0" && s.contains(name)) //If the name is used
	{
		cout << "The name is used!Enter the name:"; //Ask the user to change a name
		cin >> name;
	}
	if (name != "0") //If the name is valid
	{
		s.insert(name, result);								//Insert the polynomial
		cout << "The result was saved to " << name << endl; //Remind the user
	}
	cin.ignore(999, '\n');
	cout << "Press enter to the main menu"; //Back to the main menu
	cin.ignore(999, '\n');
}
void Integral(ST<string, Poly> &s)
{
	Star();
	cout << "Function:Integral\n";
	string t, name;
	Poly poly1 = GetPoly(s); //Get polynomial
	cout << "Enter the constant:";
	double c = GetNum();					   //Get the constant
	Poly result = poly1.intg(c);			   //Calculate
	cout << "Result:" << result << endl;	   //Print the result
	cout << "Want to store the polynomial?\n"; //Ask the user whether to store
	cout << "Enter the name to store or 0 to exit:";
	cin >> name;
	while (name != "0" && s.contains(name)) //If the name is used
	{
		cout << "The name is used!Enter the name:"; //Ask the user to change a name
		cin >> name;
	}
	if (name != "0") //If the name is valid
	{
		s.insert(name, result);								//Insert the polynomial
		cout << "The result was saved to " << name << endl; //Remind the user
	}
	cin.ignore(999, '\n');
	cout << "Press enter to the main menu"; //Back to the main menu
	cin.ignore(999, '\n');
}
void Value(ST<string, Poly> &s)
{
	Star();
	cout << "Function:Get value\n";
	string t, name;
	Poly poly1 = GetPoly(s); //Get polynomial
	cout << "Enter the value of x:";
	double x = GetNum();						 //Get the value x
	cout << "Result:" << poly1.value(x) << endl; //Calculate and print the result
	cout << "Press enter to the main menu";		 //Back to the main menu
	cin.ignore(999, '\n');
}
void Calculate(ST<string, Poly> &s)
{
	Star();
	cout << "Function:Cauculate\n";
	cout << "Enter an expression,such as p+((q+r)*s)\n"; //Remind the user
	cout << "You will get the result.\n";
	string t, name;
	cin >> t; //Get the expression
	try
	{
		vector<ele> rpn = ToRPN(t, s);			   //Transform the expression to RPN
		Poly result = CalcRPN(rpn);				   //Calculate the RPN
		cout << "Result:" << result << endl;	   //Print the result
		cout << "Want to store the polynomial?\n"; //Ask the user whether to store
		cout << "Enter the name to store or 0 to exit:";
		cin >> name;
		while (name != "0" && s.contains(name)) //If the name is used
		{
			cout << "The name is used!Enter the name:"; //Ask the user to change a name
			cin >> name;
		}
		if (name != "0") //If the name is valid
		{
			s.insert(name, result);								//Insert the polynomial
			cout << "The result was saved to " << name << endl; //Remind the user
		}
		cin.ignore(999, '\n');
	}
	catch (logic_error &le) //Catch exceptions
	{
		if (typeid(le) == typeid(no_found)) //If the reference is of type no_found
		{
			no_found &nf = dynamic_cast<no_found &>(le); //Cast it to no_found
			cout << nf.what() << endl;					 //Print the error
		}
		else
			cout << le.what() << endl; //Print the error
		cout << "Calculate Failed.\n"; //Remind the user
		cin.ignore(999, '\n');		   //Clear the input line
	}
	cout << "Press enter to the main menu"; //Back to the main menu
	cin.ignore(999, '\n');
}
void Warehouse(ST<string, Poly> &s)
{
	char ch;
	while ((ch = waremenu()) != 'q') //Using warehouse menu
	{
		switch (ch) //Using the right function according to the choice
		{
		case 'a':
			InsPoly(s);
			break;
		case 'b':
			DelPoly(s);
			break;
		case 'c':
			SrcPoly(s);
			break;
		case 'd':
			ChgPoly(s);
			break;
		case 'e':
			PrintAll(s);
			break;
		case 'f':
			ReadPoly(s);
			break;
		case 'g':
			WritePoly(s);
			break;
		default: //Debug function
			cout << "Loading~\n";
		}
	}
}
void Readme(void)
{
	Star();
	cout << "Polynomial Calculator\n";
	cout << "To know the functions\n";
	cout << "You can read the introduction\n";
	cout << "By Edward Bian,20337171\n";
	cout << "Press enter to the main menu"; //Back to the main menu
	cin.ignore(999, '\n');
}
void InsPoly(ST<string, Poly> &s)
{
	Star();
	cout << "Function:Insert a polynomial\n";
	string k, v;
	Poly poly;
	cout << "Enter the name of the polynomial:";
	while (cin >> k && s.contains(k)) //If the name is used
	{
		cout << "This name has been in the warehouse!\n";
		cout << "Change a name:"; //Ask the user to change a name
	}
	cin.ignore(999, '\n'); //Clear the input line
	bool flag = 1;
	while (flag)
	{
		cout << "Enter a polynomial:"; //Remind the user to input a polynomial
		cin >> v;
		try
		{
			poly = Poly(v);														//Transform the string to the polynomial
			cout << "Polynomial " << k << ":" << poly << " has been created\n"; //Print the polynomial
			flag = 0;															//Successfully get the valid input
		}
		catch (logic_error &le) //Catch exceptions
		{
			cout << le.what() << endl; //Print the error
			flag = 1;				   //Failed to get the valid input
		}
	}
	cout << "Are you sure to insert it?\n"; //Ask if the user is sure to insert it
	cout << "Press y to confirm and other to cancel:";
	if (confirm()) //If confirmed
	{
		s.insert(k, poly);								 //Insert it to the warehouse
		cout << "Polynomial " << k << " is inserted!\n"; //Remind the user
	}
	else										//If cancelled
		cout << "Operation cancelled\n";		//Remind the user
	cout << "Press enter to the previous menu"; //Back to the previous menu
	cin.ignore(999, '\n');
}
void DelPoly(ST<string, Poly> &s)
{
	Star();
	cout << "Function:Delete a polynomial\n";
	string k;
	cout << "Enter the name of the polynomial:";
	cin >> k;		   //Get the polynomial's name
	if (s.contains(k)) //If it exists
	{
		cout << "The polynomial is :" << s[k] << endl; //Print the polynomial
		cout << "Are you sure to delete it?\n";		   //Ask if the user is sure to delete it
		cout << "Press y to confirm and other to cancel:";
		if (confirm()) //If confirmed
		{
			s.erase(k);										//Delete it from the table
			cout << "Polynomial " << k << " is deleted!\n"; //Remind the user
		}
		else								 //If cancelled
			cout << "Operation cancelled\n"; //Remind the user
	}
	else										 //If it doesn't exist
		cout << "Cannot find the polynomial!\n"; //Remind the user
	cout << "Press enter to the previous menu";	 //Back to the previous menu
	cin.ignore(999, '\n');
}
void SrcPoly(ST<string, Poly> &s)
{
	Star();
	cout << "Function:Search a polynomial\n";
	string k;
	cout << "Enter the name of the polynomial:";
	cin >> k;										   //Get the polynomial's name
	if (s.contains(k))								   //If it exists
		cout << "The polynomial is :" << s[k] << endl; //Print the polynomial
	else											   //If it doesn't exist
		cout << "Cannot find the polynomial!\n";	   //Remind the user
	cout << "Press enter to the previous menu";		   //Back to the previous menu
	cin.ignore(999, '\n');
}
void ChgPoly(ST<string, Poly> &s)
{
	Star();
	cout << "Function:Change a polynomial\n";
	string k, v;
	cout << "Enter the name of the polynomial:";
	cin >> k; //Get the polynomial's name
	Poly poly;
	if (s.contains(k)) //If it exists
	{
		cout << "The polynomial is :" << s[k] << endl; //Print the polynomial
		bool flag = 1;
		while (flag)
		{
			cout << "Enter a polynomial:"; //Remind the user to input a polynomial
			cin >> v;
			try
			{
				poly = Poly(v);														//Transform the string to the polynomial
				cout << "Polynomial " << k << ":" << poly << " has been created\n"; //Print the polynomial
				flag = 0;															//Successfully get the valid input
			}
			catch (logic_error &le) //Catch exceptions
			{
				cout << le.what() << endl; //Print the error
				flag = 1;				   //Failed to get the valid input
			}
		}
		cout << "Are you sure to change it?\n"; //Ask if the user is sure to change it
		cout << "Press y to confirm and other to cancel:";
		if (confirm()) //If confirmed
		{
			s[k] = poly;															//Change the polynomial
			cout << "Polynomial " << k << " has been changed to" << poly << " !\n"; //Remind the user
		}
		else								 //If cancelled
			cout << "Operation cancelled\n"; //Remind the user
	}
	else										 //If it doesn't exist
		cout << "Cannot find the polynomial!\n"; //Remind the user
	cout << "Press enter to the previous menu";	 //Back to the previous menu
	cin.ignore(999, '\n');
}
void PrintAll(ST<string, Poly> &s)
{
	Star();
	cout << "Function:Print all polynomials\n";
	s.ShowAll();								//Print all stored polynomials as 3x^2-4x+6
	cout << "Press enter to the previous menu"; //Back to the previous menu
	cin.ignore(999, '\n');
}
void ReadPoly(ST<string, Poly> &s)
{
	Star();
	cout << "Function:Read polynomials from a file\n";
	ifstream fin; //Create an ifstream object
	cout << "Enter the file's name:";
	string filename, str, name;
	cin >> filename;			//Get the filename
	fin.open(filename.c_str()); //Try to open the file
	if (!fin.is_open())			//If the file can't be opened
	{
		cout << "Cannot open the file!\n"; //Remind the user
		cin.ignore(999, '\n');
		cout << "Press enter to the previous menu"; //Back to the previous menu
		cin.ignore(999, '\n');
		return;
	}
	cout << "The file " << filename << " is open!\n"; //Tell the user that the file is open
	int count = 0, x;
	Poly poly;
	while (fin >> str) //Read a line
	{
		count++;									 //Counter
		cout << "Processing Line " << count << endl; //Tell the user which line in being processed
		cout << "Contains:" << str << endl;			 //Print the line
		try
		{
			for (x = 0; x < str.size(); x++) //Scan the string
			{
				if (str[x] == '=') //Using "=" to seperate the name and the polynomial
				{
					name = str.substr(0, x);							  //Get the name
					poly = Poly(str.substr(x + 1, str.length() - x - 1)); //Transform the string to a polynomial
					break;
				}
			}
			if (x == str.size())	   //If no "=",the line is illegal
				throw illegal_input(); //Throw an exception
			if (!s.contains(name))	   //If the name is available
			{
				s.insert(name, poly);												   //Insert the polynomial into the symbol table
				cout << "Successfully get polynomial " << name << ":" << poly << endl; //Tell the user
			}
			else									 //If the name is used
				cout << "Error!The name is used!\n"; //Remind the user
		}
		catch (logic_error &le) //Catch exceptions
		{
			cout << le.what() << endl; //Print the error
		}
	}
	if (count == 0)				 //If the file is empty
		cout << "Empty file!\n"; //Remind the user
	cin.ignore(999, '\n');
	cout << "Press enter to the previous menu"; //Back to the previous menu
	cin.ignore(999, '\n');
}
void WritePoly(ST<string, Poly> &s)
{
	Star();
	cout << "Function:Write polynomials from a file\n";
	ofstream fout;																				//Create an ofstream object
	cout << "WARNING:if the file you choose has already got some words,it will be truncated\n"; //Warning
	cout << "Enter the file's name:";
	string filename, str, name;
	cin >> filename; //Get the filename
	fout.open(filename.c_str());
	if (!fout.is_open()) //If the file can't be opened
	{
		cout << "Cannot open the file!\n"; //Remind the user
		cin.ignore(999, '\n');
		cout << "Press enter to the previous menu"; //Back to the previous menu
		cin.ignore(999, '\n');
		return;
	}
	cout << "The file " << filename << " is open!\n"; //Tell the user that the file is open
	s.tofile(fout);									  //Print the polynomials in the warehouse in standard input form
	cout << "Success!\n";							  //Remind the user
	cin.ignore(999, '\n');
	cout << "Press enter to the previous menu"; //Back to the previous menu
	cin.ignore(999, '\n');
}
