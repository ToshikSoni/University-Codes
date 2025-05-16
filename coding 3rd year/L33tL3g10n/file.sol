// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
import "./FeedbackForm.sol";
import "./FeedbackRecording.sol";

contract FeedbackCollection {
    struct Feedback {
        uint256 formID;
        string[] questions;
    }
    modifier onlyAdmin() {
        require(
            FeedbackForm(msg.sender).isAdminCheck(msg.sender),
            "Only admins can collect feedback"
        );
        _;
    }

    function collectFeedback(
        uint256 _formIDs
    ) public view onlyAdmin returns (Feedback[] memory) {
        Feedback[] storage submissions = formSubmissions[_formID];
        Feedback[] memory result = new Feedback[](submissions.length);
        for (uint256 i = 0; i < submissions.length; i++) {
            result[i] = submissions[i];
        }
        return result;
    }
}
