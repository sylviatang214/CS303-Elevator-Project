#include "Doubly_List.h"
#include "elevator.h"
#include <vector>

int main() {
	//TEST 1: Multiple elevators case

	cout << "TEST 1: Multiple elevators case" << endl << endl;
	Doubly_List list_A;

	list_A.insert(0, 1, "up");
	list_A.insert(1, 2, "down");
	list_A.insert(2, 4, "down");
	list_A.insert(3, 5, "up");
	list_A.insert(4, 6, "down");
	list_A.insert(5, 8, "up");
	list_A.insert(6, 9, "down");
	list_A.insert(7, 11, "down");


	list_A.sort();

	list_A.print();

	vector<elevator> vect_elevator;

	elevator A (10, "down", 'A');
	elevator B (2, "up", 'B');
	elevator C (5, "up", 'C');
	vect_elevator.push_back(A);
	vect_elevator.push_back(B);
	vect_elevator.push_back(C);

	for (int x = 0; x < 20; x++) { 
		for (int i = 0; i < vect_elevator.size(); i++) {
			vect_elevator[i].move(list_A);
			vect_elevator[i].print();
			cout << "\n";
			list_A.update_wait();
		}
		list_A.print();
		cout << endl << endl;
	}

	system("pause");

	//TEST 2: Single elevators case
	cout << "\nTEST 2: Single elevator case" << endl << endl;

	Doubly_List list_B;

	list_B.insert(0, 1, "up");
	list_B.insert(1, 2, "down");
	list_B.insert(2, 4, "down");
	list_B.insert(3, 5, "up");
	list_B.insert(4, 6, "down");
	list_B.insert(5, 8, "up");
	list_B.insert(6, 9, "down");
	list_B.insert(7, 11, "down");

	list_B.sort();
	list_B.print();

	elevator D(2, "down", 'D');

	for (int x = 0; x < 20; x++) {
		D.move(list_B);
		D.print();
		cout << "\n";
		list_B.update_wait();
		list_B.print();
		cout << endl << endl;
	}

	system("pause");

}
