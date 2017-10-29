## Memory ##

Personally I don't think we need to do anything super crazy like override new or write our own allocation scheme that we use all the time

At the very least though, we should write utilities to make memory pools as we need them via the factory pattern

I was thinking maybe we can make the interface for them; then write simple ones as we need them

For example, for our linked list implementation, we could make a NodeFactory inherit from an abstract Factory;
then we never call 'new' or 'delete' on nodes in our linked list, we call NodeFactory::GetNewNode() or NodeFactory::ReturnNode()
which internally stores a stack of "returned" list nodes that we otherwise would have deleted. NodeFactory::GetNewNode() will first try to
return one of these inactive, reset nodes, and will only allocate a 'new' node when it doesn't have any pooled nodes available

This is a lot simpler (and less error prone) than writing our own memory system but we will still be able to
avoid unnecessary dynamic memory allocation