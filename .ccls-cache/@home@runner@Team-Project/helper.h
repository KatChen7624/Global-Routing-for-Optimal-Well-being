/* 
  * Functions I reuse to save time in reprogramming basic validation and the program loop.
  * Comments inside function definitions are the parts that get altered when adapted for a new program.
*/
#include <iostream> 
#include <fstream>
#include <iomanip>
#include "accounts.h"
#ifndef HELPER_H
#define HELPER_H

/* 
  * Gets the name of the text file and checks if it opens correctly. 
  * @RETURN Valid file name
*/
std::string get_file_name();

/* 
  * Read the data from the text file, Then process however applicable. 
  * @Param Name of the file. 
*/
void read_data(std::string filename);

/* 
  * Read the text file of accounts, username and sensitivity level. 
  * Adds into an accounts vector. 
  * @Param Vector of the accounts. 
*/
void read_accounts(std::vector<Account>& accounts);

/* 
  * Creates a new account and adds it to the accounts vector.  
  * 
  * @Param Vector of the accounts. 
*/
void update_account(std::vector<Account>& accounts);

/*
  * Saves/writes data into a seperate text file provided by the user.
  * @PARAM 
  * @PARAM 
*/
void savedata();

Account& chooseAccount(std::vector<Account>& accounts);

#endif
