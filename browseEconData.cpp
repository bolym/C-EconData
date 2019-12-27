#include "econData.hpp"

/******************************************************************
 * Function: main
 * Description: Executes framework of storing data and user browsing
 * Parameters: int argc, char* argv[]
 * Pre-Conditions: argc must be 2
 * Post-Conditions: argc and argv[] don't change
 ******************************************************************/
int main(int argc, char* argv[]){

   /* check for valid command line argument */
   ifstream reader;
   reader.open(argv[1]);

   if(reader.fail()){
      cout << "File error" << endl;
      exit(1);
   }

   int numStates;
   reader >> numStates;
		     
   /* allocate space for states in a dynamic array */
   struct state* stateArray = allocate_states(numStates);

   /* read data into state struct objects */
   read_state_data(stateArray, numStates, reader);

   reader.close();

   /* Begin Browsing */
   int again = 1;
   while(again == 1){
      
      int choice;
      choice = checkInput("Enter 1 for state data or 2 for county data: ", "12");
      browseData(stateArray, numStates, choice);
      again = checkInput("Enter 1 to keep browsing or 2 to exit: ", "12");

      }

   /* free all heap memory used */
   free_state_data(stateArray, numStates);

}
