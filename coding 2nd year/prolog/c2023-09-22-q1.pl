%Program to solve missionaries and canibals problem

mandc(0,3,0,3,1):-write("Goal State").

mandc(3,0,3,0,0):-
    write("Two cannibals take the boat and go to side B"),
    nl,
    mandc(3,0,1,2,1).

mandc(3,0,1,2,1):-
    write("One cannibal take the boat and go to side A leaving behind one cannibal"),
    nl,
    mandc(3,0,2,1,0).

mandc(3,0,2,1,0):-
    write("One cannibal and one missionary take the boat and go to side B"),
    nl,
    mandc(2,1,1,2,1).

mandc(2,1,1,2,1):-
    write("One cannibal take the boat and go to side A leaving behind one missionary"),
    nl,
    mandc(2,1,2,1,0).

mandc(2,1,2,1,0):-
    write("Two missionary take the boat and go to side B"),
    nl,
    mandc(0,3,2,1,1).

mandc(0,3,2,1,1):-
    write("One cannibal take the boat and go to side A leaving behind one missionary"),
    nl,
    mandc(0,3,3,0,0).

mandc(0,3,3,0,0):-
    write("Two cannibals take the boat and go to side B"),
    nl,
    mandc(0,3,1,2,1).

mandc(0,3,1,2,1):-
    write("One cannibal take the boat and go to side A leaving behind one cannibal"),
    nl,
    mandc(0,3,2,1,0).

mandc(0,3,2,1,0):-
    write("Two cannibals take the boat and go to side B"),
    nl,
    mandc(0,3,0,3,1).