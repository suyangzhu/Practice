import java.*;
import java.util.*; 
public class SuffixTreeNode {
    private char c;
    private List<Integer> indices = new ArrayList<Integer>();;
    private Map<Character, SuffixTreeNode> children =
        new HashMap<Character, SuffixTreeNode>();
 
    public void insert(String s, int index) {
        indices.add(index);
        if (s != null && s.length() > 0) {
            char character = s.charAt(0);
            if (children.keySet().contains(character)) {
                children.get(character).insert(
                        s.substring(1), index);
            } else {
                SuffixTreeNode child = new SuffixTreeNode();
                children.put(character, child);
                child.insert(s.substring(1), index);
            }
        }
    }
 
    public List<Integer> getIndices(String s) {
        if (s == null || s.length() == 0)
            return indices;
        else {
            char character = s.charAt(0);
            if (children.containsKey(character))
                return children.get(character).getIndices(
                        s.substring(1));
            else
                return null;
        }
    }
}
