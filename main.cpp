#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>


void sendFile(const std::string& file);
int getBiggerNumber(std::string query);
int getChosenPath(std::string query);

int main(){
    std::cout << "Content-Type: text/html\n\n";
    const char* queryStr = std::getenv("QUERY_STRING");
    std::string mainLink = "http://127.0.0.1/cgi-bin/practical-1.cgi";

    if(queryStr != nullptr && queryStr[0] != '\0'){
        std::string query(queryStr);
        int bigger = getBiggerNumber(query);
        int value = getChosenPath(query);
        
        if(bigger == value){
            sendFile("/var/www/html/cos332-html/right.htm");
        }else{
            sendFile("/var/www/html/cos332-html/wrong.htm");
        }
    }else{
        // generate 2 random numbers
        std::srand(std::time(nullptr));

        int num1 = std::rand() % 100 + 1;
        int num2 = std::rand() % 100 + 1;

        while(num1 == num2){
            num1 = std::rand() % 100 + 1;
            num2 = std::rand() % 100 + 1;
        }

        std::string urlParam = "?num1=" +std::to_string(num1) + "&num2=" + std::to_string(num2) + "&chosenPath=";
        std::string html = R"(
            <html>
                <head>
                    <meta http-equiv="Cache-Control" content="no-cache, no-store, must-revalidate">
                    <meta http-equiv="Pragma" content="no-cache">
                    <meta http-equiv="Expires" content="0">
                    <title>COS332 | Welcome To Networking</title>
                    <link rel="stylesheet" href="/cos332-css/beautiful.css">
                </head>
                <body>
                    <h1>COS332: Networking 101</h1>
                    <p>Made by <a target="_blank" href="https://www.linkedin.com/public-profile/settings/?trk=d_flagship3_profile_self_view_public_profile&lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_view_base%3BlakHMu7%2FTz%2B0FVqKWI7anw%3D%3D">Khahliso</a></p>
                    <p>To continue on this path, you must select the higher number.
                        Compare the numbers carefully and select the one that is greater.
                        Choosing the larger number ensures the correct outcome and allows you to move forward.
                        Take a moment to verify your choice before confirming.

                        <span style="color: red;"><br>Hovering over the numbers will not reveal the correct path</span>
                    </p>
                    <div id="nums">
                        <a class="number" href=")" + mainLink + urlParam + std::to_string(num1) + R"(">)" + std::to_string(num1) + R"(</a>
                        <a class="number" href=")" + mainLink + urlParam + std::to_string(num2) + R"(">)" + std::to_string(num2) + R"(</a>
                    </div> 
                </body>
            </html>
        )";
        std::cout << html;
    }

    return 0;
}

int getBiggerNumber(std::string query){
    size_t start1 = query.find("num1=") + 5;
    size_t end1 = query.find("&", start1);
    int num1 = std::stoi(query.substr(start1, end1 - start1));

    size_t start2 = query.find("num2=") + 5;
    size_t end2 = query.find("&", start2);
    int num2 = std::stoi(query.substr(start2, end2 - start2));

    if(num1 > num2) return num1;
    return num2;
}

int getChosenPath(std::string query){
    size_t start = query.find("chosenPath=") + 11;
    size_t end = query.find("&", start);

    if(end == std::string::npos)
        end = query.length();

    return std::stoi(query.substr(start, end - start));
}

void sendFile(const std::string& file){
    std::ifstream returnFile(file);
    if(!returnFile){
        std::string html = R"(
        <html>
            <head>
                <<title>COS332 | Welcome To Networking</title>
            </head>
            <body>
                <h1>Eish! Something happened on the server side</h1>
            </body>
        </html>
    )";
        std::cout << "Eish! Something happened on the server side";
        
        return;
    }

    std::string line;
    std::string finalOutput = "";
    while(std::getline(returnFile, line)){
        finalOutput += line;
    }
    std::cout << finalOutput;
}