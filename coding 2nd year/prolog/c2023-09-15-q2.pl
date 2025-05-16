state(S,B,J,Q,O):-
    J>0,
    O>0,
    write("Fill small jug by: "),
    write(Q),
    write(" liter quantity. "),
    write("Quantities of small and big jug are: "),
    write(S),
    write(" "),
    write(B),
    nl,
    read(X),
    read(Y),
    read(Z),
    A=S+Q
    state(A,B,X,Y,Z).

state(S,B,J,Q,O):-
    J<1,
    O<1,
    write("Empty big jug by: "),
    write(Q),
    write(" liter quantity. "),
    write("Quantities of small and big jug are: "),
    write(S),
    write(" "),
    write(B),
    nl,
    read(X),
    read(Y),
    read(Z),
    A=B-Q
    state(S,A,X,Y,Z).

state(S,B,J,Q,O):-
    J>0,
    O<1,
    write("Empty small jug by: "),
    write(Q),
    write(" liter quantity. "),
    write("Quantities of small and big jug are: "),
    write(S),
    write(" "),
    write(B),
    nl,
    read(X),
    read(Y),
    read(Z),
    A=S-Q
    state(A,B,X,Y,Z).

state(S,B,J,Q,O):-
    J<1,
    O>0,
    write("Fill big jug by: "),
    write(Q),
    write(" liter quantity. "),
    write("Quantities of small and big jug are: "),
    write(S),
    write(" "),
    write(B),
    nl,
    read(X),
    read(Y),
    read(Z),
    A=B+Q
    state(S,A,X,Y,Z).

state(0,2,J,Q,-1):-
    write("Final state").