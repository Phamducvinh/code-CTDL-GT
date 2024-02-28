class lineked_list{
    Node head;
    class Node{
        int data;
        Node next;

        Node(int val){data=val;next=null;}
    }
    public void push(int newData){
        Node newNode = new Node(newData);
        newNode.next = head;
        head = newNode;
    }
    public void insertAfter(Node prev, int newData){
        if(prev == null){
            System.out.println("the given previous node cannot be null");
            return;
        }
        Node newNode = new Node(newData);
        newNode.next = prev.next;
        prev.next = newNode;
    }
    public void addTail(int newData){
        Node newNode = new Node(newData);
        if(head == null){
            head = newNode;
            return;
        }
        newNode.next = null;
        
        Node cur = head;
        while(cur.next != null){
            cur = cur.next;
        }
        cur.next = newNode;
        
    }
    public void println(){
        Node cur = head;
        while(cur != null){
            System.out.println(cur.data+" ");
            cur =cur.next;
        }
    }
    public static void main(String[] args){
        lineked_list list = new lineked_list();
        list.addTail(6);
        list.push(7);
        list.push(1);
        list.addTail(4);
        list.insertAfter(list.head.next, 8);
        list.println();
    }
}

