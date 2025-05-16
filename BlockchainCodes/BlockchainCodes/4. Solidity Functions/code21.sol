//SPDX-License-Identifier:MIT
pragma solidity ^0.8.16;

contract Sample1{
    int public b = 78; //accessible both internally and externally

    int internal c = 90; //accessible only within this contract or derived

    function al() external returns(int) {
        b = 21;
        c = 9; //Internal access to state variables is allowed (accessible within this contract)

        int temp = this.b(); //External access to public  variable
        //b can have an external function call since public variable automatically has a getter function implicitly

        return temp;
        //this.b = 18 Cannot assign values using external access - since there is no setter() function for the public variable
        //this.c() Internal variable cannot be accessed externally - no getter() function
    }
}

contract Sample2{
    int internal d = 9; //accessible in derived contracts
    int private e = 90; //accessible only within this contract
}

//Third contract is inheriting from Sample2
contract Sample is Sample2{
    //Instance of Sample1 contract
    Sample1 s;

    function sample3() public returns(int){
        s = new Sample1(); //creating new instance

        int f = s.b(); //accessing public variable b
        //s.b = 18 - cannot assign values 
        //s.c() c is internal and cannot be accessed externally

        //Internal access within inherited contract Sample2
        d = 8; //allowed d is internal and inherited from Sample2
        //e=7 e is private and cannot be accessed outside Sample 2
        return f;
    }
}