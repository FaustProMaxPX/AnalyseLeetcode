//leetcode 117 填充每个节点的下一个右侧节点指针 II
#include <iostream>

using namespace std;

class Node
{
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node(){val = 0; left = right = next = nullptr;}
};

//迭代写法
Node* connect(Node* root) {
        queue<Node*> q;
        if(!root)
            return NULL;
        q.push(root);
        Node* pre = NULL;
        while(!q.empty())
        {
            int n = q.size();
            pre = q.front();
            q.pop();
            if(pre->left) q.push(pre->left);
            if(pre->right) q.push(pre->right);
            for(int i = 1; i < n; i++)
            {
                Node* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                pre->next = node;
                pre = node;
            }
        }
        return root;
    }


//递归写法
void handle(Node* & last, Node* & p, Node* & nextStart)
{
    if(last) //若上一节点存在，则连接
        last->next = p;
    if(!nextStart) //下一轮的起始结点，即本轮进行连接操作的头一个结点
        nextStart = p;
    last = p;
}

Node* connect1(Node* root)
{
    if(!root)
        return nullptr;
    Node* start, *nextStart, *last;
    start = root;
    while(start)
    {
        last = nextStart = nullptr;
        Node* p;
        for(p = start; p != nullptr; p = p->next)
        {
            if(p->left)
                handle(last, p->left, nextStart);
            if(p->right)
                handle(last, p->right, nextStart);
        }
        start = nextStart;
    }
    return root;
}
