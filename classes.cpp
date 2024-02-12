#include <bits/stdc++.h>
using namespace std;

extern void save_devices ();

            ////////////******** PARENT CLASS : DEVICE ********////////////

class Device
{
    string name;
    string brand;
    string model;
    bool is_powered_on;

public:

    Device () : is_powered_on (false) {}

    virtual void input ()
    {
        cout << "Enter Device name : ";
        getline (cin >> ws, name);
        cout << endl;

        cout << "Enter Device brand : ";
        getline (cin >> ws, brand);
        cout << endl;

        cout << "Enter Device model : ";
        getline (cin >> ws, model);
        cout << endl;

        if (name == ".")
            name = brand + " " + model;
    }

    virtual void display_short ()
    {
        cout << name;
    }

    virtual void display ()
    {
        cout << "Device name : ";
        cout << name << endl;

        cout << "Device brand : ";
        cout << brand << endl;

        cout << "Device model : ";
        cout << model << endl;

        cout << "Device is ";

        if (is_powered_on == false)
            cout << "OFF" << endl;
        else
            cout << "ON" << endl;

    }

    virtual void save_to_file (ofstream& out_file)
    {
        out_file << name << endl << brand << endl
                 << model << endl << is_powered_on << endl;
    }

    virtual void read_from_file (ifstream& in_file)
    {

        getline (in_file >> ws, name);
        getline (in_file >> ws, brand);
        getline (in_file >> ws, model);

        in_file >> is_powered_on;
    }

    virtual void display_actions () = 0;
};

            ////////////******** TELEVISION CLASS ********////////////

class Television : public Device
{
    int channel;
    int volume;
    int brightness;

public:

    Television () :
        channel (0),
        volume (0),
        brightness (50)
        {}

    void display_actions ()
    {
        vector <string> actions = {
                                    "Set Channel",
                                    "Set Volume",
                                    "Set Brightness"
                                  };

        cout << endl << "Enter your choice to update a feature : ";

        show_list (actions);

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1 : set_channel (); break;
            case 2 : set_volume (); break;
            case 3 : set_brightness (); break;
            default:print_invalid ();
        }

        save_devices ();
    }

    void set_channel ()
    {
        cout << endl << "Enter the channel number : ";
        cin >> channel;
        cout << endl;
    }

    void set_volume ()
    {
        cout << endl << "Enter new volume : ";
        cin >> volume;
        cout << endl;
    }

    void set_brightness ()
    {
        cout << endl << "Enter new brightness : ";
        cin >> brightness;
        cout << endl;
    }

    void save_to_file (ofstream& out_file)
    {
        out_file << "Television" << endl;
        Device::save_to_file (out_file);
        out_file << channel << endl << volume
                 << endl << brightness << endl;
    }

    void read_from_file (ifstream& in_file)
    {
        Device::read_from_file (in_file);
        in_file >> channel >> volume
                >> brightness;
    }

    void display_short ()
    {
        Device::display_short ();
        cout << " (Television)" << endl;
    }

    void display ()
    {
        cout << "Television" << endl;
        Device::display ();

        cout << "Channel number is : " << channel << endl;
        cout << "Volume is : " << volume << endl;
        cout << "Brightness : " << brightness << endl;
        cout<<endl;
    }
};

            ////////////******** REFRIGERATOR CLASS ********////////////

class Refrigerator : public Device
{
    float fridge_temperature;
    float freezer_temperature;

public:

    Refrigerator () :
        fridge_temperature (0.00),
        freezer_temperature (0.00)
        {}

