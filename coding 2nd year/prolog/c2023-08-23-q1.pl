% Define the initial state of the puzzle
initial_state([[2, 8, 3],
               [1, 6, 4],
               [7, _, 5]]).

% Define the goal state of the puzzle
goal_state([[1, 2, 3],
            [8, _, 4],
            [7, 6, 5]]).

% Move a tile in the puzzle
move([[Tile | RestRow] | OtherRows], Move, NewState) :-
    select(Tile, RestRow, BlankRow),
    append([BlankRow], [Move | OtherRows], NewState).

move([Row | OtherRows], Move, [Row | NewOtherRows]) :-
    move(OtherRows, Move, NewOtherRows).

% Solve the puzzle
solve(State, []) :- goal_state(State).
solve(State, [Move | Moves]) :-
    move(State, Move, NewState),
    solve(NewState, Moves).

% Predicate to start solving the puzzle
start_solving(Moves) :-
    initial_state(InitialState),
    solve(InitialState, Moves).