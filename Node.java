public class Node {
    private int data;
    private Node left;
    private Node right;

    public Node(int data) {
        this.data = data;
    }

    public int getData() {
        return this.data;
    }

    public Node getLeft() {
        return left;
    }

    public Node getRight() {
        return right;
    }

    public static Node getNode(Node node, int data) {
        if (node == null) {
            return null;
        }

        if (node.data == data) {
            return node;
        }

        if (node.getData() < data) {
            return getNode(node.getRight(), data);
        }

        return getNode(node.getLeft(), data);
    }

    public static Node insertNode(Node node, int data) {
        if (node == null) {
            return new Node(data);
        }

        if (node.getData() < data) {
            node.right = insertNode(node.getRight(), data);
        } else {
            node.left = insertNode(node.getLeft(), data);
        }

        return node;
    }

    public static void printNodeInOrder(Node node) {

        if (node == null) {
            return;
        }

        printNodeInOrder(node.getLeft());
        System.out.println("data = " + node.data);
        printNodeInOrder(node.getRight());

    }

    public static boolean deleteNode(Node node, int data) {

        Node deleteNode = Node.getNode(node, data);
        if (deleteNode == null) {
            return false;
        }

        if (node.getPredecessorNode() == null) {
            return false;
        }

        Node substituteNode = null;

        Node predecessorNode = deleteNode.getPredecessorNode();
        if (predecessorNode != null) {
            substituteNode = predecessorNode;
        }

        Node successorNode = deleteNode.getSuccessorNode();
        if (successorNode != null) {
            substituteNode = successorNode;
        }

        Node parentNodeForDeleteNode = Node.getParent(node, deleteNode.getData());

        if (substituteNode != null) {
            parentNodeForDeleteNode = Node.getParent(node, substituteNode.getData());
            deleteNode.data = substituteNode.getData();
        }

        if (parentNodeForDeleteNode.getLeft() != null &&
                parentNodeForDeleteNode.getLeft().getData() == deleteNode.getData()) {
            parentNodeForDeleteNode.left = null;
        }

        if (parentNodeForDeleteNode.getRight() != null &&
                parentNodeForDeleteNode.getRight().getData() == deleteNode.getData()) {
            parentNodeForDeleteNode.right = null;
        }

        return true;
    }

    public static Node getParent(Node node, int data) {

        if (node.getData() == data) {
            return null;
        }

        if (node.getRight() != null && node.getRight().getData() == data || node.getLeft() != null && node.getLeft().getData() == data) {
            return node;
        }

        if (node.getData() < data) {
            return getParent(node.getRight(), data);
        }

        return getParent(node.getLeft(), data);
    }

    private Node getPredecessorNode() {
        Node leftNode = this.getLeft();
        if (leftNode == null) {
            return null;
        }

        Node rightNode = leftNode.getRight();
        if (rightNode == null) {
            return leftNode;
        }

        while (rightNode.getRight() != null) {
            rightNode = rightNode.getRight();
        }

        return rightNode;
    }

    private Node getSuccessorNode() {
        Node rightNode = this.getRight();
        if (rightNode == null) {
            return null;
        }

        Node leftNode = rightNode.getLeft();
        if (leftNode == null) {
            return rightNode;
        }

        while (leftNode.getLeft() != null) {
            leftNode = leftNode.getLeft();
        }

        return leftNode;
    }

}
