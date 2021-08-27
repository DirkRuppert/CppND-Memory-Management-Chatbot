#include "graphedge.h"
#include "graphnode.h"
#include <memory>

using std::unique_ptr;

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // for task #0: removed deallocation here. Makes more sense to free allocated memory in ChatLogic.cpp destructor
     

    ////
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

void GraphNode::AddEdgeToChildNode(unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    // for task #4: get() function used due to smart pointer and return value should be the memory adress
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}