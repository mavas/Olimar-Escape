// *********************************************************************
// Project: Olimar's Escape.exe
// Project desc: A text-based RPG for the PC.
// File: Initialize.h
// *********************************************************************
////////////////////////////////////////////////////////////////////////

// initialize "Hallway"
void Init_Hallway()
{
    // INITIALIZE "Hallway"
    room = Hallway;

    // set room IDs
    for (index=0; index<5; index++)
     room[index].id = 0;

    // set room indexes
    for (index=0, w=0; index<5; index++, w++)
    {
       room[index].x = w;
       room[index].y = 0;
    }

    // set room titles
    for (index=0; index<5; index++)
     room[index].title = "Hallway";

    // set number of rooms in section
    for (index=0; index<5; index++)
     room[index].numrooms = 5;

    // set room descriptions
    for (index=0; index<5; index++)
    {
      if (index == 0)
      {
        room[0].north  = "There is a small lantern hanging on the wall.";
        room[0].south  = "There is a small lantern hanging on the wall.";
        continue;
      }
      if (index == 4)
      {
        room[4].north  = "There is a small lantern hanging on the wall.";
        room[4].south  = "There is a small lantern hanging on the wall.";
        continue;
      }
      room[index].north  = "There is a small lantern hanging on the wall.";
      room[index].south  = "There is a small lantern hanging on the wall.";
      room[index].around = "I am in a hallway.";
    }

    // set room default collision description
    for (index=0; index<5; index++)
     room[index].param.no_deflt = "I can\'t move there because there is a wall.";

    // set room move parameters
    room[0].param.east = TRUE;
    room[1].param.west = TRUE;
    room[1].param.east = TRUE;
    room[2].param.west = TRUE;
    room[2].param.east = TRUE;
    room[3].param.west = TRUE;
    room[3].param.east = TRUE;
    room[4].param.west = TRUE;

    // set some room descriptions
    room[0].west   = "The large door I came in from.";
    room[0].around = "I\'m in a hallway.  There are lamps hanging on the walls to the\nnorth and south.  To the west is the door I came in from.";
    room[4].east   = "There is a smaller, wooden door.";
    room[4].around = "I am in a hallway.  There are lamps hanging on the walls the\n\tnorth and south.  To the east is a door.";
    room[0].param.no_west = "Olimar:\n\t\"I can\'t go back out there.\"";
    room[4].param.no_east = "There is a door I must open.";

    // set doors
    room[4].param.is_door_east = TRUE;

    // set keys
    room[4].param.door_east_key = TRUE;
}

