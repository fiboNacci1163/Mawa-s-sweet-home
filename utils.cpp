
        ///////////******** FUNCTION TO PRINT INVALID MESSEGE ********////////////

void print_invalid ()
{
    cout << endl << "INVALID CHOICE!!! Please select a valid option!!!" << endl << endl;
}

        ////////////******** LIST DISPLAY FUNCTION ********////////////

void show_list (vector <string> options, char starting_index)
{
    cout << endl;
    char x = starting_index;
    for (auto s : options)
        cout << '\t' << x++ << ". " << s << endl;
}

        ////////////******** LIST DISPLAY FUNCTION ********////////////

void show_list (vector <string> options, int starting_index = 1)
{
    cout << endl;
    int x = starting_index;
    for (auto s : options)
        cout << '\t' << x++ << ". " << s << endl;
}

