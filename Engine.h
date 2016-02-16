// *********************************************************************
// Programming: David Kilgore
// Project: Olimar's Escape.exe
// Project desc: A text-based RPG for the PC.
// File: Engine.h
// *********************************************************************
////////////////////////////////////////////////////////////////////////

// write summary at the bottom of the screen
void WriteSummary(const int hp,           // Olimar's hit points
                  const char* location)   // current location
{
    gotoxy(1,6);
    cout<<"------------------------------------------------------------------------------";
    gotoxy(1,24);
    cout<<" ------------------------------------------------------------------------------\n";
    cout<<"Olimar\'s hp: "<<hp<<"\t\t    |\t\tLocation: "<<location;
    gotoxy(1,1);
}

// move Olimar if a "move" flag is set
int MoveOlimar(int &x,            // current Olimar x pos
               int &y,            // current Olimar y pos
               bool NORTH,        // move up flag
               bool EAST,         // move right flag
               bool SOUTH,        // move down flag
               bool WEST,         // move left flag
               bool PARAM_NORTH,  // current room's move up parameter
               bool PARAM_EAST,   // current room's move right parameter
               bool PARAM_SOUTH,  // current room's move down parameter
               bool PARAM_WEST)   // current room's move left parameter
{
    if (NORTH)
    {
      if (PARAM_NORTH)
       y++;
      else
       return 1;
    }
    else if (EAST)
    {
      if (PARAM_EAST)
       x++;
      else
       return 2;
    }
    else if (SOUTH)
    {
      if (PARAM_SOUTH)
       y--;
      else
       return 3;
    }
    else if (WEST)
    {
      if (PARAM_WEST)
       x--;
      else
       return 4;
    }
    else
     return 0;
}

// checks if user wants to move a direction
bool CheckMoveNorth(const char A[])
{
   if (!strcmp(A,"Move North") || !strcmp(A,"move north") || !strcmp(A,"MOVE NORTH") ||
       !strcmp(A,"Mn") || !strcmp(A,"mn") || !strcmp(A,"MU"))
     return TRUE;
   else
     return FALSE;
}
bool CheckMoveEast(const char A[])
{
   if (!strcmp(A,"Move East") || !strcmp(A,"move east") || !strcmp(A,"MOVE EAST") ||
       !strcmp(A,"Me") || !strcmp(A,"me") || !strcmp(A,"ME"))
     return TRUE;
   else
     return FALSE;
}
bool CheckMoveSouth(const char A[])
{
   if (!strcmp(A,"Move South") || !strcmp(A,"move south") || !strcmp(A,"MOVE SOUTH") ||
       !strcmp(A,"Ms") || !strcmp(A,"ms") || !strcmp(A,"MS"))
     return TRUE;
   else
     return FALSE;
}
bool CheckMoveWest(const char A[])
{
   if (!strcmp(A,"Move West") || !strcmp(A,"move west") || !strcmp(A,"MOVE WEST") ||
       !strcmp(A,"Mw") || !strcmp(A,"mw") || !strcmp(A,"MW"))
     return TRUE;
   else
     return FALSE;
}

// checks if user wants to look in a direction
bool CheckLookNorth(const char A[])
{
   if (!strcmp(A,"Look North") || !strcmp(A,"look north") || !strcmp(A,"LOOK NORTH") ||
       !strcmp(A,"Ln") || !strcmp(A,"ln") || !strcmp(A,"LN"))
     return TRUE;
   else
     return FALSE;
}
bool CheckLookEast(const char A[])
{
   if (!strcmp(A,"Look East") || !strcmp(A,"look east") || !strcmp(A,"LOOK EAST") ||
       !strcmp(A,"Le") || !strcmp(A,"le") || !strcmp(A,"LE"))
     return TRUE;
   else
     return FALSE;
}
bool CheckLookSouth(const char A[])
{
   if (!strcmp(A,"Look South") || !strcmp(A,"look south") || !strcmp(A,"LOOK SOUTH") ||
       !strcmp(A,"Ls") || !strcmp(A,"ls") || !strcmp(A,"LS"))
     return TRUE;
   else
     return FALSE;
}
bool CheckLookWest(const char A[])
{
   if (!strcmp(A,"Look West") || !strcmp(A,"look west") || !strcmp(A,"LOOK WEST") ||
       !strcmp(A,"Lw") || !strcmp(A,"lw") || !strcmp(A,"LW"))
     return TRUE;
   else
     return FALSE;
}
bool CheckLookAround(const char A[])
{
   if (!strcmp(A,"Look Around") || !strcmp(A,"look around") || !strcmp(A,"LOOK AROUND") ||
       !strcmp(A,"Look") || !strcmp(A,"look") || !strcmp(A,"LOOK") ||
       !strcmp(A,"La") || !strcmp(A,"la") || !strcmp(A,"LA"))
     return TRUE;
   else
     return FALSE;
}

