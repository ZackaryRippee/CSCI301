
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
  random_device rd; //random number generator
  mt19937 g(rd()); //mt19937 generator used

bool monty_hall(bool switch_door);

int main(){
  int num_iterations;
  string user_choice;
  cout << "Welcome to the Monty Hall Simulator! Enter how many iterations you wish to have: ";
  cin >> num_iterations;
  cout << endl << "Will you want to stay with your first door or switch? ";
  cin >> user_choice;
  bool switch_door;
  if (user_choice == "Stay" || user_choice == "stay"){
    switch_door = false;
  } else if (user_choice == "Switch" || user_choice == "switch"){
    switch_door = true;
  } else {
    cout << endl << "Please type stay or switch for an answer!" << endl;
    return 0;
  }

  double wins = 0;
  int losses = 0;
  for (int i = 0; i < num_iterations; i++){
    if (monty_hall(switch_door)){
	wins++;
      } else {
	losses++;
      }
  }

    cout << endl << "You decided to " << user_choice << "." <<
      endl << "Total wins: " << wins <<
      endl << "Total losses: " << losses <<
      endl << "Win Percentage: " << (wins / num_iterations) * 100.0 << "%." << endl;
}

bool monty_hall(bool switch_door){
  vector<int> doors = {0, 0, 1}; //0s are goats, 1 is the car
  shuffle(doors.begin(), doors.end(), g); //shuffle doors vector positions
  int first_pick = rand() % 3; //random door selected
  int host_pick;
  for (int i = 0; i < 3; i++){ //host picks a door that has a goat and is not the user's selected door
    if (i != first_pick && doors[i] == 0){
      host_pick = i;
      break;
    }
  }
  int final_pick;
  if (switch_door){ //if user switched, find other door not initially picked or opened by host
    for (int i = 0; i < 3; i++){
      if (i != first_pick && i != host_pick){
	final_pick = i;
	break;
      }
    }
  } else {
    final_pick = first_pick; //stick with initial choice if user chose to stay
  }

  return doors[final_pick] == 1; //return true if car is won
  
}
