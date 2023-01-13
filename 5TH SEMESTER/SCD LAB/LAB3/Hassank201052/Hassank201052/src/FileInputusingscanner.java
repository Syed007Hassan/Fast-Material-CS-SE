import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

 public class FileInputusingscanner {


  public static void main(String[] args)
  
 throws IOException {
 
// TODO Auto-generated method stub
  FileInputStream f = new FileInputStream("new.txt");
 Scanner s = new Scanner(f);
 while(s.hasNext()) {


System.out.println(s.nextLine());

 }

 }

 }