
public class Gen2Var <T, V> {
	
	T obj;
	V obj2;
	
	Gen2Var (T o, V o2) {
		obj = o;
		obj2 = o2;
	}

	public T getObj() {
		return obj;
	}

	public void setObj(T obj) {
		this.obj = obj;
	}
	
	public V getObj2() {
		return obj2;
	}

	public void setObj2(V obj) {
		this.obj2 = obj;
	}
	
	void showType() {
		System.out.println("Type-1: " + obj.getClass().getName());
		System.out.println("Type-2: " + obj2.getClass().getName());
	}
	

}
