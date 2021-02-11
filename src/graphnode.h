#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include "chatbot.h"

#if 0 //Original
#else // Task4
#include <memory>
#endif

// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
#if 0 // Original
    std::vector<GraphEdge *> _childEdges;  // edges to subsequent nodes
#else // Task4
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;  // edges to subsequent nodes
#endif

    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes 
#if 0 // Original
    ChatBot *_chatBot;
#else // Task5
    ChatBot _chatBot;
#endif

    ////
    //// EOF STUDENT CODE

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
#if 0 // Original
    void AddEdgeToChildNode(GraphEdge *edge);
#else // Task4
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);
#endif

    //// STUDENT CODE
    ////

#if 0 // Original
    void MoveChatbotHere(ChatBot *chatbot);
#else // Task5
    void MoveChatbotHere(ChatBot chatbot);
#endif

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */