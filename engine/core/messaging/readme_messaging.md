## messaging ##

this is where I think we should start, since messaging is a powerful way to start connecting our engine subsystems in a modular way

Messaging is used a lot in GUI coding, mostly through the MVC pattern. 
[Qt has a good writeup from a C++ point of view](http://doc.qt.io/qt-4.8/model-view-programming.html)

Also those articles in the facebook chat have some useful things to say about how it could affect our architecture

Essentially, we want to create a central system that accepts events from anyone with a time to fire, places them on a timeline, and when the 
event fires, all registered listeners are notified of the event. This will be an important system to work on and will get us off to
a good start!