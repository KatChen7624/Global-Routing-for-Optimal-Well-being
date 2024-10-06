#include "validation.h"

bool yn_val() {
  bool running = true;
  std::string ans;
  while (running) {
    std::cin.clear();
    std::cout << "ENTER 'Y' OR 'N': ";
    std::cin >> ans;
    if (ans == "y" || ans == "Y") {return true;}
    else if (ans == "n" || ans == "N") {return false;}
    else {
      std::cout << "TRY AGAIN...";
      running = true;
    }
  }
  return 0;
}

std::string word_val() {
  bool running = true;
  std::string word;
  bool yes = false;
  while (running) {
    std::cout << "ENTER: ";
    std::cin.clear();
    std::cin >> word;
    std::cout << "Is " << word << " correct?\n";
    yes = yn_val();
    if (yes) {running = false;} 
  }
  return word;
}

int menu_val(int size) {
  bool running = true;
  int ans;
  std::cout << "ENTER A VALID OPTION:";
  
  while (running) {
    std::cin >> ans;
    for (int i = 1; i <= size; i++) {
      if (ans == i) {
        std::cout << "\nYou entered " << ans << ", is this correct? \n";
        bool yes = yn_val();
        if (yes) {return ans;}
      }
    }
    std::cout << "SORRY, TRY AGAIN: ";
    std::cin.clear();
    std::cin.ignore();
  }
  return 0;
}


bool choice_val(std::string s){
	
	
}