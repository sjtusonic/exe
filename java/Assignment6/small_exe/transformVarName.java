package small_exe;

//4. дһ������, ���շ��������ַ���ת���»��������ַ���(�迼�Ǹ�������г���������)
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