    void display_actions ()
    {
        vector <string> actions = {
                                    "Set Fridge temperature",
                                    "Set Freezer temperature",
                                  };

        cout << endl << "Enter your choice to update a feature : ";

        show_list (actions);

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1 : set_fridge_temperature (); break;
            case 2 : set_freezer_temperature (); break;
            default: print_invalid ();
        }
    }

    void set_fridge_temperature ()
    {
        cout << endl << "Enter Fridge temperature : ";
        cin >> fridge_temperature;
        cout << endl;
    }

    void set_freezer_temperature ()
    {
        cout << endl << "Enter Freezer temperature : ";
        cin >> freezer_temperature;
        cout << endl;
    }

    void save_to_file (ofstream& out_file)
    {
        out_file << "Refrigerator" << endl;
        Device::save_to_file (out_file);
        out_file << fridge_temperature << endl
                 << freezer_temperature << endl;
    }

    void read_from_file (ifstream& in_file)
    {
        Device::read_from_file (in_file);
        in_file >> fridge_temperature
                >> freezer_temperature;
    }

    void display_short ()
    {
        Device::display_short ();
        cout << " (Refrigerator)" << endl;
    }

    void display ()
    {
        cout << "Refrigerator" << endl << endl;
        Device::display ();

        cout << "Fridge temperature is : " << fridge_temperature << endl;
        cout << "Freezer temperature is : " << freezer_temperature << endl;
    }
};

            ////////////******** AIR CONDITIONER CLASS ********////////////

class AirConditioner : public Device
{
    float temperature;
    int fan_speed;
    bool swing;

public:

    AirConditioner () :
        temperature (0.00),
        fan_speed (0),
        swing (false)
        {}

    void display_actions ()
    {
        vector <string> actions = {
                                    "Set Temperature",
                                    "Set Fan speed",
                                    "Set Swing"
                                  };

        cout << endl << "Enter your choice to update a feature : ";

        show_list (actions);

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1 : set_temperature (); break;
            case 2 : set_fan_speed (); break;
            case 3 : set_swing (); break;
            default: print_invalid ();
        }
    }

    void set_temperature ()
    {
        cout << endl << "Enter Temperature : ";
        cin >> temperature;
        cout << endl;
    }

    void set_fan_speed ()
    {
        cout << endl << "Enter Fan speed : ";
        cin >> fan_speed;
        cout << endl;
    }

    void set_swing ()
    {
        cout << endl << "Enter (1) to ON swing and (0) to OFF swing :";
        cin >> swing;
        cout << endl;
    }

    void toggle_swing()
    {
        swing = !swing;
        cout << endl << "Swing is turned " << (swing ? "ON" : "OFF") << endl;
    }

    void save_to_file (ofstream& out_file)
    {
        out_file << "AirConditioner" << endl;
        Device::save_to_file (out_file);
        out_file << temperature << endl
                 << fan_speed << endl
                 << swing << endl;
    }

    void read_from_file (ifstream& in_file)
    {
        Device::read_from_file (in_file);
        in_file >> temperature
                >> fan_speed
                >> swing;
    }

    void display_short ()
    {
        Device::display_short ();
        cout << " (AirConditioner)" << endl;
    }

    void display ()
    {
        cout << "AirConditioner" << endl << endl;
        Device::display ();

        cout << "Temperature is : " << temperature << endl;
        cout << "Fan speed is : " << fan_speed << endl;
        cout << "Swing is : " << swing << endl;
    }
};

            ////////////******** LIGHT BULB CLASS ********////////////

class LightBulb : public Device
{
    int brightness;
    int color_temperature;

public:

    LightBulb () :
        brightness (0),
        color_temperature (0)
        {}

    void display_actions ()
    {
        vector <string> actions = {
                                    "Set Brightness",
                                    "Set Color temperature"
                                  };

        cout << endl << "Enter your choice to update a feature : ";

        show_list (actions);

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1 : set_brightness (); break;
            case 2 : set_color_temperature (); break;
            default:print_invalid ();
        }
    }

    void set_brightness ()
    {
        cout << endl << "Enter Brightness : ";
        cin >> brightness;
        cout << endl;
    }

    void set_color_temperature ()
    {
        cout << endl << "Enter Color temperature : ";
        cin >> color_temperature;
        cout << endl;
    }

    void save_to_file (ofstream& out_file)
    {
        out_file << "LightBulb" << endl;
        Device::save_to_file (out_file);
        out_file << brightness << endl
                 << color_temperature << endl;
    }

    void read_from_file (ifstream& in_file)
    {
        Device::read_from_file (in_file);
        in_file >> brightness
                >> color_temperature;
    }

    void display_short ()
    {
        Device::display_short ();
        cout << " (LightBulb)" << endl;
    }

    void display ()
    {
        cout << "LightBulb" << endl << endl;
        Device::display ();

        cout << "Brightness : " << brightness << endl;
        cout << "Color temperature is : " << color_temperature << endl;
    }
};

            ////////////******** VACUUM CLEANER CLASS ********////////////

