/*
* Containers
*/

We will need to figure out our data structures and algorithms for the engine. We can either use STL, Boost, or roll our own

Sorry to go on and on about stuff from Andre's engine sequence, though I am interested in drawing on some post-mortem lessons from 
that class since the engine we make in it is flawed in some ways (intentionally) -- with that, Andre did some metrics on loading and
looping a C++ STL linked list vs his own simple custom one and posted the metrics on Piazza, so I put that in a PDF in the docs folder.
Since this is for educational purposes mostly, I'd say we should take the time to write our own, though we do then need to be more vigilant
about testing our data structures than we would with STL or Boost

I've never used Boost, so maybe we could do that instead?

The structures I think we need are:

linked list (for a lot of things)

vector (for a lot of things)

dictionary/sorted map
--> specifically to implement a Timeline that keys time values (in order) to linked lists of functions/commands to be fired at those times

hash/unsorted map
--> specifically for resource managers to associate hash/string file names with resource data

circular/ring buffer
--> specifically for a message ring to communicate between threads