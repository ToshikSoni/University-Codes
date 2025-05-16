// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract DynamicBytesArray {
    // Declaring a dynamic bytes array
    bytes public dynamicBytes;

    // Function to add a byte to the dynamic byte array
    function addByte(bytes1 newByte) public {
        dynamicBytes.push(newByte); // Adds a new byte to the array
    }

    // Function to remove the last byte from the dynamic byte array
    function removeLastByte() public {
        require(dynamicBytes.length > 0, "Array is empty");
        dynamicBytes.pop(); // Removes the last byte from the array
    }

    // Function to retrieve a specific byte from the dynamic byte array
    function getByte(uint index) public view returns (bytes1) {
        require(index < dynamicBytes.length, "Index out of bounds");
        return dynamicBytes[index];
    }

    // Function to update a specific byte in the dynamic byte array
    function updateByte(uint index, bytes1 newValue) public {
        require(index < dynamicBytes.length, "Index out of bounds");
        dynamicBytes[index] = newValue; // Updates the byte at the specified index
    }

    // Function to get the length of the dynamic byte array
    function getLength() public view returns (uint) {
        return dynamicBytes.length; // Returns the current length of the array
    }
}