class VacuumCleaner : public Device
{
    bool is_plugged_in;
    int suction_power;
    bool is_dustbin_full;
    int brush_height;

public:

    VacuumCleaner () :
        is_plugged_in (false),
        suction_power (0),
        is_dustbin_full (false),
        brush_height (0)
        {}

    void display_actions ()
    {
        vector <string> actions = {
                                    "Set Is_plugged_in",
                                    "Set Suction power",
                                    "Set Is_dustbin_full",
                                    "Set Brush height"
                                   };

        cout << endl << "Enter your choice to update a feature : ";

        show_list (actions);

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1 : set_is_plugged_in (); break;
            case 2 : set_suction_power (); break;
            case 3 : set_is_dustbin_full (); break;
            case 4 : set_brush_height (); break;
            default: print_invalid ();
        }
    }

    void set_is_plugged_in ()
    {
        cout << endl << "Enter (1) to Plug in and (0) to Plug out :";
        cin >> is_plugged_in;
        cout << endl;
    }

    void set_suction_power ()
    {
        cout << endl << "Enter Suction power : ";
        cin >> suction_power;
        cout << endl;
    }

    void set_is_dustbin_full ()
    {
        cout << endl << "Enter (1) if Dustbin is full and (0) if Dustbin isn't full :";
        cin >> is_dustbin_full;
        cout << endl;
    }

    void set_brush_height ()
    {
        cout << endl << "Enter Brush height : ";
        cin >> brush_height;
        cout << endl;
    }

    void save_to_file (ofstream& out_file)
    {
        out_file << "VacuumCleaner" << endl;
        Device::save_to_file (out_file);
        out_file << is_plugged_in << endl << suction_power << endl
                 << is_dustbin_full << endl << brush_height << endl;
    }

    void read_from_file (ifstream& in_file)
    {
        Device::read_from_file (in_file);
        in_file >> is_plugged_in >> suction_power
                >> is_dustbin_full >> brush_height;
    }

    void display_short ()
    {
        Device::display_short ();
        cout << " (VacuumCleaner)" << endl;
    }

    void display ()
    {
        cout << "VacuumCleaner" << endl << endl;
        Device::display ();

        if (is_plugged_in)
            cout << "=== Vacuum cleaner is plugged in!! ===" << endl;
        else
            cout << "=== Vacuum cleaner is plugged out!! ===" << endl;

        cout << "Suction power is : " << suction_power << endl;
        cout << "Brush height is : " << brush_height << endl;

        if (is_dustbin_full)
            cout << "=== Dustbin is full!! ===" << endl;
        else
            cout << "=== Dustbin is empty!! ===" << endl;
    }
};

            ////////////******** WINDOW CURTAIN CLASS ********////////////

class WindowCurtains : public Device
{
    string material;
    bool is_open;
    int height;

public:

    WindowCurtains () :
        is_open (false),
        height (0)
        {}

    void display_actions ()
    {
        vector <string> actions = {
                                    "Set Is_open",
                                    "Set Height",
                                   };

        cout << endl << "Enter your choice to update a feature : ";

        show_list (actions);

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1 : set_is_open (); break;
            case 5 : set_height (); break;
            default: print_invalid ();
        }
    }

    void set_is_open ()
    {
        cout << endl << "Enter (1) to Open and (0) to Close :";
        cin >> is_open;
        cout << endl;
    }

    void set_height ()
    {
        cout << endl << "Enter Height : ";
        cin >> height;
        cout << endl;
    }

    void save_to_file (ofstream& out_file)
    {
        out_file << "WindowCurtains" << endl;
        Device::save_to_file (out_file);
        out_file << is_open << endl
                 << height << endl;
    }

    void read_from_file (ifstream& in_file)
    {
        Device::read_from_file (in_file);
        in_file >> is_open
                >> height;
    }

    void display_short ()
    {
        Device::display_short ();
        cout << " (WindowCurtains)" << endl;
    }

    void display ()
    {
        cout << "WindowCurtains" << endl;
        Device::display ();

        if (is_open)
            cout << "=== Window curtain is opened!! ===" << endl;
        else
            cout << "=== Window curtain is closed!! ===" << endl;

        cout << endl << "Height is : " << height << endl;
    }
};

            ////////////******** SECURITY CAMERA CLASS ********////////////

