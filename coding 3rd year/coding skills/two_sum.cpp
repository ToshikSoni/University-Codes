// https://leetcode.com/problems/two-sum/

// Thales
// — Sarnsung R&D Institute
// Natwest Group
// Paypal
// Tata Img
// Delhivery
// Mathworks
// Oracle
// Microsoft
// Hexaware Technologies
// Intuit Hike
// CIS - Cyber Infrastructure Grab O Optum
// Q
// • IndiaMart BNY Mellon
// Qualcomm
// Tata Consultancy Services (TCS) Cisco
// Siemens
// e
// Paytm (One97 Communications Limited) — Acko
// Zomato
// Infosys Meesho
// Info Edge India (Naukri.com) Google
// Expedia Group
// Urban Company (UrbanClap)
// o
// Nineleaps Technologies
// Amazon
// Accenture
// PharmEasy
// •O Cognizant SAP Labs
// UST Global
// Springworks Sli¯c. Josh Technology Group
// EPAM Systems
// Mobile Premier League (MPL) Incedo Inc.
// Providence Global Center LLP
// Capegemini Consulting India Private Limited
// • Pristyn Care Kellton Tech Solutions Limited
// Tata consultancy services Ltd
// Chegg
// Coforge in Hashedln
// Global Logic Hedonova
// Fidelity Intemational VMware lnc
// Bonami Software Pvt. Ltd
// Chetu, Inc.
// Mphasis
// Airtel
// Virtusa
// in Hashedln
// PwC India
// Apisero CGI Inc.
// Detta Air Lines
// Lido Leaming
// Antino Labs Pvt Ltd
// Capita
// NCR Corporation
// Aricent Technologies (Holdings) Limited
// Spinny Coditas
// z•xc
// Happiest Minds
// DC Technology
// o
// Stantech Al
// Paxcom — Nagaaro Lowe's India

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
            if (map.find(target - nums[i]) != map.end())
            {
                result.push_back(map[target - nums[i]]);
                result.push_back(i);
                return result;
            }
            else
                map.insert({nums[i], i});
        return {};
    }
};