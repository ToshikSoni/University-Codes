// SPDX-License-Identifier: GPL-3.0 
pragma solidity >=0.4.22 <0.9.0; 
contract mapping_example {

	// Defining an array
	uint[5] public array
	= [uint(1), 2, 3, 4, 5] ;
	
	// Defining a Structure
	struct student {
		string name;
		string subject;
		uint8 marks;
	}

	// Creating a structure object
	student public std1;

	// Defining a function to return
	// values of the elements of the structure
	function structure() public returns(
	string memory, string memory, uint){
		std1.name = "John";
		std1.subject = "Chemistry";
		std1.marks = 88;
		return (
		std1.name, std1.subject, std1.marks);
	}
	
	// Creating a mapping
	mapping (address => student) result;
	address[] student_result;
}
