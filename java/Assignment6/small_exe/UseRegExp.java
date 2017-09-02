package small_exe;

public class UseRegExp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = "[lol]你好，帮我把这些markup清掉，[smile]。谢谢！";
		System.out.println(regSub(s));
	}

	public static String regSub (String s) {
//		String r=s.replaceAll("l[^l]*l", "");
		String r=s.replaceAll("\\[[^\\[|\\]]*\\]", "");
		return r;
	}
}