// initialize "Meeting Room"
void Init_Meeting_Room()
{
    // INITIALIZE "Meeting_Room"
    room = Meeting_Room;

    // set room IDs
    for (index=0; index<9; index++)
     room[index].id = 1;

    // set room indexes
    for (index=0, j=0, w=2; index<9; index++)
    {
       room[index].x = j;
       room[index].y = w;
       j++;
       if (j==3)
       {
          w--;
          j=0;
       }
    }

    // set room titles
    for (index=0; index<9; index++)
     room[index].title = "Meeting Room";

    // set number of rooms in section
    for (index=0; index<9; index++)
     room[index].numrooms = 9;

    // set room default collision description
    for (index=0; index<9; index++)
     room[index].param.no_deflt = "I can\'t move that way because there is a wall.";

    // set room move parameters
    room[0].param.east  = TRUE;
    room[0].param.south = TRUE;
    room[1].param.east  = TRUE;
    room[1].param.south = TRUE;
    room[1].param.west  = TRUE;
    room[2].param.south = TRUE;
    room[2].param.west  = TRUE;
    room[3].param.north = TRUE;
    room[3].param.east  = TRUE;
    room[3].param.south = TRUE;
    room[4].param.north = TRUE;
    room[4].param.east  = TRUE;
    room[4].param.south = TRUE;
    room[4].param.west  = TRUE;
    room[5].param.north = TRUE;
    room[5].param.south = TRUE;
    room[5].param.west  = TRUE;
    room[6].param.north = TRUE;
    room[6].param.east  = TRUE;
    room[7].param.north = TRUE;
    room[7].param.east  = TRUE;
    room[7].param.west  = TRUE;
    room[8].param.north = TRUE;
    room[8].param.west  = TRUE;

    // set room move parameter descriptions
    room[0].param.no_north = "I can\'t move north because there\'s a wall in my way.";
    room[0].param.no_west  = "I can\'t move west because there is a wall.";
    room[1].param.no_north = "I can\'t move north because there is a wall.";
    room[2].param.no_north = "I can\'t move north because there is a wall.";
    room[2].param.no_east  = "I don\'t want to step all over the table.";
    room[3].param.no_west  = "There is a door I have to open.";
    room[5].param.no_east  = "I can\'t move east because there\'s a wall in my way.";
    room[6].param.no_south = "I can\'t move south because there is a wall.";
    room[6].param.no_west  = "I can\'t move west because there is a wall.";
    room[7].param.no_south = "I can\'t move south because there is a wall.";
    room[8].param.no_east  = "I can\'t move east because there is a wall.";
    room[8].param.no_south = "I can\'t move south because there is a wall.";

    // set some room descriptions
    room[0].north  = "There is a wall with a small lantern hanging.";
    room[0].west   = "There is a half-circle shaped window.  I just see over the bottom of it.  It\'s still very dark out in the forest.";
    room[0].around = "There is a lantern on the wall to the north and a window to the west.";
    room[1].north  = "There is a wall.";
    room[1].around = "There is a wall to the north.";
    room[2].north  = "There is a wall.";
    room[2].east   = "There is a wooden desk leaned up against the wall.  It has a tin cup on the left\nside and a set of playing cards stacked in the center.  There is also a metal\nchair.";
    room[2].around = "There is a wall to the north and a wooden desk to the east.";
    room[3].west   = "There is the door I came in from.";
    room[3].around = "There is a wall to the west.";
    room[5].east   = "There is a hand-drawn picture of a beautiful, pink flower hanging from the wall in a picture frame.";
    room[5].around = "There is a picture of something to the east.";
    room[6].east   = "There is a wall.";
    room[6].south  = "There is a wall with a small lantern hanging.";
    room[6].around = "There is a wall to the east and a lantern on the wall to the south.";
    room[7].south  = "There is a wooden door here.";
    room[7].around = "There is a door to the south.";
    room[8].east   = "There is a wall.";
    room[8].south  = "There is a small, tin bucket here.";
    room[8].around = "There is a wall to the east and a bucket to the south.";

    // set doors
    room[3].param.is_door_west = TRUE;

    // set keys
    room[3].param.door_west_key = TRUE;
}

