// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract ArithmeticOps {
    function calculate(uint a, uint b) public pure returns (uint sum, uint diff, uint prod, uint div, uint mod) {
        sum = a + b;
        diff = a - b;
        prod = a * b;
        require(b != 0, "Division by zero not allowed");
        div = a / b;
        mod = a % b;
    }
}
