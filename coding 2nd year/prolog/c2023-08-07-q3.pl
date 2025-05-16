fact(0,1).
fact(N,Fact):-
    N>0,
    PrevN is N-1,
    fact(PrevN,PrevS),
    Fact is PrevS*N.