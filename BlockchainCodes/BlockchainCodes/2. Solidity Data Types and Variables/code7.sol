// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
contract DynamicArrayExample{ 
    //syntax to declare
    uint[] public dynamicArray; 

    function addElement(uint value) public {
        dynamicArray.push(value);//adds a new element
    }
    function removeLastElement() public {
        require(dynamicArray.length>0, "Array is empty");
        dynamicArray.pop();//removes last element
    }
}