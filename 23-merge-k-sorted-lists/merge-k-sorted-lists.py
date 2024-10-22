# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq;


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # Create a min-heap with tuples of the form (value, list_index, node)
        min_heap = [(lst.val, i, lst) for i, lst in enumerate(lists) if lst]
        heapq.heapify(min_heap)

        # Create a dummy head to simplify result list management
        dummy = ListNode()
        current = dummy

        while min_heap:
            # Pop the smallest element
            value, list_index, node = heapq.heappop(min_heap)

            # Add the smallest element to the merged list
            current.next = ListNode(value)
            current = current.next

            # If there's a next node in the same list, add it to the heap
            if node.next:
                heapq.heappush(min_heap, (node.next.val, list_index, node.next))

        return dummy.next