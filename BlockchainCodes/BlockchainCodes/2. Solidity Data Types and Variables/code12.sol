// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
//applying delete operation on dynamic array
contract DynamicArray { 
    uint[] public dynamicArray; // Declare a public dynamic array

    // Function to add an element to the dynamic array
    function addElement(uint value) public {
        dynamicArray.push(value); // Adds a new element at the end of the array
    }

    // Function to remove the last element from the dynamic array
    function removeLastElement() public {
        require(dynamicArray.length > 0, "Array is empty"); // Check if the array is empty
        dynamicArray.pop(); // Removes the last element from the array
    }

    // Function to reset the array to empty
    function deleteArray() public {
        delete dynamicArray; // Deletes all elements, resetting the array to an empty state
    }

    // Function to get an element at a specific index from the dynamic array
    function getElement(uint index) public view returns (uint) {
        require(index < dynamicArray.length, "Index out of bounds"); // Check if the index is within bounds
        return dynamicArray[index]; // Return the element at the specified index
    }
}
