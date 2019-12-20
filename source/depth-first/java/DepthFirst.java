import java.util.ArrayList;
import java.util.List;

public class DepthFirst {
    private List<Integer> preOrder;
    public List<Integer> getPreOrder(TreeNode root) {
        preOrder = new ArrayList<>();
        doPreOrder(root);
        return preOrder;
    }

    private void doPreOrder(TreeNode node) {
        if (node == null) {
            return;
        }

        preOrder.add(node.value); // visit the node
        doPreOrder(node.left); // traverse to the left
        doPreOrder(node.right); // traverse to the right
    }

    private List<Integer> inOrder;
    public List<Integer> getInOrder(TreeNode root) {
        inOrder = new ArrayList<>();
        doInOrder(root);
        return inOrder;
    }

    private void doInOrder(TreeNode node) {
        if (node == null) {
            return;
        }

        doInOrder(node.left); // traverse to the left
        inOrder.add(node.value); // visit the node
        doInOrder(node.right); // traverse to the right
    }

    private List<Integer> postOrder;
    public List<Integer> getPostOrder(TreeNode root) {
        postOrder = new ArrayList<>();
        doPostOrder(root);
        return postOrder;
    }

    private void doPostOrder(TreeNode node) {
        if (node == null) {
            return;
        }

        doPostOrder(node.left); //traverse to the left
        doPostOrder(node.right); //traverse to the right
        postOrder.add(node.value); //visit the node
    }

    // NOW TEST IT
    private static void TEST_PREORDER() {
        DepthFirst depthFirst = new DepthFirst();
        List<Integer> sample01PreOrder = depthFirst.getPreOrder(SampleTree01.getRootNode());
        List<Integer> sample02PreOrder = depthFirst.getPreOrder(SampleTree02.getRootNode());
        List<Integer> sample03PreOrder = depthFirst.getPreOrder(SampleTree03.getRootNode());

        try {
            SampleTree01.checkPreOrder(sample01PreOrder);
            SampleTree02.checkPreOrder(sample02PreOrder);
            SampleTree03.checkPreOrder(sample03PreOrder);
        } catch (Exception e) {
            System.out.println();
            e.printStackTrace();
        }
    }

    private static void TEST_INORDER() {
        DepthFirst depthFirst = new DepthFirst();
        List<Integer> inOrder01 = depthFirst.getInOrder(SampleTree01.getRootNode());
        List<Integer> inOrder02 = depthFirst.getInOrder(SampleTree02.getRootNode());
        List<Integer> inOrder03 = depthFirst.getInOrder(SampleTree03.getRootNode());
        try {
            SampleTree01.checkInOrder(inOrder01);
            SampleTree02.checkInOrder(inOrder02);
            SampleTree03.checkInOrder(inOrder03);
        } catch (Exception e) {
            System.out.println();
            e.printStackTrace();
        }
    }

    public static void TEST_POSTORDER() {
        DepthFirst depthFirst = new DepthFirst();
        List<Integer> postOrder1 = depthFirst.getPostOrder(SampleTree01.getRootNode());
        List<Integer> postOrder2 = depthFirst.getPostOrder(SampleTree02.getRootNode());
        List<Integer> postOrder3 = depthFirst.getPostOrder(SampleTree03.getRootNode());

        try {
            SampleTree01.checkPostOrder(postOrder1);
            SampleTree02.checkPostOrder(postOrder2);
            SampleTree03.checkPostOrder(postOrder3);
        } catch (Exception e) {
            System.out.println();
            e.printStackTrace();
        }
    }

    public static void TEST_NULL() {
        DepthFirst depthFirst = new DepthFirst();
        List<Integer> preOrder = depthFirst.getPostOrder(null);
        List<Integer> inOrder = depthFirst.getPostOrder(null);
        List<Integer> postOrder = depthFirst.getPostOrder(null);
        System.out.println(preOrder);
        System.out.println(inOrder);
        System.out.println(postOrder);
    }

    public static void main(String[] args) {
        TEST_PREORDER();
        TEST_INORDER();
        TEST_POSTORDER();
        TEST_NULL();
    }
}