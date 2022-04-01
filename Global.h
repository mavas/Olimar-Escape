// *********************************************************************
// Programming: mavas
// Project: Olimar's Escape.exe
// Project desc: A text-based RPG for the PC.
// File: Global.h
// *********************************************************************
////////////////////////////////////////////////////////////////////////

// *********************************************************************
// - Global variables -
// *********************************************************************
const char Title[] = "Olimar\'s Escape\n---------------\n";
const char BattleTitle[] = "\n----------------------------------Battle Mode----------------------------------\n";
char Input[101];                 // user input
char BackInput[101];             // extra place for user input
int index=0;                     // looping variable
int RoomNum=0;                   // holds current room number
int Rem=0;                       // used to remember last room number
int Rand1=0, Rand2=0;            // used to hold random numbers
int j=0, w=0;                    // helper numbers

// flags
int MNORTH=0;                    // if user moves a direction
int MSOUTH=0;                    //
int MWEST=0;                     //
int MEAST=0;                     //
int LNORTH=0;                    // if user looks in a direction
int LSOUTH=0;                    //
int LWEST=0;                     //
int LEAST=0;                     //
int LAROUND=0;                   //
int ODNORTH=0;                   // if user wants to open a door
int ODEAST=0;                    //
int ODSOUTH=0;                   //
int ODWEST=0;                    //
int TNORTH=0;                    // talk flags...
int TEAST=0;                     //
int TSOUTH=0;                    //
int TWEST=0;                     //
int NEWROOM=0;                   // new room flag
int BATTLE=0;                    // battle flag


// *********************************************************************
// - Global functions -
// *********************************************************************
// Kameko's conversations
void Kameko_1()
{
   Clear();
   cout<<"Hello there!";
}

