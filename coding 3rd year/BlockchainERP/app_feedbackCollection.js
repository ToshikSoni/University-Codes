import { ethers } from "https://cdnjs.cloudflare.com/ajax/libs/ethers/6.7.0/ethers.min.js";

// Replace with your actual FeedbackCollection contract address and ABI
const feedbackCollectionAddress = "0x921981C1bBb8C51EE321C7dC0E6B8b320b231ab6";
const feedbackCollectionABI = [
	{
		"inputs": [
			{
				"internalType": "address",
				"name": "_form",
				"type": "address"
			},
			{
				"internalType": "address",
				"name": "_response",
				"type": "address"
			},
			{
				"internalType": "address",
				"name": "_studentReg",
				"type": "address"
			}
		],
		"stateMutability": "nonpayable",
		"type": "constructor"
	},
	{
		"inputs": [],
		"name": "collectFeedback",
		"outputs": [],
		"stateMutability": "payable",
		"type": "function"
	},
	{
		"inputs": [],
		"name": "feedback",
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
		"name": "processedFormIDs",
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
		"name": "recording",
		"outputs": [
			{
				"internalType": "contract FeedbackRecording",
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
			}
		],
		"name": "showOutput",
		"outputs": [
			{
				"internalType": "string[]",
				"name": "questions",
				"type": "string[]"
			},
			{
				"internalType": "string[]",
				"name": "responses",
				"type": "string[]"
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

async function collectFeedback() {
    const connection = await connectWallet();
    if (!connection) return;
    const { signer } = connection;
    const feedbackCollectionContract = new ethers.Contract(feedbackCollectionAddress, feedbackCollectionABI, signer);

    try {
        const tx = await feedbackCollectionContract.collectFeedback({ value: 0 });
        await tx.wait();
        document.getElementById("collectionResult").innerText = "Feedback collected successfully!";
    } catch (error) {
        console.error("Error collecting feedback:", error);
        document.getElementById("collectionResult").innerText = "Error: " + error.message;
    }
}

async function showOutput() {
    const connection = await connectWallet();
    if (!connection) return;
    const { provider } = connection;
    // Use a read-only contract instance
    const feedbackCollectionContract = new ethers.Contract(feedbackCollectionAddress, feedbackCollectionABI, provider);

    const formID = document.getElementById("showFormIDInput").value;
    try {
        const [questions, responses] = await feedbackCollectionContract.showOutput(formID);
        let outputText = "Questions: " + questions.join(", ") + "\nResponses: " + responses.join(", ");
        document.getElementById("outputResult").innerText = outputText;
    } catch (error) {
        console.error("Error showing output:", error);
        document.getElementById("outputResult").innerText = "Error: " + error.message;
    }
}

document.getElementById("connectButton").addEventListener("click", connectWallet);
document.getElementById("collectFeedbackButton").addEventListener("click", collectFeedback);
document.getElementById("showOutputButton").addEventListener("click", showOutput);

