#include "positionlistutils.h"

void PositionListUtils::display_list(PositionList& pl, bool is_name_list)
{
	if(!pl.size())
	  {cout << "not found" << endl; return;}

	printf("found %d matches\n", (int)pl.size());
	for (PositionList::iterator i = pl.begin(); i!=pl.end(); i++)
	{
      Position crr = *i;
	  // Name list
	  if (is_name_list)
        cout << *crr << ": " << !crr << endl;
	  // Phone list: print name first
	  else
   		cout << !crr << ": " << *crr << endl;
	}
}

void PositionListUtils::sort_list(PositionList& pl, bool is_name_list)
{
	for (PositionList::iterator i = pl.begin(); i!=pl.end(); i++)
	{
	  PositionList::iterator j = i;
	  while(++j!=pl.end())
	  {
	    // Always sort by name
	    Position p = *i;
	    Position q = *j;
	    if((is_name_list && *p > *q) || (!is_name_list && !p > !q))
	    {
	      Position temp_p = *i;
	      *i = *j;
	      *j = temp_p;
	    }
	  }
	}
}
