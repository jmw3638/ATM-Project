#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <string>
#include <fstream>
#include <stdio.h> 
#include <ctype.h>
using namespace std;

void Draw();
void Input();
void Select();
void Login();
void Logout();
void CreateAccount();
void DeleteAccount();
void Deposit();
void Withdraw();
void Transfer();
void Set();
void UpdateBalance(string user,  string password, float amount, char operation);
float GetBalance(string user);
string GetPassword(string user);
void SetPassword();
void AdminDraw();
void AdminSelect();

bool runProgram = true;
bool runMenu = true;
bool admin = false;
bool loggedIn = false;
int pos = 1;
char key;
string user = "Not Logged In!";
float balance = 0.00;
string pass;
string userFile;
string error;

int main()
{
	system("title Automated Teller Machine [ATM]");	
	system("color 6");
    
 	while (runProgram)
	{
		while (runMenu)
	    {
	    	if (!admin)
	    	{
	    		Draw();
	        	Input();
			}
			else
			{
				system("color c");
				AdminDraw();
				Input();
			}
        }
	}
   
}

void Draw()
{	
	system("cls");
	
	switch (pos)
	{
		case 1:
			 cout << "[-] ATM [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "> Login" <<  endl;
 	  		 cout << "Logout" << endl;
 	  		 cout << "Create Account" << endl;
 	  		 cout << "Delete Account" << endl << endl;
			 cout << "Deposit" << endl;
			 cout << "Withdraw" << endl;
			 cout << "Transfer" << endl << endl;
			 cout << "Exit" << endl;
			 cout << endl << error << endl;
			break;
		case 2:
			 cout << "[-] ATM [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "Login" <<  endl;
 	  		 cout << "> Logout" << endl;
 	  		 cout << "Create Account" << endl;
 	  		 cout << "Delete Account" << endl << endl;
			 cout << "Deposit" << endl;
			 cout << "Withdraw" << endl;
			 cout << "Transfer" << endl << endl;
			 cout << "Exit" << endl;
			 cout << endl << error << endl;
			break;
		case 3:
			 cout << "[-] ATM [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "Login" << endl;
 	  		 cout << "Logout" << endl;
 	  		 cout << "> Create Account" << endl;
 	  		 cout << "Delete Account" << endl << endl;
			 cout << "Deposit" << endl;
			 cout << "Withdraw" << endl;
			 cout << "Transfer" << endl << endl;
			 cout << "Exit" << endl;
			 cout << endl << error << endl;
			break;
		case 4:
			 cout << "[-] ATM [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "Login" << endl;
 	  		 cout << "Logout" << endl;
 	  		 cout << "Create Account" << endl;
 	  		 cout << "> Delete Account" << endl << endl;
			 cout << "Deposit" << endl;
			 cout << "Withdraw" << endl;
			 cout << "Transfer" << endl << endl;
			 cout << "Exit" << endl;
			 cout << endl << error << endl;
			break;
		case 5:
			 cout << "[-] ATM [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "Login" << endl;
 	  		 cout << "Logout" << endl;
 	  		 cout << "Create Account" << endl;
 	  		 cout << "Delete Account" << endl << endl;
			 cout << "> Deposit" << endl;
			 cout << "Withdraw" << endl;
			 cout << "Transfer" << endl << endl;
			 cout << "Exit" << endl;
			 cout << endl << error << endl;
			break;
		case 6:
			 cout << "[-] ATM [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "Login" << endl;
 	  		 cout << "Logout" << endl;
 	  		 cout << "Create Account" << endl;
 	  		 cout << "Delete Account" << endl << endl;
			 cout << "Deposit" << endl;
			 cout << "> Withdraw" << endl;
			 cout << "Transfer" << endl << endl;
			 cout << "Exit" << endl;
			 cout << endl << error << endl;
			break;
		case 7:
			 cout << "[-] ATM [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "Login" << endl;
 	  		 cout << "Logout" << endl;
 	  		 cout << "Create Account" << endl;
 	  		 cout << "Delete Account" << endl << endl;
			 cout << "Deposit" << endl;
			 cout << "Withdraw" << endl;
			 cout << "> Transfer" << endl << endl;
			 cout << "Exit" << endl;
			 cout << endl << error << endl;
			break;
		case 8:
			 cout << "[-] ATM [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "Login" << endl;
 	  		 cout << "Logout" << endl;
 	  		 cout << "Create Account" << endl;
 	  		 cout << "Delete Account" << endl << endl;
			 cout << "Deposit" << endl;
			 cout << "Withdraw" << endl;
			 cout << "Transfer" << endl << endl;
			 cout << "> Exit" << endl;
			 cout << endl << error << endl;
			break;
		default:
		    runMenu = false;
		    runProgram = false;
		    break;
	}
}

