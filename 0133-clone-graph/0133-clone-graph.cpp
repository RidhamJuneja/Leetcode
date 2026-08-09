/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        queue<Node*> q;
        unordered_map<Node*, Node*> mp;
        Node* head = new Node(node->val);
        mp[node] = head;
        q.push(node);
        while(!q.empty())
        {
            Node* temp = q.front();
            for(auto i : temp->neighbors)
            {
                if(mp.find(i) == mp.end())
                {
                q.push(i);
                Node* newNode = new Node(i->val);
                mp[i] = newNode;
                }
                mp[temp]->neighbors.push_back(mp[i]);
                // newNode->neighbors.push_back(mp[temp]);
            }
            q.pop();
        }
        return head;
    }
};