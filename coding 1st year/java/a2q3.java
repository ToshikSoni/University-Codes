//Write a Java program that calculates the sum of an array of integers using multiple
//threads. The program should use a divide-and-conquer approach to split the array into
//smaller subarrays, calculate the sum of each subarray in a separate thread, and then
//combine the results.
import java.util.Scanner;

class t extends Thread {
    public static int SUM = 0;
    int a[];

    t() {
    }

    t(int arr[]) {
        a = arr;
    }

    synchronized public void run() {
        for (int i = 0; i < a.length; i++) {
            SUM += a[i];
        }
    }
}

public class a2q3 {
    public static int THREAD_COUNT = Runtime.getRuntime().availableProcessors();

    public static void main(String[] args) {
        System.out.print("Enter size of array: ");
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int[] arr = new int[size];
        System.out.println("Enter elements in array: ");
        for (int i = 0; i < size; i++)
            arr[i] = sc.nextInt();
        int numArr = size / (THREAD_COUNT - 1);
        int smolArr = size % (THREAD_COUNT - 1);
        sc.close();
        int[] tempArr = new int[numArr], tempsmol = new int[smolArr];
        t[] tarr = new t[THREAD_COUNT];
        int temp1 = 0, temp2 = 0;
        while (temp1 != THREAD_COUNT) {
            if (temp1 == THREAD_COUNT - 1) {
                for (int i = 0; i < smolArr; i++) {
                    tempsmol[i] = arr[temp2];
                    temp2++;
                }
                tarr[temp1] = new t(tempsmol);
            } else {
                for (int i = 0; i < numArr; i++) {
                    tempArr[i] = arr[temp2];
                    temp2++;
                }
                tarr[temp1] = new t(tempArr);
            }
            temp1++;
        }
        try {
            for (int i = 0; i < THREAD_COUNT; i++) {
                tarr[i].start();
                tarr[i].join();
            }
        } catch (Exception e) {
            System.out.println(e);
        }
        System.out.println("Sum of all elements is: " + t.SUM);
    }
}