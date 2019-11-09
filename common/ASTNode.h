#ifndef ASTNODE_H
#define ASTNODE_H
#include <iostream>

enum class ASTNodeType {
    defFunc = 1,
    callFunc = 2,
    literal = 3,
    op = 4,         //包含 assignop ， relop， +， -， *， /， %
    exp = 5,
    stmt = 6,
    defVar = 7,
    assignVar = 8,
    identifier = 8,
    loop = 10,
    select = 11,
    root = 12,
};

class AbstractASTNode
{
private:
    ASTNodeType nodeType;
    AbstractASTNode* parent;
    AbstractASTNode* peer;
    AbstractASTNode* child;
protected:
    std::string content;
    static void __printTree(AbstractASTNode* node, int depth);
    inline AbstractASTNode* getChild() { return this->child; }
    inline AbstractASTNode* getPeer() { return this->peer; }
public:
    AbstractASTNode();
    AbstractASTNode(ASTNodeType nodetype);
    AbstractASTNode(char* content, ASTNodeType nodeType);
    void addChildNode(AbstractASTNode* node);
    void addPeerNode(AbstractASTNode* node);
    AbstractASTNode* getLastPeerNode();
    void printTree();
    virtual void printInfo(int depth) = 0;
};

class RootASTNode : public AbstractASTNode
{
public:
    RootASTNode();
    void printInfo(int depth);
};
#endif
