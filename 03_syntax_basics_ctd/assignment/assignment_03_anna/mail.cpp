//
//  mail.cpp
//  Love_Letters_Mail
//
//  Created by Linda Maas on 30.05.24.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

#include "mail.hpp"
#include "ascii.hpp"



int macmail() {
    // Path to the file you want to attach
    std::string filePath = "/path/to/your/file.txt";

    std::string subject = "love letter";
    std::string body = "This is my love letter to you:";
    // Construct the mailto command
    // Note: macOS's mailto handler might not support direct file attachment through this method,
    //       this will open a new email, but user might need to manually attach the file.
    std::string command = "open 'mailto:?subject=" + subject + "&body=" + body + "'";

    // Execute the command
    int result = system(command.c_str());

    if (result != 0) {
        std::cerr << "Failed to open the mail application." << std::endl;
        return 1;
    }

    return 0;
}



int winmail() {
     // Define the subject and body of the email
    std::string subject = "Hello World";
    std::string body = "This is a test email with ASCII art.";
                       

   // Construct the mailto link
    std::string mailto_link = "mailto:someone@example.com?subject=" + subject + "&body=" + body + "'";

    // Construct the command
    std::string command = "start " + mailto_link;

    // Execute the command
    system(command.c_str());

    return 0;
}
