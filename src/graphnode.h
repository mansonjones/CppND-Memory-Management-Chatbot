#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include <memory>   // required for std::unique_ptr

#include "chatbot.h"
// Note sure if this next line is needed.  It's included in some
// of the examples from the lectures.
#include <memory>  

// For debugging only.  Eventually this dependency should be removed.
#include "move_semantics_task_5.h"

// Refer to the Program schematic:
// Owned by the class: _childEdges, _id, _answers.
// Not owned by the class: _parentEdges, _chatBot.

// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE - Task 4
    ////

    // data handles (owned)
    // For tasks 4 & 5
    // Each instance of the class GraphNode owns the outgoing edges
    // that are stored in _childEdges.

    std::vector< std::unique_ptr<GraphEdge> > _childEdges;

    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes 
    // pretty sure that this should eventually be changed to

    ChatBot _chatBot; 

    ////
    //// EOF STUDENT CODE - Task 4

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);

    //// STUDENT CODE - Task 5
    ////
    void MoveChatbotHere(ChatBot chatbot);
    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */
