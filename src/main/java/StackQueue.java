import java.util.Stack;

/**
 * 232. Implement Queue using Stacks
 * {@link "https://leetcode.com/problems/implement-queue-using-stacks/"}
 * <p/>
 * Created by desmond on 11/2/16.
 */
public class StackQueue {

    Stack<Integer>[] stacks;
    int pushStack = 0;
    int popStack = 1;

    public StackQueue() {
        stacks = new Stack[2];
        stacks[0] = new Stack<Integer>();
        stacks[1] = new Stack<Integer>();
    }

    // Push element x to the back of queue.
    public void push(int x) {
        stacks[pushStack].push(x);
    }

    // Removes the element from in front of queue.
    public void pop() {
        migrateIfpopEmpty();
        stacks[popStack].pop();
    }

    // Get the front element.
    public int peek() {
        migrateIfpopEmpty();
        return stacks[popStack].peek();
    }

    private void migrateIfpopEmpty() {
        if (stacks[popStack].empty()) {
            while (!stacks[pushStack].empty()) {
                stacks[popStack].push(stacks[pushStack].pop());
            }
        }
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return stacks[popStack].empty() && stacks[pushStack].empty();
    }
}
