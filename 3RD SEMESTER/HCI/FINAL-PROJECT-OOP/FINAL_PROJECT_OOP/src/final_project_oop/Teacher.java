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
public class Teacher {

   
    private String name;
    private String email;
    private int contact;
    private String depart;
    private String status;

    public Teacher(String name, String email, int contact, String depart, String status) {
        this.name = name;
        this.email = email;
        this.contact = contact;
        this.depart = depart;
        this.status = status;
    }
    
     public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    public int getContact() {
        return contact;
    }

    public String getDepart() {
        return depart;
    }

    public String getStatus() {
        return status;
    }
    
    
    
    
}
