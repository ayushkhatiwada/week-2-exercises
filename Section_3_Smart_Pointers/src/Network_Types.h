#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

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

    // const here means this member function does not modify the object
    // except for members explicitly marked `mutable`
    int getId() const;

    void setHub(const std::weak_ptr<Hub> &hub);

    std::shared_ptr<Hub> getHub() const;

private:
    // Static variable means same value shared by every object in class
    // This allows us to create a unique id for each Node by increasing
    // each time
    static int next_id;
    int id;

    // add a pointer to the Hub here
    std::weak_ptr<Hub> hub;
};

class Hub
{
public:
    Hub(const std::string &n);

    ~Hub();

    void addNode(std::unique_ptr<Node> node);

    void removeNode(int node_id);

private:
    std::string name;

    // add a vector or map of pointers to Nodes here
    // std::vector<std::unique_ptr<Node>> nodes;

    std::unordered_map<int, std::unique_ptr<Node>> unordered_map_nodes;
};
