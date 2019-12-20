import java.util.List;

public class SampleTree01 {
       /*
               12           
              /  \          
            /      \        
           10      30       
          /  \       \      
         6   57      40     
            /  \    /       
           13  89  93       
                    \      
                     1
    */
    public static int[] PRE_ORDER = {12, 10, 6, 57, 13, 89, 30, 40, 93, 1};
    public static int[] IN_ORDER = {6, 10, 13, 57, 89, 12, 30, 93, 1, 40};
    public static int[] POST_ORDER = {6, 13, 89, 57, 10, 1, 93, 40, 30, 12};

    public static TreeNode getRootNode() {
        TreeNode node12 = new TreeNode(12);
        TreeNode node10 = new TreeNode(10);
        TreeNode node30 = new TreeNode(30);
        TreeNode node6 = new TreeNode(6);
        TreeNode node57 = new TreeNode(57);
        TreeNode node40 = new TreeNode(40);
        TreeNode node13 = new TreeNode(13);
        TreeNode node89 = new TreeNode(89);
        TreeNode node93 = new TreeNode(93);
        TreeNode node1 = new TreeNode(1);

        node12.left = node10;
        node12.right = node30;
        node10.left = node6;
        node10.right = node57;
        node30.right = node40;
        node57.left = node13;
        node57.right = node89;
        node40.left = node93;
        node93.right = node1;

        return node12;
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