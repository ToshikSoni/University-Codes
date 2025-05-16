sum(0,0).
sum(N,Sum):-
    N>0,
    PrevN is N-1,
    sum(PrevN,PrevS),
    Sum is PrevS+N.