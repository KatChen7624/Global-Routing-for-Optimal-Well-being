/* 
  * Functions I reuse to save time in reprogramming basic validation and the program loop.
  * Comments inside function definitions are the parts that get altered when adapted for a new program.
*/
#include <iostream>
#include <fstream> 
#include "helper.h"
#ifndef MAIN_HELPER_H
#define MAIN_HELPER_H

/* 
  * Display a friendly greeting and descripton of the program.
  * @RETURN Bool to enter program or end program
*/
bool greeting();

/* 
  * Main Menu for all options user can choose from. 
  * Template formatted for 4 options, follow instructions in function to change for more/less. 
*/
bool main_menu();  //incomplete

/* 
  * Route Menu, set your starting location and destination. 
  * @PARAM Bool start, true if user has set a starting location 
  * @PARAM Bool end, true if user has set a destination
*/
void route_menu(bool& start, bool& end); //incomplete

/* 
  * Sensitivity  Menu, set your Sensitivity levels, default is average.
  * 
*/
void sensitivity_menu(); //incomplete

/* 
  * Asks the user if they would like to try  the again. 
  * @RETURN True or false
*/
bool repeat();

/* 
  * Warmly ends the program.
*/
void outro();

#endif
