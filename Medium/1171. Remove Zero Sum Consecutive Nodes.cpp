
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        mp[0] = dummy;

        ListNode* prev = dummy;
        ListNode* cur = head;
        int sum = 0;

        while (cur)
        {
            sum += cur->val;

            if (mp.find(sum) != mp.end())
            {
                //This is to remove the sums from the map which are present in the part to be remove
                ListNode* temp = mp[sum]->next;
                int temp_sum = sum;
                while (temp != cur)
                {
                    temp_sum += temp->val;
                    mp.erase(temp_sum);
                    temp = temp->next;
                }

                // Removing the zero sum path
                mp[sum]->next = cur->next;
                prev = mp[sum];
                cur = cur->next;
            }
            else {
                mp[sum] = cur;
                prev = cur;
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};
