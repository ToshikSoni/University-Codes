public class c230426q1 extends Thread {
    public void run() {
        System.out.println(Thread.currentThread().getPriority());
    }

    public static void main(String[] args) {
        /*
         * Creation of threads
         * two ways of creating the threads in java
         * 1. by extending Thread class
         * class A extends Thread
         * {
         * 
         * }
         * 
         * 2. by implementing Runnable interface
         * class A implements Runnable
         * {
         * 
         * }
         * 
         * Q. why do we have two different methods to create thread
         * Ans. because while extending we cannot enable multiple inheritance but we can
         * do it by using interface using implements
         * Recommended to use Thread class
         * 
         * *****************************************************************************
         * 
         * ** run() method
         * public void run()
         * {
         * 
         * }
         * instructions that will be executed corresponding to the thread
         * 
         * ** start() method
         * start()- it calls the run method for a specific thread suppose t1 is a thread
         * then the start method will be t1.start()
         * 
         * ****************************************************
         * 
         * methods of thread
         * 
         * 1. getID()
         * 2. getName()/setName()
         * 3. getPriority() (1-10)(default=5)[1=less,10=more]
         *      setPriority(from 1 to 10)
         * 4. Thread.currentThread()
         * 5. four constructors
         *      1. Thread()
         *      2. Thread(String name)
         *      3. Thread(Runnable )
         *      4. Thread()
         * 
         */
        c230426q1 thread1 = new c230426q1();
        c230426q1 thread2 = new c230426q1();
        thread1.start();
        thread2.start();
    }
}