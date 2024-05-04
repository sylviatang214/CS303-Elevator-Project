#include "Doubly_List.h"

Doubly_List::Doubly_List() {
	headPtr = nullptr;
	tailPtr = nullptr;
}


bool Doubly_List::empty() { //checks empty
	return (headPtr == nullptr);

}
void Doubly_List::pop(int floor, string direction) { //pop function
	node* tempNode = headPtr;

	while(tempNode->next != nullptr) {
		if (tempNode->floor == floor && tempNode->direction == direction) { // if node to pop is found
			if (headPtr == tailPtr) { // if only one node exists
				headPtr = nullptr;
				tailPtr = nullptr;
				delete tempNode;
			}
			else if (tempNode == headPtr) { // headPtr case
				if (tempNode->next != nullptr) { // if there is more than one item in the list (i.e. if head != tail)
					tempNode->next->prev = nullptr;
					headPtr = tempNode->next;
				}
				else {
					headPtr = nullptr;
				}
				tempNode->next->prev = nullptr;
				delete tempNode;

				return;
			}
			else { //pop for other cases
				tempNode->prev->next = tempNode->next;
				tempNode->next->prev = tempNode->prev;
				delete tempNode;
				return;
			}
		}
		tempNode = tempNode->next; //traverse
	}
	if (tempNode == tailPtr) { // tailPtr case 
		if (headPtr == tailPtr) {
			headPtr = nullptr;
			tailPtr = nullptr;
		}
		else {
			tailPtr = tempNode->prev;
		}
		if (tempNode->prev != nullptr) {
			tempNode->prev->next = nullptr;
		}
		delete tempNode;
		return;
	}
}
void Doubly_List::push_front(node* tempNode) { //push front function

	if (headPtr == nullptr) { //if list is empty, set headprt and tailptr as frontNode 
		headPtr = tempNode;
		tailPtr = tempNode;
	}
	else { // add to front
		tempNode->next = headPtr;
		headPtr->prev = tempNode;
		headPtr = tempNode;
	}
}

void Doubly_List::push_back(node* tempNode) { //push back function

	if (headPtr == nullptr) { //if list is empty, set headptr and tailptr as backNode 
		headPtr = tempNode;
		tailPtr = tempNode;
	}
	else { // push to back
		tailPtr->next = tempNode;
		tempNode->prev = tailPtr;
		tailPtr = tempNode;
	}
}

void Doubly_List::insert(int input, int floor, string direction) { //insert nose function
	node* insertNode = new node;

	insertNode->floor = floor;
	insertNode->direction = direction;

	if (empty() || input == 0) {
		if (headPtr == nullptr) { //if list is empty, set headprt and tailptr as frontNode 
			headPtr = insertNode;
			tailPtr = insertNode;
		}
		else { // add to front
			insertNode->next = headPtr;
			headPtr->prev = insertNode;
			headPtr = insertNode;
		}

	}
	else if (input == 1) {
		node* tempPtr = headPtr;
		if (headPtr == tailPtr) {
			tailPtr = insertNode;
		}
		else {
			tempPtr->next->next = insertNode;
		}
		tempPtr->next = insertNode;
		insertNode->prev = tempPtr;



	}
	else {
		node* tempPtr = headPtr;   //let tempNode be headptr

		node* prevPtr;
		node* nextPtr;

		//move tempNode to position input
		for (int i = 0; i < input; i++) {
			tempPtr = tempPtr->next;
			if (tempPtr == nullptr)
				break;
		}

		if (tempPtr == nullptr) {
			if (headPtr == nullptr) { //if list is empty, set headptr and tailptr as backNode 
				headPtr = insertNode;
				tailPtr = insertNode;
			}
			else { // push to back
				tailPtr->next = insertNode;
				insertNode->prev = tailPtr;
				tailPtr = insertNode;
			}

		}
		else {
			//assign floor and direction to insertNode
			insertNode->floor = floor;
			insertNode->direction = direction;

			nextPtr = tempPtr;        //assign tempNode position to nextNode
			prevPtr = tempPtr->prev;  //point prevNode to tempNode

			//put insertNode between next and prev nodes
			insertNode->next = nextPtr;
			insertNode->prev = prevPtr;

			//change prev and next node to point to insert node
			prevPtr->next = insertNode;
			nextPtr->prev = insertNode;
		}

	}


}

