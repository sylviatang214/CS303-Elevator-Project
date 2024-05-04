#include "elevator.h"

elevator::elevator() {
	int floor = 0;
	int target = 0;
	string direction = "\0";
	char id = '\0';
}

elevator::elevator(int f, string d) {
	floor = f;
	target = f;
	direction = d;
}

elevator::elevator(int f, string d, char i) {
	floor = f;
	target = f;
	direction = d;
	id = i;
}

void elevator::target_floor(Doubly_List &list) { //set elevator's target floor
	target = list.stop(floor, direction, id);
	

	if (floor < target) { //setting direction
		direction = "up";
	}
	else {
		direction = "down";
	}
}

void elevator::create_dropoff(Doubly_List& list, char ID) {
	int randAmount = rand() % 3; //generate number of person entering elevator

	for (int i = 0; i < randAmount; i++) { //generate a random floor that each person picked
		int randFloor = (rand() % 15) + 1;
		
		node* temp = new node;
		temp->floor = randFloor;
		temp->direction = "\0";
		temp->id = ID;

		cout << "A user got on elevator " << temp->id << " and pressed floor " << randFloor << "\n\n";
		list.push_back(temp);
		list.sort();
	}
}


void elevator::move(Doubly_List& list){
	if (target == floor) {	//checks if target floor needs update
		target = list.stop(floor, direction, id);
		create_dropoff(list, id);

		if (floor < target) { //setting direction
			direction = "up";
		}
		else {
			direction = "down";
		}
	}
	else {
		if (direction == "up") {
			floor++;
		}
		else {
			floor--;
		}
	}
}

void elevator::print() { //print function
	cout << "Elevator id: " << id << endl;
	cout << "Direction: " << direction << endl;
	cout << "Current floor: " << floor << endl;
	cout << "Target floor: " << target << endl;
}