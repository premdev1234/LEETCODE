class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            Node* prev = nullptr;

            for (int i = 0; i < sz; ++i) {
                Node* node = q.front(); q.pop();

                if (prev) prev->next = node;
                prev = node;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // End of level: prev->next should already be NULL
        }

        return root;
    }
};
