
public class Bounded <T extends Number>{
	T obj;
	
	Bounded (T o) {
		obj = o;
	}

	public T getObj() {
		return obj;
	}

	public void setObj(T obj) {
		this.obj = obj;
	}
	
	void showType() {
		System.out.println("Type: " + obj.getClass().getName());
	}
	
	
}
