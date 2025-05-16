state(0,0):- write("Fill the 5 liter jug"),nl,state(5,0).
state(5,0):- write("Fill the 3 liter jug by 5 liter jug"),nl,state(2,3).
state(2,3):- write("Empty the 3 liter jug"),nl,state(2,0).
state(2,0):- write("This is final state").