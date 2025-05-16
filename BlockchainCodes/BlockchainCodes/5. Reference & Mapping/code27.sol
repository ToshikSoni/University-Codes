// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Sample{
    
    struct Struct {
        mapping (int => int) myMap;
        int myNumber;
        int[] myArray;
    }
    
    Struct mystruct;

    constructor(int key, int value, int number, int[] memory array){
        mystruct.myNumber = number;
        mystruct.myArray = array;
        mystruct.myMap[key] = value;
    }

    function reset() public{
        delete mystruct.myArray;
        delete mystruct.myNumber;
    }
    //on the entire mapping we cant apply the delete operation we must mention the key
    function deleteKey(int key) public {
        delete mystruct.myMap[key]; //deletes the specified key
    }
}