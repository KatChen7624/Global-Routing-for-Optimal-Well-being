#include "main_helper.h"

// Reuse: Change cout statement, provide a descripton of the program.
bool greeting()
{
	bool newuser;
	std::cout << "Hello there!\n"
			  << "Please select an option form the following menu: \n";
	newuser = user_menu();
	return newuser;
}

bool user_menu()
{

	int options = 2; // The total amount of options available to the user.
	int ans;
	// The different options the user can choose from.
	std::cout << "(1) Returning user.\n"
			  << "(2) New user.\n";
	ans = menu_val(options);

	if (ans == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// Reuse: Change cout statement, provide a descripton of the program.
bool new_user_greeting()
{
	std::string ans;
	bool yes = false;
	std::cout << "Instructions: To progress the program you will be asked"
			  << " various questions/prompts,\n"
			  << "type your answer then press enter.\n\n";

	std::cout << "Welcome! "
			  << "This program will provide a route to your destination \n" // The description displayed to the user.
			  << "based on your specified sensitivity levels. \n"
			  << "Would you like to give it a try? \n";

	yes = yn_val();
	if (yes)
	{
		std::cout << "Let's get started!\n";
		return true;
	}
	else
	{
		return false;
	}
}

// Menu template formatted for 4 options
// Reuse: change options size, cout menu, and if statements.
bool main_menu()
{
	//This is in the menu since we'd only want to use it if the user actually wants to use it.
	init();
	int options = 5; // The total amount of options available to the user.
	int ans;
	bool again = false; // To loop the program
	bool done = false;	// To loop Menu

	bool start = false; // To ensure a starting location was chosen
	bool end = false;	// To Ensure a starting location was chosen

	PathFinder pf;
	pf.CreatePaths();
	while (!done)
	{
		// std::system ("clear");
		std::cin.ignore();
		std::cin.clear();
		// The different options the user can choose from.
		std::cout << "\nMAIN MENU\n";
		std::cout << "(1) Start Route.\n"
				  << "(2) Set Route.\n"
				  << "(3) Set Sensitivity.\n"
				  << "(4) Quit.\n";

		ans = menu_val(options);

		switch (ans)
		{
		case 1:
			// The instructions for Start Route
			// Validate that user added a start and end point.
			// If valid: Give them their route
			// Else, return to Main Menu.
			if (start == true && end == true)
			{
				StartRoute(pf);
			}
			else std::cout << "Sorry, you do not have a path set yet, please set your paths.";
			break;
		case 2:
			// The instructions for Set Route
			route_menu(start, end);
			break;
		case 3:
			// The instructions for Set Sensitivity
			sensitivity_menu();
			break;
		case 4:
			// Quit is the last option in the menu, program ends.
			done = true;
			break;
		case 5:
			Debug_Menu();
			break;
		}
	}

	return false;
}//exactly 60 lines

void StartRoute(PathFinder& pf){
	//std::cout << "Starting pathfinder\n";

	int startingLocation = SystemData::CityNameToIndex[SystemData::AccountInUse->get_start()];
	int destination = SystemData::CityNameToIndex[SystemData::AccountInUse->get_destination()];
	int aqi = SystemData::AccountInUse->get_level();

	//std::cout << startingLocation << " " << destination << " " << aqi;
	pf.dijkstra(startingLocation, SystemData::AccountInUse->get_level());
	//std::cout << "finished!\n";

	// string city name to number
	pf.printShortestPath(destination);
}
void Debug_Menu()
{

	bool done = false;
	int options = 3;
	while (!done)
	{
		std::cout << "\nGenerate Data\n";
		std::cout << "(1) Update AQI Levels.\n"
				  << "(2) Generate Random Routes.\n"
				  << "(3) Back.\n";

		switch (menu_val(options))
		{
		case 1:
			std::cout << "Pulling from APININJA Air Quality API\n";
			system("python3 pull.py");
			std::cout << "Done!\n";
			break;
		case 2:
			std::cout << "Generating new paths...\n";
			system("python3 generatenewpath.py");
			std::cout << "Generated new paths!\n";
			break;
		case 3:
			std::cout << "Backing out.";
			done = true;
			break;
		}
	}
}
void PrintAllCities()
{
	std::cout << "==== List of cities ====\n\n";
	for (int i = 0; i < SystemData::ListOfCities.size(); i++)
	{
		std::cout << std::left << std::setw(2) << std::to_string(i + 1) << " - " << std::setw(20) << SystemData::ListOfCities[i];
		if ((i + 1) % 4 == 0)
		{
			std::cout << std::endl;
		}
	}

	std::cout << "\n=========================\n";
}
// Menu to Set the Destination and Starting point.
void route_menu(bool &start, bool &end)
{
	int options = 3; // The total amount of options available to the user.
	int ans;
	bool done = false; // Stay in menu until the user choses to return.

	while (!done)
	{
		std::system("clear");
		std::cin.ignore();
		std::cin.clear();

		PrintAllCities();

		std::cout << SystemData::AccountInUse->get_start() << std::endl;
		std::cout << SystemData::AccountInUse->get_destination();
		// The different options the user can choose from.
		std::cout << "\nSET ROUTE\n";
		std::cout << "(1) Set starting location.\n"
				  << "(2) Set Destination.\n"
				  << "(3) Return to Main Menu.\n";

		ans = menu_val(options);
		int choice;
		if (ans == 1)
		{ // Set Starting Location
			// Provide list of locations to choose from.
			// Set starting location.
			do{
				std::cout << "\nEnter a valid city: ";
				std::cin >> choice;
				
			}while( !(choice > 0 && choice <= 50));
			std::string cityname = SystemData::ListOfCities[choice -1];
			SystemData::AccountInUse->set_start(cityname);
			start = true;
		}

		else if (ans == 2)
		{ // Set Destination
			// Provide list of locations to choose from.
			// Set End location
			do{
				std::cout << "\nEnter a valid city: ";
				std::cin >> choice;
			}while(!(choice > 0 && choice <= 50));
			std::string cityname = SystemData::ListOfCities[choice -1];
			SystemData::AccountInUse->set_destination(cityname);
			end = true;
		}

		else if (ans == 3)
		{				 // Return to Main Menu
			done = true; // Ends loop, returns to main menu.
		}
	}
}

// Menu to Set the Destination and Starting point.
void sensitivity_menu()
{
	int options = 4; // The total amount of options available to the user.
	int ans;
	bool done = false; // Stay in menu until the user choses to return.
	std::cout << "\nPlease choose from the following...\n";

	while (!done)
	{
		//std::system("clear");
		std::cin.ignore();
		std::cin.clear();

		// The different options the user can choose from.
		std::cout << "\nSensitivity Levels\n";
		std::cout << 	"(1) Low     (< 200 AQI)\n" 	<< 
						"(2) Average (< 150 AQI)\n" 	<< 
						"(3) High    (< 50  AQI)\n"		<<
						"(4) Return to Main Menu.\n";
		ans = menu_val(options);

		if (ans == 4)
		{				 // Return to Main Menu
			done = true; // Ends loop, returns to main menu.
		}else{
			done = true;
			SystemData::AccountInUse->set_level(250 - (50 * ans));
			//std::cout << SystemData::AccountInUse.get_level();
		}
	}
}
bool repeat()
{
	std::cout << "\nWould you like to try again? \n";
	bool ans = yn_val();
	return ans;
}

void outro()
{
	std::cout << "Sad to see you go, hope you come back soon!\n";
	exit(0);
}

void initPMTable()
{

	std::ifstream pm25file;
	pm25file.open("cityPM25.txt");
	int count = 0;
	// Loop through the file until the end

	std::string city, pm25;
	std::string s;

	while (getline(pm25file, s))
	{
		std::stringstream line_SS(s);
		getline(line_SS, city, ',');
		getline(line_SS, pm25, ',');
		// std::cout << city << '|' << pm25 << std::endl; //idk why but everytime I output something to the console it works

		// Add to the system datas
		SystemData::CityNameToIndex[city] = count;
		//std::cout << city.data() << " " << SystemData::CityNameToIndex[city] << std::endl;
		SystemData::ListOfCities.push_back(city);
		SystemData::PM25.insert(city.data(), std::stod(pm25));

		count++;
	}

	pm25file.close();
}

void initcityCoords()
{
	std::ifstream fileCoords("cityCoordinates.txt");

	std::string _line;
	while (std::getline(fileCoords, _line))
	{
		std::stringstream line_SS(_line);
		std::string city, lat, lon;

		getline(line_SS, city, ',');
		getline(line_SS, lat, ',');
		getline(line_SS, lon, ',');

		// insert name and coords to list
		coord coordinates(std::stold(lat), std::stold(lon));
		// std::cout << coordinates.first << coordinates.second;
		SystemData::cityCoordinates.insert(city.data(), coordinates);
	}
	fileCoords.close();
}

void initcityPathReader()
{

	std::ifstream filepaths("cityPaths.txt");

	std::string _line;

	std::vector<std::string> paths;

	while (std::getline(filepaths, _line))
	{

		std::stringstream line_SS(_line);

		std::string city, path;

		paths.clear();
		// This gets the first city in the column
		std::getline(line_SS, city, ',');
		// std::cout << city << "|";
		// Then all of the other paths in the program
		while (getline(line_SS, path, ','))
		{
			//	std::cout << ' ' << path << '|';
			paths.push_back(path);
		}

		// std::cout << std::endl;

		SystemData::CityPaths[city] = paths;
	}

	filepaths.close();
}
/*
	This is where we will add the data to the rest of the system data
*/
// 99% sure this works
void init()
{

	initPMTable();
	initcityCoords();
	initcityPathReader();

	int sizeoflist = SystemData::ListOfCities.size();
	for (int i = 0; i < sizeoflist; i++)
	{
		// storing data

		// std::cout << "City Name: ";
		std::string city = SystemData::ListOfCities[i];
		// std::cout << city << std::endl;
		long double pm = SystemData::PM25.find(city);
		// std::cout << "PM2.5: " << pm << std::endl;
		coord coordinates = SystemData::cityCoordinates.find(city);
		// std::cout << "Coordinates: " << coordinates.first << ", " << coordinates.second << std::endl;
		// compiling all the data into this one map
		SystemData::IndexToCity[i] = City(city, coordinates, pm);
	}
}