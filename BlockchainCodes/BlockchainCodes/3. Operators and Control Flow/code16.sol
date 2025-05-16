// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract WhileLoopExample {
    function factorial(uint num) public pure returns (uint fact) {
        fact = 1;
        uint i = num;
        while (i > 1) {
            fact *= i;
            i--;
        }
    }
}
