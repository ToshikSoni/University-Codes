// SPDX-License-Identifier: MIT
pragma solidity ^0.8;

contract A {
    function Car() public pure virtual returns (string memory) {
        return "Base Car";
    }
}

contract B is A {
    function Car() public pure override returns (string memory) {
        return "B Car";
    }
}

contract C is A {
    function Car() public pure override returns (string memory) {
        return "C Car";
    }
}

contract print {
    A a;
    B b;
    C c;

    constructor(
        address _a,
        address _b,
        address _c
    ) {
        a = A(_c);
        b = B(_b);
        c = C(_c);
    }

    function carNameA() public payable returns (string memory) {
        return a.Car();
    }

    function carNameB() public payable returns (string memory) {
        return b.Car();
    }

    function carNameC() public payable returns (string memory) {
        return c.Car();
    }
}