// initialize "Junk Yard"
void Init_Junk_Yard()
{
    // INITIALIZE "Junk Yard"
    room = Junk_Yard;

    // set number of rooms
    for (index=0; index<210; index++)
     room[index].numrooms = 210;

    // initialize room IDs
    for (index=0; index<room[0].numrooms; index++)
     room[index].id = 2;

    // initialize room indexes
    for (index=0, j=0, w=9; index<room[0].numrooms; index++)
    {
       room[index].x = j;
       room[index].y = w;
       j++;
       if (j==21)
       {
          w--;
          j=0;
       }
    }

    // set room titles
    for (index=0; index<room[0].numrooms; index++)
     room[index].title = "Junk Yard";

    // set default room description
    for (index=0; index<room[0].numrooms; index++)
     room[index].param.no_deflt = "I can\'t move into that pile of junk.";

    // set default room parameters
    for (index=0; index<room[0].numrooms; index++)
    {
       room[index].param.north = TRUE;
       room[index].param.east  = TRUE;
       room[index].param.south = TRUE;
       room[index].param.west  = TRUE;
    }

    // set room parameters

    // set north room parameters
    for (index=0; index<21; index++)
     room[index].param.north = FALSE;

    // set east room parameters (for cells (x,0))
    for (index=0, w=0; index<10; index++, w++)
    {
      for (j=0; j<room[0].numrooms; j++)
        if ( (room[j].x==20) && (room[j].y==w) )
         break;

      room[j].param.east = FALSE;
    }

    // set west room parameters (for cells (0,x))
    for (index=0, w=0; index<10; index++, w++)
    {
      for (j=0; j<room[0].numrooms; j++)
        if ( (room[j].x==0) && (room[j].y==w) )
         break;

      room[j].param.west = FALSE;
    }

    // set south room parameters
    for (index=189; index<room[0].numrooms; index++)
     room[index].param.south = FALSE;

   // set individual move parameters
   room[3].param.west    = FALSE;      //
   room[5].param.east    = FALSE;
   room[10].param.west   = FALSE;
   room[14].param.south  = FALSE;
   room[15].param.south  = FALSE;
   room[18].param.south  = FALSE;
   room[19].param.south  = FALSE;
   room[20].param.south  = FALSE;
   room[23].param.north  = FALSE;      //
   room[23].param.west   = FALSE;
   room[26].param.east   = FALSE;
   room[31].param.west   = FALSE;
   room[34].param.east   = FALSE;
   room[34].param.south  = FALSE;
   room[37].param.south  = FALSE;
   room[37].param.west   = FALSE;
   room[38].param.east   = FALSE;
   room[43].param.north  = FALSE;      //
   room[43].param.west   = FALSE;
   room[48].param.north  = FALSE;
   room[48].param.east   = FALSE;
   room[52].param.west   = FALSE;
   room[54].param.east   = FALSE;
   room[59].param.west   = FALSE;
   room[60].param.north  = FALSE;
   room[60].param.east   = FALSE;
   room[63].param.north  = FALSE;      //
   room[68].param.south  = FALSE;
   room[70].param.north  = FALSE;
   room[70].param.east   = FALSE;
   room[72].param.north  = FALSE;
   room[72].param.west   = FALSE;
   room[74].param.south  = FALSE;
   room[75].param.east   = FALSE;
   room[75].param.south  = FALSE;
   room[78].param.north  = FALSE;
   room[78].param.west   = FALSE;
   room[79].param.north  = FALSE;
   room[81].param.east   = FALSE;
   room[88].param.east   = FALSE;      //
   room[90].param.south  = FALSE;
   room[90].param.west   = FALSE;
   room[92].param.north  = FALSE;
   room[94].param.east   = FALSE;
   room[99].param.west   = FALSE;
   room[103].param.north = FALSE;
   room[104].param.north = FALSE;
   room[109].param.east  = FALSE;
   room[112].param.south = FALSE;      //
   room[112].param.west  = FALSE;
   room[115].param.east  = FALSE;
   room[118].param.north = FALSE;
   room[118].param.west  = FALSE;
   room[119].param.north = FALSE;
   room[120].param.south = FALSE;
   room[131].param.north = FALSE;      //
   room[131].param.east  = FALSE;
   room[134].param.south = FALSE;
   room[134].param.west  = FALSE;
   room[137].param.north = FALSE;
   room[138].param.north = FALSE;
   room[139].param.south = FALSE;
   room[140].param.east  = FALSE;
   room[140].param.south = FALSE;
   room[142].param.south = FALSE;
   room[142].param.west  = FALSE;      //
   room[147].param.south = FALSE;
   room[149].param.south = FALSE;
   room[150].param.south = FALSE;
   room[152].param.east  = FALSE;
   room[156].param.west  = FALSE;
   room[159].param.east  = FALSE;
   room[159].param.south = FALSE;
   room[164].param.west  = FALSE;
   room[166].param.south = FALSE;
   room[167].param.south = FALSE;      //
   room[169].param.east  = FALSE;
   room[169].param.south = FALSE;
   room[169].param.west  = FALSE;
   room[172].param.south = FALSE;
   room[172].param.west  = FALSE;
   room[174].param.north = FALSE;
   room[175].param.north = FALSE;
   room[176].param.north = FALSE;
   room[179].param.east  = FALSE;
   room[185].param.west  = FALSE;
   room[186].param.east  = FALSE;
   room[186].param.south = FALSE;
   room[194].param.west  = FALSE;      //
   room[201].param.east  = FALSE;
   room[206].param.east  = FALSE;
   room[206].param.south = FALSE;
   room[206].param.west  = FALSE;
}