// prints story
void PrintStory(char Input[],           // used to get user input
                const char Title[])     // used to print the title
{
    // turn cursor off
    CONSOLE_CURSOR_INFO cci;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleCursorInfo(hConsole, &cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cci);

    Clear();
    cout<<"\n\n\n\n\n\n\n\n\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     | Sometimes you never know what\'s going to happen. |\n";
    cout<<"\t     | Often times you don\'t even know where you are... |\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     ";
    Get(Input);

    Clear();
    cout<<"\n\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     | Olimar Ness is a young boy at the age of         |\n";
    cout<<"\t     | 17, born in Kansas, Idaho.                       |\n";
    cout<<"\t     |                                                  |\n";
    cout<<"\t     | Olimar loves his music.  His favorite kind of    |\n";
    cout<<"\t     | music is the insightful Trance music.  He loves  |\n";
    cout<<"\t     | how it puts him into the thoughtful and creative |\n";
    cout<<"\t     | state that makes his day.  He enjoys other kinds |\n";
    cout<<"\t     | of music too, like Dance music for it\'s \"happy\"  |\n";
    cout<<"\t     | quality and New Age music for it\'s \"peaceful\"    |\n";
    cout<<"\t     | quality.                                         |\n";
    cout<<"\t     |                                                  |\n";
    cout<<"\t     | As for the future, Olimar wants to become a      |\n";
    cout<<"\t     | computer programmer when he grows up.  He\'s      |\n";
    cout<<"\t     | currently writing a game called                  |\n";
    cout<<"\t     | \"Olimar\'s Escape.exe\" but still needs major work.|\n";
    cout<<"\t     | When (if) he completes the game, it will be the  |\n";
    cout<<"\t     | biggest project he has ever finished.  He will be|\n";
    cout<<"\t     | extremely proud of himself after that!  Shasha!  |\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     ";
    Get(Input);

    Clear();
    cout<<"\n\n\n\n\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     | As a break from the usual stay-at-home routine   |\n";
    cout<<"\t     | for Spring Break, Olimar\'s mother was thinking of|\n";
    cout<<"\t     | something a little different this year.  His     |\n";
    cout<<"\t     | mother was tinkering with the idea of taking a   |\n";
    cout<<"\t     | nature walk out in the nearby forest.  Olimar    |\n";
    cout<<"\t     | loves his computer because it gives so much and  |\n";
    cout<<"\t     | asks so little.  So when he heard of this trip he|\n";
    cout<<"\t     | already had an answer - no.  He would then end up|\n";
    cout<<"\t     | going anyway.  Life...                           |\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     ";
    Get(Input);

    Clear();
    cout<<"\n\n\n\n\n\n";
    cout<<"\t     ---------------------------------------------------\n";
    cout<<"\t    | When they arrived at the first tree of the forest,|\n";
    cout<<"\t    | they were astonished by what they saw: tall,      |\n";
    cout<<"\t    | beautiful trees that stretch up limitlessly into  |\n";
    cout<<"\t    | the air, the effulgent smells of scenic flowers,  |\n";
    cout<<"\t    | butterflies that seemed to float in the air.  It  |\n";
    cout<<"\t    | was truly beautiful.  Although not wanting to be  |\n";
    cout<<"\t    | there, Olimar thought it was cool too.            |\n";
    cout<<"\t     ---------------------------------------------------\n";
    cout<<"\t    ";
    Get(Input);

    Clear();
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     | Deeper into the forest they go, burrowing deeper |\n";
    cout<<"\t     | and deeper into the vast fields of nature.       |\n";
    cout<<"\t     |                                                  |\n";
    cout<<"\t     | As they adventure farther and farther, they find |\n";
    cout<<"\t     | a perfect place to rest.  Mom pitches up a tent, |\n";
    cout<<"\t     | and they both go soundly asleep...               |\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     ";
    Get(Input);

    Clear();
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     | \"Not another one\", says a blue-winged bird       |\n";
    cout<<"\t     | pirched on top of Olimar\'s head.  \"I thought     |\n";
    cout<<"\t     | Miggle was the last one!\".                       |\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     ";
    Get(Input);

    Clear();
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     | \"Well it is\", said a golden-winged bird flying   |\n";
    cout<<"\t     | down from a tall tree nearby.  The golden-winged |\n";
    cout<<"\t     | bird pirches himself on Olimar\'s head along side |\n";
    cout<<"\t     | with the blue-winged bird.                       |\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     ";
    Get(Input);

    Clear();
    cout<<"\n\n\n\n\n\n\n\n\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     | \"Do you think it\'ll pass\?\", says the blue-winged |\n";
    cout<<"\t     | bird.                                            |\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     ";
    Get(Input);

    Clear();
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     | \"It doesn\'t look any different than the others.  |\n";
    cout<<"\t     | Oh well.  Another one in a Cell Shack...\".  The  |\n";
    cout<<"\t     | two birds fly away.                              |\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     ";
    Get(Input);

    Clear();
    cout<<"\n\n\n\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     | It is very dark in the forest now - it is night. |\n";
    cout<<"\t     | There is only one light and that if from a small |\n";
    cout<<"\t     | lamp hanging from the side of a door.  A very    |\n";
    cout<<"\t     | large door.                                      |\n";
    cout<<"\t     |                                                  |\n";
    cout<<"\t     | Olimar opens his eyes.  \"Why is my face on the   |\n";
    cout<<"\t     | ground\?\".  Olimar gets up and dusts himself off  |\n";
    cout<<"\t     | frantically as he looks in front of him to find a|\n";
    cout<<"\t     | very large door.  \"This door is more than seven  |\n";
    cout<<"\t     | times my height\", he says calmly to himself as he|\n";
    cout<<"\t     | slowly cranks his head up to the highest point of|\n";
    cout<<"\t     | the door.  He looks behind him to find an        |\n";
    cout<<"\t     | extremely dark forest where you can\'t even see   |\n";
    cout<<"\t     | your own hand.  For some reason, there is no moon|\n";
    cout<<"\t     | out.  \"It\'s cold.\"                               |\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     ";
    Get(Input);

    Clear();
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     | He stays close to the door as he strafes left of |\n";
    cout<<"\t     | the door to find a large doornob.  He stops for a|\n";
    cout<<"\t     | moment, then puts his hands on the cold, metal   |\n";
    cout<<"\t     | doornob and turns it clock-wise.  Suprisingly to |\n";
    cout<<"\t     | himself, the door opens easily.  Eager to get out|\n";
    cout<<"\t     | of darkness, he enters into a long hallway.      |\n";
    cout<<"\t      --------------------------------------------------\n";
    cout<<"\t     ";
    Get(Input);

    // turn cursor back on
    cci.bVisible = TRUE;
    SetConsoleCursorInfo(hConsole, &cci);
}

