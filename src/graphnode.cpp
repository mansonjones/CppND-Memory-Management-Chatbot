#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE - Warm up task

    //// Warm up task - the program crashes when you close
    //// the window.  The crash occured because _chatbot
    //// was deleted here.  This is not consistent with
    //// RAII, which stipulates that the resources that
    //// are allocated in the constructor should be
    //// deallocted in the destructor.

    //// EOF STUDENT CODE - Warm up task
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

// Task 4
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE - Task 5
//// See  https://knowledge.udacity.com/questions/77646
//// the final version should be
#ifdef MOVE_SEMANTICS_TASK_5
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
  _chatBot = ChatBot(std::move(chatbot));
  _chatBot.SetCurrentNode(this);
}

#else

void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
}

#endif

#ifdef MOVE_SEMANTICS_TASK_5

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
  newNode->MoveChatbotHere(std::move(_chatBot));
}

#else 
void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source
}

#endif
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}
