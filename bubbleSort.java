package sorthingp;
import java.sql.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class bubble {
    public static void main(String[] args) {
        int arr[] = {3 ,3,4,74,2,4,74,2};
        bubblesort(arr);
        System.out.println(Arrays.toString(arr));
        int arr1[] = {2,3,4,5,732,4,34,234,2};
        selection(arr1);
        System.out.println(Arrays.toString(arr1));
        int arr2[] = {2,3,4,3,4,534,2,3,2,4,2,3};
        insertion(arr2);
        System.out.println(Arrays.toString(arr2));
    }
    static void cycle(int[] arr){
        // given range between one to n numbers then we need to use this
        // most important sorting method
        // we can do this in the single for loop
            int i =0;
            while(i <arr.length){
                int correct = arr[i]-1;
                if(arr[i] != arr[correct]){
                    swap(arr,i,correct);
                }
                else{
                    i++;
                }
            }
    }
    static void insertion(int[]arr){
        for (int i = 0; i < arr.length -1; i++) {
            for (int j = i+1; j >0; j--) {
                if(arr[j] < arr[j -1]){
                    swap(arr,j,j-1);
                }
            }
        }
    }
    static void selection(int [] arr) {
        for (int i = 0; i <= arr.length; i++) {
            //find the maximum item in the remaining item in the array and swap with thw correct index
            int last = arr.length - 1;
            int max = getmaxindex(arr, 0, last);
            swap(arr, max, last);
        }
    }
    private static int getmaxindex(int[] arr , int start ,int end){
        int max = start;
        for (int i = 0; i <= arr.length -1 ; i++) {
            if(arr[max] <arr[i]){
                max=i;
            }
            else {
                break;
            }
        }
        return max;
    }
    static void swap(int[] arr, int first , int secound ){
        int temp = arr[first];
        arr[first]=arr[secound];
        arr[secound]=temp;
    }
    static void bubblesort(int[] arr){
        //run the steps in n-
        for (int i = 0; i < arr.length; i++) {
            //for each step ,max item will come at last respective index
            for (int j = 1; j <= arr.length - i ; j++) {
                //swap if the item is smaller than the previous item
                if(arr[j] <arr[j-1]){
                    int temp=arr[j];
                    arr[j]=arr[j-1];
                    arr[j-1]=temp;
                }
            }
        }
    }
}
