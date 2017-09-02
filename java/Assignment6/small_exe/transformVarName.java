package small_exe;

//4. 写一个函数, 将驼峰命名法字符串转成下划线命名字符串(需考虑各类编码中常见的命名)
//
//e.g.  GetItem -> get_item
//      getItem -> get_item
//      doIT    -> do_IT
      
public class transformVarName {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s="getItaFem123";
		System.out.println(s);
		System.out.println(trans(s));
	}

	public static String trans (String s) {
		String r=s.replaceAll("([A-Z]).*([A-Z])", "$2".toLowerCase()+"$1".toLowerCase());
		return r;
	}
}
