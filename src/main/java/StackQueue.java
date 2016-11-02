import java.util.List;
import java.util.Stack;

/**
 * 232. Implement Queue using Stacks
 * {@link "https://leetcode.com/problems/implement-queue-using-stacks/"}
 *
 * Created by desmond on 11/2/16.
 */
class StackQueue {

    List<Stack<Integer>> stacks;
    int active = 0;

    public StackQueue() {
        stacks.add(new Stack<Integer>());
        stacks.add(new Stack<Integer>());
    }

    // Push element x to the back of queue.
    public void push(int x) {
        Stack<Integer> next = stacks.get(1 - active);
        next.push(x);

        Stack<Integer> stack = stacks.get(active);
        while (!stack.isEmpty()) {
            Integer i = stack.pop();
            next.push(i);
        }
        active = 1 - active;
    }

    // Removes the element from in front of queue.
    public void pop() {
        stacks.get(active).pop();
    }

    // Get the front element.
    public int peek() {
        return stacks.get(active).peek();
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return stacks.get(active).empty();
    }
}
