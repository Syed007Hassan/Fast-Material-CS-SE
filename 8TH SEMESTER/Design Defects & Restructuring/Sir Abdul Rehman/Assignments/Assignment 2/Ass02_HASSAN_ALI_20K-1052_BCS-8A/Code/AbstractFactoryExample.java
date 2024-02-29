package DDR.assignment2;

// AbstractFactory.java
interface AbstractFactory {
  Processor createProcessor();

  RAM createRAM();
}

// PCFactory.java
class PCFactory implements AbstractFactory {
  public Processor createProcessor() {
    return new PCProcessor();
  }

  public RAM createRAM() {
    return new PCRAM();
  }
}

// ServerFactory.java
class ServerFactory implements AbstractFactory {
  public Processor createProcessor() {
    return new ServerProcessor();
  }

  public RAM createRAM() {
    return new ServerRAM();
  }
}

// Processor.java
interface Processor {
  void process();
}

// RAM.java
interface RAM {
  void store();
}

// PCProcessor.java
class PCProcessor implements Processor {
  public void process() {
    System.out.println("PC Processor is processing...");
  }
}

// PCRAM.java
class PCRAM implements RAM {
  public void store() {
    System.out.println("PC RAM is storing...");
  }
}

// ServerProcessor.java
class ServerProcessor implements Processor {
  public void process() {
    System.out.println("Server Processor is processing...");
  }
}

// ServerRAM.java
class ServerRAM implements RAM {
  public void store() {
    System.out.println("Server RAM is storing...");
  }
}

// AbstractFactoryExample.java
class AbstractFactoryExample {
  public static void main(String[] args) {
    AbstractFactory pcFactory = new PCFactory();
    Processor pcProcessor = pcFactory.createProcessor();
    RAM pcRAM = pcFactory.createRAM();
    pcProcessor.process();
    pcRAM.store();

    AbstractFactory serverFactory = new ServerFactory();
    Processor serverProcessor = serverFactory.createProcessor();
    RAM serverRAM = serverFactory.createRAM();
    serverProcessor.process();
    serverRAM.store();
  }
}