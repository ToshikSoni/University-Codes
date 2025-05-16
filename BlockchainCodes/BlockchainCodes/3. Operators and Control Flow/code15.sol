// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract LogicalOps {
    function checkConditions(bool a, bool b) public pure returns (bool andResult, bool orResult, bool notA) {
        andResult = a && b; // Logical AND
        orResult = a || b;  // Logical OR
        notA = !a;          // Logical NOT
    }
}
