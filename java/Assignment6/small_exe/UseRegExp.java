package small_exe;

public class UseRegExp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = "[lol]��ã����Ұ���Щmarkup�����[smile]��лл��";
		System.out.println(regSub(s));
	}

	public static String regSub (String s) {
//		String r=s.replaceAll("l[^l]*l", "");
		String r=s.replaceAll("\\[[^\\[|\\]]*\\]", "");
		return r;
	}
}
