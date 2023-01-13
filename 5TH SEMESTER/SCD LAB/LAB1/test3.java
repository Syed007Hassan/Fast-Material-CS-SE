class Weapons {

    public void Description() {
        System.out.println("Description of weapons");
    }

}

class HotWeapons extends Weapons {

   public void Description(){
    System.out.println("Hot weapons uses gunpowder, or explode.");
   }

}

class Bombs extends HotWeapons {

    public void Description() {
        System.out.println("Bombs blow up");
    }

}

class NuclearBombs extends Bombs {

    public void Description() {
        System.out.println("Nuclear bombs blow up, and use nuclear fission and fusion.");
    }
}

public class test3 {

    public static void main(String[] args) {

        Weapons w = new Weapons();
        HotWeapons ht = new HotWeapons();
        Bombs b = new Bombs();
        NuclearBombs nb = new NuclearBombs();

       w.Description();
       ht.Description();
       b.Description();
       nb.Description();

    }

}
