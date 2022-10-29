package binary_serch;

import javax.swing.plaf.synth.SynthTextAreaUI;
import java.util.Scanner;

public class celling {
    public static void main(String[] args) {
        int []ar={1,2,3,4,5,6,77,8,8,99,9,7454,33543};
        Scanner input = new Scanner(System.in);
        System.out.println("ente  the number the u need to search");
        int a = input.nextInt();
        int ans= celing(ar,a);
        System.out.println(ans);
    }

    static int celing(int[]arr , int target){
        int start=0;
        int end = arr.length;

        while(start <=end){
            int mid = start + (end - start)/2;
            if( target < arr[mid]){
                end = mid -1;
            }
            else if (target > arr[mid ]){
                start = mid +1;
            }
            else {
                return mid ;
            }
        }
        return start;
    }
}
