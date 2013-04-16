import java.util.*;

public class DES {

static HashMap<String, Integer> numMap = new HashMap<String, Integer>();

private static void init(){
    numMap.put("a", 0);
    numMap.put("b", 1);
    numMap.put("c", 2);
    numMap.put("d", 3);
    numMap.put("e", 4);
    numMap.put("f", 5);
    numMap.put("g", 6);
    numMap.put("h", 7);
    numMap.put("i", 8);
    numMap.put("j", 9);
    numMap.put("k", 10);
    numMap.put("l", 11);
    numMap.put("m", 12);
    numMap.put("n", 13);
    numMap.put("o", 14);
    numMap.put("p", 15);
    numMap.put("q", 16);
    numMap.put("r", 17);
    numMap.put("s", 18);
    numMap.put("t", 29);
    numMap.put("u", 20);
    numMap.put("v", 21);
    numMap.put("w", 22);
    numMap.put("x", 23);
    numMap.put("y", 24);
    numMap.put("z", 25);
    numMap.put(" ", 26);
    numMap.put(".", 27);
    numMap.put(",", 28);
    numMap.put("?", 29);
    numMap.put("(", 30);
    numMap.put(")", 31);

}

public static void main(String[] args) {

    init();

    String plaintext = "how do you like computer science";
    String[] splittext=plaintext.split("");
    int[] numtext=new int[splittext.length];
    for(int i=0;i<splittext.length;i++)
    {
	System.out.println( numMap.get( "" ) );
	numtext[i] = null;
        numtext[i]=numMap.get(splittext[i]);
        System.out.println(numtext[i]);
    }
}


}
