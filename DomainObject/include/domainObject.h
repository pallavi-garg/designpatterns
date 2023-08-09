#ifndef DOMAIN_OBJECT_H
#define DOMAIN_OBJECT_H

class DomainObject
{
private:
    int id = 0;
public:
    int getId();
    DomainObject();
    DomainObject(const DomainObject&);
};

#endif