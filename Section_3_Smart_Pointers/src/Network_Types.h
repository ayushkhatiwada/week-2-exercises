#include <memory>
#include <iostream>
#include <string>

using namespace std;

// Forward declaration of Hub class.
// This is needed to let the compiler know that a type called
// Hub will be defined in the code when it compiles the 
// Node class, as the Hub class is defined afterwards.
// You can have a pointer to a forward declared class because a 
// pointer is just an address in memory, so the compiler doens't
// need to know anything the data Hub contains to work
// out the data layout for Node. 
class Hub;

class Node
{
    public:
    Node();

    ~Node();

    int getId() const;

    private:
    // Static variable means same value shared by every object in class
    // This allows us to create a unique id for each Node by increasing
    // each time
    static int next_id;
    
    int id;
    // add a pointer to the Hub here
};

class Hub
{
    public:
    Hub(const std::string &n);

    ~Hub();

    private:
    string name;
    // add a vector or map of pointers to Nodes here
};
