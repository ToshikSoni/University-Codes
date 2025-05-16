tax(X):-X>=1500000,Tax=X*1.3,write("Tax: "),write(Tax).
tax(X):-X>=1000000,write("Tax: 20%").
tax(X):-X>=500000,write("Tax: 10%").
tax(X):-X<500000,write("Tax: 0%").