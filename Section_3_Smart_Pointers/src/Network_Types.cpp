#include <memory>
#include <iostream>
#include <string>
#include "Network_Types.h"
#include <vector>

using std::cout, std::endl;

Node::Node() : id(next_id++) {}

Node::~Node()
{
    cout << "Node " << id << " destroyed." << endl;
}

int Node::getId() const
{
    return id;
}

// Static variables need to be initialised outside their class declaration
// This is because they are only initialised ONCE, not individually for every object.
int Node::next_id = 0;

void Node::setHub(std::shared_ptr<Hub> hub) {
    this->hub = std::move(hub);
}


Hub::Hub(const std::string &n) : name(n) {}

Hub::~Hub()
{
    cout << "Hub " << name << " destroyed." << endl;
}

void Hub::addNode(std::unique_ptr<Node> node) {
    nodes.push_back(std::move(node));

}
