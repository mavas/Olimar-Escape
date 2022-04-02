// *********************************************************************
// Project: Olimar's Escape.exe
// Project desc: A text-based RPG for the PC.
// File: Main.cpp
// *********************************************************************
////////////////////////////////////////////////////////////////////////

// *********************************************************************
// - Includes -
// *********************************************************************
#include <iostream.h>          // <- console functions.
#include <stdlib.h>            // <- help generate random numbers
#include <time.h>              // <- get current time and generate
                               //    random numbers.
#include <windows.h>           // <- used to clear the screen.
#include <conio.c>             // <- used for "gotoxy()" function
#include "Kitchen.h"           // <- contains house-cleaning functions.
#include "Classes.h"           // <- contains all class declarations
#include "Global.h"            // <- contains all global variables
#include "Initialize.h"        // <- initializes rooms
#include "Engine.h"            // <- processes information.


// *********************************************************************
// - Prototypes -
// *********************************************************************
void Look();
void Game_Init();
void Game_Main();
//void Game_Shutdown();


// *********************************************************************
// - Begin Program -
// *********************************************************************
int main()
{
    // set console title
    SetConsoleTitle("Olimar\'s Escape.exe");

    // declare stuff
    time_t now;
    time(&now);

    // prompt user with beginning screen
    Clear();
    cout<<Title;
    cout<<"\n\n\n\n\t\tOlimar\'s Escape";
    cout<<"\n\t\tProgramming: Olimar Ness";
    cout<<"\n\n\t\tCurrent time: "<<ctime(&now);
    cout<<"\n\n\n\t\tPress [Enter] to continue...";
    Get(Input);

    // ask if user wants to see story
    Clear();
    cout<<Title;
    cout<<"\n\n\n\n\t\tDo you want to view the story\? ";
    Get(Input);

    if (!strcmp(Input,"Yes") || !strcmp(Input,"yes") || !strcmp(Input,"YES"))
     PrintStory(Input, Title);

    // allocate and initialize variables
    Game_Init();

    // enter main game processing loop
    while(1)
     Game_Main();

    return (0);
}


// *********************************************************************
// - Support functions -
// *********************************************************************
// print description if a "look" flag is set
void Look(const int x,                  // x position to start printing
          const int y)                  // y position to start printing
{
    if (LNORTH)
    {
       gotoxy(x,y);
       if (room[RoomNum].north!=NULL)
        cout<<room[RoomNum].north;
       else
        cout<<"(Space to walk)";
    }
    else if (LSOUTH)
    {
       gotoxy(x,y);
       if (room[RoomNum].south!=NULL)
        cout<<room[RoomNum].south;
       else
        cout<<"(Space to walk)";
    }
    else if (LWEST)
    {
       gotoxy(x,y);
       if (room[RoomNum].west!=NULL)
        cout<<room[RoomNum].west;
       else
        cout<<"(Space to walk)";
    }
    else if (LEAST)
    {
       gotoxy(x,y);
       if (room[RoomNum].east!=NULL)
        cout<<room[RoomNum].east;
       else
        cout<<"(Space to walk)";
    }
    else if (LAROUND)
    {
       gotoxy(x,y);
       if (room[RoomNum].around!=NULL)
        cout<<room[RoomNum].around;
       else
        cout<<"(Nothing to display)";
    }
}

// Olimar died
void OlimarDied()
{}
// the enemy died
void EnemyDied()
{
    // print results
    Clear();
    cout<<Title<<BattleTitle;

    cout<<"\nI won the battle!\n\n";
    Get(Input);
}

// attack enemy
void Attack(CEnemy *Enemy)
{
    // decrease enemy's health based on Olimar's attack points
    Enemy->hp -= (Olimar.att - Enemy->def);

    // print results
    cout<<"\n\t\t      ------------------------------------\n\n";
    cout<<" + I attacked "<<Enemy->name<<" for "<<Olimar.att<<" hit point(s).";
}

