import java.util.List;

public class SampleTree03 {
    /*
                4
               / \
              3   5
             /     \
            2       6
           /         \
          1           7
    */
    public static int[] PRE_ORDER = {4, 3, 2, 1, 5, 6, 7};
    public static int[] IN_ORDER = {1, 2, 3, 4, 5, 6, 7};
    public static int[] POST_ORDER = {1, 2, 3, 7, 6, 5, 4};
    
    public static TreeNode getRootNode() {
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        TreeNode node4 = new TreeNode(4);
        TreeNode node5 = new TreeNode(5);
        TreeNode node6 = new TreeNode(6);
        TreeNode node7 = new TreeNode(7);

        node4.left = node3;
        node4.right = node5;
        node3.left = node2;
        node5.right = node6;
        node2.left = node1;
        node6.right = node7;

        return node4;
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