// shows all commands
void ShowCommands(const int x,          // x position to start printing
                  const int y)          // y position to start printing
{
    gotoxy(x,y);
    cout<<"Commands:\n\n";
    cout<<"commands|help - displays a full list of commands\n";
    cout<<"close|exit - exits the game\n";
    cout<<"move north/east/south/west - moves Olimar the corresponding direction\n";
    cout<<"look north/east/south/west - displays what is in the corresponding direction\n";
    cout<<"look around|look - displays everything in the current room\n";
    cout<<"show stats|stats - displays Olimar\'s stats\n";
    cout<<"show map|view map|map - displays the map\n";
}

// shows all battle commands
void ShowBattleCommands()
{
    cout<<"\nBattle Commands:\n\n";
    cout<<"commands|help - dislplays the full list of battle commands\n";
    cout<<"close|exit - exits the game\n";
    cout<<"attack - attacks enemy with the currently equiped weapon\n";
    cout<<"defend - defends against an enemy attack for one turn\n";
}

// shows Olimar's stats
void ShowStats(const int x,             // x position to start printing
               const int y,             // y position to start printing
               const int level,         // Olimar's current level
               const int exp,           // Olimar's current experience points
               const int next,          // Olimar's experience points until next level
               const int hp,            // Olimar's current hit points
               const int att,           // Olimar's current attack points
               const int def)           // Olimar's current defense points
{
    gotoxy(x,y);
    cout<<"Stats:\n\n";
    cout<<"Level:       "<<level<<"\n";
    cout<<"Experience:  "<<exp<<"\n";
    cout<<"Next level:  "<<next<<"\n";
    cout<<"HP:          "<<hp<<"\n";
    cout<<"Attack:      "<<att<<"\n";
    cout<<"Defense:     "<<def<<"\n";
}