void Input()
{
	key = getch();
	
	switch (key)
	{
        case 72: // Up Arrow
	        pos--;
	        if (pos < 1)
	        {
	        	pos = 8;
			}
			error = "";
	 		break;
	    case 80: // Down Arrow
	        pos++;
	        if (pos > 8)
	        {
	        	pos = 1;
			}
			error = "";
            break;
        case 13: // Enter Key
        	runMenu = false;
        	if (!admin)
        	{
        		Select();
			}
			else
			{
				system("color c");
			    AdminSelect();	
			}
           	break;
        default:
	    	break;		
	}
}

void Select()
{
	switch (pos)
	{
		case 1:
			system("cls");
			if (!loggedIn)
			{
				Login();
			}
			else
			{
				error = "Error! You are already logged in.";
			}
			runMenu = true;
			break;
		case 2:
            system("cls");
            if (loggedIn)
			{
				Logout();
				error = "Successfully logged out.";
			}
			else
			{
				error = "Error! You are not logged in.";
			}
            runMenu = true;
            break;
		case 3:
			system("cls");
			if (!loggedIn)
			{
				CreateAccount();
			}
			else
			{
				error = "Error! You are already logged in.";
			}
			runMenu = true;
			break;
		case 4:
			system("cls");
			if (loggedIn)
			{
				DeleteAccount();
			}
			else
			{
				error = "Error! You are not logged in.";
			}
			runMenu = true;
			break;
		case 5:
			system("cls");
			if (loggedIn)
			{
				Deposit();
			}
			else
			{
				error = "Error! You are not logged in.";
			}
			runMenu = true;
			break;
		case 6:
			system("cls");
			if (loggedIn)
			{
				Withdraw();
			}
			else
			{
				error = "Error! You are not logged in.";
			}
			runMenu = true;
			break;
		case 7:
			system("cls");
			if (loggedIn)
			{
				Transfer();
			}
			else
			{
				error = "Error! You are not logged in.";
			}
			runMenu = true;
			break;
		case 8:
			system("cls");
			runProgram = false;
			break;
		default:
		    runProgram = false;
		    break;
	}
}

void Login()
{	
	while (true)
	{
		string inputUser, inputPass, possibleUser;
	
		cout << "[-] Login [-]\nLogin to your account.\n\n";
		cout << "Username: "; 
		getline(cin, inputUser);
		
		possibleUser = inputUser; 
	    inputUser += ".txt";
			
		ifstream checkExistance;
		checkExistance.open(inputUser.c_str(), ios::in);
			
		if (!checkExistance && possibleUser != "Admin")
		{
		    error = "Error! Username does not exist.";
		    break;
		}
		
		if (admin)
		{
			user = "Logged In: " + possibleUser;
	    	userFile = possibleUser + ".txt"; 
	    	balance = GetBalance(userFile);
	    	pass = GetPassword(userFile);
	    	loggedIn = true;
	    	
	    	error = "Successfully logged in to account!";
	    	break;
		}
					
	    cout << "Password: ";
	    getline(cin, inputPass);

		checkExistance.close();
		
		if (possibleUser == "Admin" && inputPass == "AdminPass")
		{
			admin = true;
			error = "Successfully logged in to Admin!";
			break;
		}
		
		if (GetPassword(inputUser) != inputPass)
		{
			error = "Error! Incorrect password.";
			break;
		}
	    
	    user = "Logged In: " + possibleUser;
	    userFile = possibleUser + ".txt"; 
	    balance = GetBalance(userFile);
	    pass = GetPassword(userFile);
	    loggedIn = true;
	    
	    system("color 2");
	    error = "Successfully logged in!";
	    break;
	}
}

void Logout()
{
    loggedIn = false;
    system("color 6");
    user = "Not Logged In!";
    balance = 0.00;
    pass = "";
}

