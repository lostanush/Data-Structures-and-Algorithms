import java.util.LinkedList;
import java.util.Queue;

public class BTbuilder {
    static class Node{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data=data;
            this.left = null;
            this.right = null;
        }
    }






    static class BinaryTree{
        static int idx= -1;
        public static Node buildTree(int nodes[]){
            idx++;
            if(nodes[idx]==-1) return null;

            Node newNode = new Node(nodes[idx]);
            newNode.left = buildTree(nodes);
            newNode.right = buildTree(nodes);
            return newNode;
        }




        
        public static void preorder(Node root){
            if(root==null) return;
            System.out.print(" "+root.data);
            preorder(root.left);
            preorder(root.right);
        }public static void inorder(Node root){
            if(root==null) return; 
            inorder(root.left);
            System.out.print(" "+root.data);
            inorder(root.right);
        }public static void postorder(Node root){
            if(root==null) return;
            postorder(root.left);
            postorder(root.right); 
            System.out.print(" "+root.data);
        }








        public static void levelOrder(Node root){
            if(root==null) return;

            Queue<Node> q = new LinkedList<>();
            q.add(root);
            q.add(null);

            while( !q.isEmpty()){
                Node currNode = q.remove();
                if(currNode == null){
                    System.out.println();
                    if(q.isEmpty()){
                        break;
                    } else {
                        q.add(null);
                    }
                }
                else {
                    System.out.print(" "+currNode.data);
                    if(currNode.left != null){
                        q.add(currNode.left);
                    }
                    if(currNode.right != null){
                        q.add(currNode.right);
                    }
                }
            }

        }






        public static int height(Node root){
            if(root==null) return 0;
            int lh = height(root.left);
            int rh = height(root.right);
            return Math.max(lh,rh)+1;
        }






        public static int count(Node root){
            if(root==null) return 0;
            int lc = count(root.left);
            int rc = count(root.right);
            return lc + rc + 1;
        }
        





        public static int sum(Node root){
            if(root==null) return 0;
            int lsum = sum(root.left);
            int rsum = sum(root.right);
            return lsum + rsum + root.data;
        }








        public static int diameter(Node root){
            if(root == null )
                return 0;
            int ld = diameter(root.left);
            int rd = diameter(root.right);
            int lh = height(root.left);
            int rh = height(root.right);

            int selfdia = lh + rh + 1; 

            return Math.max(selfdia, Math.max(ld,rd));
        }

        static class Info{
            int dm;
            int ht;
            public Info(int d ,int h){
                dm = d;
                ht = h;
            }
        }
        public static Info diameter2(Node root){
            if(root == null )
                return new Info(0,0);

            Info li = diameter2(root.left);
            Info ri = diameter2(root.right);

            int dm = Math.max(Math.max(li.dm , ri.dm) , li.ht+ri.ht+1);
            int ht = Math.max(li.ht,ri.ht) + 1; 

            return new Info(dm,ht);

        }








        public static boolean isSubtree(Node root, Node subRoot){
            if(root == null){
                return false;
            }
            if(root.data == subRoot.data){
                if(isIdentical(root,subRoot)){
                    return true;
                }
            }
            return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
        }
    
        public static boolean isIdentical(Node node, Node subRoot){
            if(node == null && subRoot == null){
                return true;
            } else if(node == null || subRoot == null || node.data != subRoot.data){
                return false;
            }
            if(!isIdentical(node.left, subRoot.left)){
                return false;
            }
            if(!isIdentical(node.right, subRoot.right)){
                return true;
            }
            return true;
        }
    
    
    }








      public static void main(String[] args) {
        int nodes[]= {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
        BinaryTree tree = new BinaryTree();
        Node root = tree.buildTree(nodes);
        System.out.println(root.data); System.out.println();
        tree.preorder(root); System.out.println();
        tree.inorder(root); System.out.println();
        tree.postorder(root); System.out.println();
        tree.levelOrder(root); System.out.println();
        System.out.println(tree.height(root));
        System.out.println(tree.count(root));
        System.out.println(tree.sum(root));
        System.out.println(tree.diameter(root));
        System.out.println(tree.diameter2(root).dm);

        BinaryTree t = new BinaryTree();
        Node r = new Node(1);
        r.left = new Node(2);
        r.right = new Node(3);
        r.left.left = new Node(4);
        r.left.right = new Node(5);
        r.right.left = new Node(6);
        r.right.right = new Node(7);

        Node subRoot = new Node(2);
        //subRoot.left = new Node(4);
        subRoot.right = new Node(5);

        System.out.println(t.isSubtree(r, subRoot));
        

    }
}