// shows map
void ShowMap(const int x,               // x position to start printing
             const int y,               // y position to start printing
             const int RoomID,          // the current rooms id
             const int ox,              // Olimar's x position
             const int oy)              // Olimar's y position
{
    switch (RoomID)
    {
      case 0:  // map of "Hallway"
      {
         gotoxy(x,y);
         cout<<"\n\n\n";
         cout<<"\t\t\t\t   _ _ _ _ _\n";
         cout<<"\t\t\t\t0 |_|_|_|_|_|\n";
         cout<<"\t\t\t\t   0 1 2 3 4\n";
         cout<<"\n\t\t\t      I am in cell ("<<ox<<","<<oy<<").";
      } break;
      case 1:  // map of "Meeting Room"
      {
         gotoxy(x,y);
         cout<<"\n\n\n";
         cout<<"\t\t\t\t      _ _ _\n";
         cout<<"\t\t\t\t   2 |_|_|_|\n";
         cout<<"\t\t\t\t   1 |_|_|_|\n";
         cout<<"\t\t\t\t   0 |_|_|_|\n";
         cout<<"\t\t\t\t      0 1 2\n";
         cout<<"\n\t\t\t       I am in cell ("<<ox<<","<<oy<<").";
      } break;
      case 2:
      {
         gotoxy(x,y);
         cout<<"\t\t     _________________________________________\n";
         cout<<"\t\t  9 |    _|     |       |        _ _     _ _ _|\n";
         cout<<"\t\t  8 |  _|       |_      |      _|   |_  |_    |\n";
         cout<<"\t\t  7 |_|  _        |_   _|     |    _ _|   |   |\n";
         cout<<"\t\t  6 |   |_|    _    |_|    _ _|   |       |_ _|\n";
         cout<<"\t\t  5 |         | |_        |    _ _|           |\n";
         cout<<"\t\t  4 |         |_  |_      |_ _|    _          |\n";
         cout<<"\t\t  3 |           |   |_         _ _| |_        |\n";
         cout<<"\t\t  2 |_   _ _    |_ _ _|      _|       |    _ _|\n";
         cout<<"\t\t  1 | |_|   |_             _|         |  _|   |\n";
         cout<<"\t\t  0 |_________|___________|+|_________|_|_ _ _|\n\n";
         cout<<"\t\t     0 1 2 3 4 5 6 7 8 9  11  13  15  17  19\n";
         cout<<"\t\t                        10  12  14  16  18  20\n";
         cout<<"\n\t\t\t    I am in cell ("<<ox<<","<<oy<<").";
      } break;
    }
}

