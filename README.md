# designpatterns
This repository contains implementations of commonly used design patterns.

# Infrastructure
### IdManager
    This is a singleton instance which is used to generate unique object id.
### Cache
    This is LRU cache with a fixed size.

# Domain Objects
### DomainObject
    This is the base class for all objects. It has only one property 'Id' which is used to uniquely identify the objects created. At this time this is not
    a GUID. The reason is simple: I want to play with hash and collisions. With integer type, creating collisions would be faster.
### Person
    This is a basic object with a few properties.

