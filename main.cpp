// © Copyright 2026 T-PageCode Developer
#include <iostream>
#include <fstream>
#include <filesystem>
#include <windows.h>
using namespace std;

int main() {
    // UTF-8
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    // PageSystem version and ========
    cout << "========" << endl;
    cout << "PageSystem V1.0.4-11141" << endl;
    string command;
    // Command 
    while (true) {
        cout << ">>> ";
        if (!getline(cin, command)) {
            cout << "Getline error, Press Enter to exit..." << endl;
            cin.clear();
            cin.get();
            break;
        }
        if (command == "info") {
            cout << "System info:\nSystem name: PageSystem\nVersion: 1.0.3\nCopyright 2026 T-PageCode." << endl;
        }
        else if (command == "exit") {
            break;
        }
        else if (command == "print") {
            string print;
            cout << "Content: ";
            getline(cin, print);
            cout << print << endl;
        }
        else if (command == "program") {
            string name;
            cout << "Program name: ";
            getline(cin, name);
            // Cannot input |, &...!
            string cmd = "start " + name;
            int start = system(cmd.c_str());
            if (start != 0) {
                cout << "Failed to start program: " << name << " ( Code: " << start << " )" << "." << endl;
            }
            else {
                cout << "Program started: " << name << endl;
            }
        }
        else if (command == "delete") {
            string delname;
            cout << "File name: ";
            getline(cin, delname);
            try {
               filesystem::remove(delname);
               cout << "Deleted file: " << delname << "." << endl; 
            }
            catch (const exception& e) {
                cout << "Failed to delete file, info: " << e.what() << endl;
            }
        }
        else if (command == "write") {
            string filename;
            cout << "File name: ";
            getline(cin, filename);
            ofstream file(filename);
            string filecontent;
            cout << "Content: ";
            getline(cin, filecontent);
            file << filecontent << endl;
            if (!file) {
                cout << "Failed to create file: " << '"' << filename << '"' << "." << endl;
            }
            else {
                cout << "Created file: " << '"' << filename << '"' << "." << endl;
            }
            file.close();
        }
        else if (command == "download") {
            string downloadfilename;
            cout << "File name: ";
            getline(cin, downloadfilename);
            if (downloadfilename.empty()) {
                downloadfilename = "downloaded.untitled";
            }
            string downloadurl;
            cout << "URL: ";
            getline(cin, downloadurl);
            system(("curl -s -L -o " + downloadfilename + " " + downloadurl).c_str());
        }
        else {
            cout << "Command Not Found: " << command << endl;
        }
    }
    return 0;
}