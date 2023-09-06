// Step 1: Find the length of the linked list
    int length = 0;
    ListNode* current = head;
    while (current) {
        length++;
        current = current->next;
    }

    // Calculate the minimum size of each part and the number of larger parts
    int min_size = length / k;
    int num_large_parts = length % k;

    // Initialize the result vector
    vector<ListNode*> result;

    current = head;
    ListNode* prev = NULL;

    for (int i = 0; i < k; i++) {
        result.push_back(current);

        // Calculate the size of the current part
        int part_size = min_size + (i < num_large_parts ? 1 : 0);

        // Advance current to the end of the current part
        for (int j = 0; j < part_size; j++) {
            prev = current;
            current = current->next;
        }

        // Break the link between the parts
        if (prev) {
            prev->next = NULL;
        }
    }

    return result;