class SecurityCamera : public Device
{
    bool is_motion_detected;
    bool is_night_vision_enabled;

public :

    SecurityCamera () :
        is_motion_detected (false),
        is_night_vision_enabled (false)
        {}

    void display_actions ()
    {
        vector <string> actions = {
                                    "Toggle motion detection",
                                    "Toggle night vision"
                                   };

        cout << endl << "Enter your choice to update a feature : ";

        show_list (actions);

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1 : set_is_motion_detected (); break;
            case 2 : set_is_night_vision_enabled (); break;
            default: print_invalid ();
        }
    }

    void set_is_motion_detected ()
    {
        cout << endl << "Enter (1) if Motion is detected and (0) if Motion isn't detected :";
        cin >> is_motion_detected;
        cout << endl;
    }

    void set_is_night_vision_enabled ()
    {
        cout << endl << "Enter (1) if Night vision is enabled and (0) if Night vision isn't enabled :";
        cin >> is_night_vision_enabled;
        cout << endl;
    }

    void save_to_file (ofstream& out_file)
    {
        out_file << "SecurityCamera" << endl;
        Device::save_to_file (out_file);
        out_file << is_motion_detected << endl
                 << is_night_vision_enabled << endl;
    }

    void read_from_file (ifstream& in_file)
    {
        Device::read_from_file (in_file);
        in_file >> is_motion_detected
                >> is_night_vision_enabled;
    }

    void display_short ()
    {
        Device::display_short ();
        cout << " (SecurityCamera)" << endl;
    }

    void display ()
    {
        cout << "SecurityCamera" << endl;
        Device::display ();

        if (is_motion_detected)
            cout << "=== Motion is detected!! ===" << endl;
        else
            cout << "=== Motion isn't detected!! ===" << endl;

        if (is_night_vision_enabled)
            cout << "=== Night vision is enabled!! ===" << endl;
        else
            cout << "=== Night vision is not enabled!! ===" << endl;
    }
};

            ////////////******** DOOR LOCK CLASS ********////////////

class DoorLock : public Device
{
    bool is_connected;
    bool is_locked;

public :

    DoorLock () :
        is_connected (false),
        is_locked (false)
        {}

    void display_actions ()
    {
        vector <string> actions = {
                                    "Set Is_connected",
                                    "Set Is_locked",
                                   };

        cout << endl << "Enter your choice : ";

        show_list (actions);

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1 : set_is_connected (); break;
            case 2 : set_is_locked (); break;
            default: print_invalid ();
        }
    }

    void set_is_connected ()
    {
        cout << endl << "Enter (1) if Door lock is connected and (0) if Door lock isn't connected :";
        cin >> is_connected;
        cout << endl;
    }

    void set_is_locked ()
    {
        cout << endl << "Enter (1) if Door is locked and (0) if Door isn't locked :";
        cin >> is_locked;
        cout << endl;
    }

    void save_to_file (ofstream& out_file)
    {
        out_file << "DoorLock" << endl;
        Device::save_to_file (out_file);
        out_file << is_connected << endl
                 << is_locked << endl;
    }

    void read_from_file (ifstream& in_file)
    {
        Device::read_from_file (in_file);
        in_file >> is_connected
                >> is_locked;
    }

    void display_short ()
    {
        Device::display_short ();
        cout << " (DoorLock)" << endl;
    }

    void display ()
    {
        cout << "DoorLock" << endl << endl;
        Device::display ();

        if (is_connected)
            cout << "=== Door lock is connected!! ===" << endl;
        else
            cout << "=== Door lock is disconnected!! ===" << endl;

        if (is_locked)
            cout << "=== Door is Locked!! ===" << endl;
        else
            cout << "=== Door is Unlocked!! ===" << endl;
    }
};
