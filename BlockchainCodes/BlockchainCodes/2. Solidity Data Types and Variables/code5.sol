// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
contract DataType{
uint8 public myNumber;  // Declares a public state variable of type uint8

// Function to assign a value to 'myNumber'
function setNumber(uint8 _value) public {
    // require applies a constraint to check whether a particular condition is true or false
    require(_value <= type(uint8).max, "Value exceeds uint8 max");  // Checking if value is within uint8 limit
    myNumber = _value;  // Assigning the value to the state variable 'myNumber'
}

//to get the maximum value of uint8
function getMaxValue() public pure returns(uint8) //pure because it is neither changing nor reading any value
    {
        return type(uint8).max; //returns 255
    }
}