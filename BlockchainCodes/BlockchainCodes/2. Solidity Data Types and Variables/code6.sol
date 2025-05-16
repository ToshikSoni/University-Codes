// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
contract StaticArrayExample{
    uint[5] public staticArray = [1,2,3,4,5];

    function getElement(uint index) public view returns (uint){ //view because we are retreiving/reading value
        require(index<staticArray.length, "Index out of bounds");
        return staticArray[index];
    }

    //Function to update an element at a specific index
    function updateElement(uint index, uint newValue) public{
        require(index<staticArray.length, "Index out of bounds");
        staticArray[index] = newValue;
    }
}