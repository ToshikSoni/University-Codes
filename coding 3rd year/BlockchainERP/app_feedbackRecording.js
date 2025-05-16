import { ethers } from "https://cdnjs.cloudflare.com/ajax/libs/ethers/6.7.0/ethers.min.js";

// Replace with your actual FeedbackRecording contract address and ABI
const feedbackRecordingAddress = "0x2728429D73B4101BFd3baec86a2B7Bf2543f9085";
const feedbackRecordingABI = [
	{
		"inputs": [
			{
				"internalType": "address",
				"name": "_studentRegAddress",
				"type": "address"
			},
			{
				"internalType": "address",
				"name": "_feedback",
				"type": "address"
			},
			{
				"internalType": "address",
				"name": "_stdReg",
				"type": "address"
			}
		],
		"stateMutability": "nonpayable",
		"type": "constructor"
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
		"name": "FeedbackAns",
		"outputs": [
			{
				"internalType": "uint256",
				"name": "formID",
				"type": "uint256"
			}
		],
		"stateMutability": "view",
		"type": "function"
	},
	{
		"inputs": [],
		"name": "checkSubmissionStatus",
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
		"inputs": [],
		"name": "feedForm",
		"outputs": [
			{
				"internalType": "contract FeedbackForm",
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
				"name": "",
				"type": "uint256"
			}
		],
		"name": "formsSubmission",
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
				"internalType": "address",
				"name": "",
				"type": "address"
			}
		],
		"name": "hasSubmitted",
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
				"name": "_formID",
				"type": "uint256"
			}
		],
		"name": "returnAnsResponseForForm",
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
		"inputs": [],
		"name": "returnFormSubmissionID",
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
				"name": "",
				"type": "uint256"
			}
		],
		"name": "stdIDs",
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
		"name": "stdReg",
		"outputs": [
			{
				"internalType": "contract StudentRegistration",
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
				"name": "",
				"type": "uint256"
			},
			{
				"internalType": "uint256",
				"name": "",
				"type": "uint256"
			}
		],
		"name": "studentFeedback",
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
		"name": "studentReg",
		"outputs": [
			{
				"internalType": "contract StudentRegistration",
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
				"name": "_formID",
				"type": "uint256"
			},
			{
				"internalType": "string[]",
				"name": "_answers",
				"type": "string[]"
			}
		],
		"name": "submitFeedback",
		"outputs": [],
		"stateMutability": "payable",
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

async function submitFeedback() {
    const connection = await connectWallet();
    if (!connection) return;
    const { signer } = connection;
    const feedbackRecordingContract = new ethers.Contract(feedbackRecordingAddress, feedbackRecordingABI, signer);

    const formID = document.getElementById("formIDInput").value;
    let answersText = document.getElementById("answersInput").value;
    const answers = answersText.split(",").map(a => a.trim());

    try {
        const tx = await feedbackRecordingContract.submitFeedback(formID, answers, { value: 0 });
        await tx.wait();
        document.getElementById("feedbackResult").innerText = "Feedback submitted successfully!";
    } catch (error) {
        console.error("Error submitting feedback:", error);
        document.getElementById("feedbackResult").innerText = "Error: " + error.message;
    }
}

document.getElementById("connectButton").addEventListener("click", connectWallet);
document.getElementById("submitFeedbackButton").addEventListener("click", submitFeedback);
