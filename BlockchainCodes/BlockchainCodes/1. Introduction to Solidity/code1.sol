// SPDX-License-Identifier: MIT
pragma solidity ^0.8.16;
/**
~ means exact match of the solidity
^ means major version of the 
> specify a newer version, works with any version newer than >=0.7.2, <=.8.26 
//specify a range of version
**/
contract LabSectionB{
    string public greet; //this is by default private, now it will be shown when deployed
 
    constructor(string memory _greet){
        greet = _greet; //now while deploying it will ask for a value
    }

     // Function to update the greet variable. 'payable' allows sending Ether, though it's not required here.
    function updateGreet(string memory _greet) public payable {
        greet = _greet; // Update the 'greet' variable with the new value.
    }

 // View function to retrieve the current value of 'greet'.
    function viewGreet() public view returns (string memory) {
        return greet; // Returns the value of 'greet'.
    }

   // Pure function to return a hardcoded greeting. Does not read or write to the state.
    function pureGreet() public pure returns (string memory) {
        return "Hello, Solidity!"; // Hardcoded return value.
    }
}