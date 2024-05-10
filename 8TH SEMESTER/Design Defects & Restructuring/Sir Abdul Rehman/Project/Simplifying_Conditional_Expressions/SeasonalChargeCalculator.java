package Simplifying_Conditional_Expressions;

import java.time.LocalDate;

public class SeasonalChargeCalculator {
    private static final LocalDate SPRING_BEGIN = LocalDate.of(2022, 3, 20);
    private static final LocalDate SPRING_END = LocalDate.of(2022, 6, 20);

    private double springRate;
    private double autumnRate;
    private double autumnServiceCharge;

    public SeasonalChargeCalculator(double springRate, double autumnRate, double autumnServiceCharge) {
        this.springRate = springRate;
        this.autumnRate = autumnRate;
        this.autumnServiceCharge = autumnServiceCharge;
    }

    // Complex Expression for this Calculate Charge
    // public double calculateCharge(LocalDate date, int quantity) {
    //     double charge;
    //     if (date.isBefore(SPRING_BEGIN) || date.isAfter(SPRING_END)) {
    //         charge = quantity * autumnRate + autumnServiceCharge;
    //     } else {
    //         charge = quantity * springRate;
    //     }
    //     return charge;
    // }

    // Example of Simplifying Conditional Expressions
    public double calculateCharge(LocalDate date, int quantity) {
        double charge;

        if (isAutumn(date)) {
            charge = autumnCharge(quantity);
        }
        else {
            charge = springCharge(quantity);
        }

        return charge;
    }

    public boolean isAutumn(LocalDate date) {
        return date.isBefore(SPRING_BEGIN) || date.isAfter(SPRING_END);
    }

    public double autumnCharge(double quantity){
        return quantity * autumnRate + autumnServiceCharge;
    }

    public double springCharge(double quantity){
        return quantity * springRate;
    }

}





