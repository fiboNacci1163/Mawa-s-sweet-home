#include <bits/stdc++.h>
using namespace std;
#include "utils.cpp"
#include "classes.cpp"

vector <Device*> all_devices;

            ////////////******** SAVE DEVICES TO FILE ********////////////

void save_devices ()
{
    ofstream out_file ("all_devices.txt");

    for (auto& device : all_devices)
    {
        device->save_to_file (out_file);
        out_file << endl;
    }

    out_file.close ();
}

            ////////////******** ADD DEVICES ********////////////

void add_device ()
{
    while (true)
    {
        cout << "*** Select device type!!! ***" << endl;

        vector<string> options =
        {
            "Television", "AirConditioner", "Refrigerator",
            "LightBulb", "VacuumCleaner", "WindowCurtains",
            "SecurityCamera", "DoorLock", "EXIT"
        };

        cout << endl;
        show_list (options);

        int choice;
        cin >> choice;

        Device* device;

        switch (choice)
        {
            case 1 : device = new Television (); break;
            case 2 : device = new AirConditioner (); break;
            case 3 : device = new Refrigerator (); break;
            case 4 : device = new LightBulb (); break;
            case 5 : device = new VacuumCleaner (); break;
            case 6 : device = new WindowCurtains (); break;
            case 7 : device = new SecurityCamera (); break;
            case 8 : device = new DoorLock (); break;
            case 9 : return;
            default: { print_invalid (); return; }
        }

        device->input ();
        all_devices.push_back (device);

        save_devices ();

    }
}

        ////////////******** DEVICE LIST DISPLAY FUNCTION ********////////////

void show_devices ()
{
    while (true)
    {
        int count = 1;

        cout << "******** Device List ********" << endl << endl;
        for (auto& device : all_devices)
        {
            cout << '\t' << count++ << ". ";
            device->display_short ();
        }

        cout << '\t' << count << ". EXIT" << endl;


        if (count > 1)
            cout << endl<< "=== Select a device to update feature!! ===" << endl;

        cout << endl << "=== Select " << count << " to return to the main menu ===" << endl;

        int choice;
        cin >> choice;

        if (choice == count)
            return;
        else if (choice >= 1 && choice < count)
        {
            Device* device = all_devices[choice - 1];
            device->display();
            cout<<endl;
            device->display_actions ();
        }
        else
            print_invalid ();
    }
}

            ////////////******** REMOVE DEVICE ********////////////

void remove_device ()
{
    while (true)
    {
        int count = 1;

        for (auto& device : all_devices)
        {
            cout << '\t' << count++ << ". ";
            device->display_short ();
        }

        cout << '\t' << count << ". EXIT" << endl;


        if (count > 1)
            cout << "*** Select a device to remove!! ***" << endl;

        cout << endl << "*** Select " << count << " to return to the main menu!! ***" << endl;

        int choice;
        cin >> choice;

        if (choice == count)
            return;
        else if (choice > count || choice < 1)
        {
            print_invalid ();
            continue;
        }

        all_devices.erase(all_devices.begin () + choice - 1);

    }
}

            ////////////******** MAIN MENU DISPLAY FUNCTION ********////////////

void main_menu ()
{
    cout << endl << endl << "|||||||||*****  WELCOME  *****|||||||||" << endl << endl;

    while (true)
    {
        cout << endl << "*** Select your choice!!! ***" << endl;
        vector <string> options = { "Show Devices",
                                    "Add Device",
                                    "Remove Device",
                                    "Exit"
                                   };

        show_list (options);
        cout << endl;

        int choice;
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1 : show_devices (); break;
            case 2 : add_device (); break;
            case 3 : remove_device (); break;
            case 4 : { cout << endl << "|||||||||*****  THANK YOU  *****|||||||||"
                     << endl << endl; return;}
            default: { print_invalid (); }
        }
    }
}

    ////////////******** LOAD PREVIOUSLY STORED DEVICES FROM SAVED FILE ********////////////

void load_devices ()
{
    ifstream in_file ("all_devices.txt");

    while (in_file)
    {
        string type;
        in_file >> type;

        Device* device = nullptr;

        if (type == "Television")
            device = new Television;
        else if (type == "AirConditioner")
            device = new AirConditioner;
        else if (type == "Refrigerator")
            device = new Refrigerator;
        else if (type == "LightBulb")
            device = new LightBulb;
        else if (type == "VacuumCleaner")
            device = new VacuumCleaner;
        else if (type == "WindowCurtains")
            device = new WindowCurtains;
        else if (type == "SecurityCamera")
            device = new SecurityCamera;
        else if (type == "DoorLock")
            device = new DoorLock;

        if (device)
        {
            device->read_from_file (in_file);
            all_devices.push_back (device);
        }
    }
}
            ////////////******** MAIN FUNCTION ********////////////

int main ()
{
    load_devices ();
    main_menu ();

    save_devices ();
}
