#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    std::vector<std::string> students = {
        "Tarun Chaudhry", "Ismail Murtaza", "Mustafa Miyaji", "Ayan Akhtar", "Jeevna",
        "C.Vasu Sagar", "Mohammad Abdul Maliq", "M.Vivek", "Abdul Rahman", "Kartik Reddy",
        "S.Vignesh Reddy", "Akhil Kumar Reddy", "Rishitha Nagareddy", "K. Anagha", "Jahnavi Gunnam",
        "P. Lahari", "A. Saketh Reddy", "Riya Joshi", "Lavina Saini", "Ruth Jeso Johnson",
        "G.Indumathi", "Dhruv Makadiya", "A Santosh Navadeep", "Anjali Devi", "Chinthala Karthik Sai",
        "B. Sidhartha", "Rahul Amerchetti", "S. Prasanthi", "Yuvaraja Srinivas", "Malla.Abhiram",
        "Vajrala Ujwala", "Garlapati Kalyani Reddy", "Aradhya.S", "Komali Velangani Rongali", "Medagam.Hansika Reddy",
        "Navya Manda", "Kurapati Varun", "Bandari Lokesh Goud", "Himasagar Reddy", "D.Dheeraj",
        "Debbeta Vishali", "Renu", "Priyanka", "A Siri", "Raman Karthik Vishwaroju",
        "Deekshitha", "P.Bala Vyashnavi", "Chitikela Tanusree", "Rajveer Choudhry", "Charan Teja Raipally",
        "Deepak Sen", "Chinmayi Bhartiya", "Bharat Vaishnav", "Yellu Avanthika", "Banuka Sneha Rekha",
        "B.M.Snehitha Supriya", "Peteti Sai Ram Babu", "Puli Sai Siddartha", "K. Umakanth", "Mahesh Lohar",
        "K. Vaishnavi Reddy", "T.Rishika", "Poluri. Abhinave Venkat", "Yashwanth Mantri", "Pranay Jain",
        "Palusa Sai Charan Goud", "K.K.R.Sai Prakash", "Janardan Singh Gohil", "DWARAMPUDI PRATHIBA", "V. Gnana Shashank",
        "K. Akhil", "Falguni", "Harshini", "D. Harsha Narayana", "Anuj Sharma",
        "Vinayak Rathor", "Harshita Jain", "Paras Vardhan Singh", "Aniruddha Somani", "K.Shiva Chaithanya",
        "Kunchala Srilekha", "Hemant Dangi", "Beerla Akhil", "A.Vishnuvardhan Mani", "Gayatri Ranawat",
        "Hussain Bohra", "Pathan Tahasheen", "T.Venkata Narayana Reddy", "Rao Varshith", "Deepika",
        "U.Sowmya", "Udit Soni", "Nitesh Rathore", "Dwarampudi Praveena"};

    std::srand(std::time(0)); // Seed random number generator
    int randomIndex = std::rand() % students.size();

    std::cout << "Selected student: " << students[randomIndex] << std::endl;

    return 0;
}