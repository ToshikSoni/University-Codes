// SPDX-License-Identifier:MIT
pragma solidity ^0.8.0;
contract test{
    struct data{
        uint value;
        string name;
    }
    data public statedata;
    constructor(){
        statedata=data(42,"State");
    }
    /**
   function modifymemory(data memory input) public pure returns (data memory){
        //memory variable input is independent of statedata
        input.value = 100; //change is local to this function 
        //input will be in format [12,""] because it's a struct and "" is name and we need only value
        return input;
        
    }
    
    function modifystorage() public {
        data storage localstorageref=statedata; //shallow copy
        localstorageref.value=500;
    } 
    
    function independentcopy() public view{
        data memory newcopy=statedata;
        newcopy.value=10;
    } **/
    
    function demo() public view returns(data memory,data memory){
        data memory memorycopy=statedata;
        memorycopy.value=20;
        return(memorycopy,statedata);
    }//deep copy 
}