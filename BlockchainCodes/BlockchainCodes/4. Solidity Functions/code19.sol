//SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;
contract CA {
    event log(string mess, uint gasU);
    function h() public {
        emit log("hello",gasleft());

    }
    function callHelloInter() public {
        uint startgas =gasleft();
        h();
        uint gasU= startgas - gasleft();
        emit log("Internal call Executed",gasU);
    }    
}
contract CB{
    CA public  cA;
    event log(string mess, uint gasU);
    constructor(address _cA){
        cA = CA(_cA);
    }
    function callHelloEx() public {
        uint startgas = gasleft();
        cA.h();
        uint gasU =startgas- gasleft();
        emit log("Cross contract call Executed",gasU);
    } 
    function Compare() public {
        cA.callHelloInter();
        CB.callHelloEx();
    }
}