// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract DynamicStringArray {
    string public dynamicString;  // Declare a public dynamic string

    // Function to set a string value
    function setString(string memory _newString) public {
        dynamicString = _newString;  // Set the value of the dynamic string
    }

    // Function to get the length of the string
    function getStringLength() public view returns (uint) {
        return bytes(dynamicString).length;  // Convert string to bytes to get the length
        //first it is typecased into bytes because in solidity string 
        //itself is in UTF-8 format which can have varying length
    }
}
