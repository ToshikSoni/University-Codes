class t1 extends Thread {
    public void run() {
        for (int i = 1; i < 21; i++)
            if (i % 2 == 0)
                System.out.println(i);
    }
}

class t2 extends Thread {
    public void run() {
        for (int i = 1; i < 21; i++)
            if (i % 2 != 0)
                System.out.println(i);
    }
}

public class Topic9_a {
    public static void main(String ar[]) {
        t1 th1 = new t1();
        th1.start();
        try {
            th1.join();
        } catch (Exception e) {
            System.out.println(e);
        }
        t2 th2 = new t2();
        th2.start();
    }
}
