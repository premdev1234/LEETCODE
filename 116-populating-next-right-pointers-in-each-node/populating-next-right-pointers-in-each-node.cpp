class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* level_start = root;

        while (level_start->left != nullptr) {
            Node* current = level_start;

            while (current != nullptr) {
                // Connect left → right
                current->left->next = current->right;

                // Connect right → next's left, if it exists
                if (current->next)
                    current->right->next = current->next->left;

                // Move horizontally in the current level
                current = current->next;
            }

            // Move to the next level
            level_start = level_start->left;
        }

        return root;
    }
};
