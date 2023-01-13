package ExcpHndl;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class TryWithResources {
	
	//try with resources
	static String readFirstLineFromFile(String path) throws IOException {
	    try (FileReader fr = new FileReader(path);
	         BufferedReader br = new BufferedReader(fr)) {
	        return br.readLine();
	    }
	}
	
	static String readFirstLineFromFileWithFinallyBlock(String path) throws IOException {
		   
	    FileReader fr = new FileReader(path);
	    BufferedReader br = new BufferedReader(fr);
	    try {
	        return br.readLine();
	    } finally {
	        br.close();
	        fr.close();
	    }
	}
	
	public static void main(String[] args) throws IOException {
		String path = "C:\\Users\\Fast\\Desktop\\File.txt";
		
		System.out.println(readFirstLineFromFile(path));
		System.out.println(readFirstLineFromFileWithFinallyBlock(path));

	}

}
