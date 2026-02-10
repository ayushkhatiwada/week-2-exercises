#include <cstddef>
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

void Hub::addNode(std::unique_ptr<Node> node)
{
    if (!node) return;

    // If node already belongs to a hub, remove it from there
    if (auto oldHub = node->getHub()) {
        if (oldHub.get() != this) {
            oldHub->removeNode(node->getId());
        }
    }

    node->setHub(shared_from_this());
    unordered_map_nodes.emplace(node->getId(), std::move(node));
}


void Hub::removeNode(int node_id) {
    auto it = unordered_map_nodes.find(node_id);;
    if (it == unordered_map_nodes.end()) {
        throw std::invalid_argument("node_id not found");
    }

    it->second->setHub(std::weak_ptr<Hub>{});
    unordered_map_nodes.erase(it);
}
