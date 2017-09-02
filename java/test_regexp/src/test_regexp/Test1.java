package test_regexp;

import java.util.regex.*;

public class Test1 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Hello world!");
		String s="abc1def ghic2dasfc3d";
		System.out.println(s);
		Pattern p=Pattern.compile("c.d|f.g");
		Matcher m=p.matcher(s);
		Integer cntr=0;
		while (m.find()) {
			System.out.println("START:"+m.start());
			System.out.println("END:"+m.end());
			System.out.println("MATCH	 "+cntr+":"+m.group(0));
			cntr++;
		}
		String s2=m.replaceFirst("<M>");
		String s_all=m.replaceAll("<M>");
		System.out.println("REPLACE_1st:\n"+s2);
		System.out.println("REPLACE_ALL:\n"+s_all);
	}
}