void CreateAccount()
{	
	while (true)
	{
		string inputUser, inputPass, inputConfirm, possibleUser;
	
		cout << "[-] Create Account [-]\nCreate an account.\n\n";
		cout << "Username: "; 
		getline(cin, inputUser);
	
		if (inputUser.length() < 4 || inputUser.length() > 16)
		{
            error = "Error! Username must be at least 4 characters and no more than 16 characters.";
	        break;
	    }
	    
	    possibleUser = inputUser;
	    inputUser += ".txt";
			
		ofstream checkExistance;
		checkExistance.open(inputUser.c_str(), ios::in);
			
		if (checkExistance)
		{
		    error = "Error! Username already in use! Try another one.";
		    checkExistance.close();
		    break;
		}
			
	    cout << "Password: ";
	    getline(cin, inputPass);
	    
	    cout << "Confirm Password: ";
	    getline(cin, inputConfirm);
	    
	    if (inputPass != inputConfirm)
	    {
	    	error = "Error! Passwords do not match.";
	    	break;
		}
		
		ofstream newAccount;
	    newAccount.open(inputUser.c_str(), ios::app);
	    newAccount << 0.00 << endl;
	    newAccount << inputPass << endl;
	    newAccount.close();
	    
	    user = "Logged In: " + possibleUser;
	    userFile = possibleUser + ".txt"; 
	    balance = GetBalance(userFile);
	    pass = GetPassword(userFile);
		loggedIn = true;
		
		error = "Successfully created your account!";
		system("color 2");
	    break;
	}
}

void DeleteAccount()
{
	while (true)
	{	
		string confirmPass, confirmUser;

     	cout << "[-] Delete Account [-]\nDelete your account.\n\n";
     	
     	if (admin)
     	{
     		cout << "You are about to delete this account, type in the username to confirm.\n\n";
     		cout << "Username: ";
     		getline(cin, confirmUser);
		
			if (confirmUser + ".txt" != userFile)
	    	{
	    	    error = "Error! Incorrect username.";
    	 	    break;
		    }
		     
     		 remove(userFile.c_str());
        
        	 Logout();
        	 error = "Successfully deleted account!";
   			 break;
        }
     	
		cout << "You are about to delete your account, type your password to confirm.\n\n";
     	cout << "Password: ";
     	getline(cin, confirmPass);
		
		if (confirmPass != pass)
	    {
	    	error = "Error! Incorrect password.";
	    	break;
		}
		     
     	remove(userFile.c_str());
        
        Logout();
        error = "Successfully deleted account!";
   		break;
	}
}

void Deposit()
{
	while (true)
	{
		string inputString;
		float inputFloat;

		cout << "[-] Deposit [-]\nDeposit money in to your account.\n\n"; 
		cout << "How much money would you like to deposit?\n\n$";
		getline(cin, inputString);
		
		if (!(inputFloat = atof(inputString.c_str())))
		{
			error = "Error! Invalid amount.";
			break;
		}
		
		UpdateBalance(userFile, pass, inputFloat, '+');
		
		balance = GetBalance(userFile);
        error = "Successfully deposited $" + inputString + "!";
        break;
	}
}

void Withdraw()
{
	while (true)
	{
		string inputString;
		float inputFloat;

		cout << "[-] Withdraw [-]\nWithdraw money from your account.\n\n";
		cout << "How much money would you like to withdraw?\n\n$";
		getline(cin, inputString);
		
		if (!(inputFloat = atof(inputString.c_str())))
		{
			error = "Error! Invalid amount.";
			break;
		}
		
		if (GetBalance(userFile) - inputFloat < 0)
		{
			error = "Error! You do not have enough money in your account.";
			break;
		}
		
		UpdateBalance(userFile, pass, inputFloat, '-');
		
		balance = GetBalance(userFile);
		error = "Successfully withdrew $" + inputString + "!";
        break;
	}
}

