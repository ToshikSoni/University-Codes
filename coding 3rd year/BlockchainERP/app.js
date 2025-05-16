// Import ethers from a CDN (using ethers v5)
import { ethers } from "https://cdnjs.cloudflare.com/ajax/libs/ethers/6.7.0/ethers.min.js";

// Contract details (replace with your actual contract address and ABI)
const contractAddress = "0xf1F8867c344DD160E067fE97B38AaDbC1B8a7a3d"; // Replace with your deployed contract address
const contractABI = [
    {
        "inputs": [
            { "internalType": "uint256", "name": "_studentID", "type": "uint256" },
            { "internalType": "string", "name": "_name", "type": "string" }
        ],
        "name": "registerStudent",
        "outputs": [],
        "stateMutability": "payable",
        "type": "function"
    },
    {
        "inputs": [{ "internalType": "uint256", "name": "_studentID", "type": "uint256" }],
        "name": "checkStudentExists",
        "outputs": [{ "internalType": "bool", "name": "", "type": "bool" }],
        "stateMutability": "view",
        "type": "function"
    },
    {
        "inputs": [{ "internalType": "address", "name": "_studentAddress", "type": "address" }],
        "name": "isStudentRegistered",
        "outputs": [{ "internalType": "bool", "name": "", "type": "bool" }],
        "stateMutability": "view",
        "type": "function"
    },
    {
        "inputs": [{ "internalType": "uint256", "name": "", "type": "uint256" }],
        "name": "studentExists",
        "outputs": [{ "internalType": "bool", "name": "", "type": "bool" }],
        "stateMutability": "view",
        "type": "function"
    },
    {
        "inputs": [{ "internalType": "address", "name": "_studentAddress", "type": "address" }],
        "name": "students",
        "outputs": [
            { "internalType": "uint256", "name": "studentID", "type": "uint256" },
            { "internalType": "string", "name": "name", "type": "string" }
        ],
        "stateMutability": "view",
        "type": "function"
    }
];

// Function to connect to MetaMask and get a provider and signer
async function connectWallet() {
    if (!window.ethereum) {
        alert("MetaMask is not installed!");
        return;
    }

    try {
        // Use BrowserProvider in ethers v6 instead of ethers.providers.Web3Provider
        const provider = new ethers.BrowserProvider(window.ethereum);
        await provider.send("eth_requestAccounts", []);

        const signer = await provider.getSigner();
        const account = await signer.getAddress();
        console.log("Connected account:", account);
        document.getElementById("accountInfo").innerText = "Connected account: " + account;

        const blockNumber = await provider.getBlockNumber();
        console.log("Current block number:", blockNumber);
        document.getElementById("connectionStatus").innerText = "Current block: " + blockNumber;

        return { provider, signer };
    } catch (error) {
        console.error("Error connecting wallet:", error);
        document.getElementById("connectionStatus").innerText = "Error connecting to blockchain.";
    }
}


// Function to check if a student exists (calls the checkStudentExists function)
async function checkStudentExists() {
    console.log("Using contract address:", contractAddress);

    // Ensure wallet is connected
    const connection = await connectWallet();
    if (!connection) return;

    const { provider } = connection;
    // Create a contract instance (read-only)
    const contract = new ethers.Contract(contractAddress, contractABI, provider);

    // Get the student ID from the input field
    const studentID = document.getElementById("studentIDInput").value;

    try {
        // Call the contract's view function to check if the student exists
        const exists = await contract.checkStudentExists(studentID);
        console.log("Student exists:", exists);
        document.getElementById("studentResult").innerText = "Student exists: " + exists;
    } catch (error) {
        console.error("Error checking student:", error);
        document.getElementById("studentResult").innerText = "Error: " + error.message;
    }
}

// Attach event listeners
document.getElementById("connectButton").addEventListener("click", connectWallet);
document.getElementById("checkStudentButton").addEventListener("click", checkStudentExists);