// battle mode function
int BattleMode()
{
    // pick a random enemy in the current room
    Rand1 = rand()%room[RoomNum].enemynum+1;

    if (Rand1 == 1)
    {
      switch (room[RoomNum].enemy1)
      {
        case 0: Enemy = &Golem; break;
        case 1: Enemy = &Smarts; break;
        case 2: Enemy = &Skizza; break;
        case 3: Enemy = &Blue_Wizard; break;
        case 4: Enemy = &Red_Wizard; break;
        default: return (0);
      }
    }
    else if (Rand1 == 2)
    {
      switch (room[RoomNum].enemy2)
      {
        case 0: Enemy = &Golem; break;
        case 1: Enemy = &Smarts; break;
        case 2: Enemy = &Skizza; break;
        case 3: Enemy = &Blue_Wizard; break;
        case 4: Enemy = &Red_Wizard; break;
        default: return (0);
      }
    }
    else if (Rand1 == 3)
    {
      switch (room[RoomNum].enemy3)
      {
        case 0: Enemy = &Golem; break;
        case 1: Enemy = &Smarts; break;
        case 2: Enemy = &Skizza; break;
        case 3: Enemy = &Blue_Wizard; break;
        case 4: Enemy = &Red_Wizard; break;
        default: return (0);
      }
    }
    else if (Rand1 == 4)
    {
      switch (room[RoomNum].enemy4)
      {
        case 0: Enemy = &Golem; break;
        case 1: Enemy = &Smarts; break;
        case 2: Enemy = &Skizza; break;
        case 3: Enemy = &Blue_Wizard; break;
        case 4: Enemy = &Red_Wizard; break;
        default: return (0);
      }
    }
    else if (Rand1 == 5)
    {
      switch (room[RoomNum].enemy5)
      {
        case 0: Enemy = &Golem; break;
        case 1: Enemy = &Smarts; break;
        case 2: Enemy = &Skizza; break;
        case 3: Enemy = &Blue_Wizard; break;
        case 4: Enemy = &Red_Wizard; break;
        default: return (0);
      }
    }

    // enter battle loop
    while (1)
    {
        Clear();
        cout<<Title<<BattleTitle;

        // check if Olimar or the enemy is dead
        if (Olimar.hp<=0)
          OlimarDied();
        else if (Enemy->hp<=0)
        {
          EnemyDied();
          break;
        }

        // print the name of the enemy
        cout<<"\t\t\t    You are fighting: "<<Enemy->name<<"\n";

        // print Olimar's hp and enemy's hp
        cout<<"   Olimar\'s HP: "<<Olimar.hp;
        cout<<"\t\t\t\t\t  "<<Enemy->name<<"\'s HP: "<<Enemy->hp<<"\n";

        // get input from user
        cout<<"\nBattle Command: ";
        Get(Input);

        // process input...

        // if user wants a list of all the battle commands
        if (CheckShowCommands(Input))
        {
          Clear();
          cout<<Title<<BattleTitle;
          ShowBattleCommands();
          Get(Input);
        }

        // if user wants to attack
        if (CheckOlimarAttack(Input))
        {
          Attack(Enemy);
          Get(Input);
        }
    }

    // revive enemy and release pointer
    Enemy->Revive();
    Enemy = NULL;
}

// change rooms if Olimar moves into a new room
void CheckChangeRoom(const int ID, int &RoomNum, const bool NORTH, const bool EAST, const bool SOUTH, const bool WEST)
{
    switch (ID)
    {
      case 0:    // "Hallway" -> "Meeting Room"
      {
        if ((RoomNum==4) && (EAST) && (room[RoomNum].param.door_east))
        {
          MEAST = FALSE;
          room[RoomNum].param.door_east = FALSE;
          room = Meeting_Room;
          RoomNum = 3;
          Olimar.x = 0;
          Olimar.y = 1;
        }
      } break;
      case 1:    // "Meeting Room" -> "Hallway"
      {
        if ((RoomNum==3) && (WEST) && (room[RoomNum].param.door_west))
        {
          MWEST = FALSE;
          room[RoomNum].param.door_west = FALSE;
          room = Hallway;
          RoomNum = 4;
          Olimar.x = 4;
          Olimar.y = 0;
        }
      } break;
    }
}

// *********************************************************************
// - Game console functions -
// *********************************************************************
// allocate and initialize variables
void Game_Init()
{
    // initialize "Hallway"
    Init_Hallway();

    // initialize "Meeting Room"
    Init_Meeting_Room();

    // initialize "Junk Yard"
    Init_Junk_Yard();

    // set beginning room
    room = Hallway;

    // set beginning room number
    RoomNum = 0;

    // initialize Olimar data
    Olimar.x     = 0;
    Olimar.y     = 0;
    Olimar.level = 1;
    Olimar.exp   = 0;
    Olimar.next  = 100;
    Olimar.hp    = 100;
    Olimar.att   = 1;
    Olimar.def   = 1;

    // initialize Olimar's keys
    for (index=0; index<5; index++)
     Olimar.keys[index] = 0;
}

