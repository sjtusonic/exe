package test_regexp;


import java.util.regex.*;
public class Test2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Pattern p = Pattern.compile("a");
		Matcher m = p.matcher("ababcad");
		if(m.matches()) {
		    m.group(1); //ƥ���1��
		    m.group(2); //ƥ���2��
		}

	}

}
