#include <map>
#include "TwitterData.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower","Smit","Rick","smitRick@gmail.com","1117","power lifting"},
                             {"kittyKat72","Smith","Kathryn","kat@gmail.com","56","health"},
                             {"lexi5","Anderson","Alexis","lexi5@gmail.com","900","education"},
                             {"savage1","Savage","Ken","ksavage@gmail.com","17","president"},
                             {"smithMan","Smith","Rick","rick@hotmail.com","77","olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i) {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }

    //(50 pts) Map Scenario 1: Search based on UserName
    //(10 pts) Create a new std::map
    map<string, TwitterData> scenario1;
    //(10 pts) Insert all Twitter data into the std::map. Use a proper data member in 
    //TwitterData class (UserName?) to be the key. Use TwitterData class as the value.
    for (int i = 0; i < 5; i++) {
        scenario1.insert(pair<string, TwitterData>(twitter_data[i].getUserName(), twitter_data[i]));
    }

    //(10 pts) Iterate through the std::map and print the key - value pairs line by line
    map<string, TwitterData> ::iterator j;

    std::cout << "Printing key-vaue pairs in map 1: " << std::endl;
    for (j = scenario1.begin(); j != scenario1.end(); ++j) {
        std::cout << (*j).first << ": " << (*j).second.print() << std::endl;
    }

    //(10 pts) Find the person whose username is savage1 and print out the entire record
    j = scenario1.find("savage1");
    std::cout << "\nThe following record was found in the map: " << std::endl;
    std::cout << (*j).first << ": " << (*j).second.print() << std::endl;

    //(10 pts) Remove this person from the map
    scenario1.erase(j);

    //(40 pts) Map Scenario 2: Search based on EmailAddress
    //(8 pts) Create a new std::map
    map<string, TwitterData> scenario2;

    //(8 pts) Insert all Twitter data into the std::map.Use a proper data member in 
    //TwitterData class (Email) as the key. Use TwitterData class as the value.
    for (int i = 0; i < 5; i++) {
        scenario2.insert(pair<string, TwitterData>(twitter_data[i].getEmail(), twitter_data[i]));
    }

    //(8 pts) Iterate through the std::map and print the key - value pairs line by line

    std::cout << "\nPrinting key-vaue pairs in map 2: " << std::endl;
    for (j = scenario2.begin(); j != scenario2.end(); ++j) {
        std::cout << (*j).first << ": " << (*j).second.print() << std::endl;
    }

    //(8 pts) Find the person whose email is kat@gmail.com and print out the entire record
    j = scenario2.find("kat@gmail.com");
    std::cout << "\nThe following record was found in the map: " << std::endl;
    std::cout << (*j).first << ": " << (*j).second.print() << std::endl;

    //(8 pts) Remove this person from the map
    scenario2.erase(j);

    return 0;
}