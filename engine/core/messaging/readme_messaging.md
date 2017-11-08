## messaging ##

this is where I think we should start, since messaging is a powerful way to start connecting our engine subsystems in a modular way

Messaging is used a lot in GUI coding, mostly through the MVC pattern. 
[Qt has a good writeup from a C++ point of view](http://doc.qt.io/qt-4.8/model-view-programming.html)

Also those articles in the facebook chat have some useful things to say about how it could affect our architecture

Essentially, we want to create a central system that accepts events from anyone with a time to fire, places them on a timeline, and when the 
event fires, all registered listeners are notified of the event. This will be an important system to work on and will get us off to
a good start!

ideas->
(components to make: message, message bus, stack, linked list, map, timer)
--> messages have hash id + attributes and are just POD
--> message bus class has an unordered map of message IDs to linked lists of receiver objects(/functions?)
--> message bus has an internal clock/timer
--> message bus class has a timeline
------> a timeline is an ordered map of time values to stacks of messages
--> message bus has an "update" that is called in the main game loop. in the update, the timeline is iterated on in order.
    for each timeline item with a time less than the current time, the message bus pops through the stack of associated messages,
	and for each message (nested loop eh) passes the message to the map of [message IDs -> linked lists of receiver objects]
	and calls each receiver's listener function registered to the message


--> just jotting this down so i don't forget but we can whiteboard it later to work out the details