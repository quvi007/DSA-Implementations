class SLinkedList<T> {
    private SNode<T> head;

    public SLinkedList() {
        head = null;
    }

    public final T front() {
        return head.getElem();
    }

    public void addFront(T e) {
        SNode<T> v = new SNode<>();
        v.setElem(e);
        v.setNext(head);
        head = v;
    }

    public void removeFront() {
        head = head.getNext();
    }

    public boolean empty() {
        return head == null;
    }
}


class SNode<T> {
    private T elem;
    private SNode next;

    public final T getElem() {
        return elem;
    }

    public void setElem(T elem) {
        this.elem = elem;
    }

    public SNode getNext() {
        return next;
    }

    public void setNext(SNode<T> next) {
        this.next = next;
    }
}


public class Main {
    public static void main(String[] args) {
        SLinkedList<Integer> sll = new SLinkedList<>();
        sll.addFront(4);
        sll.addFront(3);
        sll.addFront(2);
        sll.addFront(1);

        while(!sll.empty()) {
            System.out.println(sll.front());
            sll.removeFront();
        }
    }
}