void Transfer()
{
	while (true)
	{
		string inputUser, inputUserFile, inputString; 
		float inputFloat;
	
		cout << "[-] Transfer [-]" << endl;
		cout << "Transfer money to another account." << endl << endl; 
		cout << "Transfer to (username): ";
		getline(cin, inputUser);
	    inputUserFile = inputUser + ".txt";
	    
	    if (inputUserFile == userFile)
		{
			error = "Error! You can not transfer money to yourself.";
			break;
		}
			
		ifstream checkExistance;
		checkExistance.open(inputUserFile.c_str(), ios::in);
			
		if (!checkExistance)
		{
		    error = "Error! Username does not exist.";
		    break;
		}

		checkExistance.close();
		
		cout << "Amount to transfer: $";
		getline(cin, inputString);
		
		if (!(inputFloat = atof(inputString.c_str())))
		{
			error = "Error! Invalid amount.";
			break;
		}
		
		if (GetBalance(userFile) - inputFloat < 0)
		{
			error = "Error! You do not have enough money in your account.";
			break;
		}
		
		UpdateBalance(userFile, pass, inputFloat, '-');
		UpdateBalance(inputUserFile, GetPassword(inputUserFile), inputFloat, '+');

		balance = GetBalance(userFile);
		error = "Successfully transfered $" + inputString + " to " + inputUser + "!";
        break;
	}
}

void Set()
{
	while (true)
	{
		string inputUser, inputUserFile, inputString; 
		float inputFloat;
	
		cout << "[-] Set Balance [-]" << endl;
		cout << "Set balance of account." << endl << endl; 
		
		cout << "Set balance to: $";
		getline(cin, inputString);
		
		if (!(inputFloat = atof(inputString.c_str())) && inputString != "0")
		{
			error = "Error! Invalid amount.";
			break;
		}
		
		if (inputString == "0")
		{
			inputFloat = 0;
		}
		
		UpdateBalance(userFile, GetPassword(userFile), inputFloat, '=');
		
		balance = GetBalance(userFile);
		error = "Successfully set balance to $" + inputString + "!";
        break;
	}
}

void UpdateBalance(string user, string password, float amount, char operation)
{
	float newAmount;
	
	switch (operation)
	{
		case '+':
			newAmount = GetBalance(user) + amount;
			break;
		case '-':
			newAmount = GetBalance(user) - amount;
			break;
		case '=':
			newAmount = amount;
			break;
		default:
			newAmount = GetBalance(user);
			break;
	}
	
    ofstream file;
    file.open(user.c_str(), ios::in);
    file << newAmount << endl;
	file << password << endl;
	file.close();
}

float GetBalance(string user)
{
	string balanceString;
	float balanceFloat;
	
	ifstream file;
	file.open(user.c_str(), ios::in);
	getline(file, balanceString);
	file.close();
	
	balanceFloat = atof(balanceString.c_str());
	
	return balanceFloat;
}

string GetPassword(string user)
{
	string balance, password;
	
	ifstream file;
	file.open(user.c_str(), ios::in);
	getline(file, balance);
	getline(file, password);
	file.close();
	
	return password;
}

void SetPassword(string user, string newPass)
{	
	ofstream file;
    file.open(user.c_str(), ios::in);
    file << GetBalance(user) << endl;
	file << newPass << endl;
	file.close();
}


