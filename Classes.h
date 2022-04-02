// *********************************************************************
// Programming: mavas
// Project: Olimar's Escape.exe
// Project desc: A text-based RPG for the PC.
// File: Classes.h
// *********************************************************************
////////////////////////////////////////////////////////////////////////

// *********************************************************************
// - Classes -
// *********************************************************************
// CLASS: Enemy ////////////////////////////////////////////////////////
class CEnemy
{
  public:
   char *name;                   // enemy name
   int level;                    // enemy level
   int exp;                      // experience awarded after battle
   int hp;                       // enemy hit points
   int att;                      // enemy attack points
   int def;                      // enemy defense points
   int stats[1];                 // enemy initial stats
   void Revive();                // restore enemy after battle
   CEnemy();                     // class constructor
} Golem, Smarts, Skizza, Blue_Wizard, Red_Wizard, *Enemy;

CEnemy::CEnemy()
{
    // initialize all variables to 0
    name=NULL;
    level=0; exp=0;
    hp=0;    att=0;
    def=0;   Enemy=NULL;
}

void CEnemy::Revive()
{
    hp = stats[0];
}

// CLASS: CRoom ///////////////////////////////////////////////////////
class CRoom
{
  public:
   char *title;                        // room title
   int x;                              // room index
   int y;                              // room index
   int id;                             // room ID
   int numrooms;                       // number of rooms in section

   // room parameters
   struct Params
   {
       // if Olimar can move here
       bool north, south, west, east;
       // collision descriptions
       char *no_north, *no_south, *no_west, *no_east, *no_deflt;

       // door key
       int key;

       // if key is needed
       bool door_north_key, door_east_key, door_south_key, door_west_key;
       // if there is a door
       bool is_door_north, is_door_east, is_door_south, is_door_west;
       // if door is open
       bool door_north, door_east, door_south, door_west;

       // if there is a person to talk to
       bool is_person_north, is_person_east, is_person_south, is_person_west;
   } param;

   bool first;                         // fist time entering this room
   int enemynum;                       // number of different enemies to pick from
   int chance;                         // room's chances of getting a battle
   int enemy1, enemy2, enemy3, enemy4, // room's enemies to choose from
       enemy5;                         //
   char *north, *south, *west, *east,  // specific room descriptions
        *around;                       //
   CRoom();                            // class constructor
} Hallway[5], Meeting_Room[9], Junk_Yard[210], *room;

CRoom::CRoom()
{
   // initialize all variables to 0
   title = NULL;
   x=0;                        y=0;
   enemynum=0;                 chance=0;
   enemy1=0;                   enemy2=0;
   enemy3=0;                   enemy4=0;
   enemy5=0;                   id=0;
   north=NULL;                 south=NULL;
   west=NULL;                  east=NULL;
   around=NULL;                room=NULL;
   param.north=FALSE;          param.south=FALSE;
   param.west=FALSE;           param.east=FALSE;
   param.no_north=NULL;        param.no_east=NULL;
   param.no_south=NULL;        param.no_west=NULL;
   param.door_north_key=FALSE; param.door_east_key=FALSE;
   param.door_south_key=FALSE; param.door_west_key=FALSE;
   param.is_door_north=FALSE;  param.is_door_east=FALSE;
   param.is_door_south=FALSE;  param.is_door_west=FALSE;
   param.door_north=FALSE;     param.door_east=FALSE;
   param.door_south=FALSE;     param.door_west=FALSE;
   param.key=0;                param.no_deflt=NULL;
   room=NULL;                  first=FALSE;
}

// CLASS: Olimar ///////////////////////////////////////////////////////
class COlimar
{
  public:
   int x;                              // Olimar's pos
   int y;                              // Olimar's pos
   int level;                          // Olimar's level
   int exp;                            // Olimar's experience
   int next;                           // number of exp points west to level up
   int hp;                             // Olimar's hit points
   int att;                            // Olimar's attack points
   int def;                            // Olimar's defense points
   int keys[4];                        // Olimar's keys
   COlimar();                          // class constructor
} Olimar;

COlimar::COlimar()
{
   // initialize all variables to 0
   x=0;      y=0;
   level=0;  exp=0;
   next=0;   hp=0;
   att=0;    def=0;
}

// CLASS: Characters ///////////////////////////////////////////////////
class CCharacters
{
  public:
   char *name;                         // character's name
   void Kameko_1();
   CCharacters();                      // class constructor
} Kameko;

CCharacters::CCharacters()
{
   name=NULL;
}

