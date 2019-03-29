#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

/*
DEFINITION ----------
You've booked a really cheap one-way flight. Unfortunately, that means you have tons 
of layovers before you reach your destination. The morning of, you woke up late and 
had to scramble to the airport to catch your first flight. However, in your rush, you 
accidentally scrambled all your flight tickets. You don't know the route of your 
entire trip now!

Write a function reconstruct_trip to reconstruct your trip from your mass of flight tickets.

INPUT ---------
typedef struct Ticket {
  char *source;
  char *destination;
} Ticket;

Ticket **tickets = {
  Ticket{ source: "PIT", destination: "ORD" },
  Ticket{ source: "XNA", destination: "CID" },
  Ticket{ source: "SFO", destination: "BHM" },
  Ticket{ source: "FLG", destination: "XNA" },
  Ticket{ source: "NONE", destination: "LAX" },
  Ticket{ source: "LAX", destination: "SFO" },
  Ticket{ source: "CID", destination: "SLC" },
  Ticket{ source: "ORD", destination: "NONE" },
  Ticket{ source: "SLC", destination: "PIT" },
  Ticket{ source: "BHM", destination: "FLG" }
};

RETURN ----------
Your function should output a char ** array of strings with the entire route of your trip. 
For the above example, it should look like this:

{ "LAX", "SFO", "BHM", "FLG", "XNA", "CID", "SLC", "PIT", "ORD", "NONE" }

NOTE ----------
We can hash each ticket such that the starting location is the key and the destination is the value.
*/

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));

  // populate hash table with routes
  for (int x = 0; x < length; x++)
  {
    hash_table_insert(ht, tickets[x]->source, tickets[x]->destination);
  }

  char *start = "NONE";
  for (int x = 0; x < length; x++)
  {
    route[x] = hash_table_retrieve(ht, start);
    start = route[x];
  }

  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%s\n", route[i]);
  }
}

#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  return 0;
}
#endif
