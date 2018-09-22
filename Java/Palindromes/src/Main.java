/**
 * DATE: 9/10/18
 * PROGRAM: Palindrome solver
 * PROGRAM PURPOSE: To solve palindromic squares
 * PROGRAMMER: Thomas Dalgetty
 *
 * The code below is a little messy but it works and it is fairly efficient.
 */

public class Main
{
    long arr[];
    public Main()
    {
        arr = new long[35];
    } //default constructor, initializes long array

    public Main(String[] _arr) //No real use for this constructor, takes in a string array converts it to long
    {
        arr = new long[35];
        parser(_arr);
    }

    public static void main(String [] args)
    {
        Main thing = new Main();
        thing.solver();
    }

    public String[] solver() //solves for the first 35 palindromes easily modified for more
    {
     String[] arr = new String[35];
     long num = 0;
     int index = 0;
     //int numindex = 1; //used for debugging
     while(arr[34] == null)
     {
        if(helper(Long.toString(num * num)))
        {
            arr[index] = Long.toString(num * num);
            //System.out.println(numindex + "NUM: " + num * num); //used for debugging and visualizing
            //numindex++; //used for debugging
            num++;
            index++;
        }
        num++;
     }
        tooLazyToLookThisUp(arr); //displays the array in console
        this.parser(arr); //assigns the values to the object array
        return arr;
    }

    public static boolean helper(String num) //recursively checks if a string is palindrome
    {
        if(num.length() <= 1)
            return true;
        else if(num.substring(0, 1).equals(num.substring(num.length() - 1)))
            return helper(num.substring(1, num.length() - 1));
        else
            return false;
    }

    public static String reverse(String str) //ignore this method, it is not used for the solution. But I did put enough thought into that I don't want to delete it
    {
        String str2 = "";
        for(int i = str.length(); i > 0; i--)
        {
            str2 += str.substring(i - 1, i);
        }
        System.out.println("Original: " + str + "\nReversed: " + str2);
        return str2;
    }

    public void parser(String[] arr) //converts a string array to long array
    {
        for(int i = 0; i < arr.length; i++)
        {
            this.arr[i] = Long.parseLong(arr[i]);
        }
    }

    public static void tooLazyToLookThisUp(String[] arr) //toString for the array, as the name suggests I was too lazy to look it up
    {
        String str = "";
        for (int i = 1; i < arr.length - 1; i++) {
            str += arr[i] + ", ";
        }
        System.out.println("[" + arr[0] + ", " + str + arr[arr.length - 1] + "]");
    }
}
