#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include <vector>
#include <string>

#include <memory>     // required when using std::unique_ptr

#include "chatgui.h"

// for debugging only.  eventually this should be removed.
#include "move_semantics_task_5.h"

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

// Refer to the program schematic:
// Owned by the class: _nodes
// Not owned by the class: _currentNode, _chatBot, _panelDialog 


class ChatLogic
{
private:
    //// STUDENT CODE - Task 3
    //// Task 3 - exclusive ownership
    //// Adapt vector _nodes in a way that instances of 
    //// GraphNodes to which the vector elements refer
    //// are exclusively owned by the class ChatLogic.
    //// Use an appropriate type of smart pointer to 
    //// achieve this.

    //// Task 4. change ownership of all instances of GraphEdge
    // data handles (owned)
 //   std::vector<GraphNode *> _nodes;
    
    std::vector< std::unique_ptr<GraphNode> > _nodes;

    ////
    //// EOF STUDENT CODE - Task 3

    // data handles (not owned)
    GraphNode *_currentNode;
    ChatBot *_chatBot;
    ChatBotPanelDialog *_panelDialog;

    // proprietary type definitions
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    // proprietary functions
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T &element);

public:
    // constructor / destructor
    ChatLogic();
    ~ChatLogic();

    // getter / setter
    void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
    void SetChatbotHandle(ChatBot *chatbot);

    // proprietary functions
    void LoadAnswerGraphFromFile(std::string filename);
    void SendMessageToChatbot(std::string message);
    void SendMessageToUser(std::string message);
    wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */
