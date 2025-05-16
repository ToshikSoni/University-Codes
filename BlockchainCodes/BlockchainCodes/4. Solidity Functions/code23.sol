//SPDX-License-Identifier:MIT
pragma solidity ^0.8.16;

//in solidity modifiers. They allow pre-execution or post-execution logic to be added to functions, to make the code more resuable.
contract Example{
    address public owner;
    constructor(){
        owner=msg.sender; //set the deployer as the owner
    }
    modifier onlyOwner(){
        require(msg.sender == owner, "Not the contract owner!");
        _; //This allows the function to continue execution
    }
    //function protected by the onlyOwner modifier
    function restrictedFunction() public onlyOwner{

    }
}