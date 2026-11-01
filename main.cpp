// © Copyright 2026 T-PageCode Developer
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

int main() {
    // System first code
    cout << "========" << endl;
    cout << "PageSystem V1.0.2" << endl;
    string command;
    // Command
    while (true) {
        cout << ">>> ";
        getline(cin, command);
        if (command == "info") {
            cout << "System info:\nSystem name: PageSystem\nVersion: 1.0.2\nCopyright 2026 T-PageCode." << endl;
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
            system(cmd.c_str());
        }
        else if (command == "delete") {
            string delname;
            cout << "Warning: Cannot delete chinese name file." << endl;
            cout << "File name: ";
            getline(cin, delname);
            filesystem::remove(delname);
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
            file.close();
            if (!filesystem::exists(filename)) {
                cout << "Failed to create file: " << '"' << filename << '"' << "." << endl;
            }
            else {
                cout << "Created file: " << '"' << filename << '"' << "." << endl;
            }
        }
        else {
            cout << "Not found command: " << command << endl;
        }
    }
    return 0;
}