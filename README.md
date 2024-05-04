**Assumption:** 

Single & Multiple elevators case:
- The elevator each has a direction it's going in, either up or down. This determines which floor call can be picked up since user outside elevator
can always presses either up or down button.
- The code will generate some number of random floor calls since more than one person might enter it.
- Once the user is inside the elevator, they can select a floor call of their own, this value is also randomized. The direction for this will be
null, this accounts for people who got on the elevator but decided to press a floor that is going in opposite direction as the elevator is heading.
Once the queue clears up and the elevator heads in the opposite direction, the floor call will be reached to drop off this person.

Multiple elevators case:
- Since users outside of the elevator might press both up and down buttons, assign each user to different elevator that is closest to them and is in
the same direction as their button choice.
