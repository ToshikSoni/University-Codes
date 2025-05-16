//SPDX-License-Identifier: MIT
pragma solidity ^0.8.16;
//Base Contract
contract Animal{
    string private sound;

    //Encapsulation using internal modifier
    function setSound(string memory _sound) internal{
        sound=_sound;
    }

    function getSound() public view virtual returns (string memory){
        return sound;
    }
}

//Derived Contract inheritance from Animal
contract Dog is Animal{
    constructor(){
        setSound("Bark");
    }

    //Function overriding
    function getSound() public view override returns (string memory){
        return string(abi.encodePacked("Dog Says: ",super.getSound()));
    }
    /**
    In the code snippet you provided, abi.encodePacked is used in conjunction with string() function when returning a string from the getSound() function.
The reason for using abi.encodePacked here is that it's necessary because of how Solidity handles strings. When concatenating two or more strings together within a contract (like "Dog Says: " + super.getSound(), you'd normally expect to get back another string as the result). However, in Solidity 0.5.x and later versions, this is not allowed directly.
The issue lies with how Solidity handles memory allocation for temporary values like strings during concatenation operations (+). In those cases where a new string needs to be created (like when you concatenate "Dog Says: " with the result of super.getSound()), it must allocate fresh memory. If this occurs, and there's no place allocated in Solidity that can hold such temporary values without causing problems like stack overflows or unexpected behavior during execution.
To overcome these issues, developers use a trick involving encoding strings to bytes first before concatenating them together (with abi.encodePacked), converting the result back into a string with string(). This ensures proper memory management and prevents Solidity from attempting unnecessary allocations.
Here's how it should look like:
function getSound() public view override returns (string memory){
    return string(abi.encodePacked("Dog Says: ",super.getSound()));
}
So, abi.encodePacked here helps avoid potential issues related to Solidity's handling of strings by encoding them into bytes first and then converting the result back into a string
    **/
    
}

//Another derived contract
contract Cat is Animal {
    constructor(){
        setSound("Meow");
    }

    function getSound() public view override returns (string memory){
        return string(abi.encodePacked("Cat Says: ",super.getSound()));
    }
}