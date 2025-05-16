//SPDX-License-Identifier:MIT
pragma solidity ^0.8.16;

contract PublicExternalDemo{
    uint256 public publicValue;
    uint256 public externalValue;

    //Public function: can be called both internally and externally
    function setPublicValue(uint256 _value) public{
        publicValue = _value;
    }

    //External function can be called only externally
    function setExternalValue(uint256 _value) external{
        externalValue = _value;
    }

    //Internal function calling the public function
    function callPublicFunction(uint256 _value) internal{
        setPublicValue(_value);
        //setExternalValue(_value) not allowed
    }

    function callExternalFunction(uint256 _value) internal{
        this.setExternalValue(_value); //called externally within the contract
    }

    function testFunctions(uint256 _publicValue, uint256 _externalValue) public {
        callPublicFunction(_publicValue);
        callExternalFunction(_externalValue);
    }
}