// main game processing
void Game_Main()
{
    // remember last room number
    Rem = RoomNum;

    // get current room number
    for (index=0; index<room[RoomNum].numrooms; index++)
    {
       if ((room[index].x == Olimar.x) && (room[index].y == Olimar.y))
       {
         RoomNum = index;
         break;
       }
    }

    // check if this is a new room
    if (Rem!=RoomNum)
     NEWROOM = 1;

    // check if there is an enemy to battle
    if (NEWROOM)
    {
       // initialize random number generator
       srand(time(NULL));

       // generate random number
       Rand1 = (rand()%10) + 1;

       // see if there is a chance
       if (Rand1<=room[RoomNum].chance)
       {
          Clear();
          BATTLE=1;
          cout<<"\n\n\n\t\t\tBATTLE!!!!!!";
          Get(BackInput);
       }
    }

    // enter battle mode if "battle" flag is set
    if (BATTLE)
     BattleMode();

    // get input from user
    Clear();
    ShowMap(1, 7, room[RoomNum].id, Olimar.x, Olimar.y);
    WriteSummary(Olimar.hp, room[RoomNum].title);
    gotoxy(1,1);
    cout<<Title;
    cout<<"\n"<<RoomNum<<" "<<room[RoomNum].title<<" ("<<Olimar.x<<", "<<Olimar.y<<")";
    cout<<"\nCommand> ";
    Get(Input);

    // process Input...

    // if user wants to show the commands
    if (CheckShowCommands(Input))
    {
      ShowCommands(1, 7);
      Get(BackInput);
    }

    // if user wants to show Olimar's stats
    if (CheckShowStats(Input))
    {
      ShowStats(1, 7, Olimar.level, Olimar.exp, Olimar.next, Olimar.hp, Olimar.att, Olimar.def);
      Get(BackInput);
    }

    // if user wants to show the map
    if (CheckShowMap(Input))
    {
      ShowMap(1, 7, room[RoomNum].id, Olimar.x, Olimar.y);
      Get(BackInput);
    }

    // check if user wants to talk
    if (CheckTalkNorth(Input))
      TNORTH = 1;
    if (CheckTalkEast(Input))
      TEAST = 1;
    if (CheckTalkSouth(Input))
      TSOUTH = 1;
    if (CheckTalkWest(Input))
      TWEST = 1;

    // talk to someone based on talk flags
    Talk(TNORTH, TEAST, TSOUTH, TWEST);

    // set "move" flags based on user input
    if (CheckMoveNorth(Input))           // move north...
      MNORTH = 1;
    else if (CheckMoveEast(Input))       // move east...
      MEAST = 1;
    else if (CheckMoveSouth(Input))      // move south...
      MSOUTH = 1;
    else if (CheckMoveWest(Input))       // move west...
      MWEST = 1;

    // check if user wants to open a door
    if(CheckOpenDoorNorth(Input))
      ODNORTH = 1;
    if(CheckOpenDoorEast(Input))
      ODEAST = 1;
    if(CheckOpenDoorSouth(Input))
      ODSOUTH = 1;
    if(CheckOpenDoorWest(Input))
      ODWEST = 1;

    // perform procedures to open a door
    OpenDoor(1, 7, ODNORTH, ODEAST, ODSOUTH, ODWEST);

    // change rooms if Olimar moves into a new room
    CheckChangeRoom(room[RoomNum].id, RoomNum, MNORTH, MEAST, MSOUTH, MWEST);

    // move Olimar based on the "move" flags and "move" parameters
    switch (MoveOlimar(Olimar.x, Olimar.y, MNORTH, MEAST, MSOUTH, MWEST, room[RoomNum].param.north, room[RoomNum].param.east, room[RoomNum].param.south, room[RoomNum].param.west))
    {
      case 1:
      {
        Clear();
        cout<<Title;
        if (room[RoomNum].param.no_north)
         cout<<"\n\n\t"<<room[RoomNum].param.no_north;
        else
         cout<<"\n\n\t"<<room[RoomNum].param.no_deflt;
        Get(BackInput);
      } break;
      case 2:
      {
        Clear();
        cout<<Title;
        if (room[RoomNum].param.no_east)
         cout<<"\n\n\t"<<room[RoomNum].param.no_east;
        else
         cout<<"\n\n\t"<<room[RoomNum].param.no_deflt;
        Get(BackInput);
      } break;
      case 3:
      {
        Clear();
        cout<<Title;
        if (room[RoomNum].param.no_south)
         cout<<"\n\n\t"<<room[RoomNum].param.no_south;
        else
         cout<<"\n\n\t"<<room[RoomNum].param.no_deflt;
        Get(BackInput);
      } break;
      case 4:
      {
        Clear();
        cout<<Title;
        if (room[RoomNum].param.no_west)
         cout<<"\n\n\t"<<room[RoomNum].param.no_west;
        else
         cout<<"\n\n\t"<<room[RoomNum].param.no_deflt;
        Get(BackInput);
      } break;
    }

    // set "look" flags based on user input
    if (CheckLookNorth(Input))           // look north...
      LNORTH = 1;
    else if (CheckLookEast(Input))       // look east...
      LEAST = 1;
    else if (CheckLookSouth(Input))      // look south...
      LSOUTH = 1;
    else if (CheckLookWest(Input))       // look west...
      LWEST = 1;
    else if (CheckLookAround(Input))     // look around...
      LAROUND = 1;

    // write room description based on "look" flags
    if (LNORTH||LEAST||LSOUTH||LWEST||LAROUND)
    {
      Look(1,7);
      Get(BackInput);
    }

    // reset flags
    MNORTH=0;           // move flags...
    MEAST=0;           //
    MSOUTH=0;         //
    MWEST=0;         //
    LNORTH=0;            // look flags...
    LSOUTH=0;           //
    LWEST=0;           //
    LEAST=0;          //
    LAROUND=0;       //
    ODNORTH=0;          // open door flags...
    ODEAST=0;          //
    ODSOUTH=0;        //
    ODWEST=0;        //
    TNORTH=0;           // talk flags...
    TEAST=0;           //
    TSOUTH=0;         //
    TWEST=0;         //
    NEWROOM=0;       // new room flag
    BATTLE=0;        // battle flag
}

