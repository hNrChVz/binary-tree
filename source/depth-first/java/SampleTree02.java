import java.util.List;

public class SampleTree02 {
    /*
                45
               /  \
              1    5 
             / \    \
           63   7   20
          /   / 
         6   87
    */
    public static int[] PRE_ORDER = {45, 1, 63, 6, 7, 87, 5, 20};
    public static int[] IN_ORDER = {6, 63, 1, 87, 7, 45, 5, 20};
    public static int[] POST_ORDER = {6, 63, 87, 7, 1, 20, 5, 45};
    
    public static TreeNode getRootNode() {
        TreeNode node45 = new TreeNode(45);
        TreeNode node1 = new TreeNode(1);
        TreeNode node5 = new TreeNode(5);
        TreeNode node63 = new TreeNode(63);
        TreeNode node7 = new TreeNode(7);
        TreeNode node20 = new TreeNode(20);
        TreeNode node6 = new TreeNode(6);
        TreeNode node87 = new TreeNode(87);

        node45.left = node1;
        node45.right = node5;
        node1.left = node63;
        node1.right = node7;
        node5.right = node20;
        node63.left = node6;
        node7.left = node87;

        return node45;
    }

    public static void checkPreOrder(List<Integer> in) throws Exception {
        System.out.println(in);

        if (in.size() != PRE_ORDER.length) {
            String str = String.format("checkPreOrder() WRONG LENGTH; expected: %d ; got: %d", PRE_ORDER.length, in.size());
            throw new Exception(str);
        }

        for (int i = 0; i < PRE_ORDER.length; ++i) {
            if (PRE_ORDER[i] != in.get(i)) {
                String str = String.format("checkPreOrder() INCORRECT; expected: %d ; got: %d", PRE_ORDER[i], in.get(i));
                throw new Exception(str);
            }
        }
    }

    public static void checkInOrder(List<Integer> in) throws Exception {
        System.out.println(in);

        if (in.size() != IN_ORDER.length) {
            String str = String.format("checkInOrder() WRONG LENGTH; expected: %d ; got: %d", IN_ORDER.length, in.size());
            throw new Exception(str);
        }

        for (int i = 0; i < IN_ORDER.length; ++i) {
            if (IN_ORDER[i] != in.get(i)) {
                String str = String.format("checkInOrder() INCORRECT; expected: %d ; got: %d", IN_ORDER[i], in.get(i));
                throw new Exception(str);
            }
        }
    }

    public static void checkPostOrder(List<Integer> in) throws Exception {
        System.out.println(in);

        if (in.size() != POST_ORDER.length) {
            String str = String.format("checkPostOrder() WRONG LENGTH; expected: %d ; got: %d", POST_ORDER.length, in.size());
            throw new Exception(str);
        }

        for (int i = 0; i < POST_ORDER.length; ++i) {
            if (POST_ORDER[i] != in.get(i)) {
                String str = String.format("checkPostOrder() INCORRECT; expected: %d ; got: %d", POST_ORDER[i], in.get(i));
                throw new Exception(str);
            }
        }
    }
}