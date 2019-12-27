#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct county {
   string name;
   float unemployed_2007;
   float unemployed_2015;
   int med_income;
};

struct state {
   string name;
   float unemployed_2007;
   float unemployed_2015;
   int med_income;
   struct county* counties;
   int n_counties;
};

int checkInput(string question, string valid);

void free_state_data(state* stateArray, int numStates);

void printMenu();

void displayStates(struct state* stateArray, int numStates);

/******************STATE FUNCTIONS****************************/

void printHighInc(struct state* stateArray, int numStates);

void printLowInc(struct state* stateArray, int numStates);

void printHighUnemp(struct state* stateArray, int numStates);

void printLowUnemp(struct state* stateArray, int numStates);

bool acompare(struct state s1, struct state s2);

void printSortedUnemp(struct state* stateArray, int numStates);

bool bcompare(struct state s1, struct state s2);

void printSortedInc(struct state* stateArray, int numStates);

/*******************COUNTY FUNCTIONS*************************/

void printHighInc(struct county* countyArray, int numCounties);

void printLowInc(struct county* countyArray, int numCounties);

void printHighUnemp(struct county* countyArray, int numCounties);

void printLowUnemp(struct county* countyArray, int numCounties);

bool ccompare(struct county c1, struct county c2);

void printSortedUnemp(struct county* countyArray, int numCounties);

bool dcompare(struct county c1, struct county c2);

void printSortedInc(struct county* countyArray, int numCounties);

/************************************************************/

void browseData(struct state* stateArray, int numStates, int choice);

void read_county_data(county* counties, int n_counties, ifstream& reader);

struct county* allocate_counties(int n_counties);

void read_state_data(state* stateArray, int numStates, ifstream& reader);

struct state* allocate_states(int numStates);
