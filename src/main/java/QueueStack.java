import java.util.LinkedList;
import java.util.Queue;

/**
 * 225. Implement Stack using Queues
 * <p/>
 * {@link "https://leetcode.com/problems/implement-stack-using-queues/"}
 * <p/>
 * Created by desmond on 11/6/16.
 */
public class QueueStack {

    private Queue<Integer>[] queues = new Queue[2];
    private int pop = 0;

    public QueueStack() {
        queues[0] = new LinkedList<Integer>();
        queues[1] = new LinkedList<Integer>();
    }

    // Push element x onto stack.
    public void push(int x) {
        queues[1 - pop].add(x);
        while (!queues[pop].isEmpty()) {
            queues[1 - pop].add(queues[pop].poll());
        }
        pop = 1 - pop;
    }

    // Removes the element on top of the stack.
    public void pop() {
        queues[pop].poll();
    }

    // Get the top element.
    public int top() {
        return queues[pop].element();
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return queues[pop].isEmpty();
    }

}
