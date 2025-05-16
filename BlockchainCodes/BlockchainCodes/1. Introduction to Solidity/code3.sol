// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract VisibilityModifier {
   
    uint public publicVar = 42;  // Public variable

    // Public function
    function setPublicVar(uint _value) public {
        publicVar = _value;
    }
     uint private privateVar;  // Private variable

    // Private function to set privateVar (not callable externally)
    function setPrivateVar(uint _value) private {
        privateVar = _value;
    }

    // Public function to set the private variable through a constructor
    constructor(uint _privateValue) {
        privateVar = _privateValue;  // Set the private variable during deployment
    }

    // Public function to get private variable (so we can check it externally)
    function getPrivateVar() public view returns (uint) {
        return privateVar;
    }
/**

    uint internal internalVar = 42;  // Internal variable

    // Internal function
    function setInternalVar(uint _value) internal {
        internalVar = _value;
    }

    // Function to demonstrate internal variable
    function getInternalVar() public view returns (uint) {
        return internalVar;
    } **/

    // External function
    function setExternalVar(uint _value) external {
        publicVar = _value;
    }

    // Function to demonstrate external function
    function getPublicVar() public view returns (uint) {
        return publicVar;
    } 

}
