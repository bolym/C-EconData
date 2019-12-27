/******************************************************************
 * Program: econData.cpp
 * Author: Michael Boly
 * Date: 1/16/2019
 * Description: Reads economic data from the given file and allows
 * 		the user to view that data in various forms.
 * Input: Command line input for .txt file, User inputs numbers to
 * 		explore menues until they wish to quit.
 * Output: States and counties sorted or compared by its fields
 *****************************************************************/

#include "./econData.hpp"

/******************************************************************
 * Function: checkInput
 * Description: Performs a do-while using question to only accept
 * 		characters that are in valid. Returns integer
 * 		version of input.
 * Parameters: string question, string valid
 * Pre-Conditions: question and valid must not be empty
 * Post-Conditions: question and valid don't change
******************************************************************/
int checkInput(string question, string valid){
   string var_str;
   size_t found;

   do{
      cout << question << endl;
      cin >> var_str;
      found = var_str.find_first_not_of(valid);
   }
   while(found != string::npos && var_str.length() < 2);

   return stoi(var_str);
}


/******************************************************************
 * Function: free_state_data
 * Description: Frees all heap data of states and county arrays
 * Parameters: state* stateArray, int numStates
 * Pre-Conditions: stateArray cannot be empty
 * Post-Conditions: stateArray no longer exists
******************************************************************/
void free_state_data(state* stateArray, int numStates){

   for(int i = 0; i < numStates; i++){
      delete[] stateArray[i].counties;
   }

   delete[] stateArray;
}


/******************************************************************
 * Function: printMenu
 * Description: Prints a menu of options for the user
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void printMenu(){
   cout << "1. Highest Median Household Income" << endl;
   cout << "2. Lowest Median Household Income" << endl;
   cout << "3. Highest Unemployment in 2015" << endl;
   cout << "4. Lowest Unemployment in 2015" << endl;
   cout << "5. Sorted by Unemployment Change from 2007-2015" << endl;
   cout << "6. Sorted by Median Household Income" << endl;
}


/******************************************************************
 * Function: displayStates
 * Description: Prints the name of all the states in stateArray
 * Parameters: state* stateArray, int numStates
 * Pre-Conditions: stateArray cannot be empty
 * Post-Conditions: stateArray and numStates don't change
******************************************************************/
void displayStates(struct state* stateArray, int numStates){

   for(int i = 0; i < numStates; i++){
      cout << i+1 << ". " << stateArray[i].name << endl;
   }
}


/***********************STATE FUNCTIONS **************************/

/******************************************************************
 * Function: printHighInc
 * Description: Prints the state with highest median household income
 * Parameters: state* stateArray, int numStates
 * Pre-Conditions: stateArray cannot be empty
 * Post-Conditions: stateArray and numStates don't change
******************************************************************/
void printHighInc(struct state* stateArray, int numStates){

   float max = stateArray[0].med_income;
   string maxName = stateArray[0].name;
   for(int i = 1; i < numStates; i++){
      if(stateArray[i].med_income > max){
	 max = stateArray[i].med_income;
	 maxName = stateArray[i].name;
      }
   }

   cout << "State with Highest Median Household Income: " << maxName << endl;
}


/******************************************************************
 * Function: printLowInc
 * Description: Prints the state with lowest median household income
 * Parameters: state* stateArray, int numStates
 * Pre-Conditions: stateArray cannot be empty
 * Post-Conditions: stateArray and numStates don't change
******************************************************************/
void printLowInc(struct state* stateArray, int numStates){

   float min = stateArray[0].med_income;
   string minName = stateArray[0].name;
   for(int i = 1; i < numStates; i++){
      if(stateArray[i].med_income < min){
	 min = stateArray[i].med_income;
	 minName = stateArray[i].name;
      }
   }

   cout << "State with Lowest Median Household Income: " << minName << endl;

}


