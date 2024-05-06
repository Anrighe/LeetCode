import java.util.Stack;


/**
 * Remove nodes from a linked list that are greater than any of the nodes that follow it.
 */
class Solution {
    public ListNode removeNodes(ListNode head) {
        
        ListNode ptr = head;
        Stack<Integer> stack = new Stack<>();
        
        ListNode result = null;
        
        int val;
        while (ptr != null) {
            val = ptr.val;
            
            while (!stack.isEmpty() && stack.peek() < val) 
                stack.pop();
            
            stack.push(val);
            ptr = ptr.next;
            
        }
        
        while (!stack.isEmpty())
            result = new ListNode (stack.pop(), result);      
        
        return result;
    }
}