#include "helper.h"
#include "hashtable.h"
std::string get_file_name() 
{
  bool running = true;
  std::fstream datafile;
  std::string filename;
  
  std::cout << "Please enter the file name below.\n";
  
  while (running) {
    filename = word_val() + ".txt";
    datafile.open(filename);
    if (datafile.fail()) {
      std::cout << "Failed to open file, please try again.\n";
      datafile.clear();
      running = true;
    } 
    else {running = false;}
  }
  return filename;
}

//Reuse: Add instructions on how to read in/process/save the data. Ex: Into array to access later.
void read_data(std::string filename) { 
  std::ifstream datafile;
	datafile.open(filename);
	
	
  //Process Data however applicable
}
void read_accounts(std::vector<Account>& accounts) { 
	std::ifstream datafile;
	datafile.open("accounts.txt");
	std::string user;
	int level; 
	while (datafile >> user >> level) {
	  Account newaccount (user, level); 
	  accounts.push_back(newaccount);
	  
	}
  
}

void create_account(std::vector<Account>& accounts) {
	Account newaccount;
	newaccount.new_account();
	accounts.push_back(newaccount);
  std::ofstream datafile;
	datafile.open("accounts.txt");
	for (int i = 0; i < accounts.size(); i++ ) {
			datafile << accounts[i].get_username() << " " << accounts[i].get_level() << "\n";
	}
}

//Reuse: Write instuction on how to properly format the data to write into the text file. 
void save_data(){
  std::ofstream savefile;
  std::string filename = get_file_name();
  savefile.open(filename);

  std::cout << "\nSAVING...\n";
  //Write Data into a seperate text file in appropriate formatting. 
  //savefile << ;

    
  std::cout << "SAVED.\n";
}