void AdminDraw()
{
	system("cls");
	
	switch (pos)
	{
		case 1:
			 cout << "[-] ATM Admin [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "> Login Account" <<  endl;
 	  		 cout << "Logout Account" << endl;
 	  		 cout << "Create Account" << endl;
 	  		 cout << "Delete Account" << endl << endl;
			 cout << "Increase Balance" << endl;
			 cout << "Decrease Balance" << endl;
			 cout << "Set Balance" << endl << endl;
			 cout << "Logout Admin" << endl;
			 cout << endl << error << endl;
			break;
		case 2:
			 cout << "[-] ATM Admin [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "Login Account" <<  endl;
 	  		 cout << "> Logout Account" << endl;
 	  		 cout << "Create Account" << endl;
 	  		 cout << "Delete Account" << endl << endl;
			 cout << "Increase Balance" << endl;
			 cout << "Decrease Balance" << endl;
			 cout << "Set Balance" << endl << endl;
			 cout << "Logout Admin" << endl;
			 cout << endl << error << endl;
			break;
		case 3:
			 cout << "[-] ATM Admin [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "Login Account" <<  endl;
 	  		 cout << "Logout Account" << endl;
 	  		 cout << "> Create Account" << endl;
 	  		 cout << "Delete Account" << endl << endl;
			 cout << "Increase Balance" << endl;
			 cout << "Decrease Balance" << endl;
			 cout << "Set Balance" << endl << endl;
			 cout << "Logout Admin" << endl;
			 cout << endl << error << endl;
			break;
		case 4:
			 cout << "[-] ATM Admin [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "Login Account" <<  endl;
 	  		 cout << "Logout Account" << endl;
 	  		 cout << "Create Account" << endl;
 	  		 cout << "> Delete Account" << endl << endl;
			 cout << "Increase Balance" << endl;
			 cout << "Decrease Balance" << endl;
			 cout << "Set Balance" << endl << endl;
			 cout << "Logout Admin" << endl;
			 cout << endl << error << endl;
			break;
		case 5:
			 cout << "[-] ATM Admin [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "Login Account" <<  endl;
 	  		 cout << "Logout Account" << endl;
 	  		 cout << "Create Account" << endl;
 	  		 cout << "Delete Account" << endl << endl;
			 cout << "> Increase Balance" << endl;
			 cout << "Decrease Balance" << endl;
			 cout << "Set Balance" << endl << endl;
			 cout << "Logout Admin" << endl;
			 cout << endl << error << endl;
			break;
		case 6:
			 cout << "[-] ATM Admin [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "Login Account" <<  endl;
 	  		 cout << "Logout Account" << endl;
 	  		 cout << "Create Account" << endl;
 	  		 cout << "Delete Account" << endl << endl;
			 cout << "Increase Balance" << endl;
			 cout << "> Decrease Balance" << endl;
			 cout << "Set Balance" << endl << endl;
			 cout << "Logout Admin" << endl;
			 cout << endl << error << endl;
			break;
		case 7:
			 cout << "[-] ATM Admin [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "Login Account" <<  endl;
 	  		 cout << "Logout Account" << endl;
 	  		 cout << "Create Account" << endl;
 	  		 cout << "Delete Account" << endl << endl;
			 cout << "Increase Balance" << endl;
			 cout << "Decrease Balance" << endl;
			 cout << "> Set Balance" << endl << endl;
			 cout << "Logout Admin" << endl;
			 cout << endl << error << endl;
			break;
		case 8:
			 cout << "[-] ATM Admin [-]" << endl;
			 cout << user << endl;
			 cout << "Balance: $" << balance << endl << endl;
 	  		 cout << "Login Account" <<  endl;
 	  		 cout << "Logout Account" << endl;
 	  		 cout << "Create Account" << endl;
 	  		 cout << "Delete Account" << endl << endl;
			 cout << "Increase Balance" << endl;
			 cout << "Decrease Balance" << endl;
			 cout << "Set Balance" << endl << endl;
			 cout << "> Logout Admin" << endl;
			 cout << endl << error << endl;
			break;
		default:
		    runMenu = false;
		    runProgram = false;
		    break;
	}
}

void AdminSelect()
{
	switch (pos)
	{
		case 1:
			system("cls");
			if (!loggedIn)
			{
				Login();
			}
			else
			{
				error = "Error! You are already logged in to an account.";
			}
			runMenu = true;
			break;
		case 2:
            system("cls");
            if (loggedIn)
			{
				Logout();
				error = "Successfully logged out of account.";
			}
			else
			{
				error = "Error! You are not logged in to an account.";
			}
            runMenu = true;
            break;
		case 3:
			system("cls");
			if (!loggedIn)
			{
				CreateAccount();
			}
			else
			{
				error = "Error! You are already logged in to an account.";
			}
			runMenu = true;
			break;
		case 4:
			system("cls");
			if (loggedIn)
			{
				DeleteAccount();
			}
			else
			{
				error = "Error! You are not logged in to an account.";
			}
			runMenu = true;
			break;
		case 5:
			system("cls");
			if (loggedIn)
			{
				Deposit();
			}
			else
			{
				error = "Error! You are not logged in to an account.";
			}
			runMenu = true;
			break;
		case 6:
			system("cls");
			if (loggedIn)
			{
				Withdraw();
			}
			else
			{
				error = "Error! You are not logged in to an account.";
			}
			runMenu = true;
			break;
		case 7:
			system("cls");
			if (loggedIn)
			{
				Set();
			}
			else
			{
				error = "Error! You are not logged in to an account.";
			}
			runMenu = true;
			break;
		case 8:
			system("cls");
			system("color 6");
			Logout();
			error = "Successfully logged out of Admin!";
			runMenu = true;
			admin = false;
			break;
		default:
		    runProgram = false;
		    break;
	}
}
