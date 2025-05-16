import java.util.Scanner;

class t1 extends Thread {
    int a[];

    t1(int arr[]) {
        a = arr;
    }

    public void run() {
        int sum = 0;
        for (int i = 0; i < a.length; i++)
            sum += a[i];
        System.out.println("Sum of all elements is: " + sum);
    }
}

class t2 extends Thread {
    int a[];

    t2(int arr[]) {
        a = arr;
    }

    public void run() {
        int small = a[0], big = a[0];
        for (int i = 0; i < a.length; i++) {
            if (small > a[i])
                small = a[i];
            if (big < a[i])
                big = a[i];
        }
        System.out.println("Smallest: " + small + "\nLargest: " + big);
    }
}

public class c230427q1 {
    public static void main(String ar[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int size = sc.nextInt();
        int arr[];
        arr = new int[size];
        System.out.println("Enter elements in array:");
        for (int i = 0; i < size; i++)
            arr[i] = sc.nextInt();
        t1 th1 = new t1(arr);
        th1.start();
        t2 th2 = new t2(arr);
        th2.start();
        sc.close();
    }
}
