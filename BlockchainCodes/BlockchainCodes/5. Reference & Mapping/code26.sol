// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
//How structures are used in Mapping
contract Mappings{
    mapping(uint256 => string) public names;
    mapping(uint256 => Book) public books;
    //concept of nested mapping 
    mapping(address => mapping(uint256 => Book)) public myBooks;

    struct Book{ //structure by itself is a reference type
        string title;
        string author;
    }

    constructor()
    {
        names[1] = "Adam";
        names[2] = "Bruce";
        names[3] = "Carl";
    }
    function addBook(
        uint256 _id,
        string memory _title,
        string memory _author
    ) public {
        books[_id] = Book(_title, _author); //we need to Book since it is a user defined datatype
    }

    function addMyBook(
        uint256 _id,
        string memory _title,
        string memory _author
    ) public {
        myBooks[msg.sender][_id] = Book(_title, _author);
    }
}