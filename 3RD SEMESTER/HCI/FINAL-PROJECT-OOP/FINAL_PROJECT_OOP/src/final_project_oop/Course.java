/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package final_project_oop;

/**
 *
 * @author Lenovo
 */
public class Course extends Student{
    private String cName;
    private String tName;
    private int Fee;
    
    Course(){
        
    }
    Course(String c, String t, int f){
        cName = c;
        tName = t;
        Fee = f;
    }
    
    public String toString(){
       return cName+ " , "  + tName +" , "+ Fee;
    }

    public String getcName() {
        return cName;
    }

    public String gettName() {
        return tName;
    }
    
    public void setTName(String tn){
        this.tName = tn;
    }

    public int getFee() {
        return Fee;
    }
}
