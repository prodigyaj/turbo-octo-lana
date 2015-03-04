public class ClimbingStairs {

    

    public int climbStairs(int n) {

        if(n==0)

            return 0;

        if(n==1)

            return 1;

        if(n==2)

            return 2;

        

        int totalWays=0;

        

        int first = 1;

        int second =2 ;

        

        for(int i=3;i<=n;i++)

        {

            totalWays=first+second;

            first=second;

            second=totalWays;

        }

        

        return totalWays;

        

            

    }

}
