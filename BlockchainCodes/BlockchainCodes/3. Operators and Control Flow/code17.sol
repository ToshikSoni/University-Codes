// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract ForLoopExample {
    function sumNumbers(uint n) public pure returns (uint sum) {
        for (uint i = 1; i <= n; i++) {
            sum += i;
        }
    }
}

