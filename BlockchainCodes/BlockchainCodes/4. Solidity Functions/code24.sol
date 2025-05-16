//SPDX-License-Identifier:MIT
pragma solidity ^0.8.16;
/** A modifier is a special type of function that you use to modify the behavior of other functions. 
Modifiers allow you to add extra conditions or functionality to a function without having to rewrite the entire function. **/
contract SampleContract{
    int public a = 90;
    modifier myModifier1(int b){
        int c = b;
        a = 8;
        _;
    }

    modifier myModifier2(){
        int c = a;
        _;
    }

    modifier myModifier3(){
        a = 96;
        _;
    }

    modifier myModifier4(){
        int c = a;
        _;
    } 

    function myFunction() public myModifier1(a) myModifier2 myModifier3 returns (int){
        return a;
    }

}