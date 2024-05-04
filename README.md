**Assumption:** 

Single & Multiple elevators case:
- The elevator each has a direction it's going in, either up or down. This determines which floor call can be picked up since user outside elevator
can always presses either up or down button.
- Use Doubly Linked List for applicaiton since elevators go either up or down.
- The code will generate some number of random floor calls since more than one person might enter it.
- Once the user is inside the elevator, they can select a floor call of their own, this value is also randomized. The direction for this will be
null, this accounts for people who got on the elevator but decided to press a floor that is going in opposite direction as the elevator is heading.
Once the queue clears up and the elevator heads in the opposite direction, the floor call will be reached to drop off this person.

**UML CLass Diagram**

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
+elevator(int f, string d);
+elevator(int f, string d, char i);
+void target_floor(Doubly_List & list)
+void create_dropoff(Doubly_List& list, char ID)
+void move(Doubly_List &list)
+void print()

