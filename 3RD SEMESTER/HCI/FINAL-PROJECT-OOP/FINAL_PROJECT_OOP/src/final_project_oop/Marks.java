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
public class Marks extends Course{
    
    private double midMarks=0;
    private double finalMarks=0;
    private double assingmentMarks=0;
    private double quizezMarks=0;
    private double cp=0;
    
    Marks(double m, double f, double a, double q, double c ){
        this.midMarks = m;
        this.finalMarks =f;
        this.assingmentMarks =a;
        this.quizezMarks = q;
        this.cp = c;
    }

    public double getMidMarks() {
        return midMarks;
    }

    public double getFinalMarks() {
        return finalMarks;
    }

    public double getAssingmentMarks() {
        return assingmentMarks;
    }

    public double getQuizezMarks() {
        return quizezMarks;
    }

    public double getCp() {
        return cp;
    }
    
    
    
}
