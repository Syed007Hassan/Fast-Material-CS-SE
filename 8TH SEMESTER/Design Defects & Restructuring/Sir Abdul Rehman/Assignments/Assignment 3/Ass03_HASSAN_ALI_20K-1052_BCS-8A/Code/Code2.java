class ARectangle {
    private float ptX;
    private float ptY;
    private float wd;
    private float ht;

    public ARectangle() {
        this.ptX = 0;
        this.ptY = 0;
        this.wd = 1;
        this.ht = 1;
    }

    public ARectangle(float ptX, float ptY, float wd, float ht) {
        this.ptX = ptX;
        this.ptY = ptY;
        this.wd = wd;
        this.ht = ht;
    }

    public float getPtX() {
        return ptX;
    }

    public void setPtX(float ptX) {
        this.ptX = ptX;
    }

    public float getPtY() {
        return ptY;
    }

    public void setPtY(float ptY) {
        this.ptY = ptY;
    }

    public float getWd() {
        return wd;
    }

    public void setWd(float wd) {
        this.wd = wd;
    }

    public float getHt() {
        return ht;
    }

    public void setHt(float ht) {
        this.ht = ht;
    }

    public float Area() {
        return wd * ht;
    }

    public float Perimeter() {
        return 2 * (wd + ht);
    }

    public boolean holds(float x, float y) {
        return (x >= ptX - wd / 2 && x <= ptX + wd / 2) && (y >= ptY - ht / 2 && y <= ptY + ht / 2);
    }

    public boolean holds(ARectangle rect) {
        float x1 = rect.ptX - rect.wd / 2;
        float x2 = rect.ptX + rect.wd / 2;
        float y1 = rect.ptY - rect.ht / 2;
        float y2 = rect.ptY + rect.ht / 2;

        return (x1 >= ptX - wd / 2 && x2 <= ptX + wd / 2) && (y1 >= ptY - ht / 2 && y2 <= ptY + ht / 2);
    }

    public boolean covers(ARectangle rect) {
        float x1 = ptX - wd / 2;
        float x2 = ptX + wd / 2;
        float y1 = ptY - ht / 2;
        float y2 = ptY + ht / 2;

        float rx1 = rect.ptX - rect.wd / 2;
        float rx2 = rect.ptX + rect.wd / 2;
        float ry1 = rect.ptY - rect.ht / 2;
        float ry2 = rect.ptY + rect.ht / 2;

        return (rx2 >= x1 && rx1 <= x2) && (ry2 >= y1 && ry1 <= y2);
    }
}

public class Code2 {

    public static void main(String[] args) {
        ARectangle rect01 = new ARectangle(1.5f, 1.5f, 5.5f, 4.9f);

        System.out.println("Area of rect01: " + rect01.Area());

        System.out.println("Perimeter of rect01: " + rect01.Perimeter());

        System.out.println("Does rect01 hold point (2.5, 2.5)? " + rect01.holds(2.5f, 2.5f));

        ARectangle rect02 = new ARectangle(3, 5, 8.5f, 3.5f);
        System.out.println("Does rect01 hold rect02? " + rect01.holds(rect02));

        ARectangle rect03 = new ARectangle(3, 5, 2.3f, 5.4f);
        System.out.println("Does rect01 cover rect03? " + rect01.covers(rect03));
    }
}