/******************************************************************
 * Function: printHighUnemp
 * Description: Prints the state with highest 2015 unemployment
 * Parameters: state* stateArray, int numStates
 * Pre-Conditions: stateArray cannot be empty
 * Post-Conditions: stateArray and numStates don't change
******************************************************************/
void printHighUnemp(struct state* stateArray, int numStates){

   float max = stateArray[0].unemployed_2015;
   string maxName = stateArray[0].name;
   for(int i = 1; i < numStates; i++){
      if(stateArray[i].unemployed_2015 > max){
	 max = stateArray[i].unemployed_2015;
	 maxName = stateArray[i].name;
      }
   }

   cout << "State with Highest 2015 Unemployment: " << maxName << endl;
}


/******************************************************************
 * Function: printLowUnemp
 * Description: Prints the state with lowest 2015 unemployment
 * Parameters: state* stateArray, int numStates
 * Pre-Conditions: stateArray cannot be empty
 * Post-Conditions: stateArray and numStates don't change
******************************************************************/
void printLowUnemp(struct state* stateArray, int numStates){

   float min = stateArray[0].unemployed_2015;
   string minName = stateArray[0].name;
   for(int i = 1; i < numStates; i++){
      if(stateArray[i].unemployed_2015 < min){
	 min = stateArray[i].unemployed_2015;
	 minName = stateArray[i].name;
      }
   }

   cout << "State with Lowest 2015 Unemployment: " << minName << endl;
}


/******************************************************************
 * Function: acompare
 * Description: Comparator for states change in unemployement
 * Parameters: state s1, state s2
 * Pre-Conditions: s1 and s2 unemployment fields must have values
 * Post-Conditions: s1 and s2 don't change
******************************************************************/
bool acompare(struct state s1, struct state s2){
   return (s1.unemployed_2015 - s1.unemployed_2007) < (s2.unemployed_2015 - s2.unemployed_2007);
}


/******************************************************************
 * Function: printSortedUnemp
 * Description: Prints the states by change in unemployment from
 * 		largest decease to largest increase
 * Parameters: state* stateArray, int numStates
 * Pre-Conditions: stateArray cannot be empty
 * Post-Conditions: stateArray and numStates don't change
******************************************************************/
void printSortedUnemp(struct state* stateArray, int numStates){

   sort(stateArray, stateArray + numStates, acompare);
   cout << "States by Increasing Change in Unemployment from 2007-2015: " << endl;

   for(int i = 0; i < numStates; i++){
      cout << stateArray[i].name << endl;
   }

}


/******************************************************************
 * Function: bcompare
 * Description: Comparator for states change in median income
 * Parameters: state s1, state s2
 * Pre-Conditions: s1 and s2 median income fields must have values
 * Post-Conditions: s1 and s2 don't change
******************************************************************/
bool bcompare(struct state s1, struct state s2){
   return s1.med_income < s2.med_income;
}


/******************************************************************
 * Function: printSortedInc
 * Description: Prints the states by median income increasing order
 * Parameters: state* stateArray, int numStates
 * Pre-Conditions: stateArray cannot be empty
 * Post-Conditions: stateArray and numStates don't change
******************************************************************/
void printSortedInc(struct state* stateArray, int numStates){

   sort(stateArray, stateArray + numStates, bcompare);
   cout << "States by Increasing Median Household Income: " << endl;

   for(int i = 0; i < numStates; i++){
      cout << stateArray[i].name << endl;
   }
}


/************************ COUNTY FUNCTIONS ***************************/

/******************************************************************
 * Function: printHighInc
 * Description: Prints the county with highest median household income
 * Parameters: county* countyArray, int numCounties
 * Pre-Conditions: countyArray cannot be empty
 * Post-Conditions: countyArray and numCounties don't change
******************************************************************/
void printHighInc(struct county* countyArray, int numCounties){

   float max = countyArray[0].med_income;
   string maxName = countyArray[0].name;
   for(int i = 1; i < numCounties; i++){
      if(countyArray[i].med_income > max){
	 max = countyArray[i].med_income;
	 maxName = countyArray[i].name;
      }
   }

   cout << "County with Highest Median Household Income: " << maxName << endl;
}


