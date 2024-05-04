**Assumption:** 

Single & Multiple elevators case:
- The elevator each has a direction it's going in, either up or down. This determines which floor call can be picked up since user outside elevator
can always presses either up or down button.
- Use Doubly Linked List for applicaiton since elevators go either up or down.
- The code will generate some number of random floor calls since more than one person might enter it.
- Once the user is inside the elevator, they can select a floor call of their own, this value is also randomized. The direction for this will be
null, this accounts for people who got on the elevator but decided to press a floor that is going in opposite direction as the elevator is heading.
Once the queue clears up and the elevator heads in the opposite direction, the floor call will be reached to drop off this person.

**UML CLass Diagram:**

Class: Node
+next: node
+prev: node
+direction: string
+id: char
+floor: int
+waitingTime: int

Class: Doubly_List
-headPtr: node
-tailPtr: node
+Doubly_List();
+insert(id: int, floor: int, direction: string): void
+print(): void
+empty(): bool
+push_front(tempNode: node): void
+push_back(tempNode: node): void
+sort(): void
+pop(floor: int, direction: string): void
+stop(floor: int, direction: string, id: char): int
+update_wait(): void

Class: Elevator
-floor: int
-target: int
-direction: string
-id: char
+elevator();
+elevator(floor: int, direction: string)
+elevator(floor: int, direction: string, id: char)
+target_floor(&list: Doubly_List): void
+create_dropoff(&list: Doubly_List, id: char): void
+move(&list: Doubly_List): void
+print(): void

**Efficiency of Algorithm:**

**Individual Contribution:** I worked alone on this project

**References:**
https://icarus.cs.weber.edu/~dab/cs1410/textbook/9.Classes_And_Objects/uml.html
https://www.geeksforgeeks.org/introduction-and-insertion-in-a-doubly-linked-list/
https://stackoverflow.com/questions/2485963/c-alignment-when-printing-cout