void Doubly_List::print() { //print function
	if (empty()) {
		cout << "List is empty" << endl;
	}
	else {
		node* tempPtr = headPtr;
		cout << left << setw(10) << "Floor calls" << right << setw(15) << "Direction" << endl << endl;;
		while (tempPtr != nullptr) {
			cout << left << setw(20) << tempPtr->floor;
			if (tempPtr->direction == "\0") {
				cout << left << setw(15) << "null" << "\n";
			}
			else{
				cout << left << setw(15) << tempPtr->direction << "\n";
			}
			tempPtr = tempPtr->next;
		}
	}

	cout << "\n\n";

}

void Doubly_List::sort() {//sort by floors and direction
	node* current = headPtr;
	node* nextPtr = current->next;
	bool sorted = false;

	while (sorted == false) { //while not sorted
		sorted = true;
		current = headPtr;
		nextPtr = current->next;
		while (nextPtr != nullptr) {
			while (nextPtr != nullptr && current->floor <= nextPtr->floor) { // traversing if already sorted
				current = nextPtr;
				nextPtr = current->next;
			}

			while (nextPtr != nullptr && current->floor > nextPtr->floor) {
				sorted = false;
				if (current->prev != nullptr) { //if prev exists
					current->prev->next = nextPtr;
					nextPtr->prev = current->prev;
				}
				if (current->next != nullptr) { //if nextptr exists
					if (nextPtr->next != nullptr) { //if nextptr next exists
						nextPtr->next->prev = current;
					}
					else { // if current is at end of list, make it tailptr
						tailPtr = current;
					}

					current->next = nextPtr->next;
				}
				//sort
				nextPtr->next = current;
				current->prev = nextPtr;
				nextPtr = current->next; //updates nextPtr

			}
		}
	}
}



int Doubly_List::stop(int f, string d, char i) { //stops and returns target floor

	
	if (empty()) {
		return f;
	}
	else if (headPtr == tailPtr) {
		int temp = headPtr->floor; //stores target floor
		pop(headPtr->floor, headPtr->direction); //remove target from linked list
		return temp;
	}


	node* tempPtr = headPtr; //move until overshoots floor
	while (tempPtr != nullptr && ((tempPtr->floor < f && d == "up") || (tempPtr->floor >f && d == "down"))) {
		tempPtr = tempPtr->next;
	}


	if (tempPtr == nullptr) {
		tempPtr = tailPtr;
	}
	else if (d == "down" && tempPtr->prev != nullptr) {
		tempPtr = tempPtr->prev;
	}


	bool go_up;
	if (d == "up") {
		go_up = true;
	}
	else {
		go_up = false;
	}

	while (true) {

		while (go_up == true) {
			if (((tempPtr->direction == "up" && go_up == true) || (tempPtr == tailPtr && tempPtr->prev->prev == nullptr)) || (tempPtr->id == i )) { //if pickup or dropoff
				if (tempPtr->floor >= f) { //up case
					int temp = tempPtr->floor; //stores target floor
					if (tempPtr->id != '\0') { // if not a drop off
						cout << "\nperson on floor " << tempPtr->floor << " waited for elevator " << tempPtr->id << " for " << tempPtr->waitingTime << " seconds.\n\n";
					}
					pop(tempPtr->floor, tempPtr->direction); //remove target from linked list
					return temp; //returns target floor
				}
			}
			if (tempPtr == tailPtr) { go_up = false; break; }
			tempPtr = tempPtr->next; //traverse
		}
		while (go_up == false) {
			if (((tempPtr->direction == "down" && go_up == false) || (tempPtr == headPtr && tempPtr->next->next == nullptr)) || (tempPtr->id == i )) { //if pickup or dropoff
				if (tempPtr->floor <= f) {  //down case
					int temp = tempPtr->floor; //stores target floor
					if (tempPtr->id != '\0') { // if not a drop off
						cout << "\nperson on floor " << tempPtr->floor << " waited for elevator " << tempPtr->id << " for " << tempPtr->waitingTime << " seconds.\n\n";
					}
					pop(tempPtr->floor, tempPtr->direction); //remove target from linked list
					return temp; //returns target floor
				}
			}
			if (tempPtr == headPtr) { go_up = true; break; }
			tempPtr = tempPtr->prev; //traverse
		}
	}
}



void Doubly_List::update_wait() { //wait time
	if (empty()) {
		return;
	}
	
	node * temp = headPtr;

	while (temp != nullptr) { //each floor takes 5 seconds to get to
		temp->waitingTime += 5;
		temp = temp->next;
	}
}