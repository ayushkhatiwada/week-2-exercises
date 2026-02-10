#include <memory>
#include <iostream>
#include <stdexcept>
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

void Node::setHub(const std::weak_ptr<Hub> &hub) {
    this->hub = hub;
}

std::shared_ptr<Hub> Node::getHub() const {
    return hub.lock();
}


//


Hub::Hub(const std::string &n) : name(n) {}

Hub::~Hub()
{
    cout << "Hub " << name << " destroyed." << endl;
}

void Hub::addNode(std::unique_ptr<Node> node) {
    // nodes.push_back(std::move(node));

    if (auto oldHub = node->getHub()) {
        oldHub->removeNode(node->getId());
    }
    
    unordered_map_nodes[node->getId()] = std::move(node);
}

void Hub::removeNode(int node_id) {
    if (unordered_map_nodes.erase(node_id) == 0) {
        throw std::invalid_argument("node_id does not exist in unordered_map_nodes");
    }
}
