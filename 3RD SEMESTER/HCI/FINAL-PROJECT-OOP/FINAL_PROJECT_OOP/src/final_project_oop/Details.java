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
public class Details {
    private String firstName;
    private String lastName;
    private String homeAddress;
    private String age;
    private int ERP;
    private String pass;
    
    Details(){
        
    }
    
    Details(String f, String l, String h, String a, int e , String p){
        this.firstName =f;
        this.lastName =l;
        this.homeAddress =h;
        this.age = a;
        this.ERP = e;
        this.pass = p;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getHomeAddress() {
        return homeAddress;
    }

    public String getAge() {
        return age;
    }

    public int getERP() {
        return ERP;
    }
    
    public String getPass() {
        return pass;
    }
    
    
}
