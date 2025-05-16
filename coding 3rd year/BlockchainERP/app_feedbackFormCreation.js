import { ethers } from "https://cdnjs.cloudflare.com/ajax/libs/ethers/6.7.0/ethers.min.js";

// Replace with your actual FeedbackForm contract address and ABI
const feedbackFormAddress = "0x81f44184d31a654369Af45d2B1d7F376Fa0c5b7c";
const feedbackFormABI = [
    {
        "inputs": [],
        "stateMutability": "nonpayable",
        "type": "constructor"
    },
    {
        "inputs": [
            {
                "internalType": "uint256",
                "name": "formID",
                "type": "uint256"
            }
        ],
        "name": "FeedbackForms",
        "outputs": [
            {
                "internalType": "string[]",
                "name": "",
                "type": "string[]"
            }
        ],
        "stateMutability": "view",
        "type": "function"
    },
    {
        "inputs": [
            {
                "internalType": "uint256",
                "name": "_formID",
                "type": "uint256"
            },
            {
                "internalType": "string[]",
                "name": "_questions",
                "type": "string[]"
            }
        ],
        "name": "createFeedbackForm",
        "outputs": [],
        "stateMutability": "payable",
        "type": "function"
    },
    {
        "inputs": [
            {
                "internalType": "uint256",
                "name": "",
                "type": "uint256"
            },
            {
                "internalType": "uint256",
                "name": "",
                "type": "uint256"
            }
        ],
        "name": "forms",
        "outputs": [
            {
                "internalType": "string",
                "name": "",
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
        "name": "formsarr",
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
        "name": "getFormsLength",
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
        "inputs": [
            {
                "internalType": "uint256",
                "name": "_id",
                "type": "uint256"
            }
        ],
        "name": "getFromLen",
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
        "inputs": [],
        "name": "returnFormsArr",
        "outputs": [
            {
                "internalType": "uint256[]",
                "name": "",
                "type": "uint256[]"
            }
        ],
        "stateMutability": "view",
        "type": "function"
    },
    {
        "inputs": [
            {
                "internalType": "uint256",
                "name": "_id",
                "type": "uint256"
            }
        ],
        "name": "returnQueArr",
        "outputs": [
            {
                "internalType": "string[]",
                "name": "",
                "type": "string[]"
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

async function createFeedbackForm() {
    const connection = await connectWallet();
    if (!connection) return;
    const { signer } = connection;
    const feedbackFormContract = new ethers.Contract(feedbackFormAddress, feedbackFormABI, signer);

    const formID = document.getElementById("formIDInput").value;
    let questionsText = document.getElementById("questionsInput").value;
    // Split by commas and trim spaces
    const questions = questionsText.split(",").map(q => q.trim());

    try {
        const tx = await feedbackFormContract.createFeedbackForm(formID, questions, { value: 0 });
        await tx.wait();
        document.getElementById("formCreationResult").innerText = "Feedback form created successfully!";
    } catch (error) {
        console.error("Error creating feedback form:", error);
        document.getElementById("formCreationResult").innerText = "Error: " + error.message;
    }
}

document.getElementById("connectButton").addEventListener("click", connectWallet);
document.getElementById("createFormButton").addEventListener("click", createFeedbackForm);
