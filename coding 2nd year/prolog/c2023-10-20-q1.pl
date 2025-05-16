%8 puzzle probelm

state([X1,X2,X3 , Y1,Y2,Y3 , Z1,Z2,Z3]):-
    write("Current state is: "),nl,
    write(X1),write("\t"),write(X2),write("\t"),write(X3),nl,
    write(Y1),write("\t"),write(Y2),write("\t"),write(Y3),nl,
    write(Z1),write("\t"),write(Z2),write("\t"),write(Z3),nl.

initial_state([X1,X2,X3 , Y1,Y2,Y3 , Z1,Z2,Z3]):-
    state([X1,X2,X3 , Y1,Y2,Y3 , Z1,Z2,Z3]).
    
goal_state([X1,X2,X3 , Y1,Y2,Y3 , Z1,Z2,Z3]):-
    state([X1,X2,X3 , Y1,Y2,Y3 , Z1,Z2,Z3]).

solve([X1,X2,X3 , Y1,Y2,Y3 , Z1,Z2,Z3]):-
    .

%Move (,) to (,)
solve   ([X1,X2,X3,
          Y1,Y2,Y3,
          Z1,Z2,Z3],M):-
    state([X1,X2,X3,
          Y1,Y2,Y3,
          Z1,Z2,Z3]),
    solve([X1,X2,X3,
          Y1,Y2,Y3,
          Z1,Z2,Z3],M).
          