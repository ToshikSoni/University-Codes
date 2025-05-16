// SPDX-License-Identifier: MIT
pragma solidity ^0.8;

contract User {
    struct UserProfile {
        string name;
        uint8 age;
        bool isRegistered;
    }

    mapping(address => UserProfile) map;

    function registerUser(string memory _name, uint8 _age) public payable {
        require(_age > 0, "Age should be greater than 0");
        map[msg.sender] = UserProfile(_name, _age, true);
    }

    function getUserProfile(address user)
        public
        view
        returns (UserProfile memory)
    {
        require(map[user].isRegistered, "User not registered");
        return map[user];
    }

    function isUserRegistered(address user) public view returns (bool) {
        return map[user].isRegistered;
    }
}
