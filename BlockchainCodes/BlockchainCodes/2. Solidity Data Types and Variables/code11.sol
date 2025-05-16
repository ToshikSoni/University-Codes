// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StaticStringArray {
    bytes32 public staticString; // Usually we do not allocate strings statically, but we can using bytes32

    // Function to set the static string value
    function setStaticString(string memory _value) public {
        require(bytes(_value).length <= 32, "String exceeds 32 bytes");
        staticString = bytes32(bytes(_value)); // Converts the string to bytes32
    }

    // Function to retrieve the static string value
    function getStaticString() public view returns (string memory) {
        return string(abi.encodePacked(staticString)); // Converts bytes32 back to string
    }
}
