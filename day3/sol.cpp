#include <vector>

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        std::vector<int> values;
        ListNode* current = head;
        int count = 1;

        while (current) {
            if (count >= left && count <= right) {
                values.push_back(current->val);
            }
            current = current->next;
            count++;
        }

        current = head;
        int value_index = values.size() - 1;
        count = 1;

        while (current) {
            if (count >= left && count <= right) {
                current->val = values[value_index];
                value_index--;
            }
            current = current->next;
            count++;
        }

        return head;
    }
};
