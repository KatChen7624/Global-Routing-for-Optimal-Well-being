/* 
  * Functions I reuse to save time in reprogramming basic validation and the program loop.
  * Comments inside function definitions are the parts that get altered when adapted for a new program.
*/
#include <iostream> 
#include <fstream>
#include "nonmember.h"
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
  * Saves/writes data into a seperate text file provided by the user.
  * @PARAM 
  * @PARAM 
*/
void savedata();

#endif
