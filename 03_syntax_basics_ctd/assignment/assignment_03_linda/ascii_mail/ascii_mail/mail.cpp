//
//  mail.cpp
//  Love_Letters_Mail
//
//  Created by Linda Maas on 30.05.24.
//
#include <iostream>
#include <fstream>
#include <curl/curl.h>
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



//int winmail() {
    // The path to the file you want to attach
   // std::string filePath = "C:\\path\\to\\your\\file.txt";

    // Prepare the mailto link
    //std::string mailto = "mailto:someone@example.com?subject=The Subject&body=See attached file.&attach=\"" + filePath + "\"";

    // Use ShellExecute to open the default email client
   // HINSTANCE result = ShellExecute(NULL, "open", mailto.c_str(), NULL, NULL, SW_SHOWNORMAL);

   // if ((int)result <= 32) {
     //   std::cerr << "Failed to open email client. Error: " << (int)result << std::endl;
     //   return -1;
   // }

    //return 0;
//}
