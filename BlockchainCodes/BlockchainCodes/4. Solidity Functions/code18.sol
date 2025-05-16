// SPDX-License-Identifier: MIT
pragma solidity ^0.8.16;

contract Sample1{
    int public a;//state variable
    constructor(int _a) payable {
        a = _a; //initialize a
    }
    function updateA(int _a) public {
        a = _a;
    }
    function payAndUpdateA(int _a) public payable {
        a = _a;
    }
    //in solidity the payable modifier is used to allow a function to receive Ether. Without this modifier,
    // if you attempt to send Ether to a function, the transaction will be rejected and will fail.
    //Fallback() function in solidity is special function that is executed when no other function matches the function signature in 
    //the call or when the contract 
}

contract Sample2{
    constructor() payable {}
    //This allows Sample2 to receive Ether when it is deployed.
    function execute(address contractAddress) public payable{
        //deploy a new sample1 instance with 12 wei and initialize 
        Sample1 s = (new Sample1){value : 12}(23);
        //seems to be trying to instantiate a contract with Sample1 with constructor arguments while also 
        //specifying a payable amount (value : 12)
        //function calls with and without sending ether
        s.payAndUpdateA(22); //regular call no Ether
        s.payAndUpdateA{value : 12 ether}(12);
        s.payAndUpdateA{gas : 10000}(12); //amount of gas allowed
        s.payAndUpdateA{value: 12 ether, gas: 10000}(12); //both Ether and Gas constraints
        //Internal and external function calls
        hello(); //Internal Call (Cheaper) -> calls the function directly within the same contract, uses the internal function dispatch meaning no actual transaction
        this.hello(); // External Call (Costlier) -> calls the function as if an external function is calling it , uses THIS which refers to the current contract's address and involves an actual transaction adding extra gas costs.
        //Interact with an already deployed Sample1 Contract
        Sample1 existingContract = Sample1(contractAddress);//use to create a contract instance from an already deployed contract at a known address.balance;
        existingContract.payAndUpdateA(112);
    }  
    function hello() public pure {}  
}