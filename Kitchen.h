// *********************************************************************
// Programming: mavas
// Project: Olimar's Escape.exe
// Project desc: A text-based RPG for the PC.
// File: Kitchen.h
// *********************************************************************
////////////////////////////////////////////////////////////////////////

// clears the screen
void Clear()
{
    COORD coordScreen = { 0, 0 };
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    SetConsoleCursorPosition(hConsole, coordScreen);
}

// close program...
void Close(char *Message=NULL)
{
    Clear();

    if (Message!=NULL)
    {
      cout<<"\n\a"<<Message<<"\nClosing program...";
      cin.get();
      exit(0);
    }
    else
    {
      cout<<"\n\aClosing program...";
      exit(0);
    }
}

// check if user wants to exit program
void CheckExit(const char A[])
{
    if (!strcmp(A,"Exit") || !strcmp(A,"exit") || !strcmp(A,"EXIT") ||
        !strcmp(A,"Close") || !strcmp(A,"close") || !strcmp(A,"CLOSE"))
     Close();
}

// get user input and check if user wants to exit game
void Get(char I[])
{
    cin.getline(I, 100);  CheckExit(I);
}

// check if user wants to show all commands
bool CheckShowCommands(const char A[], bool B=FALSE)
{
    if (!strcmp(A,"Commands") || !strcmp(A,"commands") || !strcmp(A,"COMMANDS") ||
        !strcmp(A,"Command") || !strcmp(A,"command") || !strcmp(A,"COMMAND") ||
        !strcmp(A,"Show Commands") || !strcmp(A,"show commands") || !strcmp(A,"SHOW COMMANDS") ||
        !strcmp(A,"Help") || !strcmp(A,"help") || !strcmp(A,"HELP") ||
        !strcmp(A,"Cmd") || !strcmp(A,"cmd") || !strcmp(A,"CMD") ||
        !strcmp(A,"Cmds") || !strcmp(A,"cmds") || !strcmp(A,"CMDS") ||
        !strcmp(A,"Hlp") || !strcmp(A,"hlp") || !strcmp(A,"HLP"))
     return TRUE;
    else
     return FALSE;
}

// check if user wants to show Olimar's stats
bool CheckShowStats(const char A[])
{
    if (!strcmp(A,"Stats") || !strcmp(A,"stats") || !strcmp(A,"STATS") ||
        !strcmp(A,"Show Stats") || !strcmp(A,"show stats") || !strcmp(A,"SHOW STATS") ||
        !strcmp(A,"View Stats") || !strcmp(A,"view stats") || !strcmp(A,"VIEW STATS"))
     return TRUE;
    else
     return FALSE;
}

// check if user wants to show the map
bool CheckShowMap(const char A[])
{
    if (!strcmp(A,"View Map") || !strcmp(A,"view map") || !strcmp(A,"VIEW MAP") ||
        !strcmp(A,"Show Map") || !strcmp(A,"show map") || !strcmp(A,"SHOW MAP") ||
        !strcmp(A,"Map") || !strcmp(A,"map") || !strcmp(A,"MAP"))
     return TRUE;
    else
     return FALSE;
}

// check if user wants to talk
bool CheckTalkNorth(const char A[])
{
    if (!strcmp(A,"Talk North") || !strcmp(A,"talk north") || !strcmp(A,"TALK NORTH") || !strcmp(A,"tn") || !strcmp(A,"TN"))
     return TRUE;
    else
     return FALSE;
}
bool CheckTalkEast(const char A[])
{
    if (!strcmp(A,"Talk East") || !strcmp(A,"talk east") || !strcmp(A,"TALK EAST") || !strcmp(A,"te") || !strcmp(A,"TE"))
     return TRUE;
    else
     return FALSE;
}
bool CheckTalkSouth(const char A[])
{
    if (!strcmp(A,"Talk South") || !strcmp(A,"talk south") || !strcmp(A,"TALK SOUTH") || !strcmp(A,"ts") || !strcmp(A,"TS"))
     return TRUE;
    else
     return FALSE;
}
bool CheckTalkWest(const char A[])
{
    if (!strcmp(A,"Talk West") || !strcmp(A,"talk west") || !strcmp(A,"TALK WEST") || !strcmp(A,"tw") || !strcmp(A,"TW"))
     return TRUE;
    else
     return FALSE;
}

// check if user wants to attack
bool CheckOlimarAttack(const char A[])
{
    if (!strcmp(A,"Attack") || !strcmp(A,"attack") || !strcmp(A,"ATTACK") ||
        !strcmp(A,"Att") || !strcmp(A,"att") || !strcmp(A,"ATT"))
     return TRUE;
    else
     return FALSE;
}

// check if user wants to open a door
bool CheckOpenDoorNorth(const char A[])
{
    if (!strcmp(A,"Open Door North") || !strcmp(A,"open door north") || !strcmp(A,"OPEN DOOR NORTH") || !strcmp(A,"Open DN") || !strcmp(A,"open dn") || !strcmp(A,"OPEN DN"))
     return TRUE;
    else
     return FALSE;
}
bool CheckOpenDoorEast(const char A[])
{
    if (!strcmp(A,"Open Door East") || !strcmp(A,"open door east") || !strcmp(A,"OPEN DOOR EAST") || !strcmp(A,"Open DE") || !strcmp(A,"open de") || !strcmp(A,"OPEN DE"))
     return TRUE;
    else
     return FALSE;
}
bool CheckOpenDoorSouth(const char A[])
{
    if (!strcmp(A,"Open Door South") || !strcmp(A,"open door south") || !strcmp(A,"OPEN DOOR SOUTH") || !strcmp(A,"Open DS") || !strcmp(A,"open ds") || !strcmp(A,"OPEN DS"))
     return TRUE;
    else
     return FALSE;
}
bool CheckOpenDoorWest(const char A[])
{
    if (!strcmp(A,"Open Door West") || !strcmp(A,"open door west") || !strcmp(A,"OPEN DOOR WEST") || !strcmp(A,"Open DW") || !strcmp(A,"open dw") || !strcmp(A,"OPEN DW"))
     return TRUE;
    else
     return FALSE;
}

