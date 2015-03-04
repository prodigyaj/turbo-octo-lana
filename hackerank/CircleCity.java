import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class CircleCity {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while(t>0)
        {
          int suburbs=0;
          String[] inp = sc.nextLine().split(" ");
          int rSquare = Integer.parseInt(inp[0]);
          int k = Integer.parseInt(inp[1]);
          //int r = (int)Math.sqrt(rSquare);
          for(int x=1;x*x<=rSquare;x++)
          {
            double y = Math.sqrt(rSquare - x*x);
            int yInt = (int)y;
            if(y-yInt<=0.00000001)
                suburbs+=4;
          }
          
          if(suburbs<=k)
              System.out.println("possible");
          else
              System.out.println("impossible");
          --t;
        }
    }
}
