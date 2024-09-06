# Factory Method/Function

A very common _creational_ pattern that allows consistenly creating pattern conviniently.

The Factory Method pattern (creational pattern) provides a generalized way to create instances of an object and can be a great way to hide implementation details for derived class.
We don't want the clients of our interface, or perhaps implementer who work on our code, to make the decision on how to allocate objects.
Instead we want a (factory) function that we can provide an input or inputs and get the correct output (object).
We leverage _Inheritance-based polymorphism_ to implement this pattern.
We have some Interface and we derive from it.

## Pros/Cons

Pros:

- Single responsibility
- Easy to update and can (?) be extend

Cons:

- two updates in a class: `ObjectType` enumeration and the factory function itself.
- several factory may needed for different hierarchies in the code.
