/* 
  * Team Project by Kexin Chen, Binh Nguyen, Kaleb Villalaz
  * Cs 124 Spring 23
*/
#include <iostream>
#include "main_helper.h"

int main(){
  //The greeting: returns true of false to start program or end it.
  bool running = greeting();
  
  //Loop to enter and/or repeat program.
  while (running){
	running = main_menu();
  }
  
  outro(); //Ends Program, Provides a farewell message. 
  return 0;  
}

