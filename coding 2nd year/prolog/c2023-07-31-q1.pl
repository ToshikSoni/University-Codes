parent(john,mike).
parent(john,sarah).

parent(sam,john).
parent(sam,jena).

parent(jane,john).
parent(jane,jena).

gender(john,male).
gender(mike,male).
gender(sarah,female).
gender(sam,male).
gender(jane,female).
gender(jena,female).

grandparents(X,Father,Mother,Grandfather,Grandmother):-parent(X,Father),parent(X,Mother),
    gender(Father,male),gender(Mother,female),parent(Father,Grandfather),
    parent(Father,Grandmother),gender(Grandfather,male),gender(Grandmother,female),
    write("Grandfather: "),write(Grandfather),write(", Grandmother: "),write(Grandmother),
    write(", Father: "),write(Father),write(", Mother: "),write(Mother),write(", Child: "),
    write(X),nl.