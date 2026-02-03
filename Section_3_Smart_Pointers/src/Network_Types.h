#include <memory>
#include <iostream>
#include <string>
#include <vector>

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

    void setHub(std::shared_ptr<Hub> hub);

private:
    // Static variable means same value shared by every object in class
    // This allows us to create a unique id for each Node by increasing
    // each time
    static int next_id;
    
    int id;

    // add a pointer to the Hub here
    std::shared_ptr<Hub> hub;
};

class Hub
{
public:
    Hub(const std::string &n);

    ~Hub();

    void addNode(std::unique_ptr<Node> node);

private:
    std::string name;

    // add a vector or map of pointers to Nodes here
    std::vector<std::unique_ptr<Node>> nodes;
};
