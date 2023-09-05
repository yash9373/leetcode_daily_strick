class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // First pass: Create new nodes and insert them next to the original nodes
        Node* current = head;
        while (current) {
            Node* newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }

        // Second pass: Set random pointers for the new nodes
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        // Third pass: Separate the original and copied lists
        current = head;
        Node* head2 = head->next;
        Node* current2 = head2;
        while (current) {
            current->next = current2->next;
            current = current->next;
            if (current) {
                current2->next = current->next;
                current2 = current2->next;
            }
        }

        return head2;
    }
};
