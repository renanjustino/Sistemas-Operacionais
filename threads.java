public class Threads {
    public int variavelCompartilhada = 0;
    public static void main(String [] args) {
        new Threads().executar();
    }
    public void executar() {
        Thread segundaThread = new ThreadDecrementa(this);
        segundaThread.start();
        while(true) {
            variavelCompartilhada++;
            System.out.println("Variável vale: " + variavelCompartilhada);
            dormir(1500);
        }
    }
    public void dormir(int milissegundos) {
        try {
System.out.println(Thread.currentThread().getName() + " irá dormir por " + milissegundos + " milissegundos.");
            Thread.sleep(milissegundos);
        } catch (InterruptedException e) {
        }
    }
}

class ThreadDecrementa extends Thread {
    private Threads t1;
    public ThreadDecrementa(Threads t1) {
        this.t1 = t1;
    }

    @Override
    public void run() {
        while(true) {
            t1.variavelCompartilhada--;
            System.out.println("Variável vale: " + t1.variavelCompartilhada);
            t1.dormir(1000);
        }
    }
}