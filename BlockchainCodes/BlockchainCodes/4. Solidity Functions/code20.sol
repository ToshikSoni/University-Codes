// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract CA{
    event log(string message, uint gasUsed);

    function hello() public{

        emit log("Hello from CA!",gasleft());
    }

    function callHello() public {
        uint startGas=gasleft();
        hello();
        uint gasUsed = startGas-gasleft();
        emit log("Internal Call Executed",gasUsed);
    }
    function callHelloEx() public {
        uint startGas=gasleft();
        this.hello();
        uint gasUsed = startGas-gasleft();
        emit log("Internal Call Executed",gasUsed);
    }
}

contract CB{
    CA public ca;
    event log(string message,uint gasUsed);
    constructor(address _ca){
        ca=CA(_ca);
    }

    function callHelloFromA() public{
        uint startGas=gasleft();
        ca.hello();
        uint gasUsed=startGas-gasleft();
        emit log("Cross contract call executed",gasUsed);
    }

    function compareGasUsage() public{
        ca.callHello();
        ca.callHelloEx();
    }
}