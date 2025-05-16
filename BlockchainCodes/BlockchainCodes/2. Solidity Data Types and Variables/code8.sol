// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
contract StaticBytesArray{
    bytes3 public staticBytes = 0x123456; //bytes3 is a static byte array

    function updateBytes(bytes3 newValue) public {
        staticBytes = newValue;
    }

    function getByte(uint index) public view returns (bytes1) {
        require(index<3, "Index out of bounds");
        return staticBytes[index];
    }
}