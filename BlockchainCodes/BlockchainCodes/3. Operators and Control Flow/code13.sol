// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Conditional {
    address public owner;

    constructor() {
        owner = msg.sender; // Set the contract deployer as the owner
    }

    function onlyOwner() public view {
        if (msg.sender == owner) {
            // Action to be performed if the sender is the owner
        } else {
            revert("Sender not owner");
        }
    }
}