// perform procedures to open a door
int OpenDoor(const int x, const int y, const int NORTH, const int EAST, const int SOUTH, const int WEST)
{
    if (NORTH)    // check NORTH
    {
       if (room[RoomNum].param.is_door_north)
       {
          if (room[RoomNum].param.door_north_key)
          {
             for (index=0; index<5; index++)
             {
                if (Olimar.keys[index] == room[RoomNum].param.key)
                {
                  room[RoomNum].param.door_north = TRUE;
                  gotoxy(x,y);
                  cout<<"The door to the north has been opened.";
                  Get(BackInput);
                  return (0);
                }
                else
                {
                  gotoxy(x,y);
                  cout<<"I need a specific key to open this door.";
                  Get(BackInput);
                  return (0);
                }
             }
          }
          else
          {
             room[RoomNum].param.door_north = TRUE;
             gotoxy(x,y);
             cout<<"The door to the north has been opened.";
             Get(BackInput);
             return (0);
          }
       }
       else
       {
          gotoxy(x,y);
          cout<<"There is no door to the north.";
          Get(BackInput);
          return (0);
       }
    }
    if (EAST)     // check EAST
    {
       if (room[RoomNum].param.is_door_east)
       {
          if (room[RoomNum].param.door_east_key)
          {
             for (index=0; index<5; index++)
             {
                if (Olimar.keys[index] == room[RoomNum].param.key)
                {
                  room[RoomNum].param.door_east = TRUE;
                  gotoxy(x,y);
                  cout<<"The door to the east has been opened.";
                  Get(BackInput);
                  return (0);
                }
                else
                {
                  gotoxy(x,y);
                  cout<<"I need a specific key to open this door.";
                  Get(BackInput);
                  return (0);
                }
             }
          }
          else
          {
             room[RoomNum].param.door_east = TRUE;
             gotoxy(x,y);
             cout<<"The door to the east has been opened.";
             Get(BackInput);
             return (0);
          }
       }
       else
       {
          gotoxy(x,y);
          cout<<"There is no door to the east.";
          Get(BackInput);
          return (0);
       }
    }
    if (SOUTH)     // check SOUTH
    {
       if (room[RoomNum].param.is_door_south)
       {
          if (room[RoomNum].param.door_south_key)
          {
             for (index=0; index<5; index++)
             {
                if (Olimar.keys[index] == room[RoomNum].param.key)
                {
                  room[RoomNum].param.door_south = TRUE;
                  gotoxy(x,y);
                  cout<<"The door to the south has been opened.";
                  Get(BackInput);
                  return (0);
                }
                else
                {
                  gotoxy(x,y);
                  cout<<"I need a specific key to open this door.";
                  Get(BackInput);
                  return (0);
                }
             }
          }
          else
          {
             room[RoomNum].param.door_south = TRUE;
             gotoxy(x,y);
             cout<<"The door to the south has been opened.";
             Get(BackInput);
             return (0);
          }
       }
       else
       {
          gotoxy(x,y);
          cout<<"\n\n--------------------------------------\n";
          cout<<"There is no door to the south.";
          Get(BackInput);
          return (0);
       }
    }
    if (WEST)     // check WEST
    {
       if (room[RoomNum].param.is_door_west)
       {
          if (room[RoomNum].param.door_west_key)
          {
             for (index=0; index<5; index++)
             {
                if (Olimar.keys[index] == room[RoomNum].param.key)
                {
                  room[RoomNum].param.door_west = TRUE;
                  gotoxy(x,y);
                  cout<<"The door to the west has been opened.";
                  Get(BackInput);
                  return (0);
                }
                else
                {
                  gotoxy(x,y);
                  cout<<"I need a specific key to open this door.";
                  Get(BackInput);
                  return (0);
                }
             }
          }
          else
          {
             room[RoomNum].param.door_west = TRUE;
             gotoxy(x,y);
             cout<<"The door to the west has been opened.";
             Get(BackInput);
             return (0);
          }
       }
       else
       {
          gotoxy(x,y);
          cout<<"There is no door to the west.";
          Get(BackInput);
          return (0);
       }
    }
}

// talk to someone based on talk flags
int Talk(const int NORTH, const int EAST, const int SOUTH, const int WEST)
{
    if (NORTH)
    {
       if (room[RoomNum].param.is_person_north)
       {

       }
       else
       {

       }
    }
}

