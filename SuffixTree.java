import java.*;
import java.util.*;

public class SuffixTree {
    SuffixTreeNode root = new SuffixTreeNode();
 
    public SuffixTree(String s) {
        for (int i = 0; i < s.length(); ++i) {
            root.insert(s.substring(i), i);
        }
    }
 
    public List<Integer> getIndexes(String s) {
        return root.getIndices(s);
    }

    public static void main (String[] s) {
      SuffixTree tree = new SuffixTree("mississippi");
      List<Integer> list = tree.getIndexes("is");
      for (Integer d:list) {
        System.out.println(d);
      }
    }
}
 
