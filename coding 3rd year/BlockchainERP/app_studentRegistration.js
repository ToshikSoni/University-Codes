// Import ethers from a CDN (using ethers v6)
import { ethers } from "https://cdnjs.cloudflare.com/ajax/libs/ethers/6.7.0/ethers.min.js";

// Replace with your actual StudentRegistration contract address and ABI
const studentRegAddress = "0x3c7A17C4B20801dEE8Fa6237c03d90952A62c133";
const studentRegABI = [
    {
        "inputs": [],
        "stateMutability": "nonpayable",
        "type": "constructor"
    },
    {
        "inputs": [
            {
                "internalType": "uint256",
                "name": "",
                "type": "uint256"
            }
        ],
        "name": "StudentDetails",
        "outputs": [
            {
                "internalType": "uint256",
                "name": "studentID",
                "type": "uint256"
            },
            {
                "internalType": "string",
                "name": "name",
                "type": "string"
            }
        ],
        "stateMutability": "view",
        "type": "function"
    },
    {
        "inputs": [
            {
                "internalType": "uint256",
                "name": "",
                "type": "uint256"
            }
        ],
        "name": "addrarr",
        "outputs": [
            {
                "internalType": "address",
                "name": "",
                "type": "address"
            }
        ],
        "stateMutability": "view",
        "type": "function"
    },
    {
        "inputs": [
            {
                "internalType": "address",
                "name": "_addr",
                "type": "address"
            }
        ],
        "name": "getStudentID",
        "outputs": [
            {
                "internalType": "uint256",
                "name": "",
                "type": "uint256"
            }
        ],
        "stateMutability": "view",
        "type": "function"
    },
    {
        "inputs": [],
        "name": "owner",
        "outputs": [
            {
                "internalType": "address",
                "name": "",
                "type": "address"
            }
        ],
        "stateMutability": "view",
        "type": "function"
    },
    {
        "inputs": [
            {
                "internalType": "uint256",
                "name": "_studentID",
                "type": "uint256"
            },
            {
                "internalType": "string",
                "name": "_name",
                "type": "string"
            }
        ],
        "name": "registerStudent",
        "outputs": [],
        "stateMutability": "payable",
        "type": "function"
    },
    {
        "inputs": [
            {
                "internalType": "address",
                "name": "",
                "type": "address"
            }
        ],
        "name": "student",
        "outputs": [
            {
                "internalType": "uint256",
                "name": "studentID",
                "type": "uint256"
            },
            {
                "internalType": "string",
                "name": "name",
                "type": "string"
            }
        ],
        "stateMutability": "view",
        "type": "function"
    },
    {
        "inputs": [
            {
                "internalType": "uint256",
                "name": "",
                "type": "uint256"
            }
        ],
        "name": "studentExists",
        "outputs": [
            {
                "internalType": "bool",
                "name": "",
                "type": "bool"
            }
        ],
        "stateMutability": "view",
        "type": "function"
    },
    {
        "inputs": [
            {
                "internalType": "address",
                "name": "",
                "type": "address"
            }
        ],
        "name": "studentExistsAddr",
        "outputs": [
            {
                "internalType": "bool",
                "name": "",
                "type": "bool"
            }
        ],
        "stateMutability": "view",
        "type": "function"
    },
    {
        "inputs": [
            {
                "internalType": "uint256",
                "name": "",
                "type": "uint256"
            }
        ],
        "name": "uidarr",
        "outputs": [
            {
                "internalType": "uint256",
                "name": "",
                "type": "uint256"
            }
        ],
        "stateMutability": "view",
        "type": "function"
    }
];

async function connectWallet() {
    if (!window.ethereum) {
        alert("MetaMask is not installed!");
        return;
    }
    try {
        const provider = new ethers.BrowserProvider(window.ethereum);
        await provider.send("eth_requestAccounts", []);
        const signer = await provider.getSigner();
        const account = await signer.getAddress();
        document.getElementById("accountInfo").innerText = "Connected account: " + account;
        return { provider, signer };
    } catch (error) {
        console.error("Error connecting wallet:", error);
    }
}

async function registerStudent() {
    const connection = await connectWallet();
    if (!connection) return;
    const { signer } = connection;
    const studentRegContract = new ethers.Contract(studentRegAddress, studentRegABI, signer);

    const studentID = document.getElementById("studentIDInput").value;
    const studentName = document.getElementById("studentNameInput").value;

    try {
        // Adjust the payable value if necessary; here assumed zero payment
        const tx = await studentRegContract.registerStudent(studentID, studentName, { value: 0 });
        await tx.wait();
        document.getElementById("registrationResult").innerText = "Registration successful!";
    } catch (error) {
        console.error("Registration error:", error);
        document.getElementById("registrationResult").innerText = "Error: " + error.message;
    }
}

document.getElementById("connectButton").addEventListener("click", connectWallet);
document.getElementById("registerStudentButton").addEventListener("click", registerStudent);