/******************************************************************
 * Function: printLowInc
 * Description: Prints the county with lowest median household income
 * Parameters: county* countyArray, int numCounties
 * Pre-Conditions: countyArray cannot be empty
 * Post-Conditions: countyArray and numCounties don't change
******************************************************************/
void printLowInc(struct county* countyArray, int numCounties){

   float min = countyArray[0].med_income;
   string minName = countyArray[0].name;
   for(int i = 1; i < numCounties; i++){
      if(countyArray[i].med_income < min){
	 min = countyArray[i].med_income;
	 minName = countyArray[i].name;
      }
   }

   cout << "County with Lowest Median Household Income: " << minName << endl;

}


/******************************************************************
 * Function: printHighUnemp
 * Description: Prints the county with highest 2015 unemployment
 * Parameters: county* countyArray, int numCounties
 * Pre-Conditions: countyArray cannot be empty
 * Post-Conditions: countyArray and numCounties don't change
******************************************************************/
void printHighUnemp(struct county* countyArray, int numCounties){

   float max = countyArray[0].unemployed_2015;
   string maxName = countyArray[0].name;
   for(int i = 1; i < numCounties; i++){
      if(countyArray[i].unemployed_2015 > max){
	 max = countyArray[i].unemployed_2015;
	 maxName = countyArray[i].name;
      }
   }

   cout << "County with Highest 2015 Unemployment: " << maxName << endl;
}


/******************************************************************
 * Function: printHighUnemp
 * Description: Prints the county with lowest 2015 unemployment
 * Parameters: county* countyArray, int numCounties
 * Pre-Conditions: countyArray cannot be empty
 * Post-Conditions: countyArray and numCounties don't change
******************************************************************/
void printLowUnemp(struct county* countyArray, int numCounties){

   float min = countyArray[0].unemployed_2015;
   string minName = countyArray[0].name;
   for(int i = 1; i < numCounties; i++){
      if(countyArray[i].unemployed_2015 < min){
	 min = countyArray[i].unemployed_2015;
	 minName = countyArray[i].name;
      }
   }

   cout << "County with Lowest 2015 Unemployment: " << minName << endl;
}


/******************************************************************
 * Function: ccompare
 * Description: Comparator for counties change in unemployement
 * Parameters: county c1, county c2
 * Pre-Conditions: c1 and c2 unemployment fields must have values
 * Post-Conditions: c1 and c2 don't change
******************************************************************/
bool ccompare(struct county c1, struct county c2){
   return (c1.unemployed_2015 - c1.unemployed_2007) < (c2.unemployed_2015 - c2.unemployed_2007);
}


/******************************************************************
 * Function: printSortedUnemp
 * Description: Prints the counties by change in unemployment from
 * 		largest decease to largest increase
 * Parameters: county* countyArray, int numCounties
 * Pre-Conditions: countyArray cannot be empty
 * Post-Conditions: countyArray and numCounties don't change
******************************************************************/
void printSortedUnemp(struct county* countyArray, int numCounties){

   sort(countyArray, countyArray + numCounties, ccompare);
   cout << "Counties by Increasing Change in Unemployment from 2007-2015: " << endl;

   for(int i = 0; i < numCounties; i++){
      cout << countyArray[i].name << endl;
   }

}

bool dcompare(struct county c1, struct county c2){
   return c1.med_income < c2.med_income;
}


/******************************************************************
 * Function: printSortedInc
 * Description: Prints the counties by median income increasing order
 * Parameters: county* countyArray, int numCounties
 * Pre-Conditions: countyArray cannot be empty
 * Post-Conditions: countyArray and numCounties don't change
******************************************************************/
void printSortedInc(struct county* countyArray, int numCounties){

   sort(countyArray, countyArray + numCounties, dcompare);
   cout << "Counties by Increasing Median Household Income: " << endl;

   for(int i = 0; i < numCounties; i++){
      cout << countyArray[i].name << endl;
   }
}


