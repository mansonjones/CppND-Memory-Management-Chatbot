#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE

    //// Warm up task - the program crashes when you close
    //// the window.  The crash occured because _chatbot
    //// was deleted here.  This is not consistent with
    //// RAII, which stipulates that the resources that
    //// are allocated in the constructor should be
    //// deallocted in the destructor.

    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    _childEdges.push_back(edge);
}

//// STUDENT CODE - Task 5
//// See  https://knowledge.udacity.com/questions/77646
//// the final version should be
//// void GraphNode::MoveChatbotHere(ChatBot chatbot)
//// {
////  _chatBot = ChatBot(std::move(chatbot));
////  _chatBot.setCurrentNode(this);
//// }
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
}


// The final version should be
// void GraphNode;:MoveChatbotToNewNode(GraphNode *newNode)
// {
//   newNode->MoveChatbotHere(std::move(_chatbot));
// }

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index];

    ////
    //// EOF STUDENT CODE
}