/************************************************************************/

/******************************************************************
 * Function: browseData
 * Description: Guides user through menues of data until they quit
 * Parameters: state* stateArray, int numStates, int choice
 * Pre-Conditions: choice must hold a value of 1 or 2
 * Post-Conditions: stateArray is only changed if sorted
******************************************************************/
void browseData(struct state* stateArray, int numStates, int choice){

   /* state data options */
   int option;
   if(choice == 1){
      printMenu();
      option = checkInput("Pick a piece of data: ", "123456");
      switch(option){
	 case 1: printHighInc(stateArray, numStates);
		 break;
	 case 2: printLowInc(stateArray, numStates);
		 break;
	 case 3: printHighUnemp(stateArray, numStates);
		 break;
	 case 4: printLowUnemp(stateArray, numStates);
		 break;
	 case 5: printSortedUnemp(stateArray, numStates);
		 break;
	 case 6: printSortedInc(stateArray, numStates);
		 break;
      }
   }

   /* county data options */
   if(choice == 2){
      int statePick;
      displayStates(stateArray, numStates);
      statePick = checkInput("Pick a state: ", "0123456789");
      statePick = statePick - 1;

      struct county* countyArray = stateArray[statePick].counties;
      int numCounties = stateArray[statePick].n_counties;

      printMenu();
      option = checkInput("Pick a piece of data: ", "123456");

      switch(option){
	 case 1: printHighInc(countyArray, numCounties);
		 break;
	 case 2: printLowInc(countyArray, numCounties);
		 break;
	 case 3: printHighUnemp(countyArray, numCounties);
		 break;
	 case 4: printLowUnemp(countyArray, numCounties);
		 break;
	 case 5: printSortedUnemp(countyArray, numCounties);
		 break;
	 case 6: printSortedInc(countyArray, numCounties);
		 break;
      }
   }
}


/******************************************************************
 * Function: read_county_data
 * Description: Reads county data from .txt file into county structs
 * Parameters: county* counties, int n_counties, ifstream& reader
 * Pre-Conditions: reader must be initialized and in place
 * Post-Conditions: reader is updated and counties arrays filled
******************************************************************/
void read_county_data(county* counties, int n_counties, ifstream& reader){

   for(int i = 0; i < n_counties; i++){
     reader >> counties[i].name;
     reader >> counties[i].unemployed_2007;
     reader >> counties[i].unemployed_2015;
     reader >> counties[i].med_income;
   }
}


/******************************************************************
 * Function: allocate_counties
 * Description: Creates and returns a new array of counties
 * Parameters: int n_counties
 * Pre-Conditions: n_counties must be positive
 * Post-Conditions:n_counties doesn't change
******************************************************************/
struct county* allocate_counties(int n_counties){

   struct county* countyArray = new struct county[n_counties];

   return countyArray;
}


/******************************************************************
 * Function: read_state_data
 * Description: Reads state data from .txt file into state structs
 * Parameters: state* stateArray, int numStates, ifstream& reader
 * Pre-Conditions: reader must be initialized and in place
 * Post-Conditions: reader is updated and stateArray array filled
******************************************************************/
void read_state_data(state* stateArray, int numStates, ifstream& reader){

   for(int i = 0; i < numStates; i++){
     reader >> stateArray[i].name;
     reader >> stateArray[i].unemployed_2007;
     reader >> stateArray[i].unemployed_2015;
     reader >> stateArray[i].med_income;
     reader >> stateArray[i].n_counties;
     stateArray[i].counties = allocate_counties(stateArray[i].n_counties);
     read_county_data(stateArray[i].counties, stateArray[i].n_counties, reader);
   }
}


/******************************************************************
 * Function: allocate_states
 * Description: Creates and returns a new array of states
 * Parameters: int numStates
 * Pre-Conditions: numStates must be positive
 * Post-Conditions:numStates doesn't change
******************************************************************/
struct state* allocate_states(int numStates){

   struct state* stateArray = new struct state[numStates];

   return stateArray;
}

